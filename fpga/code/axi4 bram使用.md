信号                |  AXI4        | AXI4-Lite
--------------------|--------------|---------------
ACLK                | 支持         |            
ARESETn             | 支持         |                                          
AWID[3:0]           | 支持         |
AWADDR[31:0]        | 支持         |
AWLEN[3:0]          | 支持         | 不支持
AWSIZE[2:0]         | 支持         | 不支持
AWBURST[1:0]        | 支持         | 不支持
AWLOCK[1:0]         | 支持         | 不支持
AWCACHE[3:0]        | 支持         | 不支持
AWPROT[2:0]         | 支持         |
AWVALID             | 支持         |
AWREADY             | 支持         |
WID[3:0]            | 支持         | 不支持
WDATA[31:0]         | 支持         |
WSTRB[3:0]          | 支持         |
WLAST               | 支持         | 不支持
WVALID              | 支持         |
WREADY              | 支持         |
BID[3:0]            | 支持         | 不支持
BRESP[1:0]          | 支持         |
BVALID              | 支持         |
BREADY              | 支持         |
ARID[3:0]           | 支持         | 不支持
ARADDR[31:0]        | 支持         |
ARLEN[3:0]          | 支持         | 不支持
ARSIZE[2:0]         | 支持         | 不支持
ARBURST[1:0]        | 支持         | 不支持
ARLOCK[1:0]         | 支持         | 不支持
ARCACHE[3:0]        | 支持         | 不支持
ARPROT[2:0]         | 支持         |
ARVALID             | 支持         |
ARREADY             | 支持         |
RID[3:0]            | 支持         | 不支持
RDATA[31:0]         | 支持         |
RRESP[1:0]          | 支持         |
RLAST               | 支持         | 不支持
RVALID              | 支持         |
RREADY              | 支持         |

# AWLEN， ARLEN
每次burst传输的单位个数，
ARLEN[3:0] AWLEN[3:0]  |  传输单位个数
-----------------------|-------------
b0000                    | 1
b0001                    | 2
b0010                    | 3
b01011                   | 4
b0100                    | 5
b0101                    | 6
b0110                    | 7
b0111                    | 8
b1000                    | 9
b1001                    | 10
b1010                    | 11
b1011                    | 12
b1100                    | 13
b1101                    | 14
b1110                    | 15
b1111                    | 16

# AWSIZE, ARSIZE
每个节拍内传输的数据字节数，一般情况下 size = 数据宽度/8
AWSIZE[2:0] ARSIZE[2:0]  |  字节数
-----------------------|-------------
b000                    | 1
b001                    | 2
b010                    | 4
b011                    | 8
b100                    | 16
b101                    | 32
b110                    | 64
b111                    | 128

# 复位信号
低电平复位

# valid信号
1. `s_axi_awvalid`和`s_axi_wvalid`可以一起给出
2. `s_axi_bready`可以一直为高
3. 根据握手信号的依赖关系，slave的`s_axi_bvalid`肯定会在`s_axi_awvalid`和`s_axi_wvalid`有效后给出

# 关于地址（针对bram）
1. `s_axi_awaddr`指定的bram地址以byte为单位
2. 假定`s_axi_wdata`为32bit，那么每写一次数据，占用4个地址
3. `s_axi_awaddr`指定地址的时候需要为**4的整数倍**
> 地址为0，1，2，3的时候都会写入bram的地址0x00处
> 地址为4，5，6，7的时候都会写入bram的地址0x01处

4. 写地址时，无论是写单个单位数据还是burst写多个单位数据，`s_axi_awvalid`和`s_axi_awready`只需要一个有效clk
