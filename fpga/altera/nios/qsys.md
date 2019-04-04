# nios_cpu.qsys 配置信息
* clk : 100Mhz
* on-chip ram: 96KB
* system clock
* timestamp timer
* epcs flash

# 连线原则
数据主端口(data_master)与所有的外设IP核连接，而指令主端口(instruction_master)只连接存储器IP核。

# PIO操作

## 1.利用给定的宏定义函数，函数原型如下：
```c
    IOWR_ALTERA_AVALON_PIO_DATA(base, data)
```
其中，base是要访问的IO口的基地址，data是所要写入的数据

## 2.当我们跳入到上述函数的定义时，可以发现其定义方式为

```c
#define IOWR_ALTERA_AVALON_PIO_DATA(base, data)       IOWR(base, 0, data)
```
      因此，我们可以直接调用函数IOWR(base, 0, data)来对PIO口赋值，参数的含义同上。
## 3.直接对寄存器赋值
根据PIO的寄存器映射，可以直接对PIO的寄存器进行赋值。假设PIO的基地址如下：
```c
#define LED_PIO_BASE 0x11000020
```
则可以定义如下结构体：
```c
typedef struct
{
    unsigned long int DATA;
    unsigned long int DIRECTION;
    unsigned long int INTERRUPT_MASK;
    unsigned long int EDGE_CAPTURE;
}PIO_STR;
```
同时，将LED_PIO的基地址映射到该结构体的首地址
```c
#ifdef _LED
#define LED ((PIO_STR *)LED_PIO_BASE)
#endif
```
这样，可以直接对上述结构体操作，以实现对PIO口的操作，如对IO写一个数据，可以如下方式操作:
```c
LED->DATA = 0XFF;
```
同时也可以对其的其他寄存器访问。

# 中断

```c
#include "sys/alt_irq.h"
void nIRQ_Initial(void)
{
    /*
    打开相关中断
    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(KEY_BASE, 1);
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEY_BASE, 1);
    */
    // register ISR function
    alt_ic_isr_register(
    		KEY_IRQ_INTERRUPT_CONTROLLER_ID,    // 中断控制器ID，从system.h复制
    		KEY_IRQ,     // 硬件中断号，从system.h复制
	        nPIO_ISR, // 中断服务子函数
            (void*)0,  // 指向与设备驱动实例相关的数据结构体
            0x0);     // flags，保留未用

      alt_ic_irq_enable(KEY_IRQ_INTERRUPT_CONTROLLER_ID, KEY_IRQ);
}

// ISR
void nPIO_ISR(void* nirq_isr_context)
{
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEY_BASE, 1);
    key = key ^1;
}
```