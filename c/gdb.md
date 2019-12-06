https://blog.csdn.net/yinjiabin/article/details/7732931

# 启动gdb
- 启动gdb，并且分屏显示源代码
`$gdb -tui a.out`

- 修改发送给程序的参数
  `(gdb) set args no`

- 显示缺省的参数列表： 
  `(gdb) show args`

# 列出指定区域代码
- 列出指定区域(n1到n2之间)的代码： 
  `(gdb) list n1 n2 `

  一般来说在list后面可以跟以下这们的参数： 
<linenum>   行号。 
<+offset>   当前行号的正偏移量。 
<-offset>   当前行号的负偏移量。 
<filename:linenum>  哪个文件的哪一行。 
<function>  函数名。 
<filename:function> 哪个文件中的哪个函数。 
<*address>  程序运行时的语句在内存中的地址。 