# 静态库
假设有`add.h`和`add.c`两个文件。内容分布如下：
```c
int add(int a, int b);
```


```c
#include "add.h"

int add(int a, int b)
{
    return a + b;
};
```

1. 将add.c编译为add.o文件
`gcc -c add.c`

2. 将add.o组合成静态库
`ar -r libadd.a add.o`

3. 使用
`gcc main.c -L. -ladd`