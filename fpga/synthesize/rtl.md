# 组合逻辑
## 普通组合逻辑电路
### 代码
```verilog
module test
(
    input   wire                a,
    input   wire                b,
    input   wire                c,
    input   wire                d,
    input   wire [03:00]        sel,

    output  wire                led
);

assign                      led = &sel[03:00] & a & b & c &d;
endmodule
```
### RTL视图
![1-1](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-1.png?raw=true)

### 总结
1.	没有括号改变优先级的逻辑操作，是延迟连很长的组合逻辑电路，会影响时序性能
2.	程序语句中最先面的输入，数据路径最长；最后面的输入，数据路径最短
3.	程序语句从左到右，每两个输入公用一个组合逻辑节点
4.	如果有大于等于4个输入进行逻辑操作，使用括号可以减少关键路径的节点
例如：
```verilog
assign                      led = &sel[03:00] & (a & b) & (c & d);
```
![1-2](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-2.png?raw=true)

## 组合逻辑环
1. 必须是组合逻辑
2. 必须是环路（等号左边的值出现在了等号右边）。
必须同时满足上面两个条件才可能出现组合逻辑环，在时序电路里永远不可能出现这种电路的
### 代码
```verilog
`timescale  1 ns/1 ps

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
![1-3](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-3.png?raw=true)

## if-else组合逻辑电路
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
        led <= a;
    else
        led <= b;
end
endmodule
```
#### RTL视图
1. `if`里的条件综合成简单逻辑电路
2. `if-else`语句必然综合出一个Mux
3. Mux的位宽和输入数据宽度一致
![1-4a](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-4a.png?raw=true)

### 条件不完备
#### 代码
```verilog
module test
(
    input   wire [03:00]        a,
    input   wire                e,

    output  reg  [03:00]        led
);

always @(*)
begin
    if(e)
        led <= a;
end
endmodule
```
#### RTL视图
![1-5a](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-5a.png?raw=true)

## if-elseif-else组合逻辑电路
### 条件完备
#### 代码
```verilog
`timescale  1 ns/1 ps

module test
(
    input   wire                clk,

    input   wire                a,
    input   wire                b,
    input   wire                c,
    input   wire                d,
    input   wire                e,
    input   wire [03:00]        sel,

    output  reg                 led
);

always @(*)
begin
    if(sel[0])
        led <= a;
    else if(sel[1])
        led <= b;
    else if(sel[2])
        led <= c;
    else if(sel[3])
        led <= d;
    else
        led <= e;
end
endmodule
```
#### RTL视图
1. 选择器的级数和`else( if)`的个数相等
![1-6](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-6.png?raw=true)

### 条件不完备
#### 代码
```verilog
module test
(
    input   wire                a,
    input   wire                b,
    input   wire                c,

    input   wire                t1,
    input   wire                t2,
    input   wire                t3,

    output  reg                 led
);

always @(*)
begin
    if(t1)
        led <= a;
    else if(t2)
        led <= b;
    else if(t3)
        led <= c;
end
endmodule
```
#### RTL视图
1. 选择器的级数和`else if`的个数相等
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

# 时序逻辑电路
根据设计风格要求，每个`always @ (posedge clk)`语句块只描述一个信号

## if-else
### 条件完备
#### 代码
#### RTL视图

### 条件不完备
#### 代码
#### RTL视图

## 多个独立if语句
### 代码
### RTL视图

## if-elseif-else
### 条件完备
#### 代码
#### RTL视图

### 条件不完备
#### 代码
#### RTL视图

## case
### 条件完备
#### 代码
#### RTL视图

### 条件不完备
#### 代码
#### RTL视图