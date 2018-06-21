# 基本绘图
```python
import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0, 10, 1000)
y = np.sin(x)
z = np.cos(x)

fig = plt.figure()
#按照[left,bottom,width,height]新建一个axes到figure
ax = fig.add_axes([0.1, 0.1, 0.8, 0.8])
ax.plot(x, y, 'r')

plt.show()
```
[figure()](https://matplotlib.org/api/_as_gen/matplotlib.pyplot.figure.html#matplotlib.pyplot.figure)
[plot()](https://matplotlib.org/api/_as_gen/matplotlib.pyplot.plot.html#matplotlib.pyplot.plot)

[subplot()](https://matplotlib.org/api/_as_gen/matplotlib.pyplot.subplot.html#matplotlib.pyplot.subplot)

## 栅格控制
```python
```
```python
ax.grid(True, linestyle='-.')
```
[grid详细属性](https://matplotlib.org/api/_as_gen/matplotlib.pyplot.grid.html#matplotlib.pyplot.grid)

## 坐标轴标签
```python
ax.set_xlabel('x')
ax.set_ylabel('sinx')
```

## 坐标设置
```python
ax.tick_params(labelcolor='r', labelsize='medium', width=3)
```
ax.set_title('sinx function')

[plt.gca()](https://matplotlib.org/api/_as_gen/matplotlib.pyplot.gca.html#matplotlib.pyplot.gca)

# 不同数据范围显示不同颜色
```python
import numpy as np
import matplotlib.pyplot as plt

t = np.arange(0.0, 2.0, 0.01)
s = np.sin(2 * np.pi * t)

upper = 0.77
lower = -0.77


supper = np.ma.masked_where(s < upper, s)
slower = np.ma.masked_where(s > lower, s)
smiddle = np.ma.masked_where(np.logical_or(s < lower, s > upper), s)

fig, ax = plt.subplots()
ax.plot(t, smiddle, t, slower, t, supper)
plt.show()
```