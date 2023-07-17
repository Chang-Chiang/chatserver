# MySQL 数据库环境搭建

## 简介

MySQL 在该项目中主要用于：

| MySQL 中的表名 | 表功能说明                                       |
| :------------- | :----------------------------------------------- |
| user           | 存储用户注册登录信息：用户名、密码、登录状态     |
| friend         | 存储用户好友列表：用户 id、好友 id               |
| allgroup       | 存储群组信息：群名、群描述                       |
| groupuser      | 存储群成员信息：群 id、用户 id、用户在群中的角色 |
| offlinemessage | 存储离线消息：用户 id、用户离线期间收到的消息    |

## MySQL 环境安装与设置

### 安装 MySQL

```bash
$ sudo apt-get update
$ sudo apt install libmysqlclient-dev  # 安装开发包<mysql/mysql.h>
$ sudo apt-get install mysql-server    # 安装最新版 MySQL 服务器
```

### 查看 MySQL 默认登录用户名、密码

+ 默认登录用户名：`user     = debian-sys-maint`
+ 默认登录密码     ：`password = 8tMp4GgzNQ7DtCo7`

```bash
$ cd /etc/mysql
$ sudo vim debian.cnf
# Automatically generated for Debian scripts. DO NOT TOUCH!
[client]
host     = localhost
user     = debian-sys-maint
password = 8tMp4GgzNQ7DtCo7
socket   = /var/run/mysqld/mysqld.sock
[mysql_upgrade]
host     = localhost
user     = debian-sys-maint
password = 8tMp4GgzNQ7DtCo7
socket   = /var/run/mysqld/mysqld.sock
~                                                                       
~ 
```

### 查看 MySQL 服务启用状态、启动 MySQL 服务

```bash
$ sudo service mysql status  # 查看 mysql 状态
$ sudo service mysql start   # 启动 mysql
* Starting MySQL database server mysqld
```

或者使用 Linux 系统命令查看：

```bash
$ sudo netstat -tanp  # 查看 mysql 是否启动
tcp6       0      0 :::3306                 :::*                    LISTEN      1222/mysqld
```

### 修改 MySQL 的 root 用户密码

```bash
# 先用默认用户名和密码登录
$ mysql -u debian-sys-maint -p8tMp4GgzNQ7DtCo7

# mysql 5.7 
# 修改 MySQL 的 root 用户密码为 123456
mysql> update mysql.user set authentication_string=password('123456') where user='root' and host='localhost';

# mysql 8
# 修改 MySQL 的 root 用户密码为 123456
mysql> use mysql;
mysql> update user set authentication_string='123456' where user='root';
mysql> flush privileges;
mysql> ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'root';

# https://blog.51cto.com/u_15307418/6215167
# mysql 8
mysql> ALTER USER 'root'@'localhost' IDENTIFIED BY '123456';
Query OK, 0 rows affected (0.02 sec)
```

### MySQL 客户端登录

```bash
# 测试数据库连接
$ mysql -u root -p  # 连接数据库
mysql>
```

## 项目数据库表设计

### user 表：存储用户注册登录信息

| 字段名称 | 字段类型                  | 字段说明     | 约束                        |
| :------- | :------------------------ | :----------- | :-------------------------- |
| id       | INT                       | 用户 id      | PRIMARY KEY, AUTO_INCREMENT |
| name     | VARCHAR(50)               | 用户名       | NOT NULL, UNIQUE            |
| password | VARCHAR(50)               | 用户密码     | NOT NULL                    |
| state    | ENUM('online', 'offline') | 当前登录状态 | DEFAULT 'offline'           |

### friend 表：存储用户好友列表

| 字段名称 | 字段类型 | 字段说明 | 约束               |
| :------- | :------- | :------- | :----------------- |
| userid   | INT      | 用户 id  | NOT NULL、联合主键 |
| friendid | INT      | 好友 id  | NOT NULL、联合主键 |

### allgroup 表：存储群组信息

| 字段名称  | 字段类型     | 字段说明 | 约束                        |
| :-------- | :----------- | :------- | :-------------------------- |
| id        | INT          | 群 id    | PRIMARY KEY、AUTO_INCREMENT |
| groupname | VARCHAR(50)  | 群名     | NOT NULL, UNIQUE            |
| groupdesc | VARCHAR(200) | 群描述   | DEFAULT ''                  |

