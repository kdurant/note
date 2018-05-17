
# eclipse开启c99模式
* 在makefile中添加`-std=c99`

# nios FIFO写数据
调用api `altera_avalon_fifo_write_fifo()`写入0x1234abcd，FPGA接受到的数据时0xabcd1234，所以写入(读出)数据的时候要交换高低位

# nios中内联汇编

和AT&T语法一致
```c
asm("statement");
```