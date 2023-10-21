# STM32 电机驱动 4-4 PMSM FOC算法简介

## 1. 坐标变换

### 克拉克（Clark）变换

### Clark 变换理论

Clark 变换将三相电流矢量转换为两个互相垂直的电流矢量。

![NULL](picture_1.jpg)

> 只需要将三相电流投影到二维坐标平面上即可实现 Clark 变换。
> $$
> I_{\alpha} = i_a - cos60^\circ i_b - cos60^\circ i_c \\
> I_{\beta} = cos30^\circ i_b - cos30^\circ i_c
> $$
> 