# partial
functools.partial提供对象的默认参数而生成一个新的访问形式

> 典型的，函数在执行时，要`带上所有必要的参数`进行调用。然后，有时参数可以在函数被调用之前提前 获知。这种情况下，一个函数`有一个或多个参数预先就能用上`，以便函数能用更少的参数进行调用。

```python
import functools
def add(a, b):
    return a+b

# 一般情况下，调用函数，需要带上所有的参数
>>> add(4, 2)
6

# add的参数'3'已知，下次调用时，只需要添加另一个参数
>>> p3 = functools.partial(add, 3)
functools.partial(<function add at 0x000001F1A07570D0>, 3)

>>> p3(10)
13
```