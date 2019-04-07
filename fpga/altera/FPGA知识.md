# 配置模式
根据FPGA在配置电路中的角色, 其`配置数据`可以使用3种方式`载入到目标器件`中
1. FPGA主动方式(Active Serial)
   由目标FPGA来主动输出控制和同步信号(包括配置时钟)给Altera专用的串行配置芯片, 在配置芯片收到命令后, 就把配置数据发到FPGA, 完成配置过程.

   在该配置模式下, FPGA输出有效配置时钟信号DCLK, 它是由FPGA内部的振荡器产生的.
   > pof文件

2. 被动(Passive)模式.
    由系统中的其他设备发起并控制被指过程. 这些设备可以是Altera的配置芯片, 微处理器, CPLD等智能设备.
   * 被动串行PS(Passive Serial)
   * 快速被动并行(Fast Passive Paraller)
   * 被动并行同步(Passive Parallel Synchronous)
   * 被动并行异步(Passive Paraller A上ynchronous)
   * 被动串行异步(Passive Serial A上ynchronous)
3. JTAG模式

# 配置过程
复位->配置->初始化->用户模式

# 上电流程