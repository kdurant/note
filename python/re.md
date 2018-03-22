![](https://upload-images.jianshu.io/upload_images/141249-f9ab21ea9ea1aac5?imageMogr2/auto-orient/strip%7CimageView2/2/w/700)
# re模块中常用功能函数
## re.findall
```python
findall(pattern, string, flags=0)
```
返回string中所有与pattern相匹配的全部字符串的列表
```python
import re
animal = 'dog cat bird cat dog cat duck fuck'
>>> re.findall('cat', animal)
['cat', 'cat', 'cat']

>>> re.findall('dog.+dog', animal)
['dog cat bird cat dog']

>>> re.findall('.uck', animal)
['duck', 'fuck']
```

## re.sub
```python
sub(pattern, repl, string, count=0, flags=0)
```
对字符串string按照正则表达式pattern，将string的匹配项替换成字符串repl

`pattern`为表示正则中的模式字符串，
`repl`为replacement，被替换的内容，repl可以是字符串，也可以是函数。
`string`为正则表达式匹配的内容。
`count`：由于正则表达式匹配到的结果是多个，使用count来限定替换的个数（顺序为从左向右），默认值为0，替换所有的匹配到的结果。
`flags`是匹配模式，可以使用按位或’|’表示同时生效，也可以在正则表达式字符串中指定。

## re.compile()

将正则表达式模式编译成一个正则表达式对象，它可以用于匹配使用它的`match()`和`search()`方法。
格式如下：
```python
re.compile(pattern, flags=0)
# pattern: 编译时用的表达式字符串
# flags: 编译标志位，用于修改正则表达式的匹配方式
```

```python
re.sub('cat', 'mouse', animal)
>>> 'dog mouse bird mouse dog mouse duck fuck'

```

标志             |      含义
-----          |-------
re.S(DOTALL)    |使.匹配包括换行在内的所有字符
re.I（IGNORECASE）|使匹配对大小写不敏感
re.L（LOCALE）    | 做本地化识别（locale-aware)匹配，法语等
re.M(MULTILINE) |多行匹配，影响^和$
re.X(VERBOSE)   |该标志通过给予更灵活的格式以便将正则表达式写得更易于理解
re.U            | 	根据Unicode字符集解析字符，这个标志影响\w,\W,\b,\B

```python
import re
tt = "Tina is a good girl, she is cool, clever, and so on..."
rr = re.compile(r'\w*oo\w*')
>>> print(rr.findall(tt))   # 在tt中查找所有包含'oo'的单词
['good', 'cool']
```

## re.match
```python
match(pattern, string, flags=0)
```
总是从string的头部开始查找pattern，没有找到返回None

```python
p = re.compile(r'hello')
r1 = re.match(p, 'hello123')
print(r1.group())

r2 = re.match(pattern, '123hello')
>>> print(r2)
None
```

## re.search
```python
search(pattern, string, flags=0)
```
对整个字符串进行搜索，并返回第一个匹配的字符串的match对象
```python
p = re.compile(r'hello')
r1 = re.search(p, '123hello123')

>>> print(r1)
<_sre.SRE_Match object; span=(3, 8), match='hello'>

