# STM32 电机驱动 4-3 PMSM FOC算法简介

## 1. 坐标变换

### 克拉克（Clark）变换

#### Clark 变换理论

Clark 变换将三相电流矢量转换为两个互相垂直的电流矢量。

![NULL](picture_1.jpg)

> 只需要将三相电流投影到二维坐标平面上即可实现 Clark 变换。
> $$
> I_{\alpha} = i_a - cos60^\circ i_b - cos60^\circ i_c \\
> I_{\beta} = cos30^\circ i_b - cos30^\circ i_c
> $$

$$
\left[\begin{matrix}
i_\alpha \\
i_\beta
\end{matrix}\right] = P
\left[\begin{matrix}
1 & -\frac{1}{2} & -\frac{1}{2} \\
0 & \frac{\sqrt{3}}{2} & -\frac{\sqrt{3}}{2}
\end{matrix}\right]
\left[\begin{matrix}
i_a \\ 
i_b \\
i_c
\end{matrix}\right]
$$

$P = \frac{2}{3}$时为等幅值变换，$P = \frac{\sqrt{3}}{2}$为等功率变换。

![NULL](picture_2.jpg)

为了使线性区调制比范围是 $[0,1]$ ，通常定义调制比为线电压幅值与直流母线电压的比值，如果采用等幅值 Clark 变换，坐标变换将不会改变电流的幅值。与等功率变换相比，等功率变换调制比范围将扩大，超出线性调制区原来的范围。所以采用等功率变换时，电流控制器输出的指令电压需要再乘以$P = \sqrt{\frac{2}{3}}$，才能给逆变器进行 PWM 调制。

为节省电流采样成本，通常使用基尔霍夫定律进行化简：
$$
i_a + i_b + i_c = 0
$$
则有：
$$
\left[\begin{matrix}
i_\alpha \\
i_\beta
\end{matrix}\right] = 
\left[\begin{matrix}
1 & 0 \\
\frac{1}{\sqrt{3}} & \frac{2}{\sqrt{3}} 
\end{matrix}\right]
\left[\begin{matrix}
i_a \\ i_b
\end{matrix}\right]
$$

#### Clark Simulink仿真和代码生成

### 帕克 （Park） 变换和反变换

#### Park 变换和反变换理论

Park 变换将定子静止的$\alpha$和$\beta$坐标系转换为固连在转子上的$d$和$q$坐标系，便于描述电机旋转时的电流规律。$d$轴设置为转子N级，$q$轴垂直于转子。$dq$坐标系相对于$\alpha \beta$坐标系旋转的角度为电角度。

![NULL](picture_3.jpg)

Park 变换公式如下：
$$
\left[\begin{matrix}
i_d \\
i_q
\end{matrix}\right] = 
\left[\begin{matrix}
cos\theta & sin\theta \\
-sin\theta & cos\theta
\end{matrix}\right]
\left[\begin{matrix}
i_\alpha \\ i_\beta
\end{matrix}\right]
$$
相对的，Park 反变换公式为：
$$
\left[\begin{matrix}
i_\alpha \\
i_\beta
\end{matrix}\right] = 
\left[\begin{matrix}
cos\theta & -sin\theta \\
sin\theta & cos\theta
\end{matrix}\right]
\left[\begin{matrix}
i_d \\ i_q
\end{matrix}\right]
$$

$i_q$产生电机的力矩，是电机力矩环（电流环）的驱动目标，$i_d$产生电机的热量，通常需要控制为0。

####  Park Simulink 仿真和代码生成

## 2. SPWM 和 SVPWM

### SPWM 单相正弦波调制

### SVPWM 三相正弦波调制

由三相逆变器的六个开关元件组成的特定开关模式，使输出电压波形尽可能接近于理想的正弦波形。SVPWM计算的是三相逆变器的六个开关何时导通，何时切断。

![NULL](picture_4.gif)

#### 空间矢量

ABC三个桥臂分别有0,1两种状态，0是下管开通上管关断，1是上管开通下管关断。（同一个半桥不可同时导通上下桥臂）

即有6个非零矢量（001，010，011，100，101，110）和两个零矢量（000，111）。

对于其中的非零矢量，假定三相阻抗一致，则由分压可得下列矢量表：

