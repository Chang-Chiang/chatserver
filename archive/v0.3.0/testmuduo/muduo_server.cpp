/**
 * @file muduo_server.cpp
 * @author Chang Chiang (Chang_Chiang@outlook.com)
 * @brief 基于 muduo 网络库的聊天服务器程序
 *      + muduo 网络库主要给用户提供两个类:
 *          + TcpServer: 用于编写服务器程序
 *          + TcpClient: 用于编写客户端程序
 *      + 好处: 能够把 网络 I/O 代码 和 业务代码 区分开
 *          + 网络库用于监听和上报业务事务
 *          + 业务代码只需处理事务: 用户的连接、断开、用户的可读写事件
 * @version 0.1
 * @date 2023-04-19
 *
 * @copyright Copyright (c) 2023
 *
 */

// g++ -o muduo_server muduo_server.cpp -lmuduo_net -lmuduo_base -lpthread
/**
 * muduo 网络库给用户提供了两个主要的类
 * TcpServer : 用于编写服务器程序的
 * TcpClient : 用于编写客户端程序的
 *
 * epoll + 线程池
 * 好处：能够把网络 I/O 的代码和业务代码（用户的连接和断开、用户的可读写事件）区分开
 * 用户的连接和断开、用户的可读写事件：什么时候发生由网络库上报、如何监听事件的发生也是网络库内部实现
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

/**
 * @brief
 * 1. 组合 TcpServer 对象;
 * 2. 创建 EventLoop 事件循环对象的指针;
 * 3. 明确 TcpServer 构造函数需要什么参数, 输出 ChatServer 的构造函数
 * 4. 在当前服务器类的构造函数当中, 注册处理连接的回调函数和处理事件的回调函数
 * 5. 设置合适的服务器端的线程数量, muduo 库自己分配 I/O 线程和工作线程
 */
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
    InetAddress addr("127.0.0.1", 6000);
    ChatServer  server(&loop, addr, "ChatServer");

    server.start(); // listenfd epoll_ctl=>epoll
    loop.loop(); // epoll_wait以阻塞方式等待新用户连接，已连接用户的读写事件等
}