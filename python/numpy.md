numpy 数组类称为`ndarray`，具有以下重要属性
1. ndarray.ndim

2. ndarray.shape

3. ndarray.size

4. ndarray.dtype

5. ndarray.itemsize

6. ndarray.data

```python
>>> a = np.arange(0, 9).reshape(3, 3)
>>> a
array([[0, 1, 2],
       [3, 4, 5],
       [6, 7, 8]])

>>> a.ndim
2

>>> a.size
9

>>> a.dtype
dtype('int32')
>>> a.dtype.name
'int32'


>>> a.itemsize
4

```



# 随机数


# randint()
```python
r0 = np.random.randint(80, 100)         # 产生一个随机数
r0 = np.random.randint(80, 100, size=(2,3))     # 
```