# 一重积分
## <font color=red>定义</font>
$设函数f(x)在[a, b]上有界，在[a,b]中任意插入若干个分点$
$$a = x_0 < x_1 < x_2<...< x_{n-1} < x_n = b$$
$把去间[a, b]分成n个小区间$
$$ [x_0, x_1],[x_1, x_2],...,[x_{n-1},x_n], $$
$各个小区间的长度依次为$
$$ \Delta x_1 = x_1-x_0, \Delta x_2 = x_2-x_1,..., \Delta x_n = x_n - x_{n-1}, $$
$在每个小去间[x_{i-1}, x_i]上任取一点\xi_i(x_{i-1} \leq \xi_i \leq x_i)，做函数值f(\xi_i)与小区间长度\Delta x_i的乘积f(\xi_i)\Delta x_i (i=1, 2, ... , n)，并作出和$

$$\int_a^bf(x)dx = \lim_{\lambda \to 0}^nf(\xi_i)\Delta x_i$$
1. 积分区域

### 几何意义
1. 被积函数在被积区域里与x轴围成的图形面积

## 曲线弧长积分
### 参数方程定义
设曲线弧由参数方程
$$\begin{cases}
x = \varphi(t), \\
y = \psi(t) \qquad ( \alpha \leq t \leq \beta)
\end{cases}$$
给出，其中$\varphi(t)$、$\psi(t)$在$[\alpha, \beta]$上具有连续导数，且$\varphi(t) + \psi(t) $不同时为零，则弧长
$$\color{teal}s = \int_a^b\sqrt{\varphi^{'2}(t) + \psi^{'2}(t)}dt$$

### 向量值函数定义
当t从t=a增加到t=b时，恰好描绘一次的光滑曲线$\vec{t}=f(t)\vec{i}+g(t)\vec{j}+h(t)\vec{k}的长度是$
$$\color{teal}s = \sqrt{(\tfrac{df}{dt})^2 + (\tfrac{dg}{dt})^2 + (\tfrac{dh}{dt})^2}dt$$


## 第一类曲线积分（对弧长的曲线积分）
### <font color=red>定义</font>
$$\int_Lf(x, y)ds = \lim_{\lambda \to 0}\sum_{i=1}^n f(\xi_i, \eta_i)\Delta s_i$$

### 意义
1. 曲线形物体的质量
    L: 积分区域，二维曲线
    f(x, y)：曲线密度
    ds:弧长微元

### 计算方法
* 转换为一重积分
设f(x,y)在曲线弧L上有定义且连续，L的参数方程为
$$\begin{cases}
x = \varphi(t), \\
y = \psi(t) \qquad ( \alpha \leq t \leq \beta)
\end{cases}$$
若$\varphi(t)$、$\psi(t)$在$[\alpha, \beta]$上具有一阶连续导数，且$\varphi^{'2}(t) + \psi^{'2}(t) \neq 0$，则曲线积分$f(x,y)ds$存在，且

$$\color{teal}\int_Lf(x, y)ds = \int_\alpha^\beta f[\varphi(t),\psi(t)]\sqrt{\varphi^{'2}(t) + \psi^{'2}(t)}dt$$

## 第二类曲线积分（对坐标的曲线积分）
### <font color=red>定义</font>
$$\int_LP(x, y)dx = \lim_{\lambda \to 0}^n\Sigma P(\xi_i, \eta_i)\Delta x_i,$$ 
$$\int_LQ(x, y)dy = \lim_{\lambda \to 0}^n\Sigma Q(\xi_i, \eta_i)\Delta y_i$$
以上二个积分称为第二类曲线积分
记做：
1. 代数形式
$$\int_LP(x, y)dx + Q(x, y)dy$$
2. 向量形式
$$\int_L\vec{F}(x,y)\cdot d\vec{r}$$
其中$\vec{F} = P(x,y)\vec{i} + Q(x,y)\vec{j}$为向量值函数， $d\vec{r} = dx\vec{i} + dy\vec{j}$

### 意义
1. 变力沿曲线所做的功
   L：物体的移动轨迹，二维曲线
   $P(x, y)dx$：变力在x轴的分量
   $Q(x, y)dy$：变力在y轴的分量

### 计算方法
1. 转换为一重积分
设f(x,y)在曲线弧L上有定义且连续，L的参数方程为
$$\begin{cases}
x = \varphi(t), \\
y = \psi(t), 
\end{cases}$$

