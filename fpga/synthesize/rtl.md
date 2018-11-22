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

## 组合逻辑环
### 代码
### RTL视图

## if-else组合逻辑电路
### 代码
### RTL视图

## case组合逻辑电路
### 代码
### RTL视图

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