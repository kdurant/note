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
ax.plot(x, y, 'r', label = 'sin')
plt.legend() # 显示plot函数里的label标签

plt.show()
```

## [figure函数](https://matplotlib.org/api/_as_gen/matplotlib.pyplot.figure.html#matplotlib.pyplot.figure)
## [plot函数](https://matplotlib.org/api/_as_gen/matplotlib.pyplot.plot.html#matplotlib.pyplot.plot)

格式  | 意义       
:----| :--------             
'-'  | 实线
'--' |   虚线
'-.' |   点与线
':'  |   点
'.'  |   点标记
','  |  像素标记
'o'  |  圆圈标记
'v'  |  倒三角标记
'^'  |  正三角标记
'<'  |  左三角标记
'>'  |  右三角标记
'1'  |   向下Y标记
'2'  |  向上Y标记
'3'  |  向左Y标记
'4'  |  向右Y标记
's'  |  正方形标记
'p'  |  五角星标记
'*'  |   *标记
'h'  |  六边形1 标记
'H'  |  六边形2 标记
'+'  |  +标记
'x'  |  x标记
'D'  |  钻石标记
'd'  |  薄砖石标记
'|'  |  垂直线标记
'_'  |  水平线标记

## [subplot函数](https://matplotlib.org/api/_as_gen/matplotlib.pyplot.subplot.html#matplotlib.pyplot.subplot)

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

## 图片标题
```python
fig = plt.suptitle('title')
plt.title('title')
```

# 子图
```python
import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0, 10, 1000)
y = np.sin(x)
z = np.cos(x)

fig, ax = plt.subplots(2, 1, constrained_layout=True)
ax[0].plot(x, y, label='sin')
ax[0].set_title('subplot 1')
ax[0].set_xlabel('t')
ax[0].set_ylabel('sin(t)')
plt.legend() # 显示plot函数里的label标签


ax[1].plot(x, z, label='cos')
ax[1].set_title('subplot 1')
ax[1].set_xlabel('t')
ax[1].set_ylabel('cos(t)')
plt.legend() # 显示plot函数里的label标签

plt.show()
```
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



# 绘制三维图
```python
from matplotlib import pyplot as plt 
import numpy as np 
from mpl_toolkits.mplot3d import Axes3D

fig = plt.figure()
ax = Axes3D(fig)
X = np.arange(-4, 4, 0.25)
Y = np.arange(-4, 4, 0.25)
X, Y = np.meshgrid(X, Y)
#R = np.sqrt(X**2 + Y**2)
#Z = np.sin(R)
Z = np.sqrt(4- X**2 - Y**2)

ax.plot_surface(X, Y, Z, rstride = 1, cstride = 1, cmap = 'rainbow')

plt.show()
```

# 三维图上画二维图像
```python
from mpl_toolkits.mplot3d import Axes3D  # noqa: F401 unused import

import numpy as np
import matplotlib.pyplot as plt

fig = plt.figure()
ax = fig.gca(projection='3d')

# Plot a sin curve using the x and y axes.
x = np.linspace(0, 1, 100)
y = np.sin(x * 2 * np.pi) / 2 + 0.5
ax.plot(x, y, zs=0, zdir='z', label='curve in (x,y)')

ax.plot(x, y, 'r', zs=0, zdir='y', label='curve in (x,z)')
ax.plot(x, y, 'g', zs=0, zdir='x', label='curve in (y,z)')

ax.legend()
ax.set_xlim(0, 1)
ax.set_ylim(0, 1)
ax.set_zlim(0, 1)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')

#ax.view_init(elev=20., azim=-35)

plt.show()
```


# 参数方程
```python
from mpl_toolkits.mplot3d import Axes3D  # noqa: F401 unused import

import numpy as np
import matplotlib.pyplot as plt


plt.rcParams['legend.fontsize'] = 10

fig = plt.figure()
ax = fig.gca(projection='3d')

# Prepare arrays x, y, z
theta = np.linspace(-4 * np.pi, 4 * np.pi, 100)
z = np.linspace(-2, 2, 100)
# r = z**2 + 1
# x = r * np.sin(theta)
# y = r * np.cos(theta)
x = np.sin(theta)
y = np.cos(theta)

ax.plot(x, y, z, label='parametric curve')
ax.legend()

plt.show()
```