SystemVerilog扩展了Verilog内建的变量类型，并且增强了指定文字值的能力。本章解释了这些增强功能并且提供正确使用的建议。一些小李子在上下文中说明这些增强。后续涨价包含了利用SystemVerilog的增强变量类型和文字值的其他示例。下一章介绍了变量类型，用户定义类型的另一个重要改进。

本章介绍的增强功能包括：
* 增强的文字值
* `define文本替换增强
* 时间值
* 新的变量类型
* 有符号和无符号类型
* 变量初始化
* 静态和自动变量
* 类型转换
* 常量

#3.1 增强的文字值赋值

## 用文字值填充矢量
在Verilog语言中，向量可以很容易的被填充为**0**，**x**，**z**。
```verilog
parameter   SIZE = 64; 
reg     [SIZE-1:0] data;
data = 0;   // fills all bits of data with zero
data = 'bz; // fills all bits of data with Z
data = 'bx; // fills all bits of data with X
```
上面例子中每个赋值都是可变的。如果SIZE参数被重新定义，例如128，赋值会自动扩展去填充新的数据。然后Verilog不提供一个方便的方法去给数据所有的bit填充1。为了给一个文字值所有位设置位1，SIZE必须被明确的指定，例如：
```verilog
data=64'hFFFFFFFFFFFFFFFF;
```
上面的例子是不可变的。如果常量SIZE被重定义为一个更大的值，例如128，文字值必须手动更改以反映新的数据大小。

为了进行所有可变的赋值，Verilog设计人员必须学习编码技巧，例如使用某种类型的操作来给所有元素赋值。接下来的两个列子说明如何使用补数运算符和二进制补码运算符来填充所有的矢量。
```verilog
data = ~0;  // one's complement operation
data = -1;  // two's complement operation
```

## 用于填充矢量的特殊字面值
SystemVerilog通过两种方式增强了文字值的赋值。首先，添加了一个更简单的语法，允许指定填充值，而不必指定二进制、八进制或十六进制的基。其次，填充值也可以是逻辑1。语法是指定要填充每个位的值，在其前面加上一个撇号(')，从而：
* `'0`填充左值的所有位为0
* `'1`填充左值的所有位为1
* `'z`或者 `'Z`填充左值的所有位为z
* `'x`或者 `'X`填充左值的所有位为x
使用SystemVerilog，任何宽度的矢量都可以用所有的1填充，而不用硬编码要分配的值的宽度或使用操作。
```SystemVerilog
data = '1; // fills all bits of data with 1
```

#3.2 `define 增强
SystemVerilog通过允许宏文本包含某些特殊字符扩展了Verilog'定义文本替换宏的能力。

##3.2.1 字符串中的宏参数替换

##3.2.2 从宏构造标识符名称

#3.3 SystemVerilog变量

##3.3.1 对象类型和数据类型

### Verilog硬件类型
Verilog语言具有以硬件为中心的变量类型和网络类型。 这些类型具有特殊的仿真和综合语义来表示芯片或系统中实际连接的行为。
* Verilog reg，integer和time变量有4个逻辑值：0，1，Z和X
* Verilog wire wor，wand和其他网络类型每位具有120个值（4态逻辑加多个强度级别）和特殊的有线逻辑分辨率功能。

### SystemVerilog硬件类型
Verilog没有清楚地区分`信号类型`和`信号可以存储或传输的值`。 在Verilog中，所有的网络和变量都使用4态值，所以不需要明确区分。 为了在变量和网络类型以及这些类型可以存储或传输的值中提供更大的灵活性，SystemVerilog标准定义设计中的信号具有`类型`和`数据类型`

> type(类型)定义data是网络还是变量

Type显示信号是线网还是变量。SystemVerilog使用所有的Verilog变量类型， 例如**reg**和**integer**，增加了一些变量类型，例如**byte**和**int**。SystemVerilog没有增加任何的线网类型。

> 'data type' 定义数据是2值还是4值
**Data Type**表示线网和变量的值系统，对于2状态数据类型为0或1，对于4状态数据类型为0,1，Z或X。SystemVerilog关键字**bit**定义对象是2状态数据类型。 SystemVerilog关键字**logic**定义对象是4状态数据类型。 在SystemVerilog-2005标准中，变量类型可以是2态或4态的数据类型，其中线网类型只能是4态数据类型。

##3.3.2 SystemVerilog 4值变量