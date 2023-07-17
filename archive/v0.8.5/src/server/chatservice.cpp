#include "chatservice.hpp"

#include <muduo/base/Logging.h>

#include <vector>

#include "public.hpp"

// 获取单例对象的接口函数
ChatService* ChatService::instance() {
    static ChatService service;
    return &service;
}

// 注册消息以及对应的Handler回调操作
ChatService::ChatService() {
    // 用户基本业务管理相关事件处理回调注册

    _msgHandlerMap.insert(
        {LOGIN_MSG, std::bind(
                        &ChatService::login, this, std::placeholders::_1, std::placeholders::_2,
                        std::placeholders::_3)});

    _msgHandlerMap.insert(
        {REG_MSG, std::bind(
                      &ChatService::reg, this, std::placeholders::_1, std::placeholders::_2,
                      std::placeholders::_3)});

    _msgHandlerMap.insert(
        {ONE_CHAT_MSG, std::bind(
                           &ChatService::oneChat, this, std::placeholders::_1,
                           std::placeholders::_2, std::placeholders::_3)});
}

// 处理登录业务  id  pwd   pwd
void ChatService::login(const muduo::net::TcpConnectionPtr& conn, json& js, muduo::Timestamp time) {
    int         id = js["id"].get<int>();
    std::string pwd = js["password"];

    User user = _userModel.query(id);
    if (user.getId() == id && user.getPwd() == pwd) {
        if (user.getState() == "online") {
            // 该用户已经登录，不允许重复登录
            json response;
            response["msgid"] = LOGIN_MSG_ACK;
            response["errno"] = 2;
            response["errmsg"] = "this account is using, input another!";
            conn->send(response.dump());
        }
        else {

            // 登录成功，记录用户连接信息
            // 注意加锁粒度，锁的粒度一定要小
            // 数据库操作的并发安全由 mysql server 保证
            {
                std::lock_guard<std::mutex> lock(_connMutex);
                _userConnMap.insert({id, conn});
            }

            // 登录成功，更新用户状态信息 state offline=>online
            user.setState("online");
            _userModel.updateState(user);

            json response;
            response["msgid"] = LOGIN_MSG_ACK;
            response["errno"] = 0;
            response["id"] = user.getId();
            response["name"] = user.getName();
            conn->send(response.dump());
        }
    }
    else {
        // 该用户不存在，用户存在但是密码错误，登录失败
        json response;
        response["msgid"] = LOGIN_MSG_ACK;
        response["errno"] = 1;
        response["errmsg"] = "id or password is invalid!";
        conn->send(response.dump());
    }
}

// 处理注册业务  name  password
void ChatService::reg(const muduo::net::TcpConnectionPtr& conn, json& js, muduo::Timestamp time) {
    std::string name = js["name"];
    std::string pwd = js["password"];

    User user;
    user.setName(name);
    user.setPwd(pwd);
    bool state = _userModel.insert(user);
    if (state) {
        // 注册成功
        json response;
        response["msgid"] = REG_MSG_ACK;
        response["errno"] = 0;
        response["id"] = user.getId();
        conn->send(response.dump());
    }
    else {
        // 注册失败
        json response;
        response["msgid"] = REG_MSG_ACK;
        response["errno"] = 1;
        conn->send(response.dump());
    }
}

// 一对一聊天业务
void ChatService::oneChat(
    const muduo::net::TcpConnectionPtr& conn, json& js, muduo::Timestamp time) {
    int toid = js["toid"].get<int>();

    {
        std::lock_guard<std::mutex> lock(_connMutex);
        auto                        it = _userConnMap.find(toid);
        if (it != _userConnMap.end()) {
            // toid在线，转发消息   服务器主动推送消息给toid用户
            it->second->send(js.dump());
            return;
        }
    }

    // toid不在线，存储离线消息
    // _offlineMsgModel.insert(toid, js.dump());
}

// 处理客户端异常退出
void ChatService::clientCloseException(const muduo::net::TcpConnectionPtr& conn) {
    User user;
    {
        std::lock_guard<std::mutex> lock(_connMutex);
        for (auto it = _userConnMap.begin(); it != _userConnMap.end(); ++it) {
            if (it->second == conn) {
                // 从map表删除用户的连接信息
                user.setId(it->first);
                _userConnMap.erase(it);
                break;
            }
        }
    }

    // 更新用户的状态信息
    if (user.getId() != -1) {
        user.setState("offline");
        _userModel.updateState(user);
    }
}

// 获取消息对应的处理器
MsgHandler ChatService::getHandler(int msgid) {
    // 记录错误日志，msgid没有对应的事件处理回调
    auto it = _msgHandlerMap.find(msgid);
    if (it == _msgHandlerMap.end()) {
        // 返回一个默认的处理器，空操作
        return [=](const muduo::net::TcpConnectionPtr& conn, json& js, muduo::Timestamp) {
            LOG_ERROR << "msgid:" << msgid << " can not find handler!";
        };
    }
    else {
        return _msgHandlerMap[msgid];
    }
}