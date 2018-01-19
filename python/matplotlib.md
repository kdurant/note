# 基本图形
```python
import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0, 10, 1000)
y = np.sin(x)
z = np.cos(x)

plt.figure()
plt.plot(x, y)
plt.plot(x, z)
plt.show()
```

## 设置图形标题
```python
```
```python
plt.title('sinx cosx function')
```

## 设置轴标签
```python
plt.xlabel('x')
plt.ylabel('sinx cosx')
```

# 面对对象API
## 1
```python
import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0, 10, 1000)
y = np.sin(x)
z = np.cos(x)

fig = plt.figure()
#按照[left,bottom,width,height]新建一个axes到figure
axes = fig.add_axes([0.1, 0.1, 0.8, 0.8])
axes.plot(x, y, 'r')

axes.set_xlabel('x')
axes.set_xlabel('sinx')
axes.set_title('sinx function')

#fig.show()
```

## 2
```python
import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0, 10, 1000)
y = np.sin(x)
z = np.cos(x)

fig = plt.figure()
axes1 = fig.add_axes([0.1, 0.1, 0.8, 0.8])
axes2 = fig.add_axes([0.2, 0.5, 0.4, 0.3])
axes1.plot(x, y, 'r')
axes2.plot(x, z, 'g')

#fig.show()
```