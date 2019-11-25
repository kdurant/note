#!/bin/bash

curl -fLo ~/.local/share/nvim/site/autoload/plug.vim --create-dirs \
    https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim

vim_config_folder='vimrc'

ssh_config_folder="/home/wj/.ssh"

if [ -d "$vim_config_folder" ]; then
    cd $vim_config_folder
    cp .config/init.vim ~/.config/nvim
    cp .config/nvim/basic_map.vim ~/.config/nvim
    cp .config/nvim/plugin_config.vim ~/.config/nvim
    cp .config/nvim/plugin_map.vim ~/.config/nvim
    cp .config/nvim/self_fun.vim ~/.config/nvim
    cp .config/nvim/user_plugin.vim ~/.config/nvim

    if [ ! -d "$ssh_config_folder" ]; then
        mkdir $ssh_config_folder
        cp .ssh/id_rsa $ssh_config_folder
        cp .ssh/id_rsa.pub $ssh_config_folder
    fi
else
    git clone https://github.com/kdurant/vimrc
fi

#git clone https://github.com/kdurant/bookmark

