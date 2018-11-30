# 1. 代码与电路结构
## 1.1. 简单组合逻辑电路
> 组合逻辑电路是指在任何时刻，输出状态只决定于同一时刻各输入状态的组合，而与电路以前状态、其他时间的状态无关

* Altera RTL视图中电路符号说明
  Analyzing Designs with Quartus II Netlist Viewers -> Schematic View -> Schematic Symbols
 
* Xilinx RTL视图中电路符号说明
### 1.1.1. 代码
```verilog
module test
(
    input   wire [03:00]       a,
    input   wire [03:00]       b,
    input   wire [03:00]       c,
    input   wire [03:00]       d,
    input   wire [03:00]       e,

    output  wire [03:00]       led
);

assign                      led = ~(a + b - c & d | e);
endmodule
```
### 1.1.2. RTL视图
![1-1a](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-1a.png?raw=true)
![1-1b](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-1b.png?raw=true)

### 1.1.3. 总结
1.	没有括号改变优先级的逻辑操作，是延迟连很长的组合逻辑电路，会影响时序性能
2.	程序语句中最先面的输入，数据路径最长；最后面的输入，数据路径最短
3.	程序语句从左到右，每两个输入公用一个组合逻辑节点
4.	如果有大于等于4个输入进行逻辑操作，使用括号可以减少关键路径的节点

## 1.2. 组合逻辑环
1. 必须是组合逻辑
2. 必须是环路（等号左边的值出现在了等号右边）。
必须同时满足上面两个条件才可能出现组合逻辑环，在时序电路里永远不可能出现这种电路的
### 1.2.1. 代码
```verilog
module test
(
    input   wire                a,
    input   wire                b,
    output  wire                c
);

assign                  c  = a & b & c;
endmodule
```
### 1.2.2. RTL视图
![1-3a](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-3a.png?raw=true)

![1-3b](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-3b.png?raw=true)

quartus编译后出现了如下提示，vivado没有发现类似提示
> Warning (10755): Verilog HDL warning at test.v(8): assignments to c create a combinational loop


## 1.3. if-else组合逻辑电路
当条件不完备的时候，无论是`if`还是`case`语句，都会生成锁存器，在设计中应该尽量避免
### 1.3.1. 条件完备
#### 1.3.1.1. 代码
```verilog
module test
(
    input   wire [03:00]        a,
    input   wire [03:00]        b,
    input   wire [03:00]        c,

    output  reg  [03:00]        led
);

always @(*)
begin
    if(c)
        led = a;
    else
        led = b;
end
endmodule
```
#### 1.3.1.2. RTL视图
1. `if`里的条件 <font color=red size=5>对应</font> 简单逻辑电路
2. `if-else`语句 <font color=red size=5>对应</font> Mux
3. Mux的个数和输入数据宽度一致
![1-4a](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-4a.png?raw=true)

![1-4b](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-4b.png?raw=true)
### 1.3.2. 条件不完备
#### 1.3.2.1. 代码
```verilog
module test
(
    input   wire [03:00]        a,
    input   wire [03:00]        e,

    output  reg  [03:00]        led
);

always @(*)
begin
    if(e)
        led = a;
end
endmodule
```
#### 1.3.2.2. RTL视图
![1-5a](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-5a.png?raw=true)
![1-5b](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-5b.png?raw=true)

## 1.4. if-elseif-else组合逻辑电路
### 1.4.1. 条件完备
#### 1.4.1.1. 代码
```verilog
module test
(
    input   wire [03:00]        a,
    input   wire [03:00]        b,
    input   wire [03:00]        c,
    input   wire [03:00]        d,
    input   wire [03:00]        e,
    input   wire [03:00]        sel,

    output  reg  [03:00]        led
);

always @(*)
begin
    if(sel[0])
        led = a;
    else if(sel[1])
        led = b;
    else if(sel[2])
        led = c;
    else if(sel[3])
        led = d;
    else
        led = e;
end
endmodule
```
#### 1.4.1.2. RTL视图
1. 选择器的级数和`else( if)`的个数相等
2. 最早出现条件的路径延时最少
![1-6a](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-6a.png?raw=true)
![1-6b](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-6b.png?raw=true)

### 1.4.2. 条件不完备
#### 1.4.2.1. 代码
```verilog
module test
(
    input   wire [03:00]        a,
    input   wire [03:00]        b,
    input   wire [03:00]        c,
    input   wire [03:00]        d,
    input   wire [03:00]        sel,

    output  reg  [03:00]        led
);

always @(*)
begin
    if(sel[0])
        led = a;
    else if(sel[1])
        led = b;
    else if(sel[2])
        led = c;
    else if(sel[3])
        led = d;
end
endmodule
```
#### 1.4.2.2. RTL视图
1. 选择器的级数和`else if`的个数相等
![1-7a](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-7a.png?raw=true)
![1-7b](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-7b.png?raw=true)

