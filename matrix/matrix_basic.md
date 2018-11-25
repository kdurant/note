# 创建普通矩阵
```python
m = np.mat([1, 2, 3])
m = np.matrix([[1, 2, 3], [2, 3, 4]])
m = np.mat(np.ones((3,3)) * 2)
m = np.mat(np.random.rand(2,2))
m = np.mat('4 3; 2 1')
```
# 零矩阵
元素都是零的矩阵称为零矩阵
```python
m = np.mat(np.zeros((3,3)))
```

# 单位矩阵
主对角线上都是1，其他元素都0的矩阵称为单位矩阵
```python
m = np.mat(np.eye(4,4, dtype=int))
m = np.mat(np.identity(3))
```

# 对角矩阵
不再对叫上的元素都是0，称为对焦矩阵
```python
m = np.mat(np.diag([1,2,3]))        
```

# 对称矩阵(symmetric matrix)
元素以对角线为对称轴对应相等
```python
m = np.random.rand(5**2).reshape(5, 5)
n = np.triu(m)  // 保留其上三角部分
n += n.T - np.diag(n.diagonal())    // 将上三角”拷贝”到下三角部分

```

# 伴随矩阵

# 逆矩阵
$对于n阶矩阵\mathbf{A}，如果有一个n阶矩阵\mathbf{B}，使$
$$\mathbf{A}\mathbf{B} = \mathbf{B}\mathbf{A} = \mathbf{E}$$
$则说矩阵\mathbf{A}是可逆的，并把矩阵\mathbf{B}称为\mathbf{A}的逆矩阵$

# 正交矩阵
$A^T A = E,则称A为正交矩阵$

# 相似矩阵

# 矩阵运算
```python
m = np.mat(np.diag([1,2,3]))
n = np.mat(np.ones((3,3)) * 2)
```

# 矩阵乘法
```python
m*n
```
# 矩阵点乘（对应元素相乘）
```python
np.multiply(m*n)
```

# 求逆
```python
# np.linalg.det(m) != 0 时，矩阵才存在逆矩阵
m.I
np.linalg.inv(m)
```

# 转置
把矩阵A的行换成同序数的的列得到一个新矩阵，叫做A的转置矩阵
```python
m.T
```

# 秩
矩阵A的最高阶非0子式的阶数
```python
np.linalg.matrix_rank(m)
```

# 方阵的特征值和特征向量
```python
a,b = np.linalg.eig(m)  # 特征值保存在a中，特征向量保存在b中
```

# 线性代数名词
## 初等变换
## 初等矩阵
## 相似矩阵

## 迹
一个 的矩阵 的迹（或迹数），是指 的主对角线（从左上方至右下方的对角线）上各个元素的总和
```python
m.trace()
```

## 范数
1. 内积

设有n维向量
$$
 \left\{
 \begin{matrix}
   x_1  \\
   x_2  \\
   \cdots \\
   x_n 
  \end{matrix}
  \right\},
   \left\{
 \begin{matrix}
   y_1  \\
   y_2  \\
   \cdots \\
   y_n 
  \end{matrix}
  \right\}$$

$令[\mathbf{x}, \mathbf{y}] = x_1y_1 + x_2y2 + \cdots + x_ny_n,\\ [\mathbf{x}, \mathbf{y}]称为\mathbf{x}, \mathbf{y}的内积$

2. 范数
   令$||\mathbf{x}|| = \sqrt{[\mathbf{x},\mathbf{x}]} = \sqrt{x_1^2+x_2^2+\cdots + x_n^2}, ||\mathbf{x}||称为n维向量\mathbf{x}的长度(或范数)$

## 线性相关
$给定向量组A：\mathbf{a_1},\mathbf{a_2}, ... , \mathbf{a_n}, 如果存在不全为零的数k_1,k_2,... ,k_n, 使$
$$k_1\mathbf{a_1} + k_2\mathbf{a_2} + ... + k_n\mathbf{a_n} = 0$$
$则称向量组A使线性相关的，否则称为线性无关$


# array 和 matrix区别
1. 转置不同
   对matrix转置可以得到