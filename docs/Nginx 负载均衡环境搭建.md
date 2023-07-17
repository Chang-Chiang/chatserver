# Nginx 编译安装

## 简介

单台服务器性能有限，通过服务器集群提高服务器所能满足的并发量。负载均衡器，通过预设的负载算法，指导客户端连接集群中的不同 服务器。在该项目中，使用 Nginx 作为负载均衡器。

## 下载

> [nginx: download](http://nginx.org/en/download.html)

## 配置编译 tcp 负载均衡模块：提示缺少依赖库

```bash
$ tar -axvf nginx-1.12.2.tar.gz
$ cd nginx-1.12.2
$ ./configure --with-stream
···
checking for PCRE library ... not found
checking for PCRE library in /usr/local/ ... not found
checking for PCRE library in /usr/include/pcre/ ... not found
checking for PCRE library in /usr/pkg/ ... not found
checking for PCRE library in /opt/local/ ... not found

./configure: error: the HTTP rewrite module requires the PCRE library.
You can either disable the module by using --without-http_rewrite_module
option, or install the PCRE library into the system, or build the PCRE library
statically from the source with nginx by using --with-pcre=<path> option.
```

## 安装依赖库

```bash
# 我的 wsl2 环境只缺少 PCRE 依赖库，应该是我之前安装 libevent 时安装了其他库
$ sudo apt-get install libpcre3 libpcre3-dev  # 安装 PCRE

# $ sudo apt-get install zlib1g zlib1g-dev  # zlib 库
# $ sudo apt-get install openssl libssl-dev  # 安装 OpenSSL
```

## 重新配置编译 tcp 负载均衡模块

```bash
nginx-1.12.2$ ./configure --with-stream
checking for OS
 + Linux 5.10.102.1-microsoft-standard-WSL2 x86_64
checking for C compiler ... found
 + using GNU C compiler
 + gcc version: 11.2.0 (Ubuntu 11.2.0-19ubuntu1) 
checking for gcc -pipe switch ... found
checking for -Wl,-E switch ... found
checking for gcc builtin atomic operations ... found
checking for C99 variadic macros ... found
checking for gcc variadic macros ... found
checking for gcc builtin 64 bit byteswap ... found
checking for unistd.h ... found
checking for inttypes.h ... found
checking for limits.h ... found
checking for sys/filio.h ... not found
checking for sys/param.h ... found
checking for sys/mount.h ... found
checking for sys/statvfs.h ... found
checking for crypt.h ... found
checking for Linux specific features
checking for epoll ... found
checking for EPOLLRDHUP ... found
checking for EPOLLEXCLUSIVE ... found
checking for O_PATH ... found
checking for sendfile() ... found
checking for sendfile64() ... found
checking for sys/prctl.h ... found
checking for prctl(PR_SET_DUMPABLE) ... found
checking for sched_setaffinity() ... found
checking for crypt_r() ... found
checking for sys/vfs.h ... found
checking for nobody group ... not found
checking for nogroup group ... found
checking for poll() ... found
checking for /dev/poll ... not found
checking for kqueue ... not found
checking for crypt() ... not found
checking for crypt() in libcrypt ... found
checking for F_READAHEAD ... not found
checking for posix_fadvise() ... found
checking for O_DIRECT ... found
checking for F_NOCACHE ... not found
checking for directio() ... not found
checking for statfs() ... found
checking for statvfs() ... found
checking for dlopen() ... found
checking for sched_yield() ... found
checking for SO_SETFIB ... not found
checking for SO_REUSEPORT ... found
checking for SO_ACCEPTFILTER ... not found
checking for SO_BINDANY ... not found
checking for IP_BIND_ADDRESS_NO_PORT ... found
checking for IP_TRANSPARENT ... found
checking for IP_BINDANY ... not found
checking for IP_RECVDSTADDR ... not found
checking for IP_PKTINFO ... found
checking for IPV6_RECVPKTINFO ... found
checking for TCP_DEFER_ACCEPT ... found
checking for TCP_KEEPIDLE ... found
checking for TCP_FASTOPEN ... found
checking for TCP_INFO ... found
checking for accept4() ... found
checking for eventfd() ... found
checking for int size ... 4 bytes
checking for long size ... 8 bytes
checking for long long size ... 8 bytes
checking for void * size ... 8 bytes
checking for uint32_t ... found
checking for uint64_t ... found
checking for sig_atomic_t ... found
checking for sig_atomic_t size ... 4 bytes
checking for socklen_t ... found
checking for in_addr_t ... found
checking for in_port_t ... found
checking for rlim_t ... found
checking for uintptr_t ... uintptr_t found
checking for system byte ordering ... little endian
checking for size_t size ... 8 bytes
checking for off_t size ... 8 bytes
checking for time_t size ... 8 bytes
checking for AF_INET6 ... found
checking for setproctitle() ... not found
checking for pread() ... found
checking for pwrite() ... found
checking for pwritev() ... found
checking for sys_nerr ... not found
checking for _sys_nerr ... not found
checking for maximum errno ... found
checking for localtime_r() ... found
checking for posix_memalign() ... found
checking for memalign() ... found
checking for mmap(MAP_ANON|MAP_SHARED) ... found
checking for mmap("/dev/zero", MAP_SHARED) ... found
checking for System V shared memory ... found
checking for POSIX semaphores ... found
checking for struct msghdr.msg_control ... found
checking for ioctl(FIONBIO) ... found
checking for struct tm.tm_gmtoff ... found
checking for struct dirent.d_namlen ... not found
checking for struct dirent.d_type ... found
checking for sysconf(_SC_NPROCESSORS_ONLN) ... found
checking for openat(), fstatat() ... found
checking for getaddrinfo() ... found
checking for PCRE library ... found
checking for PCRE JIT support ... found
checking for zlib library ... found
creating objs/Makefile

Configuration summary
  + using system PCRE library
  + OpenSSL library is not used
  + using system zlib library

  nginx path prefix: "/usr/local/nginx"
  nginx binary file: "/usr/local/nginx/sbin/nginx"
  nginx modules path: "/usr/local/nginx/modules"
  nginx configuration prefix: "/usr/local/nginx/conf"
  nginx configuration file: "/usr/local/nginx/conf/nginx.conf"
  nginx pid file: "/usr/local/nginx/logs/nginx.pid"
  nginx error log file: "/usr/local/nginx/logs/error.log"
  nginx http access log file: "/usr/local/nginx/logs/access.log"
  nginx http client request body temporary files: "client_body_temp"
  nginx http proxy temporary files: "proxy_temp"
  nginx http fastcgi temporary files: "fastcgi_temp"
  nginx http uwsgi temporary files: "uwsgi_temp"
  nginx http scgi temporary files: "scgi_temp"
```

## 编译安装

```bash
# root 用户执行
make && make install
```

## 启动

```bash
# root 用户启动 
/usr/local/nginx/sbin/nginx
```

## 查看是否运行

```bash
$ netstat -tanp
Active Internet connections (servers and established)
Proto Recv-Q Send-Q Local Address           Foreign Address         State       PID/Program name    
tcp        0      0 0.0.0.0:80              0.0.0.0:*               LISTEN      20151/nginx: master 
```

## 配置负载均衡

```bash
# nginx 默认安装路径 /usr/local/nginx/
# nginx 可执行文件 /usr/local/nginx/sbin/
# nginx 配置文件 /usr/local/nginx/conf/nginx.conf
# nginx -s reload 重新加载配置文件启动
# nginx -s stop 停止nginx服务

vi /usr/local/nginx/conf/nginx.conf

# nginx tcp koadbalance config
stream {
	upstream ChatServer {
		hash $remote_addr consistent;
		server 127.0.0.1:6000 weight=1 max_fails=3 fail_timeout=30s;
		server 127.0.0.1:6002 weight=1 max_fails=3 fail_timeout=30s;
	}
	
	server {
		proxy_connect_timeout 1s; 
		# proxy_timeout 3s; nginx 与 server 连接 3s 就断开
		listen 8000;
		proxy_pass ChatServer;
		tcp_nodelay on;
	}
}
```

## 平滑加载配置文件启动

```bash
/usr/local/nginx/sbin/nginx -s reload # 重新加载配置文件启动
```

## 参考

+ [Ubuntu22.04 编译安装nginx](https://www.cnblogs.com/ggborn-001/p/17021865.html)
