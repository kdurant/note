# 基本属性
numpy 数组类称为`ndarray`，具有以下重要属性
```python
t1 = np.zeros( (3,3), dtype=np.uint8)
t2 = np.zeros( (3,3), dtype=np.float64)
```

1. ndarray.ndim
数组的维度
```python
>>> t1.ndim
2
```

2. ndarray.shape
数字的行列
```python
>>> t1.shape
(3,3)
```

3. ndarray.size
数组的元素总数。这等于形状元素的乘积。和元素类型无关
```python
>>> t1.size
9
>>> t2.size
9
```

4. ndarray.dtype
数组元素的类型
```python
>>> t1.dtype
dtype('uint8')
>>> t2.dtype
dtype('float64')
```

5. ndarray.itemsize
数组元素在内存中占用的字节数
```python
>>> t1.itemsize
1
>>> t2.itemsize
8
```

6. ndarray.data

# 数组生成方法
```python
a = np.array( [2, 3, 4] )

a = np.ones( (2, 3, 4), dtype=np.int16)

# 根据内存状态，创建一个随机数组，默认元素类型为 np.float64
a = np.empty( (2, 3) , dtype=np.float64)

>>> np.arange(10, 30, 5)
array([10, 15, 20, 25])

# 9 numbers from 0 to 2
>>> np.linspace(0, 2, 9)
array([ 0. , 0.25, 0.5 , 0.75, 1. , 1.25, 1.5 , 1.75, 2. ])
```


# 随机数


# randint()
```python
r0 = np.random.randint(80, 100)         # 产生一个随机数
r0 = np.random.randint(80, 100, size=(2,3))     # 
```