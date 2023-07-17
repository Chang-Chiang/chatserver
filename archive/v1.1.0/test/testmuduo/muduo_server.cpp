/**
 * @file muduo_server.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-19
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpServer.h>

#include <functional> // std::bind
#include <iostream>
#include <string>
using namespace std;
using namespace muduo;
using namespace muduo::net;
using namespace placeholders;

class ChatServer {
public:
    /**
     * @brief Construct a new Chat Server object
     *
     * @param loop 事件循环
     * @param listenAddr IP + Port
     * @param nameArg
     */
    ChatServer(EventLoop* loop, const InetAddress& listenAddr, const string& nameArg)
        : _server(loop, listenAddr, nameArg), _loop(loop) {

        // 给服务器注册用户连接的创建和断开回调
        _server.setConnectionCallback(std::bind(&ChatServer::onConnection, this, _1));

        // 给服务器注册用户读写事件回调
        _server.setMessageCallback(std::bind(&ChatServer::onMessage, this, _1, _2, _3));

        // 设置服务器端的线程数量 1个I/O线程   3个worker线程
        _server.setThreadNum(4);
    }

    void start() { _server.start(); }

private:
    /**
     * @brief 专门处理用户的连接创建和断开  epoll listenfd accept
     *
     * @param conn
     */
    void onConnection(const TcpConnectionPtr& conn) {
        if (conn->connected()) {
            cout << conn->peerAddress().toIpPort() << " -> " << conn->localAddress().toIpPort()
                 << " state:online" << endl;
        }
        else {
            cout << conn->peerAddress().toIpPort() << " -> " << conn->localAddress().toIpPort()
                 << " state:offline" << endl;
            conn->shutdown(); // close(fd)
            // _loop->quit();
        }
    }

    /**
     * @brief 专门处理用户的读写事件
     *
     * @param conn 连接
     * @param buffer 缓冲区
     * @param time 接收到数据的时间信息
     */
    void onMessage(const TcpConnectionPtr& conn, Buffer* buffer, Timestamp time) {
        string buf = buffer->retrieveAllAsString();
        cout << "recv data:" << buf << " time:" << time.toFormattedString() << endl;
        conn->send(buf);
    }

    TcpServer  _server; // #1
    EventLoop* _loop;   // #2 epoll
};

int main() {
    EventLoop   loop; // epoll
    InetAddress addr("127.0.0.1", 6'000);
    ChatServer  server(&loop, addr, "ChatServer");

    server.start(); // listenfd epoll_ctl=>epoll
    loop.loop(); // epoll_wait以阻塞方式等待新用户连接，已连接用户的读写事件等
}