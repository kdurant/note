# nios_cpu.qsys 配置信息
* clk : 100Mhz
* on-chip ram: 96KB
* system clock
* timestamp timer
* epcs flash

# 连线相关
## Nios CPU
* Nios II Process生成时，data_master和instruction_master都已经连接到了debug_mem_slave
* Nios II Process的debug_reset_request可以连到其他IP的reset端口上
* 数据主端口(data_master)与所有的外设IP核的Avalon Memory Mapped Slave连接
* 指令主端口(instruction_master)只连接存储器IP核的Avalon Memory Mapped Slave端口

## DDR2 SDRAM Controller with ALTMEMPHY
* refclk是输入时钟，由clk source直接给入
* soft_reset_n可以连接到 Nios II Process的debug_reset_request端口
* global_reset_n连到clk source的clk_reset端口
* reset_request_n可以连到其他IP的reset引脚
* sysclk作为其他IP的时钟输入


* clk IP核的时钟信号`clk`与其余的各个IP核的`clk`连接起来
* clk IP核的时钟信号`reset`与其余的各个IP核的`reset`连接起来

# 最小系统模板
```verilog
module nios
(
    input               clk,
    output wire  epcs_flash_dclk,
    output wire  epcs_flash_sce,
    output wire  epcs_flash_sdo,
    input  wire  epcs_flash_data0
);

wire            clk_100m;

pll     pllEx01 
(
    .inclk0              (    clk                 ),
    .c0                  (    clk_100m            ),
    .locked              (                        )
);

nios_cpu u0 (
    .clk_clk             (    clk_100m            ),
    .reset_reset_n       (    1'b1                ),

    .epcs_flash_dclk     (    epcs_flash_dclk     ),
    .epcs_flash_sce      (    epcs_flash_sce      ),
    .epcs_flash_sdo      (    epcs_flash_sdo      ),
    .epcs_flash_data0    (    epcs_flash_data0    )
);

endmodule

```

# NIOS工程设置
1. 减少代码编译后占用空间
    * 勾选`enable_reduced_device_drivers`
    * 勾选`enalbe_small_c_library`
    * 不勾选`enable_c_plus_plus`
    * 不勾选`enable_clean_exit`

# 定时器
## 间隔定时器(Interval Timer)
```c
// timer.h
#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "system.h"
#include "altera_avalon_timer_regs.h"
#include "alt_types.h"
#include "sys/alt_irq.h"

typedef struct __timer_flag
{
    unsigned char flag;
}TimerFlag;

extern TimerFlag time_flag;

void timer_init(void);

void sys_timer_interrupt(void *context);
void timestamp_timer_interrupt(void *context);

#endif

// timer.c
#include "../inc/timer.h"

TimerFlag time_flag;

void timer_init(void) //初始化中断
{
    //清除system timer中断标志寄存器
    IOWR_ALTERA_AVALON_TIMER_STATUS(SYS_CLOCK_BASE, 0x00);
    //设置system timer周期, time/period - 1, 1s/10ns -1 = 100000000-1
    IOWR_ALTERA_AVALON_TIMER_PERIODH(SYS_CLOCK_BASE, 100000000 >> 16);
    IOWR_ALTERA_AVALON_TIMER_PERIODL(SYS_CLOCK_BASE, 100000000);
    //允许system timer中断
    IOWR_ALTERA_AVALON_TIMER_CONTROL(SYS_CLOCK_BASE, 0x07);
    //注册system timer中断
    alt_ic_isr_register(
        SYS_CLOCK_IRQ_INTERRUPT_CONTROLLER_ID, 
        SYS_CLOCK_IRQ,
        sys_timer_interrupt,
        (void *)SYS_CLOCK_BASE,
        0x0
    );

    //清除timestamp timer中断标志寄存器
    IOWR_ALTERA_AVALON_TIMER_STATUS(TIMESTAMP_TIMER_BASE, 0x00);
    //设置timestamp timer周期
    IOWR_ALTERA_AVALON_TIMER_PERIODH(TIMESTAMP_TIMER_BASE, 100000000 >> 16);
    IOWR_ALTERA_AVALON_TIMER_PERIODL(TIMESTAMP_TIMER_BASE, 100000000);
    //允许timestamp timer中断
    IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMESTAMP_TIMER_BASE, 0x07);
    //注册timestamp timer中断
    alt_ic_isr_register(
        TIMESTAMP_TIMER_IRQ_INTERRUPT_CONTROLLER_ID, 
        TIMESTAMP_TIMER_IRQ,
        timestamp_timer_interrupt,
        (void *)TIMESTAMP_TIMER_BASE,
        0x0
        );
}


void sys_timer_interrupt(void *context)
{
    IOWR_ALTERA_AVALON_TIMER_STATUS(SYS_CLOCK_BASE, 0x00);
    time_flag.flag = 1;
}

void timestamp_timer_interrupt(void *context)
{
    IOWR_ALTERA_AVALON_TIMER_STATUS(TIMESTAMP_TIMER_BASE, 0x00);
    time_flag.flag = 2;
}
```




## 系统定时器
普通定时器作为系统定时器使用
```c
int alt_alarm_start (alt_alarm* alarm, alt_u32 nticks,
                     alt_u32 (*callback) (void* context),
                     void* context)
nticks 为执行回调函数（在这里理解为中断服务函数即可）的时间间隔(定时器模块的设置周期)


```c
alt_alarm_start(&alarm, 50, my_alarm_callback, NULL);


// return的值作为下一次nticks
alt_u32 my_alarm_callback(void *context)
{
    time_flag.flag = ~time_flag.flag;
    IOWR_ALTERA_AVALON_PIO_DATA(LED0_BASE, time_flag.flag);
    return 50;
    return alt_ticks_per_second();
}
```

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