## 1.5. case组合逻辑电路
### 1.5.1. 条件完备
条件有两种情况：
1. 列出了所有可能的case
#### 1.5.1.1. 代码
```verilog
module test
(
    input   wire [02:00]        a,
    input   wire [02:00]        b,
    input   wire [02:00]        c,
    input   wire [02:00]        d,

    input   wire                t1,
    input   wire                t2,

    output  reg  [02:00]        led
);

always @(*)
begin
    case ({t2, t1})
        2'b00: led = a;
        2'b01: led = b;
        2'b10: led = c;
        2'b11: led = d;
    endcase
end
endmodule
```
#### 1.5.1.2. RTL视图
![1-8-1b](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-8-1b.png?raw=true)

2. 没有列出所有可能的case，但有default
#### 1.5.1.3. 代码
```verilog
module test
(
    input   wire [02:00]        a,
    input   wire [02:00]        b,
    input   wire [02:00]        c,
    input   wire [02:00]        d,

    input   wire                t1,
    input   wire                t2,
    input   wire                t3,

    output  reg  [02:00]        led
);

always @(*)
begin
    case ({t3, t2, t1})
        3'b001: led = a;
        3'b010: led = b;
        3'b100: led = c;
        default: led = d;
    endcase
end
endmodule
```
#### 1.5.1.4. RTL视图
![1-8-2b](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-8-2b.png?raw=true)

### 1.5.2. 条件不完备
#### 1.5.2.1. 代码
```verilog
module test
(
    input   wire [02:00]        a,
    input   wire [02:00]        b,
    input   wire [02:00]        c,

    input   wire                t1,
    input   wire                t2,
    input   wire                t3,

    output  reg  [02:00]        led
);

always @(*)
begin
    case ({t3, t2, t1})
        3'b001: led = a;
        3'b010: led = b;
        3'b100: led = c;
    endcase
end
endmodule
```
#### 1.5.2.2. RTL视图
![1-9b](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-9b.png?raw=true)

1. 使用Mux的个数和选择数据的宽度有关
2. 条件会连接到每个Mux的选择端口
3. 数据会连接到每个Mux的数据端口(实际逻辑决定？)

## 1.6. 时序逻辑电路
时序逻辑电路 = 组合逻辑电路 + 寄存器

1. 条件不完备的组合电路会产生锁存器，对应的时序电路RTL就是将锁存器换成寄存器，例如将下面代码及其RTL结构和`1.3.2`比较即可
```verilog
module test
(
    input   wire                clk,
    input   wire [03:00]        a,
    input   wire [03:00]        e,

    output  reg  [03:00]        led
);

always @(posedge clk)
begin
    if(e)
        led <= a;
end
endmodule
```

![1-10a](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-10a.png?raw=true)
![1-10b](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-10b.png?raw=true)

2. 对于条件完备的时序电路其RTL结构和组合电路相比，只是在输出端添加了一级寄存器

# 2. 阻塞赋值和非阻塞赋值在always块中的区别
## 2.1. 非阻塞赋值
### 2.1.1. 代码
```python
module test
(
    input   wire                clk,
    input   wire [03:00]        a,
    output  reg  [03:00]        data_r0,
    output  reg  [03:00]        data_r1,
    output  reg  [03:00]        z

);

always @ (posedge clk)
begin
    data_r0 <= a;
    data_r1 <= data_r0;
    z <= data_r1;
end
endmodule
```
### 2.1.2. RTL结构
![2-1a](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/2-1a.png?raw=true)
1. 典型的流水线结构
2. 异步信号同步

## 2.2. 阻塞赋值
### 2.2.1. 代码
```python
module test
(
    input   wire                clk,
    input   wire [03:00]        a,
    output  reg  [03:00]        data_r0,
    output  reg  [03:00]        data_r1,
    output  reg  [03:00]        z

);

always @ (posedge clk)
begin
    data_r0 = a;
    data_r1 = data_r0;
    z = data_r1;
end
endmodule
```

### 2.2.2. RTL结构
![2-2a](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/2-2a.png?raw=true)

1. 如果不将`data_r0, data_r1`放到端口上，则会被直接优化掉，RTL上只有一个4bit的寄存器

# 3. 关键路径延迟优化方法
关键路径是指系统中两个寄存器之间组合逻辑延迟最大的路径，它有着决定系统Fmax的能力。所谓关键路径优化，就是要想办法减少组合逻辑的延迟。

## 3.1. 树结构

# 4. 资源共享

## 4.1. 共享加法器

### 4.1.1. 没共享时
#### 4.1.1.1. 代码
```python
module test
(
    input   wire [03:00]        a1,
    input   wire [03:00]        b1,
    input   wire [03:00]        c1,
    input   wire [03:00]        d1,
    input   wire                cond1,
    output  reg  [04:00]        z1,

    input   wire [03:00]        a2,
    input   wire [03:00]        b2,
    input   wire [03:00]        c2,
    input   wire [03:00]        d2,
    input   wire                cond2,
    output  reg  [04:00]        z2
);

always @(*)
begin
    if(cond1)
        z1 = a1 + b1;
    else
        z1 = c1 + d1;
end

always @(*)
begin
    if(cond2)
        z2 = a2 + b2;
    else
        z2 = c2 + d2;
end
endmodule
```
### 4.1.2. RTL视图
![4-1a](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/4-1a.png?raw=true)

