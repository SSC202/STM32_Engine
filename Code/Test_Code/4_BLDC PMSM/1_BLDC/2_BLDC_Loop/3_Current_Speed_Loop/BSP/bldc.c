#include "bldc.h"
#include "adc.h"
#include "opamp.h"

BLDC_Motor motor;
PID speed_pid;

/***************************宏定义段*********************************/
#define MAX_PWM_DUTY                  (((50000) - 1) * 0.96)                      /* 最大占空比限制 */
#define SPEED_COEFF                   (uint32_t)((20000 / (2 * POLE_PAIRS)) * 60) /* 旋转一圈变化4个信号，2对级永磁体特性，NSNS共4级数，计数频率20000*/
#define FirstOrderRC_LPF(Yn_1, Xn, a) Yn_1 = (1 - a) * Yn_1 + a * Xn;             /* 一阶低通滤波器，Yn:out;Xn:in;a:系数 */

/***************************************** 全局变量定义 *************************************************/
const uint8_t hall_table_cw[6]  = {6, 2, 3, 1, 5, 4}; /* 顺时针旋转表 */
const uint8_t hall_table_ccw[6] = {5, 1, 3, 2, 6, 4}; /* 逆时针旋转表 */

const uint8_t hall_cw_table[12]  = {0x62, 0x23, 0x31, 0x15, 0x54, 0x46, 0x63, 0x21, 0x35, 0x14, 0x56, 0x42};
const uint8_t hall_ccw_table[12] = {0x45, 0x51, 0x13, 0x32, 0x26, 0x64, 0x41, 0x53, 0x12, 0x36, 0x24, 0x65};

int32_t temp_pwm    = 0.0; /* 存放PID计算后的期望值 */
int32_t motor_pwm_s = 0;   /* 存放一阶滤波后的数据 */
/****************************驱动函数段******************************/

/**
 * @brief  U相上桥臂导通，V相下桥臂导通
 * @param  无
 * @retval 无
 */
static void UH_VL(void)
{
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_U_CHANNEL, motor.pwm_duty); /* U相上桥臂PWM */
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_V_CHANNEL, 0);
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_W_CHANNEL, 0);
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_U_PORT, MOTOR_LOW_SIDE_U_PIN, GPIO_PIN_RESET); /* U相下桥臂关闭 */
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_V_PORT, MOTOR_LOW_SIDE_V_PIN, GPIO_PIN_SET);   /* V相下桥臂导通 */
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_W_PORT, MOTOR_LOW_SIDE_W_PIN, GPIO_PIN_RESET); /* W相下桥臂关闭 */
}

/**
 * @brief  U相上桥臂导通，W相下桥臂导通
 * @param  无
 * @retval 无
 */
static void UH_WL(void)
{
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_U_CHANNEL, motor.pwm_duty); /* U相上桥臂PWM */
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_V_CHANNEL, 0);
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_W_CHANNEL, 0);
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_U_PORT, MOTOR_LOW_SIDE_U_PIN, GPIO_PIN_RESET); /* U相下桥臂关闭 */
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_V_PORT, MOTOR_LOW_SIDE_V_PIN, GPIO_PIN_RESET); /* V相下桥臂关闭 */
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_W_PORT, MOTOR_LOW_SIDE_W_PIN, GPIO_PIN_SET);   /* W相下桥臂导通 */
}

/**
 * @brief  V相上桥臂导通，W相下桥臂导通
 * @param  无
 * @retval 无
 */
static void VH_WL(void)
{
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_V_CHANNEL, motor.pwm_duty); /* V相上桥臂PWM */
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_U_CHANNEL, 0);
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_W_CHANNEL, 0);
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_U_PORT, MOTOR_LOW_SIDE_U_PIN, GPIO_PIN_RESET); /* U相下桥臂关闭 */
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_V_PORT, MOTOR_LOW_SIDE_V_PIN, GPIO_PIN_RESET); /* V相下桥臂关闭 */
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_W_PORT, MOTOR_LOW_SIDE_W_PIN, GPIO_PIN_SET);   /* W相下桥臂导通 */
}

/**
 * @brief  V相上桥臂导通，U相下桥臂导通
 * @param  无
 * @retval 无
 */
