#!/bin/bash

sudo -i

# 更换源
echo "----------------更换软件源-------------------------"
if [ ! -e "/etc/apt/source.list.bak" ]; then
    cp /etc/apt/source.list /etc/apt/source.list.bak
fi
echo "deb [by-hash=force] http://packages.deepin.com/deepin lion main contrib non-free
#deb-src http://packages.deepin.com/deepin lion main contrib non-free" > /etc/apt/source.list
apt update
apt upgrade

# 安装帮助手册
echo "----------------安装帮助手册-------------------------"
apt install manpages-de manpages-de-dev manpages-dev glibc-doc manpages-posix-dev manpages-posix manpages-zh

# 
echo "----------------python相关-------------------------"
sudo apt install cmake
sudo apt install lsb-core lib32stdc++6
sudo apt install global
sudo apt install lua5.3
sudo apt install python3-pip
pip3 install pynvim
pip3 install ipython

# 安装clang 
echo "----------------安装clang-------------------------"
which clang | grep clang 
if [ $? -ne 0 ]; then
    if [ ! -d "/home/wj/program" ]; then
        mkdir program; cd program
        wget http://releases.llvm.org/9.0.0/clang+llvm-9.0.0-x86_64-linux-gnu-ubuntu-18.04.tar.xz
        tar xvJf clang+llvm-9.0.0-x86_64-linux-gnu-ubuntu-18.04.tar.xz
    fi

    echo "export PATH=$PATH:~/program/clang+llvm-9.0.0-x86_64-linux-gnu-ubuntu-18.04/bin" >> ~/.bashrc
fi


# 安装交叉编译器
echo "----------------安装linaro交叉编译器-------------------------"
if which arm-linux-gnueabihf-gcc; then
    echo "Has install!"
else
    wget https://releases.linaro.org/components/toolchain/binaries/latest-7/arm-linux-gnueabihf/gcc-linaro-7.4.1-2019.02-x86_64_arm-linux-gnueabihf.tar.xz
    tar xvJf gcc-linaro-7.4.1-2019.02-x86_64_arm-linux-gnueabihf.tar.xz
    echo "export PATH=$PATH:~/program/gcc-linaro-7.4.1-2019.02-x86_64_arm-linux-gnueabihf/bin" >> ~/.bashrc
    source ~/.bashrc
fi
