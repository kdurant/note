本节介绍串行ATA的物理层。提供的信息包括两种-`信息`和`规范`。除非另有说明，否则这些信息应被视为规范性质，并作为必要条件列入本文件，以便正确允许一件设备连接到另一件设备。规范性信息是有意识地构建的，只能在兼容性要求的范围内约束和定义区域。 提供的信息和提供的信息仅用于帮助读者更好地理解规范部分，仅作为示例。 `确切的实现可能有所不同`。

# 7.1 Phy电气规格说明
以下术语是针对各种电气规范而开发的：
* Gen1i: 第1代电气规格：这是内部主机到设备应用的1.5 Gbps电气规格。
* Gen1m: 第1代Short Backplane板和外部布线应用的电气规格：
* Gen1x:
* Gen2i:
* Gen2m:
* Gen2x:
* Gen3i:

## 7.1.1服务列表
* 在指定的电平上传输1.5 Gbps，3.0 Gbps或6.0 Gbps差分NRZ串行数据流。
> NRZ : 不归零码(NRZ,Non-Return to Zero)，
* 在发射机上提供一个100欧姆的匹配终端（差分）。
* 序列化来自链路的10,20,40或其他宽度并行输入用于传输
* 接收1.5Gbps，3.0Gbps或6.0Gbps的差分NRZ串行数据流，其数据速率为±350 ppm，由标称数据速率+0 / -5000 ppm（根据SSC配置文件）。
* 在接收器上提供100欧姆的匹配终端（差分）。
* 从串行流中提取数据（以及可选的时钟）。
* 反序列化串流。
* 检测K28.5逗号字符并提供对齐10,20,40或其他宽度并行输出的位和字
* 提供指定的OOB信号检测和传输
* 使用OOB信号协议初始化Serial ATA接口，并且使用OOB序列执行预定义的速度协商功能
* 执行正确的上电序列和速度协商
* 为链接层提供设备状态
    - 设备存在
    - 设备不存在。
    - 设备存在但无法协商通信。
* 可选的支持电源管理模式
* 可选择执行发射机和接收机阻抗校准
* 处理由扩频发射机时钟引起的输入数据速率频率变化。
* 容纳请求进入远端重定时回送，以及其他BIST命令时激活FIS测试操作模式。

## 7.1.2 低级电子设备框图（资料性附录）
下面提供的框图作为本文件以下部分的参考

