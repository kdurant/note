#!/bin/bash

sudo -i

# 更换源
echo "----------------更换软件源-------------------------"
# https://developer.aliyun.com/mirror
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
sudo apt install dos2unix
sudo apt install cmake
sudo apt install lsb-core lib32stdc++6
sudo apt install global
sudo apt install lua5.3
sudo apt install python3-pip
sudo apt install python-pip

if [ ! -d "$HOME/.pip" ]; then
    mkdir  $HOME/.pip; cd $HOME/.pip
    echo "[global] 
index-url = https://pypi.tuna.tsinghua.edu.cn/simple" > pip.config
fi

sudo pip install --upgrade pynvim
sudo pip3 install --upgrade pynvim
sudo pip3 install ipython

sudo apt install nodejs
sudo apt install npm
npm config set registry http://registry.npm.taobao.org/
sudo npm install -g yarn
yarn config set registry https://registry.npm.taobao.org -g
yarn config set sass_binary_site http://cdn.npm.taobao.org/dist/node-sass -g

sudo npm  i -g bash-language-server

# git配置
echo "----------------配置git，ssh-------------------------"
ssh_config_folder="$HOME/.ssh"
vim_config_folder="$HOME/vimrc"
if [ ! -d "$vim_config_folder" ]; then
    echo "--------------------download config file---------------------"
    git clone https://github.com/kdurant/vimrc $vim_config_folder
else
    cd $vim_config_folder
    echo "--------------------update config file-----------------------"
    git pull
    cd ..
fi
if [ ! -d $ssh_config_folder ]; then
    mkdir $ssh_config_folder
    cp .ssh/id_rsa $ssh_config_folder
    cp .ssh/id_rsa.pub $ssh_config_folder

    chmod 600 $ssh_config_folder/id_rsa
    chmod 600 $ssh_config_folder/id_rsa.pub
fi
git config --global user.email "wj@163.com"
git config --global user.name "wj"
git config --global alias.st "status"
git config --global alias.br "branch"
git config --global alias.lo "log --graph --pretty=oneline"
git config --global alias.co "commit -m"

echo "alias update_vim='/home/wj/.config/nvim/vi_config.sh'" >> ~/.bashrc

# 安装clang 
# sudo apt install clang 
# sudo apt install clang-tools
# sudo apt install clang-format

which clang | grep clang 
if [ $? -ne 0 ]; then
    echo "----------------安装clang-------------------------"
    if [ ! -d "$HOME/program" ]; then
        mkdir program; cd program
        wget http://releases.llvm.org/9.0.0/clang+llvm-9.0.0-x86_64-linux-gnu-ubuntu-18.04.tar.xz
        tar xvJf clang+llvm-9.0.0-x86_64-linux-gnu-ubuntu-18.04.tar.xz
    fi

    echo "export PATH=$PATH:$HOME/program/clang+llvm-9.0.0-x86_64-linux-gnu-ubuntu-18.04/bin" >> ~/.bashrc
    source ~/.bashrc
else
    echo "Has install clang"
fi


# 安装交叉编译器
if which arm-linux-gnueabihf-gcc; then
    echo "Has install linaro!"
else
    echo "----------------安装linaro交叉编译器-------------------------"
    wget https://releases.linaro.org/components/toolchain/binaries/latest-7/arm-linux-gnueabihf/gcc-linaro-7.4.1-2019.02-x86_64_arm-linux-gnueabihf.tar.xz
    tar xvJf gcc-linaro-7.4.1-2019.02-x86_64_arm-linux-gnueabihf.tar.xz
    echo "export PATH=$PATH:~/program/gcc-linaro-7.4.1-2019.02-x86_64_arm-linux-gnueabihf/bin" >> ~/.bashrc
    source ~/.bashrc
fi

