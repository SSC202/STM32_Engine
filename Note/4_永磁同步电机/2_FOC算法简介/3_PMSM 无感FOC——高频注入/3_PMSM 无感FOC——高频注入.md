# Engine 4.2.3 无感FOC 高频注入简介

> **Attention**：本笔记仅介绍最基本的高频注入，关于更加深入的内容暂不公开。

对于 FOC ，获取当前的电角度是一个重要的研究方向，使用 HALL 传感器虽然低成本，但是误差较大，难以实现位置控制；使用磁编码器虽然精度高，但是硬件成本较高，设计较复杂。无感 FOC 是当前交流电机控制的主要研究方向。

无感技术分为两大类：

>- 基于反电动势的无感算法：磁链观测器，滑膜观测器，扩展 Kalman 滤波器 ... 该方法在中高速时存在良好的控制效果，但是在低速时由于反电动势噪声较大，跟踪效果较差。
>- 基于检测电机凸极特性的无感算法：高频注入，电感测量法 ... 该方法在低速时存在良好的控制效果。

高频注入法基于转子的凸极效应：一类是通过转子本身的凸极效应得到（IPMSM的凸极效应），称为结构性凸极；另一类是通过磁路饱和产生的突击性，称之饱和性凸极。

高频注入法有四种，旋转高频电压注入，旋转高频电流注入，脉振高频电压注入，高频方波电压注入，考虑到 PMSM 的驱动器通常使用电压源型逆变器，使用旋转高频电压注入，脉振高频电压注入，高频方波电压注入较为普遍。

## 0. 高频注入的 PMSM 模型

$$
\begin{bmatrix}
u_d \\
u_q \\
\end{bmatrix} 
=
\begin{bmatrix}
R_s & 0 \\
0 & R_s \\
\end{bmatrix} 
\begin{bmatrix}
i_d \\
i_q 
\end{bmatrix}
+
\begin{bmatrix}
L_d & 0 \\
0 & L_q \\
\end{bmatrix} 
\frac{d}{dt}
\begin{bmatrix}
i_d \\
i_q 
\end{bmatrix}
+
\omega_e
\begin{bmatrix}
0 & -L_q \\
L_d & 0 \\
\end{bmatrix} 
\begin{bmatrix}
i_d \\
i_q 
\end{bmatrix}
+
\omega_e\Psi_m
\begin{bmatrix}
0 \\
1
\end{bmatrix}
$$

通常，高频注入时注入信号的频率远高于电机基波频率，同时电阻远小于电抗，因此忽略有关项可以得到：
$$
\begin{bmatrix}
u_d \\
u_q \\
\end{bmatrix} 
=
\begin{bmatrix}
L_d & 0 \\
0 & L_q \\
\end{bmatrix} 
\frac{d}{dt}
\begin{bmatrix}
i_d \\
i_q 
\end{bmatrix}
$$

## 1. 旋转高频电压注入

### 高频电流响应

旋转高频电压注入要求在 $\alpha - \beta$ 坐标系下注入高频正交正弦电压：
$$
\begin{bmatrix}
u_{\alpha h} \\
u_{\beta h} 
\end{bmatrix}
=
U_h
\begin{bmatrix}
cos(\omega_h t) \\
sin(\omega_h t)
\end{bmatrix}
$$
 首先进行 Park 变换：
$$
\begin{bmatrix}
u_{d h} \\
u_{q h} 
\end{bmatrix}
=
U_h
\begin{bmatrix}
cos(\omega_h t - \theta_e) \\
sin(\omega_h t - \theta_e)
\end{bmatrix}
$$
由于 $\omega_h$ 很大，可以忽略此时 $\theta_e$ 的变化，代入 PMSM 的基本方程，得到：
$$
\begin{bmatrix}
i_{dh} \\
i_{qh}
\end{bmatrix}
=
\frac{U_h}{\omega_h}
\begin{bmatrix}
\frac{1}{L_d}sin(\omega_h t - \theta_e) \\
-\frac{1}{L_q}cos(\omega_h t - \theta_e)
\end{bmatrix}
$$
进行 Park 反变换，可以得到电流响应：
$$
i_{\alpha \beta h} = I_{hp}e^{j(\omega_h t -\frac{\pi}{2})} + I_{hn}e^{j(- \omega_h t + 2\theta_e + \frac{\pi}{2})}
$$
$I_{hp} = \frac{U_h}{\omega_h L_q L_d}\frac{L_d + L_q}{2}$ 为正序分量，$I_{hn} = \frac{U_h}{\omega_h L_q L_d}\frac{L_q - L_d}{2}$ 为负序分量。仅负序分量包含当前的电机电角度。

