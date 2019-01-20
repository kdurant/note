# VMware Workstation安装
[官方链接](http://download3.vmware.com/software/wkst/file/VMware-workstation-full-15.0.2-10952284.exe)

VMware Workstation 15永久激活密钥：YZ718-4REEQ-08DHQ-JNYQC-ZQRD0

# 更换软件源
1. `sudo gedit /etc/apt/sources.list`
2. 2
```
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-security main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-security main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-proposed main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-proposed main restricted universe multiverse
```
3. 
```
sudo apt-get update
sudo apt-get upgrade
```

# git 配置
```
git config --global user.email "wangjun850725@163.com"
git config --global user.name "kdurant"
```
复制windows下id_rsa, id_rsa.pub文件内容