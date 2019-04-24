generate语句块不能包含端口声明, 参数声明, `specify`语句块和`specparam`声明. 

# loops generate
`loops generate`允许使用类似于for循环语句的语法多次实例化生成块。
循环索引变量应在`genvar`声明中声明，然后才能在循环生成方案中使用。

> 除了在循环生成方案中，genvar不应被引用。



# conditional generate