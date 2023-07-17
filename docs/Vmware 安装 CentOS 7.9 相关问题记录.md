# Vmware 安装 CentOS 7.9 使用记录

> 虚拟机
>
> + 用户名：cc
> + 密码：cc
> + root 密码：cc

## 安装后无法联网

> [解决CentOS7虚拟机连不上网络的办法](https://blog.csdn.net/ralopo/article/details/126115072)

主要是设置：网关、DNS、掩码

```bash
$ sudo vi etc/sysconfig/network-scripts/ifcfg-ens33
$ systemctl restart network  # 为什么每次开机都得?
```

![image-20230324235239383](./assets/image-20230324235239383.png)

![image-20230325002227026](./assets/image-20230325002227026.png)

```bash
TYPE="Ethernet"
PROXY_METHOD="none"
BROWSER_ONLY="no"
BOOTPROTO="dhcp"
DEFROUTE="yes"
IPV4_FAILURE_FATAL="no"
IPV6INIT="yes"   
IPV6_AUTOCONF="yes" 
IPV6_DEFROUTE="yes"
IPV6_FAILURE_FATAL="no"
IPV6_ADDR_GEN_MODE="stable-privacy"
NAME="ens33"
DEVICE="ens33"
ONBOOT="yes"
GATEWAY=117.17.23.254
DNS1=117.17.23.1
NETMASK=255.255.255.0
```



### 网关和子网掩码

![image-20230325002543797](./assets/image-20230325002543797.png)

### DNS

在 windows 上查看

```bash
ipconfig
```

![image-20230325002727323](./assets/image-20230325002727323.png)

## 设置与 windows 共享文件夹

> [无桌面的linux安装VMWare Tools配置教程](https://www.yii666.com/blog/153907.html)

![image-20230325143230374](./assets/image-20230325143230374.png)

+ 挂载

  > [Linux下挂载出现的错误](https://blog.csdn.net/Grit_ICPC/article/details/52837087)

  ```bash
  $ mount -t iso9660 /dev/cdrom /mnt
  ```

+ 拷贝 vmtools 至 linux

  ```bash
  $ cp /mnt/VMWareTools-10.0.10-4301679.tar.gz /home/cc/VMWareTools-10.0.10-4301679.tar.gz
  ```

+ 安装前需准备的依赖环境

  ```bash
  $ sudo yum groupinstall "Perl Support"
  ```
  
+ 解压缩执行安装

  > [Linux挂载共享文件夹（VMware挂载共享文件夹）（挂载hgfs共享文件）](https://blog.csdn.net/hcu5555/article/details/107182222)
  
  ```bash
  $ cd ~
  $ tar -zxf VMWareTools-10.0.10-4301679.tar.gz
  $ cd vmware-tools-distrib/
  $ ./vmware-install.pl
  
  # 还是没有共享文件夹
  $ vmware-hgfsclient
  GitHub
  $ sudo vmhgfs-fuse .host:/GitHub /mnt/hgfs -o subtype=vmhgfs-fuse,allow_other
  ```
