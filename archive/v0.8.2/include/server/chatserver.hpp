#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpServer.h>

// 聊天服务器的主类
class ChatServer {
private:
    muduo::net::TcpServer  server_; // 组合的 muduo 库，实现服务器功能的类对象
    muduo::net::EventLoop* loop_;   // 指向事件循环对象的指针

public:
    // 初始化聊天服务器对象
    ChatServer(
        muduo::net::EventLoop* loop, const muduo::net::InetAddress& listenAddr,
        const std::string& nameArg);

    // 启动服务
    void start();

private:
    // 上报连接相关信息的回调函数
    void onConnection(const muduo::net::TcpConnectionPtr&);

    // 上报读写事件相关信息的回调函数
    void onMessage(const muduo::net::TcpConnectionPtr&, muduo::net::Buffer*, muduo::Timestamp);
};
#endif