### 7.1.2.1 物理框图
![figure111](https://github.com/kdurant/note/blob/master/res/sata/ch07/Figure111.png?raw=true)
* 模拟前端：该模块由高速差分驱动器和接收器以及OOB信号电路组成。
* 控制模块：该模块是逻辑电路，用于控制PHY的
* 固定模式源：该模块提供支持电路，根据需要生成ALIGNp模式。
* 固定模式检测：这个模块提供了支持电路，以便正确处理ALIGNp原语。
* 数据提取模块：该模块提供了支持电路，将时钟和数据从高速输入流中分离出来。
* TX时钟：该信号是物理设备的内部信号，是一个参考信号，用于调节串行数据流通过高速信号路径发送的频率。
* TX+/TX-：
* RX+/RX-：
* DATAIN：从链路层发送到Phy层进行序列化和传输的数据。
* PHYRESET：该输入信号使Phy初始化为已知状态，并开始通过接口产生COMRESET OOB信号。
* PHYRDY：表示Phy的信号已成功建立通信。 Phy与接收器的输入信号保持同步，并在其发送器上发送有效信号。
* SLUMBER：使Phy层转换到“睡眠电源管理”状态。
* PARTIAL：导致物理层转换到部分电源管理状态
* NEARAFELB：使Phy将串行数据流从发送器回送到接收器
* FARAFELB：使Phy将来自接收器的串行数据流环回到其发送器
* SPDSEL：使控制逻辑自动协商可用的接口速度或设置特定的接口速度。 此输入的实际功能是供应商特定的，因制造商而异。
* SPDMODE：反映当前接口速度设置的输出信号。 该信号的实际功能是供应商特定的，因制造商而异。
* SYSTEMCLOCK：这个输入是大部分控制电路的时钟源，并且是建立发送接口速度的基础。
* COMMA：该信号表示在输入高速数据流中检测到K28.5字符。
* DATAOUT：由Phy接收和反序列化并传递给链路层
* RX CLOCK/Recovered clock:该信号来自高速输入数据信号，并确定何时在DATAOUT引脚处并行数据已正确形成，并可用于传输到外部电路。
* COMWAKE: OOB检测明COMWAKE信号

### 7.1.2.2 模拟前端（AFE）框图描述
![](https://github.com/kdurant/note/blob/master/res/sata/ch07/Figure112.png?raw=true)
* TX：
* RX：
* Termination calibration：
* Squelch
* OOB signal detector
* PLL：
* Voltage Regulator：
* TX+/TX-：
* RX+/RX-：
* TxData：
* RxData：
* COMWAKE：
* COMRESET/COMINIT
![](https://github.com/kdurant/note/blob/master/res/sata/ch07/Figure113.png?raw=true)

## 7.1.3 兼容性测试

## 7.1.4 连接性能

### 7.2.2.6 OOB详细规格信息

#### 7.2.2.6.1 OOB信号突发产生
OOB信号是由`低频`，`波形脉冲`， `空隙`组成的波形分组。这些数据在正常的数据流传输过程中不会出现，而是在数据传输开始之前的初始通知和校准期间用于传输低频识别信息。OOB信号由定义的空闲时间量和定义的突发时间量组成，该组合重复多次。在空闲时间，物理链路进行直流空闲。在突发时间期间，物理链路承载旨在用于包络检测装置的重复波形的低频信号转换。这些脉冲被转换成ON/OFF时间，作为低速通信的手段。OOB信号关闭时间由波形突发之间的空闲时间的长度决定。

OOB突发期间的信号模式是以GEN1速度发送的`D24.3字符（推荐）`或者`ALIGN原语（允许）`组成。 OOB突发只需要生成一个信封，以便由交流耦合检测电路检测。一个D24.3字符的突发，在Gen1速度相当于一个方波模式，是一个‘1’对两个UIoob周期，然后‘0’一个‘0’的两个UIoob周期，或简单地说，一个方波周期为2.66 ns。所有的数据速度发生器都应该使用GEN1 OOB突发速度，这对所有OOB检测电路都提出了一个单一的要求。

### 7.2.2.6.2 OOB信号检测阈值

### 7.2.2.6.3 UI During OOB Signaling
OOB突发传输期间的平均数据周期（Gen1 速度 +/-3%)

### 7.2.2.6.4 


# 7.5 接口状态

## 7.5.1 带外信号
Phy使用/检测三个带外信号：COMRESET，COMINIT和COMWAKE。OOB信号应通过发送4个Gen1 ALIGN基元的突发或由4个Gen1双字组成的突发来实现，每个双字由4个D24.3字符组成，每个突发的持续时间为160个UI。每个突发时间之后是空闲周期。持续时间如图180和表49所示
> preferred D24.3
> allowed ALIGN primitives

![180](https://github.com/kdurant/note/blob/master/res/sata/ch07/Figure180.png?raw=true)

以前版本的串行ATA只允许ALIGN序列作为合法的OOB信号内容。本节中定义的备用OOB序列在时域和频域都具有与ALIGN序列不同的特性。
The use of alternate OOB signal content may lead to backwards incompatibility with Gen1 Phys designed to previous Serial ATA specification versions. 

Interoperability issues with Gen1 Phys designed to the earlier SATA specification arising from the use of alternate OOB signal content are the sole responsibility of the Phy transmitting this alternate content.

在OOB信号传输期间，信号线的差分和共模电平应符合7.2节规定的与正常数据传输相同的电气规范。OOB信号通过检测差分对上的相邻活动突发之间的时间间隔来观察。接收机不需要gi检查OOB突发的持续时间。

即使它们以明显的Gen1定时进行传输，也可以使用Gen2上升/下降时间来传输OOB突发传输。

任何小于或大于表34中COMWAKE检测器关闭阈值的间隔都将使COMWAKE检测器输出无效。COMWAKE OOB信号用于使Phy从8.4.3.2节中描述的断电状态（部分或睡眠）中退出。至少在最后一次突发后，表34中的最大COMWAKE检测器关闭阈值，接口应保持不活动，以确保远端检测器正确检测到否定。该设备应保持接口不活动，不超过最大COMWAKE检测器关闭阈值加两个Gen1双字（约228.3纳秒）在COMWAKE结束，以防止串扰易感性。

### 7.5.1.1 空闲总线状态
在空闲总线条件下，差分信号在共模电平保持不变的情况下减小到零。

### 7.5.1.2 COMRESET
COMRESET始终来自主机控制器，并强制设备进行硬件复位。它通过总线空闲的情况下传输分开的突发数据来指示。

COMRESET信号由不少于6个数据的突发，包括内部的时间间隔

COMMRESET信号应该：
1. 只要系统处于复位状态，COMRESET需要一直持续
2. 在系统硬件复位期间启动，并在系统硬件复位否决后一段时间结束
3. 在系统硬件复位信号否定之后立即传输

主机控制器应忽略从接受硬件复位信号之前接收到的任何信号，直到发送COMRESET信号。

每个突发应为160个Gen1 UI单位（106.7 ns），每个突发间空闲状态为480个Gen1 UI单位（320 ns）。 COMRESET探测器寻找四个连续脉冲间隔320ns（标称）。
> 160个时钟周期（1s/1.5G = 0.667ps, 160*0.667ps = 106.7ns)。ALIGN原语的内容为`32'h7B4A4ABC`，经8B10B转换后有40bit。160个时钟周期，发送4个ALIGN原语
> 
> 空闲时间480个Gen1时钟周期
> 上面两步，重复5次？

任何小于175 ns或大于525 ns的间隔都将使COMRESET检测器输出无效。到PHY层的COMRESET接口信号将启动下面图所示的复位序列。
在最后一次突发之后，接口应保持非激活状态至少525 ns，以确保远端检测器正确检测到否定。

![183](https://github.com/kdurant/note/blob/master/res/sata/ch07/Figure183.png?raw=true)
描述：
1. 主机/设备通过某种形式的主动通信供电并正常运行
2. 主机中的一些条件导致主机发出COMRESET
3. 主机释放COMRESET。一旦有条件导致COMRESET被释放，主机释放COMRESET信号并使总线处于静止状态。
4. 设备发送COMINIT。当设备检测到COMRESET释放的时候，以COMINIT回应。当设备后启动的时候，这也是个入口点。设备可以在任何时候通过发送COMMIT，请求重新建立通信连接。
5. 主机校准并发出一个COMWAKE
6. 设备响应。设备检测RX引脚对上的COMWAKE序列并且校准收发器（可选）。在校准之后，设备发送一个六脉冲COMWAKE序列，然后以设备支持的最高速度发送一个连续的ALIGN序列流。在ALIGNp Dword被发送了54.6us（2048标称的Gen1双字时间）之后，如果没有从主机接收到的ALIGNp原语的检测来确定主机的响应，则设备假定主机不能以该速度通信。如果有更多的速度可用，设备将以这个速度发送ALIGNp双字，以54.6 us（2048标称Gen1双字时间）来尝试下一个较低的支持速度。
重复此步骤的速度与支持的速度相同。一旦达到最低速度而没有来自主机的响应，则设备进入错误状态。
7. 主机锁定 - 在检测到COMWAKE后，主机以最低的支持速度开始传输D10.2字符（见7.6）。同时，主机接收机锁定到ALIGN序列，准备就绪后，以接收的相同速度将ALIGN序列返回给设备。主机应设计成在任何给定的速度下获得54.6us（2048标称Gen1双字时间）的锁定。在检测到COMWAKE释放以接收第一个ALIGNp之后，主机应该允许至少873.8 us（32768标称Gen1双字时间）。这确保了与多代和同步设计的互操作性。如果在873.8 us之内没有收到ALIGNp（32768标称Gen1双字时间），主机将重新启动上电顺序 - 无限重复，直到被应用层告知停止。
8. 设备锁定 - 设备锁定于ALIGN序列，准备就绪后，发送SYNCp原语指示它已准备好开始正常操作。一旦收到三个背对背的非ALIGNp原语，通信链路就建立起来，并且可以开始正常的操作。
9. 一旦收到三个连续的非ALIGNp原语，通信链路就建立起来，并且可以开始正常的操作。

### 7.5.1.3 COMINIT
COMINIT始终来自设备并请求通信初始化。 它与COMRESET信号在电气上是相同的，除了它来源于设备并被发送到主机。 它被设备用来按照下图所示的顺序从主机请求重置。
![184](https://github.com/kdurant/note/blob/master/res/sata/ch07/Figure184.png?raw=true)
描述：
1. 主机/设备通过某种形式的主动通信供电并正常运行
2. 设备中的某些条件会导致设备发出COMINIT命令
3. 主机校准并发送COMWAKE
4. 设备响应 - 设备检测到RX对上的COMWAKE序列并校准其发送器（可选）。在校准之后，设备发送一个六脉冲COMWAKE序列，然后以设备支持的最高速度发送一个连续的ALIGN序列流。 在ALIGNp Dword被发送了54.6us（2048标称的Gen1双字时间）之后，如果没有从主机接收到的ALIGNp原语的检测来确定主机的响应，则设备假定主机不能以那个速度进行通信。如果有额外的速度可用，设备将以这个速度发送ALIGNp Dword达到54.6 us（2048标称Gen1双字时间），从而尝试下一个较低的支持速度。这一步重复所支持的较慢的速度。一旦达到最低速度而没有来自主机的响应，则设备进入错误状态
5. 主机锁定 - 在检测到COMWAKE后，主机以最低的支持速度开始发送D10.2个字符（见7.6节）。同时，主机接收机锁定到ALIGN序列，准备就绪后，以接收的相同速度将ALIGN序列返回给设备。主机应该设计成在任何给定速度下获得54.6us（2048标称Gen1双字时间）的锁定。在检测到COMWAKE释放以接收第一个ALIGNp之后，主机应该允许至少873.8 us（32768标称Gen1双字时间）。这确保了与多代和同步设计的互操作性。如果在873.8 us之内没有收到ALIGNp（32768标称Gen1双字时间），主机将重新启动上电顺序 - 无限重复，直到被应用层告知停止。

6.设备锁定 - 设备锁定到ALIGN序列，准备就绪时，发送SYNCP指示它已准备好开始正常操作。
7.一旦收到三个背对背的非ALIGNp原语，通信链路就建立起来，并且可以开始正常的操作。

### 7.5.1.4 COMWAKE
COMWAKE可能来自主机控制器或设备。 它通过发送由空闲总线条件分开的六个突发数据来发信号通知。OOB COMWAKE信令应包含`不少于6个数据突发`，包括突发间时间间隔。
每个突发应该是160个Gen1 UI长，每个突发间空闲状态应该是160个Gen1 UI长。

COMWAKE检波器以106.7 ns的间隔（标称值）寻找四个连续的脉冲串。

任何小于35 ns或大于175 ns的间距都应使COMWAKE检测器输出无效。

COMWAKE OOB信号用于使Phy离开掉电状态
（部分或睡眠），如8.1节所述。 在最后一次突发之后，接口应至少保持175ns的无效状态，以确保远端检测器正确检测到否定。

在COMWAKE结束时，器件应保持非激活状态不超过228.3 ns（175 ns +两个Gen1双字），以防止串扰。
### 7.5.1.5 设计实例（资料性）
> squelch(静噪): 当信号低于一定电平时使信号静音的电路。常用于只存在噪声时的信号静音。 
## 7.5.2 空闲总线状态

# 7.6 弹性缓冲管理
对于非跟踪实现，可能需要弹性缓冲电路来吸收主机和设备之间频率的轻微差异。与SSC兼容的设备与非SSC设备通话时，最大的频率差异产生。 平均频率差异刚刚超过0.25％，偏差高达0.5％。

编写Serial ATA规范是为了支持跟踪和非跟踪架构。 非跟踪体系结构应包含Phy层内的弹性缓冲区。

请注意，由于此弹性缓冲区被设计为具有有限长度，因此需要在Phy层协议级别有一个机制，允许该接收机缓冲区重置，而不会丢弃或添加任何位到数据流。在接收长时间连续的数据流时，这一点尤为重要。 该Phy层协议不仅支持过采样体系结构，而且还适应无限的帧大小（帧大小受CRC多项式的限制）

链路层应跟踪一个可复位的计数器，该计数器至多每1024个传输字符（256个Dword）翻转。 在前滚动点（全1）之前或之后，链路层将触发发出双连续的ALIGNp原语，这些原语将被包括在Dword计数中。

在通信建立之后，链路层之外的第一个和第二个字应该是双ALIGNp原语序列，最后是最多254个非ALIGNp双字。循环重复以另一个双连续的ALIGNp原语序列开始。链路可以发出多个双重ALIGNp原语序列，但是不应该发送一个不成对的ALIGNp原语（即ALIGNp原语总是成对发送），除了重新定时的环回。

**ALIGNp由以下四个字符组成**
 (rd+)     |    (rd-)   |              
 ----------|------------|--------------
1100000101 | 0011111010 |Align1 (K28.5)
0101010101 | 0101010101 |Align2 (D10.2)
0101010101 | 0101010101 |Align3 (D10.2)
1101100011 | 0010011100 |Align4 (D27.3)
> 很重要
