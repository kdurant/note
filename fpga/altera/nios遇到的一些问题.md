
# eclipse开启c99模式
* 在makefile中添加`-std=c99`

# nios FIFO写数据
调用api `altera_avalon_fifo_write_fifo()`写入0x1234abcd，FPGA接受到的数据时0xabcd1234，所以写入(读出)数据的时候要交换高低位

# nios中内联汇编

和AT&T语法一致
```c
asm("statement");
```

# 大小端
* 大端模式：是指数据的高字节保存在内存的低地址中，而数据的低字节保存在内存的高地址中
* 小端模式，是指数据的高字节保存在内存的高地址中，而数据的低字节保存在内存的低地址中

nios采用小端格式
```c
char buf[8] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 };
int *dat = (int *)buf;
// *dat = 0x04030201
```

# quartus编译
quartus编译nios核时只需要在工程里添加一个qsys文件即可

# nios程序固化
1. 在qsys中添加flash控制器
2. nios cpu中将reset vector选择为flash.(将reset vector设置为ram后即可进行debug)
3. quartus里将flash使用到的几个多功能引脚设置为普通IO, 并分配引脚
4. nios里选择`Flash Program`, 选择sof和elf进行下载
