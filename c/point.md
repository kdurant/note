# 二维数组

## 定义
```c
char zippo[3][20] = {
    "abcdef",
    "nimenhao",
    "hello world"
};
```
`[]`的结合方向为从左到右，zippo[3]说明这是一个数组
zippo[3][20]说明数组里的每个元素是20个char长度的数组
想使用指针自增输出每个字符串
> zippo 是二维数组首地址
## 数组空间
二维数组占用的空间为：row\*column\* sizeof(char)

## 二维数组的遍历
```c
for (int i = 0; i < 3; i++)
{
    printf("%s\n", zippo[i]);
}
```

## 二维数组作为函数参数
```c
char (*p)[20] = zippo;  //
void show_array(char (*p)[20], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%s\n", p[i]);
    }
}
```
> * 和 p 构成一个指针的定义，指针名是 p， char 修饰的是数组的内容
> 即数组里的每个元素。数组在这里并没有名字，是个匿名数组

# 指针数组

## 定义
```c
char *str[3] = {
    "aaaaaa", 
    "cccccc", 
    "ddddddddd"
};
```
`[]`的优先级大于`*`，str先与`[]`结合，说明这是一个数组，数组里的元素是`char *`的指针

## 指针数据的遍历
```c
for (int i = 0; i < 3; i++)
{
    printf("%s\n", str[i]);
}
```
## 指针数组作为函数参数
```c
void show_array(char **p, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%s\n", p[i]);
    }
}
```

# void指针

## 基本概念
void的意思就是“无类型”，void指针则为“无类型指针”，void指针可以指向任何类型的数据。
所以void指针一般被称为通用指针或者泛指针,或者叫做万能指针

## 定义形式
```c
void *p;
```

## 可以将任意类型的指针传递给 void *
```c
void test(void *data, size_t n)
{
    memset(data, 0x00, n);
}
```
可以将任何类型的指针传递给test函数而不需要cast。


# 空指针
在C语言中，如果一个指针不指向任何数据，我们就称之为空指针，用NULL表示。例如：
```c
int *p = NULL;
```
> NULL 是一个宏定义，在stdio.h被定义为：
> #define NULL ((void *)0)


# 函数指针
## 定义
```c
// 方法 1， p_func可以指向 void function_name(int, int, float)类型的函数
void (*p_func)(int, int, float)


/* 方法2 */
typedef void (*tp_func)(int, int, float);       //只是定义了函数指针类型
tp_func p_func = NULL;
```

# 回调函数
回调函数就是一个通过函数指针调用的函数。如果你把`函数的指针（地址）作为参数`传递给另一个函数，当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。回调函数不是由该函数的实现方直接调用，而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或条件进行响应。