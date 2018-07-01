# 基本绘图
只设置x，y的数据
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

    '-'      实线
    '--'    虚线
    '-.'    点与线
    ':'     点
    '.'     点标记
    ','    像素标记
    'o'    圆圈标记
    'v'    倒三角标记
    '^'    正三角标记
    '<'    左三角标记
    '>'    右三角标记
    '1'     向下Y标记
    '2'    向上Y标记
    '3'    向左Y标记
    '4'    向右Y标记
    's'    正方形标记
    'p'    五角星标记
    '*'     *标记
    'h'    六边形1 标记
    'H'    六边形2 标记
    '+'    +标记
    'x'    x标记
    'D'    钻石标记
    'd'    薄砖石标记
    '|'    垂直线标记
    '_'    水平线标记

[subplot()](https://matplotlib.org/api/_as_gen/matplotlib.pyplot.subplot.html#matplotlib.pyplot.subplot)

## 栅格控制
1. 设置栅格线的形状
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

# 根据Y轴数据的范围设置显示颜色
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

# 绘制X
