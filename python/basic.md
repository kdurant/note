# 特殊函数

## __call__()

## __len__()
如果一个类表现得像一个list，要获取有多少个元素，就得用 len() 函数。要让 len() 函数工作正常，类必须提供一个特殊方法__len__()，它返回元素的个数。
```python
class Students(object):
    def __init__(self, *args):
        self.names = args
    def __len__(self):
        return len(self.names)
ss = Students('Bob', "Alice', 'Tim')
>>> print(len(ss))
3
```

## __getattr__()
使用点号(.)获取实例属性属性如 s.name

## __getitem__()
使用[]获取实例属性，如s['name']
```python
class Student:
    def __getitem__(self, item):
        return self.__dict__[item]

s = Student()
s.age = 1
>>> print(s['age'])
1
```

## __contains__()
使用`in`, `not in`对象的时候调用

## __dict__
用来存储对象属性的一个字典，其键为属性名，值为属性的值。
```python
class Students(object):
    def __init__(self, name):
        self.names = name
s = Student('Tom')
>>> s.__dict__
{'names': 'Tom'}
>>> s.__dict__['names']
'Tom'
```

可以方便构建字典
```python
class Version:

    """Helper class for version info."""

    def __init__(self, **kwargs):
        """Create the Version object."""
        self.__dict__.update(kwargs)
v = Version(major=0, minor=1, patch=14, prerelease="dev")
>>> v.__dict__
{'major': 0, 'minor': 1, 'patch': 14, 'prerelease': 'dev'}

>>> v.__dict__['prerelease']
'dev'
```

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