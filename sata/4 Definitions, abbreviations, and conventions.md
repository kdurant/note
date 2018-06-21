# 定义和缩写

## Active Port

## ATA(AT Attachment)
ATA定义了存储设备连接的物理，电气，传输和命令协议

## ATAPI (AT Attachment Packet Interface) device
一个实现Packet Command功能集的设备。

## BER (bit error rate)
单位间隔的倒数

## bitrate

## bit synchronization
接收器将内部接收器时钟同步到外部发送器并发送重定时串行数据的状态。

## burst
从接口上的空闲状态开始并结束的一个短的脉冲数据。 这些用于OOB信号。

## byte

## character
字符是Zxx.y表示法中的一个字节的表示

## character alignment
字符对齐是一种接收器操作，它将字符边界重置为在ALIGNp的K28.5控制字符中找到的逗号序列的字符边界，并建立输入串行数据流的Dword同步。

## character slipping
字符滑动是通过在ALIGNp的字符内添加或删除位时间来将接收器的时钟重新对准接收的位流的接收器动作

## ClickConnect
内部单通道互连的可选正锁存解决方案

## CLTF (Closed Loop Transfer Function)
对于反馈系统，CLTF是输出变量的幅度和相位与输入变量的幅度和相位之比，作为正弦激励的频率的函数。 这个术语用在本规范的参考时钟部分。

## code violation
代码违规

## comma character
逗号字符是一个控制字符，它在编码时包含逗号序列。 在串行ATA中，唯一使用的逗号字符是K28.5，只有ALIGNp包含逗号字符。 逗号序列是编码字符的前七位。

## comma sequence
逗号序列是编码流中的0011111或1100000的七位序列。
逗号序列是唯一的，因为它只出现在单个编码字符中，而且可能不出现在相邻编码字符的任何位中。
这个独特的属性允许逗号序列用于确定接收的数据流的对齐。

## command aborted
命令中止是命令完成，错误寄存器中的ABRT位设置为1，状态寄存器中的ERR位设置为1。

## command completion
命令完成描述命令请求的操作完成，适用于设备。 命令完成也适用于命令已终止且发生错误的情况，并且发生了以下操作：
1. 状态寄存器的相应位已被更新
2. BSY和DRQ位已清零
3. 断言INTRQ（如果nIEN为低电平有效），假设命令协议指定INTRQ置为有效
在串行ATA中，寄存器内容通过寄存器 - 设备 - 主机FIS传送到主机。

## command packet
在执行包含命令和命令参数的PACKET命令期间传送给设备的数据结构。

## concentrator
集中器是一个通用术语，用于描述具有多个串行ATA端口连接到串行ATA设备以及少量端口连接到主机的逻辑块。 在最简单的情况下，集中器可以是插入到连接到一些串行ATA设备（例如PCI串行ATA控制器卡）的主机的主机总线适配器（HBA）。 集中器也可以是内部或外部RAID控制器，例如光纤通道到串行ATA RAID控制器，或者可以是通过扇出方案扩展端口数量的一些元件，如端口倍增器。

## Control Block registers
控制块寄存器是用于设备控制和发布备用状态的接口寄存器。

## control character
控制字符是其中Z等于K的字符

## control port
端口倍增器有一个端口地址保留用于与端口倍增器本身的控制和状态通信。 控制端口地址Fh。

## 4.1.24 control variable
控制变量，Z，是确定代码集将被用来解释一个数据字节的标志。 控制变量的值为D（用于数据字符）或K（用于控制字符）。

## CRC (Cyclic Redundancy Check)

## 4.1.26 data character
数据字符是其中Z等于D的字符

## 4.1.27 data signal source
提供串行ATA数据信号的仪器。

## 4.1.28 device
设备是一个存储外设。 传统上，接口上的设备一直是硬盘驱动器，但是只要设备符合本规范和ATA标准，任何形式的存储设备都可以放置在该接口上。

## 4.1.29 device port
设备端口是连接到设备的端口倍增器或端口选择器上的端口。 端口倍增器最多可以有15个设备端口。 端口选择器有一个设备端口。

## DCB (DC block)
DC模块被定义为一个器件，可以将频率从10 MHz传递到至少12 GHz，同时对信号的幅度或相位影响最小。

## differential signal


##  DJ (deterministic jitter – peak to peak)

## DMA (direct memory access)

## Dword
Dword是32bit数据的有序集合。 最低位是位0，最高位是位31。

## Dword synchronization
接收者已经识别了逗号序列的状态，并且正在从逗号字符的零参考产生一个双字对齐数据流（四个连续字节）。

##  EMI (Electromagnetic Interference)

## encoded character

## 4.1.38 endpoint device
ATA或者ATAPI设备

## 4.1.39 elasticity buffer
弹性缓冲器是接收器中进行字符滑动和/或字符对齐的部分。