### 4.1.3. 使用资源
![4-2a](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/4-2a.png?raw=true)

# 5. 简单电路在在always语句块中阻塞赋值、非阻塞赋值的研究

## always @ (posedge clk)语句块
遵循一个always语句块只对一个变量进行控制原则的话，赋值方式对综合出的RTL结构好像没有影响
### 5.1. always @ (posedge clk) 中使用非阻塞赋值
常用方式之一，生成时序逻辑电路
1. 代码
```python
module test
(
    input   wire [03:00]        a,
    input   wire [03:00]        b,
    input   wire [03:00]        c,
    input   wire [03:00]        d,
    input   wire                cond,
    output  reg  [04:00]        z
);

always @(posedge clk)
begin
    if(cond)
        z <= a + b;
    else
        z <= c + d;
end
endmodule
```
2. RTL结构
![5-1a](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/5-1a.png?raw=true)

### 5.2. always @ (posedge clk) 中使用阻塞赋值
1. 代码
```python
module test
(
    input   wire                clk,
    input   wire [03:00]        a,
    input   wire [03:00]        b,
    input   wire [03:00]        c,
    input   wire [03:00]        d,
    input   wire                cond,
    output  reg  [04:00]        z
);

always @(posedge clk)
begin
    if(cond)
        z = a + b;
    else
        z = c + d;
end
endmodule
```
2. RTL结构
和上面情况一致

### 5.3. always @ (posedge clk) 中使用混用赋值
1. 代码
```python
module test
(
    input   wire                clk,
    input   wire [03:00]        a,
    input   wire [03:00]        b,
    input   wire [03:00]        c,
    input   wire [03:00]        d,
    input   wire                cond,
    output  reg  [04:00]        z
);

always @(posedge clk)
begin
    if(cond)
        z <= a + b;
    else
        z = c + d;
end
endmodule
```
2. RTL结构
和上面情况一致

## always @ (*)语句块
### 5.4. always @ (*) 中使用非阻塞赋值
1. 代码
```python
```
2. RTL结构

### 5.5. always @ (*) 中使用阻塞赋值
1. 代码
```python
```
2. RTL结构
### 5.6. always @ (*) 中使用混用赋值
1. 代码
```python
```
2. RTL结构


# 三段式状态的RTL结构
三段式状态机有逻辑清晰的三段组成，分别为
* 组合逻辑描述的状态跳转
* 时序逻辑描述的状态转移
* 时序逻辑描述的状态输出

## 代码
```verilog
module test
(
    input   wire                clk,
    input   wire                rst_n,
    input   wire                a,
    input   wire                b,

    input   wire [03:00]        x,
    input   wire [03:00]        y,
    output  reg  [03:00]        z
);


localparam              IDLE    = 0;
localparam              OVER    = 1;
(* KEEP = "TRUE" *)reg     [OVER:00]       cs = 'd1, ns = 'd1;
reg     [15:00]         state_cnt;

// synthesis translate_off
reg [127:0] cs_STRING;
always @(*)
begin
    case(1'b1)
        cs[IDLE]: cs_STRING = "IDLE";
        cs[OVER]: cs_STRING = "OVER";
        default: cs_STRING = "XXXX";
    endcase
end
// synthesis translate_on

always @(posedge clk or negedge rst_n)
begin
    if(~rst_n)
        cs <= 'd1;
    else
        cs <= ns;
end

always @(*)
begin
    ns = 'd0;
    case(1'b1)
        cs[IDLE]:
        begin
            if(a)
                ns[OVER] = 1'b1;
            else
                ns[IDLE] = 1'b1;
        end
        cs[OVER]:
        begin
            if(b)
                ns[IDLE] = 1'b1;
            else
                ns[OVER] = 1'b1;
        end
        default:
            ns[IDLE] = 1'b1;
    endcase
end

always @(posedge clk or negedge rst_n)
begin
    if(~rst_n)
        z <= 0;
    else if(cs[IDLE])
        z <= x;
    else if(cs[OVER])
        z <= y;
    else
        z <= 0;
end

//always @(posedge clk or negedge rst_n)
//begin
    //if(~rst_n)
        //state_cnt <= 0;
    //else if (cs != ns)
        //state_cnt <= 0;
    //else
        //state_cnt <= state_cnt + 1'b1;
//end
endmodule
```

## RTL结构
* ns没有体现在RTL视图里
* 每个状态转移的条件都会综合出一个1bit的Mux, 然后作为cs对应寄存器的输入
* 时序逻辑的输出RTL结构由第三段状态决定

![6-1b](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/6-1b.png?raw=true)
* 粉红色部分为时序输出部分RTL结构。
* 橙色部分为状态转移
* 余下的组合逻辑为状态跳转