| $S_a$ | $S_b$ | $S_c$ | 矢量符号 | $U_a$                | $U_b$                | $U_c$                |
| ----- | ----- | ----- | -------- | -------------------- | -------------------- | -------------------- |
| 0     | 0     | 0     | $U_0$    | 0                    | 0                    | 0                    |
| 1     | 0     | 0     | $U_4$    | $\frac{2}{3}V_{cc}$  | $-\frac{1}{3}V_{cc}$ | $-\frac{1}{3}V_{cc}$ |
| 1     | 1     | 0     | $U_6$    | $\frac{1}{3}V_{cc}$  | $\frac{1}{3}V_{cc}$  | $-\frac{2}{3}V_{cc}$ |
| 0     | 1     | 0     | $U_2$    | $-\frac{1}{3}V_{cc}$ | $\frac{2}{3}V_{cc}$  | $-\frac{1}{3}V_{cc}$ |
| 0     | 1     | 1     | $U_3$    | $-\frac{2}{3}V_{cc}$ | $\frac{2}{3}V_{cc}$  | $\frac{2}{3}V_{cc}$  |
| 0     | 0     | 1     | $U_1$    | $-\frac{1}{3}V_{cc}$ | $-\frac{1}{3}V_{cc}$ | $\frac{2}{3}V_{cc}$  |
| 1     | 0     | 1     | $U_5$    | $\frac{1}{3}V_{cc}$  | $-\frac{2}{3}V_{cc}$ | $\frac{1}{3}V_{cc}$  |
| 1     | 1     | 1     | $U_7$    | 0                    | 0                    | 0                    |

由此可以将电压矢量分为六个扇区：

![NULL](picture_5.jpg)

#### 扇区判断

通过$U_\beta$和$U_\alpha$之间的角度关系，可以将任意的电压矢量确定在某一扇区：

| 扇区 | 角度条件                                                   | 比例条件                               |
| ---- | ---------------------------------------------------------- | -------------------------------------- |
| 1    | $0 < arctan(\frac{U_\beta}{U_\alpha}) < 60^\circ$          | $0<\frac{U_\beta}{U_\alpha}<\sqrt{3}$  |
| 2    | $60^\circ < arctan(\frac{U_\beta}{U_\alpha}) < 120^\circ$  | $|\frac{U_\beta}{U_\alpha}|>\sqrt{3}$  |
| 3    | $120^\circ < arctan(\frac{U_\beta}{U_\alpha}) < 180^\circ$ | $0>\frac{U_\beta}{U_\alpha}>-\sqrt{3}$ |
| 4    | $180^\circ < arctan(\frac{U_\beta}{U_\alpha}) < 240^\circ$ | $0<\frac{U_\beta}{U_\alpha}<\sqrt{3}$  |
| 5    | $240^\circ < arctan(\frac{U_\beta}{U_\alpha}) < 300^\circ$ | $|\frac{U_\beta}{U_\alpha}|>\sqrt{3}$  |
| 6    | $300^\circ < arctan(\frac{U_\beta}{U_\alpha}) < 360^\circ$ | $0>\frac{U_\beta}{U_\alpha}>-\sqrt{3}$ |

计算以上表格，进行条件简化：

> - $U_1$ = $U_\beta$
> - $U_2 = \frac{\sqrt{3}}{2}U_\alpha - \frac{1}{2}U_\beta$
> - $U_3 = - \frac{\sqrt{3}}{2}U_\alpha - \frac{1}{2}U_\beta$
>
> 令A，B，C，取值条件如下：
>
> - $U_1 > 0$，$A = 1$，反之为0；
> - $U_2 > 0$，$B = 1$，反之为0；
> - $U_3 > 0$，$C = 1$，反之为0；
>
> $N = 4C + 2B + A$，则扇区确定条件如下：
>
> | 扇区 | A    | B    | C    | N    |
> | ---- | ---- | ---- | ---- | ---- |
> | 1    | 1    | 1    | 0    | 3    |
> | 2    | 1    | 0    | 0    | 1    |
> | 3    | 1    | 0    | 1    | 5    |
> | 4    | 0    | 1    | 1    | 4    |
> | 5    | 0    | 1    | 1    | 6    |
> | 6    | 0    | 0    | 0    | 2    |

#### 扇区发波

- 七段式发波方法

为了减少谐波，采用七段式或五段式的发波方法，以扇区1为例：

![NULL](picture_6.jpg)

注意，每次发波只控制一个桥臂的MOS通断。

发波顺序：0-4-6-7-6-4-0或7-6-4-0-4-6-7。

如果考虑软件的计算方便，每次发波都先发000矢量，中间插入111矢量，那么就要按照图中红色曲线发波。

无论七段式SVPWM还是五段式SVPWM，在一个开关周期内，一个开关都只做一次动作。但是由于七段式在一个周期内比五段式多插入了一个零矢量，导致电流频率是开关频率的两倍。
同时七段式的开关损耗比五段式多了1/3。

- 五段式发波方法：

五段式SVPWM，又被称为DPWM。由于其在一个开关周期内只插入了一个零矢量，是不连续的SVPWM。而在不同扇区内对零矢量的不同选择，导致了DPWM有很多个变种，每个变种对开关管的损耗、相电压的谐波都会造成不同的结果。

1. DPWM有最基本的两条路径，如下图所示：

