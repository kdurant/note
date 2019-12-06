# 基本格式
> gcc [选项] 

# -E
预编译
`gcc -E hello.c > pianoapan.txt`

# -S
只激活预处理和编译, 产生汇编代码
`gcc -s main.c`

#. -c
编译或汇编源文件,但是不作连接.编译器输出对应于源文件的目标文件`.o`

# -o
指定输出文件，如果没有使用 -o 选项,默认的输出结果是:可执行文件为 a.out
`gcc main.o list.o -o main`

# -g 
带调试信息 `gcc -g main.c -o main`

# -D
定义宏`-D TEST`

# -I
利用-I来显式指定头文件的所在地
`gcc -std=c99 -g -I./head -D TEST -c main.c -o main.o`

# -xc
等于`-x c`, x用于指定输入的程序的语言，如果使用该选项，GCC就不再根据文件的后缀名判断语言类型。 

# -MMD
将输出将导入到.d的文件里面:

# 
> gcc -g -c test.c
> objdump -d -M intel -S test.o