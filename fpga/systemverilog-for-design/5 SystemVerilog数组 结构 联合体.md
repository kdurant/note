SystemVerilog对Verilog添加了几个增强，用于表示大量数据。Verilog数组结构在数据表示方式和数组操作方面都得到了扩展。结构和联合类型已经添加到Verilog中，作为表示变量集合的一种方法。
本节介绍：
* 结构体
* 联合
* 结构体和联合的操作
* 未压缩数组
* 数组操作
* foreach循环
* 数组的系统函数
* $bit系统函数

# 5.1 结构体
设计的数据通常是有逻辑的信号组，例如总线协议的所有控制信号，或状态控制器中使用的所有信号。Verilog语言没有一种方便的机制来将公共信号收集到一个组中。相反，设计器必须使用特殊分组方法，例如命名约定，其中组中的每个信号以一组通用字符开始或结束。

> 结构体和C语言定义类似。
SystemVerilog添加了和C语言类似的结构体。结构是将多个相关信息组合在一起的一种方便的方式。使用struct关键字声明结构。结构成员可以是任何变量类型，包括用户定义的类型和任何常量类型.。一个结构声明示例是：
```verilog
struct {
    int a, b; // 32-bit variables
    opcode_t opcode; // user-defined type
    logic [23:0] address; // 24-bit variable
    bit error; // 1-bit 2-state var.
} Instruction_Word;
```
> C语言中的tag是不需要的
SystemVerilog中的结构声明语法非常类似于C语言。一个不同之处是C允许在struct关键字之后和开始大括号之前使用可选的“tag”。SystemVerilog不允许tag。
> 结构是变量和/或常量的集合。
结构是一个变量和/或常量在一个名称下的集合。可以使用结构的名称引用整个集合。结构中的每个成员都有一个名称，用于从结构中选择它。引用结构成员与在C中引用相同。
```verilog
<structure_name>.<variable_name>
```
> 结构体和数组不同的地方
结构不同于数组，因为数组是所有类型和大小相同的元素的集合，而结构是变量和/或常量的集合，可以是不同的类型和大小。另一个不同之处是，数组的元素被索引引用到数组中，而结构的成员则由成员名引用。

# 5.1.1 结构体声明
> 变量或者线网可以作为结构体成员
结构体是变量的集合，可以单独或作为一个整体访问。可以使用var关键字将结构作为一个整体声明为变量。还可以使用任何Verilog网络类型(如wire或tri)将结构定义为网络。当定义为net类型时，结构的所有成员都必须是4状态类型.
```verilog
var struct { // structure variable
    logic [31:0] a, b;
    logic [ 7:0] opcode;
    logic [23:0] address;
} Instruction_Word_var;
wire struct { // structure net
    logic [31:0] a, b;
    logic [ 7:0] opcode;
    logic [23:0] address;
} Instruction_Word_net
```
将结构体声明为`var`或者`wire`是可选的。如果没有指定，默认为`var`。
```verilog
struct { // structure variable
    logic [31:0] a, b;
    logic [ 7:0] opcode;
    logic [23:0] address;
} Instruction_Word_var;
```
注意，虽然结构作为一个整体可以被声明为一个线网类型，但是在结构中不能使用`wire`类型。`wire`可以组合在一起作为`interface`使用，这将在10章介绍。

** 类型化匿名结构**
> 结构体可以使用自定义类型

# 5.3 数组
## 5.3.1 未压缩数组
Verilog中数组的声明方式为

`<data_type> <vector_size> <array_name> <array_dimensions>`

例如
```verilog
reg [15:0] RAM [0:4095]; // memory array
```

verilog-1995只允许声明一维数组。一维数组通常被称为存储器，它的主要目的是建模诸如硬件存储器件的存储RAM和ROM。
verilog-1995还限制了数组支持的数据类型reg，interger和time。

Verilog-2001通过允许除事件类型之外的任何变量或者网络类型被声明为一个数组，并允许多维数组，
从而显着增强了Verilog-1995数组。 从Verilog-2001开始，可以在数组中使用`reg`类型和`wire`类型。

```verilog
// a 1-dimensional unpacked array of
// 1024 1-bit nets
wire n [0:1023];
// a 1-dimensional unpacked array of
// 256 8-bit variables
reg [7:0] LUT [0:255];
// a 1-dimensional unpacked array of
// 1024 real variables
real r [0:1023];
// a 3-dimensional unpacked array of
// 32-bit int variables
integer i [7:0][3:0][7:0];
```

Verilog将数组的访问限制为一次只有该数组的一个元素，或单个元素的位选择或部分选择。
任何读取或写入数组的多个元素都是错误。