如果在六个扇区内都选择插入000矢量，那么六个扇区内的矢量分别是6-4-0-4-6，6-2-0-2-6，3-2-0-2-3，3-1-0-1-3,5-1-0-1-5,5-4-0-4-5，如下图蓝色曲线；

如果在六个扇区内都选择插入111矢量，那么六个扇区内的矢量分别是4-6-7-6-4，2-6-7-6-2，2-3-7-3-2，1-3-7-3-1,1-5-7-5-1,4-5-7-5-4，如下图红色曲线；

![NULL](picture_7.jpg)

2. 以上方式会导致MOS管发热不均匀，为解决此问题，采用奇数扇区插入和偶数扇区相反的零矢量：

![NULL](picture_8.jpg)

3. 除了以上几种DPWM之外，还有三次谐波插入法THIPWM，平顶式SVPWM，半频式SVPWM，FFCSVPWM，GDPWM等发波方式。

#### 矢量作用时间计算

以第一扇区为例，按伏秒平衡的原则来合成该扇区内的任意电压矢量。式中$T$为PWM周期，$\frac{T_4}{T}$为$U_4$对应的占空比。

$U_{ref}T = U_4T_4 + U_6T_6 + U_0(T - T_4-T_6)$

以此类推：

| 扇区 | N    | $T_x$                                                        | $T_y$                                                        |
| ---- | ---- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 1    | 3    | $\frac{\sqrt{3}T_S}{U_{dc}}(\frac{\sqrt{3}}{2}U_\alpha - \frac{1}{2}U_\beta)$ | $\frac{\sqrt{3}T_S}{U_{dc}}U_\beta$                          |
| 2    | 1    | $\frac{\sqrt{3}T_S}{U_{dc}}(-\frac{\sqrt{3}}{2}U_\alpha + \frac{1}{2}U_\beta)$ | $\frac{\sqrt{3}T_S}{U_{dc}}(\frac{\sqrt{3}}{2}U_\alpha + \frac{1}{2}U_\beta)$ |
| 3    | 5    | $\frac{\sqrt{3}T_S}{U_{dc}}U_\beta$                          | $ - \frac{\sqrt{3}T_S}{U_{dc}}(\frac{\sqrt{3}}{2}U_\alpha + \frac{1}{2}U_\beta)$ |
| 4    | 4    | $- \frac{\sqrt{3}T_S}{U_{dc}}U_\beta$                        | $\frac{\sqrt{3}T_S}{U_{dc}}(- \frac{\sqrt{3}}{2}U_\alpha + \frac{1}{2}U_\beta)$ |
| 5    | 6    | $- \frac{\sqrt{3}T_S}{U_{dc}}(\frac{\sqrt{3}}{2}U_\alpha + \frac{1}{2}U_\beta)$ | $- \frac{\sqrt{3}T_S}{U_{dc}}(- \frac{\sqrt{3}}{2}U_\alpha + \frac{1}{2}U_\beta)$ |
| 6    | 2    | $\frac{\sqrt{3}T_S}{U_{dc}}(\frac{\sqrt{3}}{2}U_\alpha + \frac{1}{2}U_\beta)$ | $- \frac{\sqrt{3}T_S}{U_{dc}}U_\beta$                        |

#### 矢量切换时间的计算

![NULL](picture_9.jpg)

如图，以第一扇区为例，由于发波需要对称，所以零矢量被均分为两段。

以此类推：

| 扇区 | N    | $T_a$                       | $T_b$                       | $T_c$                       |
| ---- | ---- | --------------------------- | --------------------------- | --------------------------- |
| 1    | 3    | $\frac{T_s - T_x - T_y}{4}$ | $\frac{T_s + T_x - T_y}{4}$ | $\frac{T_s + T_x + T_y}{4}$ |
| 2    | 1    | $\frac{T_s + T_x - T_y}{4}$ | $\frac{T_s - T_x - T_y}{4}$ | $\frac{T_s + T_x + T_y}{4}$ |
| 3    | 5    | $\frac{T_s + T_x + T_y}{4}$ | $\frac{T_s - T_x - T_y}{4}$ | $\frac{T_s + T_x - T_y}{4}$ |
| 4    | 4    | $\frac{T_s + T_x + T_y}{4}$ | $\frac{T_s + T_x - T_y}{4}$ | $\frac{T_s - T_x - T_y}{4}$ |
| 5    | 6    | $\frac{T_s + T_x - T_y}{4}$ | $\frac{T_s + T_x + T_y}{4}$ | $\frac{T_s - T_x - T_y}{4}$ |
| 6    | 2    | $\frac{T_s - T_x - T_y}{4}$ | $\frac{T_s + T_x + T_y}{4}$ | $\frac{T_s + T_x - T_y}{4}$ |

