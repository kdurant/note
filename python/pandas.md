# Series
Series用来表示一维数据结构，和数据类似

| 基本index    | 声明index           | value  |
| :-----------:|:-------------:| :----:|
| 0            | 'a'           | 12 |
| 1            | 'b'           |   -4 |
| 2            | 'c'           |    7 |
| 3            | 'd'           |    9 |

## 创建方式
```python
pd.Series(data,index=)
```

1. 数组方式传入
```python
s = pd.Series([12, -4, 7, 9], index=['a', 'b', 'c', 'd'])
```

2. ndarray生成数组传入
```python
s = pd.Series(np.random.randn(5), index = list('ABCDE')
```

3. 把Series对象当做字典
```python
>>> mydict = {'red':2000, 'blue':1000, 'yellow':500, 'orange':1000}
>>> myseries = pd.Series(mydict)
>>> myseries
blue      1000
orange    1000
red       2000
yellow     500
dtype: int64
```

## 基本操作
1. 查看index
`s.index`

2. 查看value
`s.values`

3. 选择单一内部元素
* 指定元素index，`s[2]`或者`s['a']`

4. 选择多个连续元素
* 和列表一样使用slice操作`s[0:2]`

5. 选择多个不连续元素
* 将index放到数组中 `s[['a', 'c']]`

6. 筛选数据
`s[s > 8]`

7. 去除相同元素
```python
>>> serd = pd.Series([1, 10, 5, 1, 22, 33], index=['white', 'white', 'blue', 'green', 'green', 'yellow'])

>>> serd
white      1
white     10
blue       5
green      1
green     22
yellow    33
dtype: int64

>>> serd.unique()
array([ 1, 10,  5, 22, 33], dtype=int64)
```

8. 统计元素在Series中出现个数
```python
>>> serd.value_counts()
1     2
22    1
5     1
33    1
10    1
dtype: int64
```

9. 判读元素所属关系
```python
>>> serd.isin([22, 5])
white     False
white     False
blue       True
green     False
green      True
yellow    False
dtype: bool
```

# DataFrame

## 定义DataFrame对象
```python
>>> data = {'color': ['blue', 'green', 'yellow', 'red', 'while'], 
        'object': ['ball', 'pen', 'pencil', 'paper', 'mug'], 
        'price': [1.2, 1.0, 0.6, 0.9, 1.7]}

>>> frame = pd.DataFrame(data)
>>> frame
    color  object  price
0    blue    ball    1.2
1   green     pen    1.0
2  yellow  pencil    0.6
3     red   paper    0.9
4   while     mug    1.7

>>> f2 = pd.DataFrame(data, columns=['object', 'price'])
>>> f2
   object  price
0    ball    1.2
1     pen    1.0
2  pencil    0.6
3   paper    0.9
4     mug    1.7

```

## 获得对象列所有的名称
```python
>>> frame.columns
Index(['color', 'object', 'price'], dtype='object')
```

## 获得对象所有列的索引
```python
>>> frame.index
RangeIndex(start=0, stop=5, step=1)
```

## 获得对象存储在数据结构中的元素
```python
>>> frame.values
array([['blue', 'ball', 1.2],
       ['green', 'pen', 1.0],
       ['yellow', 'pencil', 0.6],
       ['red', 'paper', 0.9],
       ['while', 'mug', 1.7]], dtype=object)

>>> frame.price
0    1.2
1    1.0
2    0.6
3    0.9
4    1.7
Name: price, dtype: float64

>>> frame['price']
0    1.2
1    1.0
2    0.6
3    0.9
4    1.7
Name: price, dtype: float64

```

