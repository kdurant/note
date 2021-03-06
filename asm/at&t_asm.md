# 寄存器
`eax`, `ebx`, `ecx`, `edx`, `esi`, `edi`, `ebp`, `esp`等都是X86 汇编语言中CPU上的通用寄存器的名称，是32位的寄存器(64bit机器上将e改为r,则表示64bit寄存器)。他们不仅可以作为通用寄存器使用，还都有特别之处。

# ESP(extended stack pointer)栈顶指针寄存器
寄存器的内容是一个指针（地址），该指针永远指向系统栈最上面的一个栈帧的栈顶（地址最小）

* 不要将ESP寄存器用作其他用途



# EBP(extender base pointer)
寄存器的内容是一个指针（地址），该指针永远指向系统栈最上面的一个栈帧的底部.
在函数调用过程中保持不变

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



# C函数调用参数保存顺序
普通调用，把前 6 个参数依次用 rdi、rsi、rdx、`rcx`、r8、r9保存
系统调用，把前 6 个参数依次用 rdi、rsi、rdx、`r10`、r8、r9保存


# 汇编系统调用

## 查询有什么系统调用可以使用
`/usr/include/asm/unistd.h`
`/usr/include/x86_64-linux-gnu/asm/unistd_x32.h`

## 系统调用参数在寄存器中的位置
每个输入值要被按照特定的顺序存放到寄存器中。
1. EBX（第一个参数）
2. ECX（第二个参数）
3. EDX（第三个参数）
4. ESI（第四个参数）
5. EDI（第五个参数）

## 返回值
返回值存放在`ebx`中，可以使用`echo $?`查看