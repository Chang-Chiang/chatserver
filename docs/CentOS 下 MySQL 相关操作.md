# CentOS 上使用 MySQL

> [Centos下安装mysql 总结](https://www.shuzhiduo.com/A/VGzlMav7Jb/)

## 安装

## 重要目录

+ 数据库目录： `/var/lib/mysql/ `
+ 配置文件，mysql.server命令及配置文件：  `/usr/share/mysql`
+ 相关命令，mysqladmin mysqldump等命令：`/usr/bin`
+ 启动脚本：`/etc/rc.d/init.d/`

## 登录

```bash
$ mysql -uroot -p  # 刚安装 MYSQL, root 没有密码
mysql>

# 连接远程MySQL
# 远程主机的IP为：110.110.110.110, 用户名为 root, 密码为 abcd123
$ mysql -h110.110.110.110 -uroot -pabcd123 
mysql>

mysql> exit  # 退出MYSQL
```

## 修改登录密码

```bash
# 首次改密码
# 给 root 添加密码 ab12
$ mysqladmin -uroot -password ab12

# 再次改密码
mysqladmin -uroot -pab12 password djg345
```

## 增加用户

```bash
# root 登录
$ mysql -uroot -p

# grant select on 数据库.* to 用户名@登录主机 identified by \"密码\"
# 增加一个用户test1密码为abc，让他可以在任何主机上登录，并对所有数据库有查询、插入、修改、删除的权限
mysql> grant select,insert,update,delete on *.* to test1@\"%\" Identified by \"abc\";

# 增加一个用户test2密码为abc,让他只可以在localhost上登录，并可以对数据库mydb进行查询、插入、修改、删除的操作 （localhost指本地主机，即MySQL数据库所在的那台主机）
mysql> grant select,insert,update,delete on mydb.* to test2@localhost identified by \"abc\";

# 不想test2有密码，可以再打一个命令将密码消掉
# mysql> grant select,insert,update,delete on mydb .* to test2@localhost identified by \"\";　

# 新用户登录
# -h 后跟的是要登录主机的 ip 地址
$ mysql -u user_1 -p　-h 192.168.113.50
```

## 启动与停止

```bash
$ /etc/init.d/mysql start  # 启动　 
$ /etc/init.d/mysql stop  # 停止

$ /sbin/chkconfig -list  # 察看mysql是否在自动启动列表中　
$ /sbin/chkconfig　-add　mysql  # 把MySQL添加到你系统的启动服务组里面去
$ /sbin/chkconfig　-del　mysql  # 把MySQL从启动服务组里面删除
```

## 更改 MySQL目录

MySQL 默认的数据文件存储目录为 `/var/lib/mysql`

下面操作把目录移到 `/home/data`

```bash
$ cd /home 　　
$ mkdir data 　
$ mysqladmin -u root -p shutdown
$ mv /var/lib/mysql　/home/data/ 
$ cp /usr/share/mysql/my-medium.cnf　/etc/my.cnf 
$ vi　 my.cnf
# The MySQL server 　　　 [mysqld] 　　　
port　　　= 3306 　　　
#socket　 = /var/lib/mysql/mysql.sock  #（原内容, 用“#”注释此行）　　　
socket　 = /home/data/mysql/mysql.sock #（加上此行）　
$ vi　/etc/rc.d/init.d/mysql 　　
#datadir=/var/lib/mysql　  　#（注释此行）　　
datadir=/home/data/mysql　　 #（加上此行
$ /etc/rc.d/init.d/mysql　start 
```

## 输入密码也无法登录 MySQL

> [关于centos中安装mysql后使用密码无法登陆](https://blog.csdn.net/m0_58691386/article/details/125211423)

```bash
$ sudo vi /etc/my.cnf
[mysqld]
# 
# ···
skip-grant-tables
$ systemctl restart mysqld.service
$ mysql -uroot -p
mysql> use mysql
mysql> update user set authentication_string=password(‘123456’) where user=‘root’;
mysql> flush privileges;
$ sudo vi /etc/my.cnf
[mysqld]
# 
# ···
# skip-grant-tables
$ systemctl restart mysqld.service
```

## 密码太简单需要重置密码

> [ERROR 1820 (HY000): You must reset your password using ALTER USER statement](https://blog.csdn.net/weixin_46018506/article/details/121273337)

```bash
$ sudo vi /etc/my.cnf
#添加密码验证插件
plugin-load-add=validate_password.so

#服务器在启动时加载插件，并防止在服务器运行时删除插件
validate-password=FORCE_PLUS_PERMANENT

$ systemctl restart mysqld

# 修改validate_password_policy参数的值
# validate_password_length(密码长度)参数默认为8，我们修改为1
$ mysql -uroot -p

mysql> set global validate_password_policy=0;
Query OK, 0 rows affected (0.00 sec)

mysql> set global validate_password_length=1;
Query OK, 0 rows affected (0.00 sec)

mysql> alter user 'root'@'localhost' identified by '123456';
Query OK, 0 rows affected (0.00 sec)
```