### 位置跟踪

- 基波电流与高频电流幅值相差较大，PWM 开关频率远高于注入频率，可以使用带通滤波器进行滤除；
- 使用同步轴系高通滤波器（SFF）滤除正序分量：首先基于以注入频率旋转的坐标系进行坐标变换将正序分量变换为直流分量，用高通滤波器滤除后仅剩余负序分量。
- 控制时，使用低通滤波器得到非高频分量进行控制。

![NULL](./assets/picture_2.jpg)

- 为了提取相位信息中的位置信号，使用锁相环进行位置提取。

## 2. 脉振高频电压注入

脉振高频电压注入是在估计的旋转 $\hat{d}\hat{q}$ 坐标系中的 $\hat{d}$ 轴中注入高频正弦电压，在 $\alpha \beta$ 中以脉振信号响应。

![NULL](./assets/picture_3.jpg)

### 高频电流响应

在真实 $dq$ 坐标系中，电感表示为：
$$
\bold{L_{dq}} = 
\begin{bmatrix}
L_d & 0 \\
0 & L_q \\
\end{bmatrix}
$$
根据 HFI 基本方程：
$$
\begin{bmatrix}
u_d \\
u_q \\
\end{bmatrix} 
=
\begin{bmatrix}
L_d & 0 \\
0 & L_q \\
\end{bmatrix} 
\frac{d}{dt}
\begin{bmatrix}
i_d \\
i_q 
\end{bmatrix}
$$
转换到 $\hat{d}\hat{q}$ 坐标系中为：
$$
\begin{bmatrix}
pi_{\hat{d}} \\
pi_{\hat{q}} \\
\end{bmatrix} 
=
\begin{bmatrix}
cos\tilde{\theta_e} & -sin\tilde{\theta_e}\\
sin\tilde{\theta_e} & cos\tilde{\theta_e}
\end{bmatrix} 
\begin{bmatrix}
\frac{1}{L_d} & 0 \\
0 & \frac{1}{L_q} 
\end{bmatrix} 
\begin{bmatrix}
cos\tilde{\theta_e} & sin\tilde{\theta_e}\\
-sin\tilde{\theta_e} & cos\tilde{\theta_e}
\end{bmatrix} 
\begin{bmatrix}
u_{\hat{d}} \\
u_{\hat{q}} \\
\end{bmatrix}
$$
定义共模电感 $L = \frac{L_d+L_q}{2}$ ，差模电感 $\Delta L = \frac{L_q - L_d}{2}$ 。

代入可得：
$$
\begin{bmatrix}
pi_{\hat{d}} \\
pi_{\hat{q}} \\
\end{bmatrix} 
=
\frac{1}{L^2 - \Delta L^2}
\begin{bmatrix}
L-\Delta L cos\tilde{2\theta_e} & -\Delta L sin\tilde{\theta_e}\\
-\Delta L sin\tilde{\theta_e} & L+\Delta L cos\tilde{2\theta_e}
\end{bmatrix} 
\begin{bmatrix}
u_{\hat{d}} \\
u_{\hat{q}} \\
\end{bmatrix}
$$
如果在 $\hat{q}$ 轴注入高频信号，响应为：
$$
\begin{bmatrix}
i_{\hat{d}} \\
i_{\hat{q}} \\
\end{bmatrix} 
=
\frac{U_hsin\omega_h t}{\omega_h(L^2 - \Delta L^2)}
\begin{bmatrix}
-\Delta L sin\tilde{\theta_e}\\
L+\Delta L cos\tilde{2\theta_e}
\end{bmatrix}
$$
当角度误差趋于 0 时，$q$ 轴电压响应仍然存在高频分量，使得力矩存在脉动，所以使用 $\hat{d}$ 轴注入法：
$$
u_{\hat{d}} = U_hsin(\omega_h t)
$$
计算可以得到 $\hat{q}$ 轴的电流响应为：
$$
i_{\hat{q}} = -\frac{U_hsin(\omega_h t)}{\omega_h(L^2 - \Delta L^2)}\Delta L sin\tilde{2\theta_e}
$$

