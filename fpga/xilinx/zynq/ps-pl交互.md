# 系统框图
![pic](https://images2015.cnblogs.com/blog/957523/201607/957523-20160719200456029-550513100.png)

# PL，PS接口
PS-PL之间的AXI 接口分为三种：
• 通用 AXI（General Purpose AXI） — 一条 32 位数据总线，适合 PL 和 PS 之间的中低速通信。接口是透传的不带缓冲。总共有四个通用接口：两个 PS 做主机，另两个 PL 做主机。
• 加速器一致性端口（Accelerator Coherency Port） — 在 PL 和 APU 内的 SCU之间的单个异步连接，总线宽度为 64 位。这个端口用来实现 APU cache 和 PL的单元之间的一致性。PL 是做主机的。
• 高性能端口（High Performance Ports） — 四个高性能 AXI 接口，带有 FIFO缓冲来提供 “ 批量 ” 读写操作，并支持 PL 和 PS 中的存储器单元的高速率通信。数据宽度是 32 或 64 位，在所有四个接口中 PL 都是做主机的。

即：
![](https://images2015.cnblogs.com/blog/957523/201607/957523-20160719195253497-1940159988.png)


# IO方式
* MIO
    - 只对PS部分可见，PL不可用
    - 分布在Bank0, Bank1
    - 引脚固定
    - 直接由PS操作
* EMIO
    - PS可用，但需要分配引脚。PL可用
    - 分布在Bank2，Bank3
    - 引脚由PL扩展，可直接由PS操作
* AXI_GPIO
    - PS通过M_AXI_GPIO接口控制PL非EMIO，使用时消耗管脚资源和逻辑资源

## PS控制EMIO

## PS控制AXI_GPIO

# AXI_GP接口
2个32位主设备接口和2个32位从设备接口

## PS通过AXI_GP_MASTER写FIFO， PL读
AXI-Stream FIFO

## PL通过AXI_GP_MASTER写FIFO， PS读

# AXI_HP接口
用于PL访问PS上的存储器（DDR，on-chip RAM）

## PL读写DDR

## PL读写on-chip RAM


# 中断方式

# DMA方式