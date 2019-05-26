# 示例1
```c
int add (int a, int b)
{
    int c = a + 2;
    int d = b + 3;

    int sum = c + d;
    return sum;
}
int main(void)
{
    int r;
    int t = 5;
    r = add(1, 4);
    t = t + r;
    return 0;
}
```
# 函数内基本数据类型变量的声明

简单变量直接放到通用寄存器中
```arm
MOVS     r5,#0x05
```


# 函数参数为基本数据类型

在调用函数前将参数先放到寄存器后，再调用函数

在汇编中为
```arm
MOVS     r1,#0x04
MOVS     r0,#0x01
BL.W     add
```

# 函数返回值为基本数据类型
需要返回的值直接放到寄存器中