#  --ascii 
解决`cannot convert to multi-byte string reverting to english`问题

# -p
在操作符两边插入空格，如=、+、-等。

# -n
不生成备份文件，即默认的 .orig文件

# --indent=tab   --indent=space
缩进使用tab或者空格，缺省都是4个字符

# --style=ansi

# -H 
在关键字'if', 'for', 'while'之后添加空格

# -U 
去除括号间号之间多余空格
```c
if ( isFoo( a, b ) )
    bar ( a, b );
```
```c
if (isFoo(a, b))
    bar (a, b);
```