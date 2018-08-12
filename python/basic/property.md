@property装饰器能把一个方法变成属性一样来调用

# 作用

## 创建一个允许设置的属性
```python
class Student(object):
    def __init__(self, name, score):
        self.name = name
        self.__score = score

    @property
    def score(self):
        return self.__score

    @score.setter
    def score(self, score):
        if score < 0 or score > 100:
            raise ValueError('invalid score')
        
        self.__score = score

s = Student('Bob', 59)
s.score = 60
```