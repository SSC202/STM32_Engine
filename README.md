# STM32_Engine
基于 STM32F407VET6 的 STM32 电机驱动学习笔记

## 本库的使用方法

本库是STM32 电机驱动的笔记合集，适用于学习STM32的基础驱动后进行学习。

STM32 基础驱动：[Click Here](https://github.com/SSC202/STM32_Basic)

### 使用此库的前置条件

1. 一定的自动控制理论基础（非必要）；
2. 基础的高等数学和几何基础；
3. STM32 TIM，GPIO，ADC，USART的基本使用（必要）；
4. 基本硬件知识。

### 相关Code和Note说明

| Note                                                         | Note说明                                                     | Code                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| [1_直流有刷电机](https://github.com/SSC202/STM32_Engine/tree/main/Note/1_直流有刷电机) | 直流有刷电机驱动介绍                                         | 1. [直流有刷电机开环驱动实验（编码器测速）](https://github.com/SSC202/STM32_Engine/tree/main/Code/Test_Code/1_BDC/1_BDC_OpenLoop_Driver) 2. 直流有刷电机闭环驱动实验 |
| [2_步进电机](https://github.com/SSC202/STM32_Engine/tree/main/Note/2_步进电机) | 步进电机驱动介绍（开环驱动，加减速算法）                     | 1. [步进电机开环驱动实验](https://github.com/SSC202/STM32_Engine/tree/main/Code/Test_Code/2_Step_Engine/1_Step_Engine_Openloop) 2. [步进电机梯形加减速实验](https://github.com/SSC202/STM32_Engine/tree/main/Code/Test_Code/2_Step_Engine/2_Step_Engine_T_Accel) 3. [步进电机S形加减速实验](https://github.com/SSC202/STM32_Engine/tree/main/Code/Test_Code/2_Step_Engine/3_Step_Engine_S_Accel) 4. 步进电机直线插补实验 5. 步进电机圆弧插补实验 |
| [3_舵机](https://github.com/SSC202/STM32_Engine/tree/main/Note/3_舵机) | 舵机驱动介绍                                                 | [舵机驱动实验](https://github.com/SSC202/STM32_Engine/tree/main/Code/Test_Code/3_Steer_Engine) |
| [4_直流无刷电机](https://github.com/SSC202/STM32_Engine/tree/main/Note/4_直流无刷电机) | 直流无刷电机驱动介绍（六步换相算法BLDC，FOC算法PMSM/BLDC）（使用STM32G4） | 1. [BLDC 六步换相开环驱动实验（霍尔编码器测速）](https://github.com/SSC202/STM32_Engine/tree/main/Code/Test_Code/4_BLDC%20PMSM/1_BLDC_OpenLoop/HALL_GPIO) 2. [BLDC 六步换相闭环驱动实验](https://github.com/SSC202/STM32_Engine/tree/main/Code/Test_Code/4_BLDC%20PMSM/2_BLDC_Loop) 3. [PMSM FOC开环驱动实验](https://github.com/SSC202/STM32_Engine/tree/main/Code/Test_Code/4_BLDC%20PMSM/3_PMSM_OpenLoop) 4. PMSM FOC闭环驱动实验 |
| [5_底盘运动学模型](https://github.com/SSC202/STM32_Engine/tree/main/Note/5_底盘运动学模型) | 底盘运动学模型介绍                                           | 1.[麦克纳姆轮四轮底盘驱动实验](https://github.com/SSC202/STM32_Engine/tree/main/Code/Test_Code/5_Chassis/1_Mecanum_wheel) 2. [全向轮三轮驱动实验](https://github.com/SSC202/STM32_Engine/tree/main/Code/Test_Code/5_Chassis/2_Onimi_wheel) |

### 板级支持包使用说明

| BSP_Bag                                                      | 说明                                         |
| ------------------------------------------------------------ | -------------------------------------------- |
| [Feetech](https://github.com/SSC202/STM32_Engine/tree/main/BSP_Bag/FeeTech) | 飞特舵机驱动库（C版本）                      |
| [DJI](https://github.com/SSC202/STM32_Engine/tree/main/BSP_Bag/DJI) | DJI电机驱动库（旧版仅支持F4，新版支持F4/H7） |

### 模型使用说明

