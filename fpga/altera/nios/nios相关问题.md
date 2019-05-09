# 创建nios工程
1. 创建bsp. `File -> New -> Nios II Board Support Package`
   第一次创建: nios2-bsp $BSP_TYPE $BSP_DIR $SOPC_DIR $NIOS2_BSP_ARGS
    - $BSP_TYPE, 一般为`hal`
    - $BSP_DIR, 生成bsp文件的目录
    - $SOPC_DIR, `sopcinfo`文件目录
    - $NIOS2_BSP_ARGS, `--cpu-name cpu`, cpu-name为qsys中cpu的名称
   
   > `nios2-bsp hal ./xxx_bsp ../nios_cpu.sopcinfo --cpu-name cpu` 
   > 在图形界面中有`Use relative path`选项, 会影响生成的Makefile中`SOPC_FILE`使用的路径方式

   更新bsp:
   `nios2-bsp-generate-files --bsp-dir . --settings settings.bsp`

   
2. 创建nios工程. 
    * `File -> New -> Nios II Application and BSP from Template`
    * `File -> New -> Nios II Application`

3. 用户头文件和源文件放在nios工程下

> 可以在一个BSP的基础上建立很多Application
> 根据同一个sopcinfo建立的BSP是相同的, 所以版本工具可以忽略此目录


# eclipse开启c99模式
* 在makefile中添加`-std=c99`

# 修改include路径
`Properties -> Nios II Application Path -> Application include directories`

# nios FIFO写数据
1. 调用api `altera_avalon_fifo_write_fifo()`写入0x1234abcd，FPGA接受到的数据时0xabcd1234，所以写入(读出)数据的时候要交换高低位
2. for循环写入数据时, 大概135个时钟周期写入一个数据(125Mhz)
3. for循环读出数据时, 大概135个时钟周期读出一个数据(`altera_avalon_fifo_read_fifo`)

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

* 需使用nios先启动一次仿真, 然后生成了hex文件后, 自己的仿真才能进行


# epcs使用
1. 勾选`enable_reduced_device_drivers`, 否则`alt_sys_init.c`里不会初始化epcs
2. 注意`epcs_read_device_id()`或者`epcs_read_electronic_signature()`返回的器件ID. 如果因为返回ID不匹配导致无法识别epcs, 手动修改相关部分代码
3. 1
```c
typedef struct flash_region {
        int offset; /* region相对FLASH首地址的偏移量 */
        int region_size;        /* region的大小, flash总的容量, 单位Byte*/
        int number_of_blocks;   /* 每个region中block的数量 */
        int block_size;/* block的大小*/
}flash_region;
```