```verilog
integer i [7:0][3:0][7:0];
integer j;
j = i[3][0][1]; // legal: selects 1 element
j = i[3][0]; // illegal: selects 8 elements
```
SystemVerilog将数组声明的Verilog样式称为未压缩数组。
使用未压缩的数组，阵列的每个元素可以独立于其他元素存储，但拥有一个通用的名称。
Verilog不会定义软件工具如何将元素存储在数组中。
例如，给定一个8位宽数组，模拟器或其他软件工具可能会以32位字存储每个8位元素。 图5-3说明了如何将以下声明存储在内存中。

```verilog
wire [7:0] table [3:0];
```

figure5-3

SystemVerilog扩张了未压缩数组的维度，以包括verilog `event`和SystemVerilog中的`logic, bit, byte, int, longint, shortreal, real`。
使用typedef定义的用户定义类型的未压缩数组也可以被声明，包括使用struct和enum的类型。

```verilog
bit [63:0] d_array [1:128]; // array of vectors
shortreal cosines [0:89]; // array of floats
typedef enum {Mo, Tu, We, Th, Fr, Sa, Su} Week;
Week Year [1:52]; // array of Week types
```

SystemVerilog还增加了Verilog引用整个未压缩数组，或者一个未压缩数组中多个元素段的能力。
slice是数组一个维度内的一个或多个连续编号的元素。
这些增强功能可以将整个数组的内容或特定维度复制到另一个数组中。

为了将多个元素直接复制到未压缩数组中，分配左侧的数组或数组切片的布局和元素类型必须与右侧的布局和元素类型完全匹配。
也就是说，元素类型和大小以及复制的维数必须相同。

以下示例是合法的。 即使数组的维数没有编号，每个数组的大小和布局是一样的。

```verilog
int a1 [7:0][1023:0]; // unpacked array
int a2 [1:8][1:1024]; // unpacked array
a2 = a1; // copy an entire array
a2[3] = a1[0]; // copy a slice of an array
```

C语言数组始终以地址0开始。因此，C中的数组声明只需要指定数组的大小。 例如：

```c
int array [20]; // a C array with addresses
// from 0 to 19
```

硬件地址不需要始终从0开始，因此verilog需要数组声明的时候指定起始地址和结束地址

```verilog
int array [64:83]; // a Verilog array with addresses from 64 to 83
```

SystemVerilog添加了类C的数组声明方式，允许使用维度大小来指定**未压缩数组**，而不是开始和结束地址。 数组声明：

```verilog
logic [31:0] data [1024];
// equivalent to the declaration:
logic [31:0] data [0:1023];
```

和C一样，未压缩数组元素编号从地址0开始，以地址大小-1结尾。

## 5.3.2 压缩数组

Verilog语言允许使用单位类型创建向量，例如reg和wire。 矢量范围在信号名称之前，而未压缩数组范围在信号名称之后。

SystemVerilog将向量声明称为压缩数组。 Verilog向量是一维压缩数组

```verilog
wire [3:0] select; // 4-bit "packed array"
reg [63:0] data; // 64-bit "packed array"
```

SystemVerilog添加了在压缩数组中声明多个维度的功能。

```verilog
logic [3:0][7:0] data; // 2-D packed array
```

SystemVerilog定义了如何存储压缩数组的元素。 整个数组必须存储为连续位，与向量相同。 打包数组的每个维度都是向量内的一个子字段。

在上面的压缩数组声明中，有一个4位8位子数组。 图5-4说明了无论软件编译器，操作系统或平台如何，上述二维数组将如何被存储。

figure5-4

压缩数组必须使用位类型（`logic, bit, reg`），其他压缩数组，压缩结构体和压缩联合体形成。 
压缩数组也可以由Verilog网络数据类型（`wire, uwire, wand, tri, triand, trior, tri0, tri1, trireg`）组成。

```verilog
typedef struct packed {
logic [ 7:0] crc;
logic [63:0] data;
} data_word;
data_word [7:0] darray; // 1-D packed array of packed structures
```

压缩数组可以作为整体引用、作为位或部分引用。 多维压缩数组也可以在slice中引用。 

```verilog
logic [3:0][7:0] data; // 2-D packed array
wire [31:0] out = data; // whole array
wire sign = data[3][7]; // bit-select
wire [3:0] nib = data [0][3:0]; // part-select
byte high_byte;
assign high_byte = data[3]; // 8-bit slice
logic [15:0] word;
assign word = data[1:0]; // 2 slices
```

因为压缩数组作为向量存储，所以可以在Verilog向量上执行的任何合法操作也可以在压缩数组上执行。 
这包括能够在压缩数组进行位选择和部分选择，连接操作，数学运算，关系运算，位运算和逻辑运算。

```verilog
logic [3:0][15:0] a, b, result; // packed arrays
...
result = (a << 1) + b;
```

Verilog向量和SystemVerilog压缩数组之间没有语义上的差异。
压缩数组使用标准Verilog向量规则进行操作和赋值语句。 当矢量大小不一致时，压缩数组将在左侧被截断或向左扩展，就像Verilog向量一样。

## 5.3.3 使用压缩数组和未压缩数组

