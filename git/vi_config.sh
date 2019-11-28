#!/bin/bash

#curl -fLo ~/.local/share/nvim/site/autoload/plug.vim --create-dirs \
   # https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim

vim_config_folder='vimrc'

ssh_config_folder="/home/wj/.ssh"

if [ ! -d "$vim_config_folder" ]; then
        echo "--------------------download config file---------------------"
	git clone https://github.com/kdurant/vimrc
else
	cd $vim_config_folder
        echo "--------------------update config file-----------------------"
	git pull
	cd ..
fi

if [ ! -d "/home/wj/.config/nvim" ]; then
	mkdir -p /home/wj/.config/nvim
fi

cd $vim_config_folder
cp .config/nvim/init.vim ~/.config/nvim
cp .config/nvim/basic_map.vim ~/.config/nvim
cp .config/nvim/plugin_config.vim ~/.config/nvim
cp .config/nvim/plugin_map.vim ~/.config/nvim
cp .config/nvim/self_fun.vim ~/.config/nvim
cp .config/nvim/user_plugin.vim ~/.config/nvim
cp AppData/Local/nvim/coc-settings.json ~/.config/nvim
cp gtags.conf ~/.config/gtags.conf

if [ ! -d "$ssh_config_folder" ]; then
	mkdir $ssh_config_folder
	cp .ssh/id_rsa $ssh_config_folder
	cp .ssh/id_rsa.pub $ssh_config_folder
fi

#git clone https://github.com/kdurant/bookmark

