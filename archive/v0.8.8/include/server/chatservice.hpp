#ifndef CHATSERVICE_H
#define CHATSERVICE_H

#include <muduo/net/TcpConnection.h>

#include <functional>
#include <mutex>
#include <unordered_map>

#include "friendmodel.hpp"
#include "json.hpp"
#include "offlinemessagemodel.hpp"
#include "usermodel.hpp"

using json = nlohmann::json;

// 表示处理消息的事件回调方法类型
using MsgHandler =
    std::function<void(const muduo::net::TcpConnectionPtr& conn, json& js, muduo::Timestamp)>;

// 聊天服务器业务类
class ChatService {
public:
    // 获取单例对象的接口函数
    static ChatService* instance();

    // 处理登录业务
    void login(const muduo::net::TcpConnectionPtr& conn, json& js, muduo::Timestamp time);

    // 处理注册业务
    void reg(const muduo::net::TcpConnectionPtr& conn, json& js, muduo::Timestamp time);

    // 一对一聊天业务
    void oneChat(const muduo::net::TcpConnectionPtr& conn, json& js, muduo::Timestamp time);

    // 添加好友业务
    void addFriend(const muduo::net::TcpConnectionPtr& conn, json& js, muduo::Timestamp time);

    // 处理客户端异常退出
    void clientCloseException(const muduo::net::TcpConnectionPtr& conn);

    // 服务器异常，业务重置方法
    void reset();

    // 获取消息对应的处理器
    MsgHandler getHandler(int msgid);

private:
    ChatService();

    // 存储消息id和其对应的业务处理方法
    std::unordered_map<int, MsgHandler> _msgHandlerMap;

    // 存储在线用户的通信连接
    std::unordered_map<int, muduo::net::TcpConnectionPtr> _userConnMap;

    // 定义互斥锁，保证_userConnMap的线程安全
    std::mutex _connMutex;

    // 数据操作类对象
    UserModel _userModel;

    // 离线消息操作类对象
    OfflineMsgModel _offlineMsgModel;

    // 好友操作类对象
    FriendModel _friendModel;
};

#endif