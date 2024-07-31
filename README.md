# STM32_Engine
电机驱动学习笔记

## 本库的使用方法

本库是电机及底盘驱动的笔记合集，适用于学习STM32的基础驱动后进行学习。

V1.0 版本停止更新，V2.0 继续更新并加入永磁同步电机(Odrive,VESC,SimpleFOC)的驱动教程。

STM32 基础驱动：[Click Here](https://github.com/SSC202/STM32_Basic)

### 使用此库的前置条件


1. 基础的高等数学和几何基础；
2. STM32 TIM，GPIO，ADC，USART的基本使用（必要）；
3. 基本硬件知识。
4. (V2.0)经典控制理论基础；
5. (V2.0)电力电子技术和电机学知识；
6. (V2.0)Matlab仿真基础。

### 文件夹结构

```
.
|--  BSP_Bag    // 板级支持包
|--  Code       // 测试例程
|--  Note       // 笔记
|--  Handbook   // 官方手册
```



### 板级支持包使用说明

| BSP_Bag                                                      | 说明                                         |
| ------------------------------------------------------------ | -------------------------------------------- |
| [Feetech](https://github.com/SSC202/STM32_Engine/tree/main/BSP_Bag/FeeTech) | 飞特舵机驱动库（C版本）                      |
| [DJI](https://github.com/SSC202/STM32_Engine/tree/main/BSP_Bag/DJI) | DJI电机驱动库（支持F4/H7） |
| [AK](https://github.com/SSC202/STM32_Engine/tree/main/BSP_Bag/AK) | CubeMars AK系列电机驱动库（支持F4） |