### groupuser 表：存储群成员信息

| 字段名称  | 字段类型                  | 字段说明   | 约束               |
| :-------- | :------------------------ | :--------- | :----------------- |
| groupid   | INT                       | 群 id      | NOT NULL、联合主键 |
| userid    | INT                       | 群成员 id  | NOT NULL、联合主键 |
| grouprole | ENUM('creator', 'normal') | 群成员角色 | DEFAULT ‘normal’   |

### offlinemessage 表：存储离线消息

| 字段名称 | 字段类型     | 字段说明                   | 约束     |
| :------- | :----------- | :------------------------- | :------- |
| userid   | INT          | 用户id                     | NOT NULL |
| message  | VARCHAR(500) | 离线消息（存储Json字符串） | NOT NULL |

## 项目数据库表创建

### 查看已存在数据库

```mysql
mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
5 rows in set (0.18 sec)
```

### 新建数据库

```mysql
mysql> create database chat;
Query OK, 1 row affected (0.00 sec)
```

### 切换数据库

```mysql
mysql> use chat;
Database changed
```

### 查看数据库中已存在的表

```mysql
mysql> show tables;
Empty set (0.00 sec)
```

### 新建表

+ user 表

    ```mysql
    CREATE TABLE `user` (
      `id` int(11) NOT NULL AUTO_INCREMENT,
      `name` varchar(50) DEFAULT NULL,
      `password` varchar(50) DEFAULT NULL,
      `state` enum('online','offline') CHARACTER SET latin1 DEFAULT 'offline',
      PRIMARY KEY (`id`),
      UNIQUE KEY `name` (`name`)
    ) ENGINE=InnoDB AUTO_INCREMENT=22 DEFAULT CHARSET=utf8;
    ```

+ friend 表

  ```mysql
  CREATE TABLE `friend` (
    `userid` int(11) NOT NULL,
    `friendid` int(11) NOT NULL,
    KEY `userid` (`userid`,`friendid`)
  ) ENGINE=InnoDB DEFAULT CHARSET=utf8;
  ```

+ allgroup 表

  ```mysql
  CREATE TABLE `allgroup` (
    `id` int(11) NOT NULL AUTO_INCREMENT,
    `groupname` varchar(50) CHARACTER SET latin1 NOT NULL,
    `groupdesc` varchar(200) CHARACTER SET latin1 DEFAULT '',
    PRIMARY KEY (`id`),
    UNIQUE KEY `groupname` (`groupname`)
  ) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
  ```

+ groupuser 表

  ```mysql
  CREATE TABLE `groupuser` (
    `groupid` int(11) NOT NULL,
    `userid` int(11) NOT NULL,
    `grouprole` enum('creator','normal') CHARACTER SET latin1 DEFAULT NULL,
    KEY `groupid` (`groupid`,`userid`)
  ) ENGINE=InnoDB DEFAULT CHARSET=utf8;
  ```

+ offlinemessage 表

  ```mysql
  CREATE TABLE `offlinemessage` (
    `userid` int(11) NOT NULL,
    `message` varchar(500) NOT NULL
  ) ENGINE=InnoDB DEFAULT CHARSET=latin1;
  ```

## 设置 MySQL 字符编码为 utf-8，支持中文操作

```mysql
# 查看MySQL默认的字符编码
mysql> show variables like "char%";
+--------------------------+----------------------------+
| Variable_name            | Value                      |
+--------------------------+----------------------------+
| character_set_client     | utf8mb4                    |
| character_set_connection | utf8mb4                    |
| character_set_database   | utf8mb4                    |
| character_set_filesystem | binary                     |
| character_set_results    | utf8mb4                    |
| character_set_server     | utf8mb4                    |
| character_set_system     | utf8mb3                    |
| character_sets_dir       | /usr/share/mysql/charsets/ |
+--------------------------+----------------------------+
8 rows in set (0.01 sec)

# 设置字符编码
mysql> set character_set_server=utf8;
Query OK, 0 rows affected (0.00 sec)

# 修改表的字符编码
mysql> alter table user default character set utf8;

# 修改属性的字符编码
mysql> alter table user modify column name varchar(50) character set utf8;
```
