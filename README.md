# chatserver
基于 muduo 网络库的集群聊天服务器

+ 使用 线程池 + epoll + Reactor + one thread per loop 方案的 muduo 库作为项目网络模块
+ 使用 json 序列化和反序列化消息作为私有通信协议
+ 使用 MySQL 关系型数据库作为项目数据的落地存储
+ 配置 Nginx 基于 TCP 的负载均衡，实现聊天服务器的集群功能，提高后端服务的并发能力
+ 基于 Redis 的发布-订阅功能，实现跨服务器的消息通信

![chatserver](./assets/chatserver.svg)

## 目录

+ [工程结构](#工程结构)
+ [环境依赖](#环境依赖)
+ [个人开发环境](#个人开发环境)
+ [下载运行](#下载运行)
+ [文档](#文档)
+ [参考](#参考)

## 工程结构

```angular
.
├── archive         # 项目开发过程归档
├── bin             # 可执行文件
├── build           # 编译中间文件 
├── docs            # 项目相关文档说明
├── include         # 项目头文件  
├── lib             # 项目库文件  
├── src             # 项目源文件
├── test            # 项目相关代码的测试文件 
├── thirdparty      # 项目使用的三方文件
├── CMakeLists.txt  # CMake
└── autobuild.sh    # 自动化编译脚本
```

## 环境依赖

+ Linux
+ CMake
+ JSON
+ 

## 个人开发环境

> 环境：Windows11, WSL2
>
> ```bash
> $ lsb_release -a
> No LSB modules are available.
> Distributor ID: Ubuntu
> Description:    Ubuntu 22.04 LTS
> Release:        22.04
> Codename:       jammy
> ```

## 下载运行

## 文档

+ [JSON 三方库测试](./docs/JSON 三方库测试.md)

+ [muduo 网络库安装与测试](./docs/muduo 网络库安装与测试.md)
+ [MySQL 数据库环境搭建](./docs/MySQL 数据库环境搭建)
+ [Nginx 负载均衡环境搭建](./docs/Nginx 负载均衡环境搭建)
+ [Redis 环境搭建](./docs/Redis 环境搭建)
+ [个人运行流程记录]()
+ [功能测试文档](./docs/功能测试文档)
+ [部署至 CentOS 7 服务器记录]()

## 参考

+ 
