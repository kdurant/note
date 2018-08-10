# 作用
在类的继承中，如果重定义了某个方法，该方法会覆盖同类的同名方法，但有时，我们希望能同时实现父类的功能，这时，我们就需要调用父类的方法了，可通过`super`实现。
```python
class Animal(object):
    def __init__(self, name):
        self.name = name

    def greet(self):
        print('hello, I am %s.' % self.name)

class Dog(Animal):
    def greet(self):
        #super(Dog, self).greet()       # python2写法
        super().greet()                 # python3写法
        print('Wang Wang')

d = Dog('pipi')
d.greet()
```
如果没有在`greet`中调用`super`方法，将输出
>> Wang Wang
否则，会将`Animal`类中的信息一起输出