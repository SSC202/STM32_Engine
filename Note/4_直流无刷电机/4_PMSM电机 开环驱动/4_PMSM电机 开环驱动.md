# STM32 电机驱动 4-4 PMSM电机的VF驱动

## 1. STM32高级定时器

![NULL](picture_1.jpg)

### PWM互补输出

通常的，为了能够使用七段式SVPWM，通常使用STM32定时器的中心对齐模式PWM。

### 死区时间计算

