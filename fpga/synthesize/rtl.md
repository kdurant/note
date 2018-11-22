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
### 条件不完备
#### 代码
```verilog
module test
(
    input   wire                a,
    input   wire                e,

    output  reg                 led
);

always @(*)
begin
    if(e)
        led <= a;
end
endmodule
```
#### RTL视图
![1-4](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-4.png?raw=true)

### 条件完备
#### 代码
```verilog
module test
(
    input   wire                a,
    input   wire                b,
    input   wire                e,

    output  reg                 led
);

always @(*)
begin
    if(e)
        led <= a;
    else
        led <= b;
end
endmodule
```
#### RTL视图
![1-5](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-5.png?raw=true)

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
![1-7](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-7.png?raw=true)

## case组合逻辑电路
### 条件完备
条件有两种情况：
* 列出了所有可能的case
* 没有列出所有可能的case，但有default
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
    case ({t3, t2, t1})
        3'b001: led <= a;
        3'b010: led <= b;
        3'b100: led <= c;
        default:;
    endcase
end
endmodule
```
#### RTL视图
![1-8](https://github.com/kdurant/note/blob/master/fpga/synthesize/img/1-8.png?raw=true)

### 条件不完备
#### 代码
#### RTL视图

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