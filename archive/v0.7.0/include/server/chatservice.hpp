#ifndef CHATSERVICE_H
#define CHATSERVICE_H

#include <muduo/net/TcpConnection.h>

#include <functional>
#include <mutex>
#include <unordered_map>

#include "json.hpp"

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

    // 获取消息对应的处理器
    MsgHandler getHandler(int msgid);

private:
    ChatService();

    // 存储消息id和其对应的业务处理方法
    std::unordered_map<int, MsgHandler> _msgHandlerMap;
};

#endif