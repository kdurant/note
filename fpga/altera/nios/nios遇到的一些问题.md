
# eclipse开启c99模式
* 在makefile中添加`-std=c99`

# nios FIFO写数据
1. 调用api `altera_avalon_fifo_write_fifo()`写入0x1234abcd，FPGA接受到的数据时0xabcd1234，所以写入(读出)数据的时候要交换高低位
2. for循环写入数据时, 大概135个时钟周期写入一个数据(125Mhz)

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
2. nios cpu中将reset vector选择为flash(将reset vector设置为ram后即可进行debug), 重新生成nios
3. quartus里将flash使用到的几个多功能引脚设置为普通IO, 并分配引脚
4. nios里选择`Flash Program`, 选择sof和elf进行下载
    - Nios II -> Flash Programer (打开新界面) 
    - File -> New, 选择sopc
    - 添加sof和elf文件进行固化

> 可以通过修改 BSP Editor -> Adanvce -> hal.linker的前两项来完成
> 使能前两项: 固化程序
> disable前两项: reset vector选择为flash时也可以进行程序调试
> 勾选`enable-alt-load_copy-rodata`
> 勾选`enable-alt-load_copy-exceptions`

# nios II在modelsim里的仿真
仿真nios所需要的全部文件都在simulation目录下

* 需要编译下列文件
    - simulation/nios_cpu.v
    - simulation/submodules/*.v
    - simulation/submodules/*.vo
    - simulation/submodules/*.sv

* 将simulation/submodules/下的hex, mif, dat文件copy到modelsim所在目录
```tcl
file copy -force ../simulation/submodules/nios_cpu_cpu_cpu_bht_ram.dat ./
file copy -force ../simulation/submodules/nios_cpu_cpu_cpu_bht_ram.hex ./
file copy -force ../simulation/submodules/nios_cpu_cpu_cpu_bht_ram.mif ./
```

* 将software/project_name/mem_init下的文件copy到modelsim所在目录
