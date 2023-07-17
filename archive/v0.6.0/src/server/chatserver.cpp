#include "chatserver.hpp"

#include <functional>
#include <iostream>
#include <string>

// 初始化聊天服务器对象
ChatServer::ChatServer(
    muduo::net::EventLoop* loop, const muduo::net::InetAddress& listenAddr,
    const std::string& nameArg)
    : server_(loop, listenAddr, nameArg), loop_(loop) {
    // 注册链接回调
    server_.setConnectionCallback(
        std::bind(&ChatServer::onConnection, this, std::placeholders::_1));

    // 注册消息回调
    server_.setMessageCallback(std::bind(
        &ChatServer::onMessage, this, std::placeholders::_1, std::placeholders::_2,
        std::placeholders::_3));

    // 设置线程数量
    server_.setThreadNum(4);
}

// 启动服务
void ChatServer::start() { server_.start(); }

// 上报链接相关信息的回调函数
void ChatServer::onConnection(const muduo::net::TcpConnectionPtr& conn) {}

// 上报读写事件相关信息的回调函数
void ChatServer::onMessage(
    const muduo::net::TcpConnectionPtr& conn, muduo::net::Buffer* buffer, muduo::Timestamp time) {}