# str.format()
## 通过位置格式化
```python
>>> '{0}, {1}'.format('kzc',18) 
kzc, 18

>>> '{1}, {0}, {1}'.format('kzc',18) 
18, kzc, 18
```
字符串的format函数可以接受不限个参数，位置可以不按顺序，可以不用或者用多次

## 通过关键字参数
```python
>>> '{name},{age}'.format(age=18,name='kzc')
'kzc,18'
```
# *args
*args 用来将参数打包成tuple给函数体调用
```python
def func(*args):
    print(args, type(args))

>>> func(1)
(1,) <class 'tuple'>

>>> func(1, 2)
(1, 2) <class 'tuple'>
```

# **kwargs
**kwargs 打包关键字参数成dict给函数体调用
```python
def func(**kwargs):
    print( 'args type is {}'.format(type(kwargs)))
    return kwargs
t = func(a=2, b=3)
args type is <class 'dict'>

print(t)
{'a': 2, 'b': 3}
```

# 类变量 和 成员变量
```python
class test(object):
    x = 0
    
    def __init__(self):
    self.y = 1
```
上面的代码中，`x`是类变量，`y`是成员变量

> 当通过名字来访问一个对象的属性时，先从对象的命名空间里寻找，如果没有找到则从类的命名空间里找，如果都找不到，则返回异常

1. 通过类来赋值
如果通过类来赋值之前，没有声明类的对象，则后面声明的类都使用类赋值之后的值
如果通过类来赋值之前，已经有声明的对象，则类赋值不会改变已声明类对象的类变量
```python
a = test()  # a.x = 0
test.x = 10
b = test()  # b.x = 10, a.x = 0
```