### 位置跟踪

使用锁相环进行位置跟踪，首先设计鉴相器环节，考虑到 $i_{\hat{q}}$ 中包含 $\tilde{\theta_e}$ 的信息，所以需要对电流进行解调：
$$
\epsilon = i_{\hat{q}}sin(\omega_h t) = \frac{U_h\Delta L sin\tilde{2\theta_e}}{\omega_h(L^2 - \Delta L^2)}(\frac{1}{2}-\frac{1}{2}cos(2\omega_h t))
$$
使用低通滤波器滤除高频成分可以得到直流量：
$$
LPF(\epsilon) =  \frac{U_h\Delta L sin\tilde{2\theta_e}}{2 \omega_h(L^2 - \Delta L^2)}
$$
$ \tilde{\theta_e} $ 趋于 0 时可以得到线性的 PD 环节。此后只需要使用 PI 环节和 VCO 积分环节即可得到角度估计值 $\hat{\theta_e}$

### 脉振高频电压注入总体框图

![NULL](./assets/picture_4.jpg)

> **仿真注意事项**：
>
> 1. 搭建框架时，注入部分和控制部分分离，变换后在静止坐标系注入，控制部分使用实际的电机速度和电机电角度，注入部分使用估计的电机速度和电机电角度；
> 2. 调整 PLL 带宽（通常很大），当速度误差和角度误差收敛到 0 时，可以将控制部分的电机速度和电机电角度替换为估计值，如果出现不收敛，增大 PLL 带宽（提供快速响应）和减小 FOC 控制带宽（减缓控制波动）。
> 3. 注入频率一般为开关频率的1/10。

![NULL](./assets/picture_5.jpg)

![NULL](./assets/picture_6.jpg)

![NULL](./assets/picture_7.jpg)

## 3. 方波高频电压注入

方波高频电压注入是在估计的旋转 $\hat{d}\hat{q}$ 坐标系中的 $\hat{d}$ 轴中注入高频方波电压。

### 高频电流响应

由下式
$$
\begin{bmatrix}
pi_{\hat{d}} \\
pi_{\hat{q}} \\
\end{bmatrix} 
=
\frac{1}{L^2 - \Delta L^2}
\begin{bmatrix}
L-\Delta L cos\tilde{2\theta_e} & -\Delta L sin\tilde{\theta_e}\\
-\Delta L sin\tilde{\theta_e} & L+\Delta L cos\tilde{2\theta_e}
\end{bmatrix} 
\begin{bmatrix}
u_{\hat{d}} \\
u_{\hat{q}} \\
\end{bmatrix}
$$
当 $\hat{d}$ 轴中注入高频方波电压 $\hat{u_d} = (-1)^nU_h$ 时，得到：
$$
\Delta \hat{i_{qh}} = \Delta T (-1)^n U_h \frac{1}{2}(\frac{1}{L_d}-\frac{1}{L_q})sin\tilde{2\theta_e}
$$

### 位置跟踪

首先需要对响应电流进行滤波，为了尽可能保留高频分量，应考虑使用低通滤波器滤波后的剩余分量。

然后再一个方波周期内求差分：

![NULL](./assets/picture_8.jpg)

使用符号函数 $sgn((-1)^n U_h)$ 进行调制：

![NULL](./assets/picture_9.jpg)

可以得到误差信号：
$$
\epsilon = \frac{U_h\Delta L \Delta T}{L^2 - \Delta L^2}sin\tilde{2\theta_e}
$$
随后使用 PLL 即可得到 $\hat{\theta_e}$ 。

### 方波高频电压注入总体框图

![NULL](./assets/picture_12.jpg)

![NULL](./assets/picture_10.jpg)

![NULL](./assets/picture_11.jpg)

> **仿真注意事项**：
>
> 1. 方波注入频率通常更高，在更低速的情况下表现会更好。一般将注入频率设置为 PWM 开关频率。
