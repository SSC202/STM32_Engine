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
4. (V2.0)经典控制理论和现代控制理论基础；
5. (V2.0)电力电子技术和电机学知识；
6. (V2.0)Matlab/Simulink仿真基础；
7. (V2.0)信号分析和处理基础，PLL设计基础。

### 文件夹结构

```
.
|--  BSP_Bag    // 板级支持包
|--  Code       // 测试例程
|--  Note       // 笔记
|--  Handbook   // 官方手册
```

### 笔记说明

| Note                                                         | 说明                                   |
| ------------------------------------------------------------ | -------------------------------------- |
| [1_直流电机驱动](https://github.com/SSC202/STM32_Engine/tree/V2.0/Note) | 直流电机原理和驱动笔记                 |
| [2_舵机驱动](https://github.com/SSC202/STM32_Engine/tree/V2.0/Note/2_舵机) | 舵机原理和驱动笔记                     |
| [3_步进电机驱动](https://github.com/SSC202/STM32_Engine/tree/V2.0/Note/3_步进电机) | 步进电机原理和驱动笔记                 |
| [4_BLDC和PMSM驱动](https://github.com/SSC202/STM32_Engine/tree/V2.0/Note/4_永磁同步电机) | PMSM原理和FOC原理，FOC固件笔记         |
| [5_底盘运动学模型](https://github.com/SSC202/STM32_Engine/tree/V2.0/Note/5_底盘运动学模型) | 底盘运动学解算                         |
| [6_底盘控制](https://github.com/SSC202/STM32_Engine/tree/V2.0/Note/6_底盘控制/2_底盘路径跟踪) | 底盘定位，路径规划和路径跟踪（未开始） |

### 板级支持包使用说明

| BSP_Bag                                                      | 说明                                         |
| ------------------------------------------------------------ | -------------------------------------------- |
| [Feetech](https://github.com/SSC202/STM32_Engine/tree/main/BSP_Bag/FeeTech) | 飞特舵机驱动库（C版本）                      |
| [DJI](https://github.com/SSC202/STM32_Engine/tree/main/BSP_Bag/DJI) | DJI电机驱动库（支持F4/H7） |
| [AK](https://github.com/SSC202/STM32_Engine/tree/main/BSP_Bag/AK) | CubeMars AK系列电机驱动库（支持F4） |