static void VH_UL(void)
{
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_V_CHANNEL, motor.pwm_duty); /* V相上桥臂PWM */
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_U_CHANNEL, 0);
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_W_CHANNEL, 0);
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_U_PORT, MOTOR_LOW_SIDE_U_PIN, GPIO_PIN_SET);   /* U相下桥臂导通 */
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_V_PORT, MOTOR_LOW_SIDE_V_PIN, GPIO_PIN_RESET); /* V相下桥臂关闭 */
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_W_PORT, MOTOR_LOW_SIDE_W_PIN, GPIO_PIN_RESET); /* W相下桥臂关闭 */
}

/**
 * @brief  W相上桥臂导通，U相下桥臂导通
 * @param  无
 * @retval 无
 */
static void WH_UL(void)
{
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_W_CHANNEL, motor.pwm_duty); /* W相上桥臂PWM */
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_U_CHANNEL, 0);
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_V_CHANNEL, 0);
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_U_PORT, MOTOR_LOW_SIDE_U_PIN, GPIO_PIN_SET);   /* U相下桥臂导通 */
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_V_PORT, MOTOR_LOW_SIDE_V_PIN, GPIO_PIN_RESET); /* V相下桥臂关闭 */
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_W_PORT, MOTOR_LOW_SIDE_W_PIN, GPIO_PIN_RESET); /* W相下桥臂关闭 */
}

/**
 * @brief  W相上桥臂导通，V相下桥臂导通
 * @param  无
 * @retval 无
 */
static void WH_VL(void)
{
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_W_CHANNEL, motor.pwm_duty); /* W相上桥臂PWM */
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_U_CHANNEL, 0);
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_V_CHANNEL, 0);
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_U_PORT, MOTOR_LOW_SIDE_U_PIN, GPIO_PIN_RESET); /* U相下桥臂关闭 */
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_V_PORT, MOTOR_LOW_SIDE_V_PIN, GPIO_PIN_SET);   /* V相下桥臂导通 */
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_W_PORT, MOTOR_LOW_SIDE_W_PIN, GPIO_PIN_RESET); /* W相下桥臂关闭 */
}

/**
 * @brief       获取霍尔传感器引脚状态
 * @retval      霍尔传感器引脚状态
 */
static uint32_t HALL_Get_State(void)
{
    __IO static uint32_t state;
    state = 0;

    if (HAL_GPIO_ReadPin(HALL_A_GPIO_Port, HALL_A_GPIO_Pin) != GPIO_PIN_RESET) /* 霍尔传感器状态获取 */
    {
        state |= 0x01U;
    }
    if (HAL_GPIO_ReadPin(HALL_B_GPIO_Port, HALL_B_GPIO_Pin) != GPIO_PIN_RESET) /* 霍尔传感器状态获取 */
    {
        state |= 0x02U;
    }
    if (HAL_GPIO_ReadPin(HALL_C_GPIO_Port, HALL_C_GPIO_Pin) != GPIO_PIN_RESET) /* 霍尔传感器状态获取 */
    {
        state |= 0x04U;
        motor.hall_single_sta = 1;
    } else
        motor.hall_single_sta = 0;

    return state;
}

/**
 * @brief       电机方向检测函数
 * @param       umotor 电机控制句柄
 * @retval      res 旋转方向
 */
static uint8_t HALL_Check_Dir(BLDC_Motor *umotor)
{
    uint8_t temp, res = HALL_ERROR;
    if ((umotor->step_last <= 6) && (umotor->step_sta <= 6)) {
        temp = ((umotor->step_last & 0x0F) << 4) | (umotor->step_sta & 0x0F);
        if ((temp == hall_ccw_table[0]) || (temp == hall_ccw_table[1]) ||
            (temp == hall_ccw_table[2]) || (temp == hall_ccw_table[3]) ||
            (temp == hall_ccw_table[4]) || (temp == hall_ccw_table[5])) {
            res = CCW;
        } else if ((temp == hall_cw_table[0]) || (temp == hall_cw_table[1]) ||
                   (temp == hall_cw_table[2]) || (temp == hall_cw_table[3]) ||
                   (temp == hall_cw_table[4]) || (temp == hall_cw_table[5])) {
            res = CW;
        }
    }
    return res;
}