$当参数t单调地有\alpha变到\beta时，点M(x,y)从L的起点A运动到终点B，若\varphi(t)与\psi(t)在以\alpha及\beta为端点的闭区间上具有一阶连续导数，且\varphi^{'2}(t) + \psi^{'2}(t) \neq 0，则曲线积分\int_LP(x, y)dx + Q(x, y)dy存在，且$
$$\color{teal}\int_LP(x, y)dx + Q(x, y)dy \\ =\int_\alpha^\beta \{P[\varphi(t),\psi(t)]\varphi^{'}(t) + Q[\varphi(t),\psi(t)]\psi^{'}(t)\}dt$$


1. 格林公式
$$\mathop{\iint}\limits_D\left(\frac{\partial Q}{\partial x}-\frac{\partial P}{\partial y} \right )dxdy=\oint _LPdx+Qdy$$

## 两类曲线积分联系

# 二重积分
## <font color=red>定义</font>
$$\mathop{\iint}\limits_D f(x,y)d\sigma = \lim_{\lambda \to 0}\sum_{i=1}^n f(\xi_i, \eta_i)\Delta s_i$$

## 意义
1. 确定柱体的体积
   D: 柱体的底面
   $f(x,y)$: 柱体的顶面

2. 平面薄片的质量
   D：平面薄片的面积
   $f(x,y)$:薄片的质量分布
> 薄片必须是平面

## 计算
   
# 三重积分
## <font color=red>定义</font>
$$\mathop{\iiint}\limits_D f(x,y,z)d\sigma = \lim_{\lambda \to 0}\sum_{i=1}^n f(\xi_i, \eta_i, \zeta_i)\Delta v_i$$

# 曲面积分
## 第一类曲面积分(对面积的曲面积分)
### <font color=red>定义</font>
$设曲线\Sigma是光滑的，函数f(x,y,z)在\Sigma上有界。把\Sigma任意分成n小块\Delta S_i，设(\xi_i,  \eta_i, \zeta_i)是\Delta S_i上任取的一点，做乘积f(\xi_i,  \eta_i, \zeta_i)\Delta S_i (i=1,2,3...n)，并作和\sum_{i=1}^n$
$$\mathop{\iint}\limits_\Sigma f(x, y, z)dS = \lim_{\lambda \to 0}\sum_{i=1}^n f(\xi_i, \eta_i, \zeta_i)\Delta S_i$$

### 物理意义
1. 密度分布不均匀的曲面要计算其质量
   $\Sigma$：积分区域，是三维曲面

### 计算方法
将曲面积分化为二重积分
$$\color{teal}\mathop{\iint}\limits_\Sigma f(x, y, z)dS = \mathop{\iint}\limits_{D_{xy}}f[x,y,z(x,y)]\sqrt{1+z_x^2(x,y) + z_y^2(x,y)}dxdy$$

## 第二类曲面积分(对坐标的曲面积分)
### <font color=red>定义</font>
$$\mathop{\iint}\limits_\Sigma R(x, y, z)dxdy = \lim_{\lambda \to 0}\sum_{i=1}^n R(\xi_i, \eta_i, \zeta_i)(\Delta S_i)_{xy}$$
$$\mathop{\iint}\limits_\Sigma P(x, y, z)dydz = \lim_{\lambda \to 0}\sum_{i=1}^n P(\xi_i, \eta_i, \zeta_i)(\Delta S_i)_{yz}$$
$$\mathop{\iint}\limits_\Sigma Q(x, y, z)dzdx = \lim_{\lambda \to 0}\sum_{i=1}^n Q(\xi_i, \eta_i, \zeta_i)(\Delta S_i)_{zx}$$
以上三个曲面积分称为第二类曲面积分

## 物理意义
1. 流速场通过曲面 S 的流量,也就是如何计算单位时间通过横断面流体的体


# 麦克斯韦方程组
1. 积分形式
   $$\mathop{\oiint}\limits_\Sigma \mathbf{E} \cdot d\mathbf{s} = \tfrac{Q}{\epsilon_0}$$
   $$\mathop{\oiint}\limits_\Sigma \mathbf{B} \cdot d\mathbf{s} = 0$$
   $$\mathop{\oint}_L \mathbf{E} \cdot d\mathbf{l} = -\tfrac{d\Phi}{dt}$$
   $$\mathop{\oint}_L \mathbf{H} \cdot d\mathbf{l} = I_f + \tfrac{d\Phi_B}{dt}$$


2. 微分形式
   $$\nabla \cdot \mathbf{E} = \tfrac{\rho}{\epsilon}$$
   $$\nabla \cdot \mathbf{B} = 0$$
   $$\nabla \times \mathbf{E} = -\tfrac{\partial\mathbf{B}}{\partial t}$$
   $$\nabla \times \mathbf{H} = \mathbf{J}_f + \tfrac{\partial \mathbf{D}}{\partial t}$$