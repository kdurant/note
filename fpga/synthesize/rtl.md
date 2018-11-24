# 代码与电路结构
## 简单组合逻辑电路
> 组合逻辑电路是指在任何时刻，输出状态只决定于同一时刻各输入状态的组合，而与电路以前状态、其他时间的状态无关

* Altera RTL视图中电路符号说明
  Analyzing Designs with Quartus II Netlist Viewers -> Schematic View -> Schematic Symbols
 
* Xilinx RTL视图中电路符号说明
### 代码
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
### RTL视图
![1-1a](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-1a.png?raw=true)
![1-1b](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-1b.png?raw=true)

### 总结
1.	没有括号改变优先级的逻辑操作，是延迟连很长的组合逻辑电路，会影响时序性能
2.	程序语句中最先面的输入，数据路径最长；最后面的输入，数据路径最短
3.	程序语句从左到右，每两个输入公用一个组合逻辑节点
4.	如果有大于等于4个输入进行逻辑操作，使用括号可以减少关键路径的节点

## 组合逻辑环
1. 必须是组合逻辑
2. 必须是环路（等号左边的值出现在了等号右边）。
必须同时满足上面两个条件才可能出现组合逻辑环，在时序电路里永远不可能出现这种电路的
### 代码
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
### RTL视图
![1-3a](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-3a.png?raw=true)

![1-3b](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-3b.png?raw=true)

quartus编译后出现了如下提示，vivado没有发现类似提示
> Warning (10755): Verilog HDL warning at test.v(8): assignments to c create a combinational loop


## if-else组合逻辑电路
当条件不完备的时候，无论是`if`还是`case`语句，都会生成锁存器，在设计中应该尽量避免
### 条件完备
#### 代码
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
#### RTL视图
1. `if`里的条件 <font color=red size=5>对应</font> 简单逻辑电路
2. `if-else`语句 <font color=red size=5>对应</font> Mux
3. Mux的个数和输入数据宽度一致
![1-4a](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-4a.png?raw=true)

![1-4b](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-4b.png?raw=true)
### 条件不完备
#### 代码
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
#### RTL视图
![1-5a](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-5a.png?raw=true)
![1-5b](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-5b.png?raw=true)

## if-elseif-else组合逻辑电路
### 条件完备
#### 代码
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
#### RTL视图
1. 选择器的级数和`else( if)`的个数相等
2. 最早出现条件的路径延时最少
![1-6a](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-6a.png?raw=true)
![1-6b](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-6b.png?raw=true)

### 条件不完备
#### 代码
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
#### RTL视图
1. 选择器的级数和`else if`的个数相等
![1-7a](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-7a.png?raw=true)
![1-7b](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-7b.png?raw=true)

## case组合逻辑电路
### 条件完备
条件有两种情况：
1. 列出了所有可能的case
#### 代码
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
#### RTL视图
![1-8-1b](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-8-1b.png?raw=true)

2. 没有列出所有可能的case，但有default
#### 代码
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
#### RTL视图
![1-8-2b](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-8-2b.png?raw=true)

### 条件不完备
#### 代码
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
#### RTL视图
![1-9b](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-9b.png?raw=true)

1. 使用Mux的个数和选择数据的宽度有关
2. 条件会连接到每个Mux的选择端口
3. 数据会连接到每个Mux的数据端口(实际逻辑决定？)

## 时序逻辑电路
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

![2-1a](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/2-1a.png?raw=true)
![2-1b](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/2-1b.png?raw=true)

2. 对于条件完备的时序电路其RTL结构和组合电路相比，只是在输出端添加了一级寄存器

# 关键路径延迟优化方法
关键路径是指系统中两个寄存器之间组合逻辑延迟最大的路径，它有着决定系统Fmax的能力。所谓关键路径优化，就是要想办法减少组合逻辑的延迟。

# 资源重用方法