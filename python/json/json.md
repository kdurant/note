JSON(JavaScript Object Notation) 是一种轻量级的数据交换格式。 易于人阅读和编写。同时也易于机器解析和生成。 它基于JavaScript Programming Language, Standard ECMA-262 3rd Edition - December 1999的一个子集。 JSON采用完全独立于语言的文本格式，但是也使用了类似于C语言家族的习惯（包括C, C++, C#, Java, JavaScript, Perl, Python等）。 这些特性使JSON成为理想的数据交换语言。

JSON建构于两种结构：

* `“名称/值”对的集合（A collection of name/value pairs）`。不同的语言中，它被理解为对象（object），纪录（record），结构（struct），字典（dictionary），哈希表（hash table），有键列表（keyed list），或者关联数组 （associative array）。
* `值的有序列表（An ordered list of values）`。在大部分语言中，它被理解为数组（array）


# JSON 语法规则
1. 数据在名称/值对中
2. 数据由逗号分隔
3. 花括号保存对象
4. 方括号保存数组

# JSON 名称/值对

JSON 数据的书写格式是：名称/值对。

名称/值对包括字段名称（在双引号中），后面写一个冒号，然后是值：
```json
"firstName" : "John"
```

# JSON 值
![](https://sfault-image.b0.upaiyun.com/4b/85/4b85ca012e31a1d9eb73b42a4e2220ab_articlex)
JSON 值可以是：
* 数字（整数或浮点数）
* 字符串（在双引号中）,在JSON字符串中，不能使用函数或者正则表达式字面量
* 逻辑值（true 或 false）
* 数组（在方括号中）
* 对象（在花括号中）
* null

# JSON 对象
![](https://sfault-image.b0.upaiyun.com/00/07/00077e283c07754189106221b6886c4b_articlex)
JSON 对象在花括号中书写：
对象可以包含多个名称/值对：
```json
{ "firstName":"John" , "lastName":"Doe" }
```

# JSON 
数组在方括号中书写：
数组可包含多个对象：
```json
{
    "employees": [
        { "firstName":"John" , "lastName":"Doe" },
        { "firstName":"Anna" , "lastName":"Smith" },
        { "firstName":"Peter" , "lastName":"Jones" }
    ]
}
```
