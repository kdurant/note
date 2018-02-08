# 二位数组
```c
char zippo[3][20] = {
    "abcdef",
    "nimenhao",
    "hello world"
};
```
zippo[3]说明这是一个数组
zippo[3][20]说明数组里的每个元素是20个char长度的数组
想使用指针自增输出每个字符串

> zippo 是二维数组首地址

```c
char (*p)[20] = zippo;  //
for (int i = 0; i < 3; i++)
{
    printf("%s\n", p);
    p++;
}
```
> * 和 p 构成一个指针的定义，指针名是 p， char 修饰的是数组的内容
> 即数组里的每个元素。数组在这里并没有名字，是个匿名数组

# 指针数组
```c
char *str[3] = {
    "aaaaaa", 
    "cccccc", 
    "ddddddddd"
};
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