/**
 * @brief       检测输入信号是否发生变化
 * @param       val :输入信号
 * @note        测量速度使用，获取输入信号状态翻转情况，计算速度
 * @retval      0 计算高电平时间，1 计算低电平时间，2 信号未改变
 */
static uint8_t HALL_Edge(uint8_t val)
{
    /* 主要是检测val信号从0 - 1 在从 1 - 0的过程，即高电平所持续的过程 */
    static uint8_t oldval = 0;
    if (oldval != val) {
        oldval = val;
        if (val == 0)
            return 0;
        else
            return 1;
    }
    return 2;
}

typedef void (*pctr)(void);
/*  六步换向函数指针数组 */
pctr pfunclist[6] =
    {
        &UH_WL, &VH_UL, &VH_WL,
        &WH_VL, &UH_VL, &WH_UL};

/**
 * @brief       定时器中断回调
 * @param       htim:定时器句柄
 * @retval      无
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    int16_t speed    = 0; /* 临时速度存储 */
    uint8_t bldc_dir = 0; /* 方向 */
    if (htim->Instance == SAMPLE_TIMER) {
        // 六步换相
        if (motor.run_flag == RUN) {
            if (motor.dir == CW) /* 正转 */
            {
                motor.step_sta = HALL_Get_State(); /* 顺序6,2,3,1,5,4 */
            } else                                 /* 反转 */
            {
                motor.step_sta = 7 - HALL_Get_State(); /* 顺序5,1,3,2,6,4 。使用7减完后可与数组pfunclist_m1对应上顺序 实际霍尔值为：2,6,4,5,1,3*/
            }

            if ((motor.step_sta <= 6) && (motor.step_sta >= 1)) /* 判断霍尔组合值是否正常 */
            {
                pfunclist[motor.step_sta - 1](); /* 通过数组成员查找对应的函数指针 */

            } else /* 霍尔传感器错误、接触不良、断开等情况 */
            {
                BLDC_Motor_Stop();
                motor.run_flag = STOP;
            }
        }
        // 速度计算
        motor.count_j++;                                        /* 计算速度专用计数值 */
        motor.hall_sta_edge = HALL_Edge(motor.hall_single_sta); /* 检测单个霍尔信号的变化 */
        if (motor.hall_sta_edge == 0)                           /* 统计单个霍尔信号的高电平时间，当只有一对级的时候，旋转一圈为一个完整脉冲。一高一低相加即旋转一圈所花的时间*/
        {
            /*计算速度*/
            if (motor.dir == CW)
                speed = (SPEED_COEFF / motor.count_j);
            else
                speed = -(SPEED_COEFF / motor.count_j);
            FirstOrderRC_LPF(motor.speed, speed, 0.2379f); /* 一阶滤波 */
            motor.no_single = 0;
            motor.count_j   = 0;
        }
        if (motor.hall_sta_edge == 1) /* 当采集到下降沿时数据清0 */
        {
            motor.no_single = 0;
            motor.count_j   = 0;
        }
        if (motor.hall_sta_edge == 2) /* 霍尔值一直不变代表未换向 */
        {
            motor.no_single++; /* 不换相时间累计 超时则判定速度为0 */

            if (motor.no_single > 15000) {

                motor.no_single = 0;
                motor.speed     = 0; /* 超时换向 判定为停止 速度为0 */
            }
        }
        // 位置记录
        if (motor.step_last != motor.step_sta) {
            bldc_dir = HALL_Check_Dir(&motor);
            if (bldc_dir == CCW) {
                motor.pos -= 1;
            } else if (bldc_dir == CW) {
                motor.pos += 1;
            }
            motor.step_last = motor.step_sta;
        }
        // PID 控制
        temp_pwm = PID_Cal(&speed_pid, motor.speed);    /* PID控制算法，输出期望值 */
        FirstOrderRC_LPF(motor_pwm_s, temp_pwm, 0.085); /* 一阶滤波 */
        if (motor_pwm_s < -47999) {
            motor_pwm_s = -47999;
        }
        if (motor_pwm_s > 47999) {
            motor_pwm_s = 47999;
        }
        if (motor_pwm_s < 0) /* 判断正负值 */
        {
            motor.pwm_duty = -motor_pwm_s;
        } else {
            motor.pwm_duty = motor_pwm_s;
        }
    }
}

