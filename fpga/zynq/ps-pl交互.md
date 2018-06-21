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

## MIO 
MIO属于PS部分，对PL部分不可见，不需要约束。
MIO有53个引脚可用

## EMIO
PL控制EMIO时和普通IO一致。
PS也控制控制EMIO

# FIFO方式

# BRAM方式

# DDR方式

# 中断方式

# DMA方式