# muduo 网络库

## 简介

muduo网络库给用户提供了两个主要的类：

+ TcpServer ： 用于编写服务器程序的

+ TcpClient ： 用于编写客户端程序的

实现：epoll + 线程池

好处：能够把网络I/O的代码（用户的连接和断开）和业务代码（用户的可读写事件）区分开

核心实现：[Chang-Chiang/muduo (github.com)](https://github.com/Chang-Chiang/muduo)

## muduo 网络库安装

### 安装包下载至本地

```bash
$ ls
boost_1_69_0.tar.gz  muduo-master.zip
```

### boost 库安装

```bash
$  tar -zxvf boost_1_69_0.tar.gz 
$ cd boost_1_69_0/
$ ./bootstrap.sh
$ ./b2
···
./boost/thread/pthread/thread_data.hpp:60:5: error: missing binary operator before token "("
   60 | #if PTHREAD_STACK_MIN > 0
···

# https://github.com/boostorg/thread/issues/364
# 在thread_data.hpp中加入
#undef PTHREAD_STACK_MIN
#define PTHREAD_STACK_MIN 16384

$ ./b2
The Boost C++ Libraries were successfully built!

The following directory should be added to compiler include paths:

    /home/chang/boost_1_69_0

The following directory should be added to linker library paths:

    /home/chang/boost_1_69_0/stage/lib
$ ./b2 install  # root 执行
```

### boost 库测试

```c++
// test_boost.cpp
// 示例 demo
#include <iostream>
#include <boost/bind.hpp>
#include <string>
using namespace std;

class Hello {
public:
	void say(string name) { 
        cout << name << " say: hello world!" << endl; 
    }
};

int main() {
	Hello h;
	auto func = boost::bind(&Hello::say, &h, "zhang san");
	func();
	return 0;
}
```

```bash
$ g++ -o test_boost test_boost.cpp
$ ./test_boost
zhang san say: hello world!
```

### muduo 库安装

```bash
$ unzip muduo-master.zip
$ cd muduo-master
$ vi CMakeLists.txt
# 注释该行
#  option(MUDUO_BUILD_EXAMPLES "Build Muduo examples" ON)
$ ./build.sh
[100%] Built target muduo_inspect
$ ./build.sh install

$ cd /home/chang/build/release-install-cpp11
$ ls
include  lib

$ cd include/
$ ls
muduo
$ sudo mv muduo/ /usr/include/

$ cd ../lib/
$ ls
libmuduo_base.a  libmuduo_http.a  libmuduo_inspect.a  libmuduo_net.a
$ sudo mv * /usr/local/lib/
```

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

+ [boost库源码编译安装](https://blog.csdn.net/QIANGWEIYUAN/article/details/88792874)
+ [Linux平台下muduo网络库源码编译安装](https://blog.csdn.net/QIANGWEIYUAN/article/details/89023980)
