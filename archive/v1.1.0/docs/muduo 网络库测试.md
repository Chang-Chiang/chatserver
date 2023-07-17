# muduo 网络库

把网络 I/O 的代码、业务代码区分开

## 简介

muduo网络库给用户提供了两个主要的类

+ TcpServer ： 用于编写服务器程序的

+ TcpClient ： 用于编写客户端程序的

epoll + 线程池

好处：能够把网络I/O的代码和业务代码区分开

​            *用户的连接和断开    用户的可读写事件



## 基于muduo网络库开发服务器流程

1. 组合TcpServer对象

2. 创建 EventLoop 事件循环对象的指针

3. 明确 TcpServer 构造函数需要什么参数，输出 ChatServer 的构造函数

4. 在当前服务器类的构造函数当中，注册处理连接的回调函数和处理读写时间的回调函数

5. 设置合适的服务端线程数量，muduo 库会自己分配 I/O 线程和 worker 线程

## 示例 demo

### 编译

```bash
$ g++ -o server muduo_server.cpp -lmuduo_net -lmuduo_base -lpthread
# -l 依赖库的顺序
# muduo_base, muduo_net 依赖 pthread 库
# muduo_net 依赖 muduo_base 库
```

### 运行

+ server

  ```bash
  $ ./server
  20230419 13:22:07.736537Z 12453 INFO  TcpServer::newConnection [ChatServer] - new connection [ChatServer-127.0.0.1:6000#1] from 127.0.0.1:32950 - TcpServer.cc:80
  127.0.0.1:32950 -> 127.0.0.1:6000 state:online
  recv data:hello
   time:20230419 13:22:38.252278
  ```

+ client

  ```bash
  $ telnet 127.0.0.1 6000
  Trying 127.0.0.1...
  Connected to 127.0.0.1.
  Escape character is '^]'.  # ctrl + ] 退出 telnet
  hello
  hello
  ```

## 参考

