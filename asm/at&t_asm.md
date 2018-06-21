# 寄存器
`eax`, `ebx`, `ecx`, `edx`, `esi`, `edi`, `ebp`, `esp`等都是X86 汇编语言中CPU上的通用寄存器的名称，是32位的寄存器。他们不仅可以作为通用寄存器使用，还都有特别之处。

# ESP(extended stack pointer)
寄存器的内容是一个指针（地址），该指针永远指向系统栈最上面的一个栈帧的栈顶（地址最小）

* 不要将ESP寄存器用作其他用途

# EBP(extender base pointer)
寄存器的内容是一个指针（地址），该指针永远指向系统栈最上面的一个栈帧的底部

## EIP 
存放下一个CPU指令存放的内存位置，当CPU执行完当前指令后，从EIP寄存器中读取下一条指令的内存地址，以便继续执行

* 不能使用MOV指令直接修改EIP寄存器的值，使其指向那种不同位置的能力

# 伪指令

## .align

## 

# 指令

## call
函数调用指令
1. 将下一条指令的地址即返回地址压入栈中（所以， esp地址会减小4或者8）
2. 修改指令指针`eip`以指向函数起始处

# 寻址方式
* `变址内存模式(indexed memory mode)`, 索引寻址方式
>> base_address(offset_address, index, size)
任意值为0，就可以忽略。 offset_address和index的值必须是`寄存器`

```asm
movl    $2,     %edi
movl    values(, %edi, 4), %eax
```
将values标签开始的第三个4字节的内存值加载到EAX寄存器中

* 间接寻址方式
从寄存器指定的地址加载值
>> move (%eax), %ebx

* 基址寻址方式
和间接寻址方式类似，不同之处在于它将一个常量值与寄存器中的地址相加
```asm
movl    %ebx,   %edi    ;将ebx的值加载到edi寄存器中
movl    %ebx,   (%edi)  ;将ebx的值传送edi寄存器中所包含的内存位置

movl    %ebx,   4(%edi)  ;将ebx的值传送edi寄存器内容所指向内存位置之后4个字节的内存位置
```

3. 