## 4.1.40 eSATA
系统到系统互连 - 外部桌面应用程序使用模型（5.2.6）

## 4.1.41 Fbaud
通过通道的标称数据速率，单位为GHz。

## FER (frame error rate)

## First-party DMA Data Phase

## First-party DMA access

## 4.1.45 FIS (Frame Information Structure)
帧的用户有效载荷不包括SOFP，CRC和EOFP分隔符。

## 4.1.46 frame
帧是主机和设备之间交换信息的不可分割的单位。 一个帧由SOFP，帧信息结构，在FIS的内容上计算的CRC，和EOFP组成。

## Gen1
指的是以1.5 Gbps的速度为特征的第一代信令

## Gen1i
1.5 Gbps的内部电气规格，电缆长度可达1米。

## Gen1m
短背板应用，外部桌面应用和数据中心应用中使用的电气规格，电缆长度可达两米，定义为1.5 Gbps。

## Gen1x
长背板应用和数据中心应用中使用的电气规格支持长达两米以上的电缆，定义为1.5 Gbps。

## Gen2
指第二代信号，速度为3.0 Gbps

## Gen2i
内部电气规格为3.0 Gbps，电缆长度可达1米。

## Gen2m
短背板应用，外部桌面应用和数据中心应用中使用的电气规格，电缆长度可达两米，定义为3.0 Gbps。

## Gen2x
长背板应用和数据中心应用中使用的电气规格，支持的电缆长度高达两米，定义为3.0 Gbps。

## Gen3
指速度为6.0 Gbps的第三代信令

## Gen3i
内部电气规格为6.0 Gbps，电缆长度可达1米。

## HBA (Host Bus Adapter)
HBA是连接到主机系统的扩展总线以提供设备连接的组件。 HBA通常也被称为控制卡或者仅仅是控制器。

## HBWS (High Bandwidth Scope)
示波器在测量路径中具有10 GHz或更高的模拟带宽

## Gen1/Gen2 Requirement
对于Gen1 / Gen2测量，应在测量路径中使用模拟带宽为10 GHz或更高的示波器。

## Gen3 Requirement
对于Gen3测量，应在测量路径中使用模拟带宽为12 GHz或更高的示波器。

## HFTP (High Frequency Test Pattern)
这种模式提供了串行ATA编码规则中允许的最大频率。 模式：1010101010 1010101010b =编码的D10.2。 该模式是重复的。

## hot plug
SATA设备连接到已经供电的主机系统。
SATA设备已经上电或在插入/连接时通电。
有关热插拔方案的详细信息，请参见第7.2.5.1节。

## host port
主机端口是用于将端口倍增器或端口选择器连接到主机的端口。 端口倍增器有一个主机端口。 端口选择器有两个主机端口。

## inactive port
非活动端口是当前未在端口选择器上选择的主机端口。

## interrupt pending
当器件协议要求器件通过置位INTRQ来通知主机一个事件时，中断挂起是存在于器件的内部状态，当nIEN被置为低电平有效。

## immediate NCQ command

## ISI (inter-symbol interference)

## JMD (jitter measuring device)

## JTF (Jitter Transfer Function)

## junk

## LBA (Logical Block Address)
用于引用逻辑扇区的值。

## LBP (Lone Bit Pattern)

## LED (Light Emitting Diode)

## legacy mode

## legal character

## LFSR (Linear Feedback Shift Register)

## LFTP (low frequency test pattern)

## LL (laboratory load)

## LSS (laboratory sourced signal or lab-sourced signal)

## MFTP (mid frequency test pattern)

## NCQ streaming command

## NCQ Non-streaming command

## 4.1.81 OOB (Out-of-Band signaling)
OOB信号是由D24.3字符组成的Dword和空闲时间或者ALIGNp原语的模式，用来初始化Serial ATA接口。OOB信号还用于从低功率状态中恢复并在测试模式期间用信号通知特定的动作

## OS-aware hot plug

## OS-aware hot removal

## Phy offline

## PIO (programmed input/output)

## port address

## PRD (Physical Region Descriptor)

## primitive

## protocol-based port selection

## quiescent power condition

## RJ (random jitter)

## sector

## SEMB (Serial ATA Enclosure Management Bridge)

## SEP (Storage Enclosure Processor)

## Shadow Register Block registers

## side-band port selection

## SMART

## SSC (spread spectrum clocking)

## surprise hot plug

## surprise hot removal

## SYNC Escape

## TDR (time domain reflectometer)

## TIA (timing interval analyzer)

## TJ (total jitter)

## UI (unit interval)

## unrecoverable error

## UUT (unit under test)

## VNA (vector network analyzer)

## warm plug

## word

## xSATA

## zero crossing

# Conventions

## Precedence

## Keywords

## expected

## 

## 

## 

## 

## 

## 

## 
## 

## 

## 

## 

## 

## 

## 

## 