/**
 * @brief 注入组转换完成回调函数
 */
void HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    uint32_t temp_current_u;
    uint32_t temp_current_v;
    uint32_t temp_current_w;
    if (hadc == &hadc1) {
        temp_current_u = hadc1.Instance->JDR1;
        FirstOrderRC_LPF(temp_current_u, temp_current_u, 0.85);
        motor.current_u = ((float)(temp_current_u - 0x7ef)) * 0.0193359375f; // 0.0193359375为运放增益，7ef,7f5,7e8为运放直流偏置
        temp_current_v  = hadc1.Instance->JDR2;
        FirstOrderRC_LPF(temp_current_v, temp_current_v, 0.85);
        motor.current_v = ((float)(temp_current_v - 0x7f5)) * 0.0193359375f;
    } else if (hadc == &hadc2) {
        temp_current_w = hadc2.Instance->JDR1;
        FirstOrderRC_LPF(temp_current_w, temp_current_w, 0.85);
        motor.current_w = ((float)(temp_current_w - 0x7e8)) * 0.0193359375f;
    }
}
/****************************用户函数段******************************/
/**
 * @brief  关闭电机运转
 * @param  无
 * @retval 无
 */
void BLDC_Motor_Stop(void)
{
    /* 关闭PWM输出 */
    HAL_TIM_PWM_Stop(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_U_CHANNEL);
    HAL_TIM_PWM_Stop(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_V_CHANNEL);
    HAL_TIM_PWM_Stop(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_W_CHANNEL);
    /* 上下桥臂全部关断 */
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_U_CHANNEL, 0);
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_V_CHANNEL, 0);
    __HAL_TIM_SET_COMPARE(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_W_CHANNEL, 0);
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_U_PORT, MOTOR_LOW_SIDE_U_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_V_PORT, MOTOR_LOW_SIDE_V_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(MOTOR_LOW_SIDE_W_PORT, MOTOR_LOW_SIDE_W_PIN, GPIO_PIN_RESET);
    motor.run_flag = STOP;
    motor.speed    = 0;
    motor_pwm_s    = 0;
    motor.pwm_duty = 0;
}

/**
 * @brief  开启电机运转
 * @param  无
 * @retval 无
 */
void BLDC_Motor_Start(void)
{
    /* 使能PWM输出 */
    HAL_TIM_PWM_Start(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_U_CHANNEL);
    HAL_TIM_PWM_Start(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_V_CHANNEL);
    HAL_TIM_PWM_Start(MOTOR_HIGH_SIDE_TIMER_HANDLE, MOTOR_HIGH_SIDE_W_CHANNEL);
    BLDC_Motor_Current_Read();
}

/**
 * @brief       速度控制函数
 * @param       dir     电机方向
 * @param       speed   速度
 * @retval      无
 */
void BLDC_Motor_Speed_Set(int32_t speed)
{
    if (speed > 0) {
        motor.dir = CW;
    } else if (speed < 0) {
        motor.dir = CCW;
    }
    speed_pid.SetPoint = speed;
}

/**
 * @brief       无刷电机初始化
 * @retval      无
 */
void BLDC_Motor_Init(void)
{
    // 运放使能
    HAL_OPAMP_Start(&hopamp1);
    HAL_OPAMP_Start(&hopamp2);
    HAL_OPAMP_Start(&hopamp3);
    // ADC校验
    HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);
    HAL_ADCEx_Calibration_Start(&hadc2, ADC_SINGLE_ENDED);
    PID_Init(&speed_pid, 10.0f, 0.01f, 2.0f);
    HAL_TIM_Base_Start_IT(SAMPLE_TIMER_HANDLE);
}

/**
 * @brief       无刷电机电流读取
 * @retval      无
 */
void BLDC_Motor_Current_Read(void)
{
    // 注入组转换使能
    HAL_ADCEx_InjectedStart_IT(&hadc1);
    HAL_ADCEx_InjectedStart_IT(&hadc2);
    // 规则组转换使能
    HAL_ADC_Start(&hadc1);
    HAL_ADC_Start(&hadc2);
    motor.current_s = HAL_ADC_GetValue(&hadc2) * 0.02494726f;
}