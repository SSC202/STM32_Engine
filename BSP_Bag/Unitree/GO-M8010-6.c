/**
 * @file GO-M8010-6.c
 * @author Liam (quan.2003@outlook.com)
 * @brief Unitree_M8010-6电机驱动端代码
 * @version 1.0
 * @data 2023-10-10
 *
 * @copyright Copyright (c) 2023
 */

#include "motor_control.h"
#include "crc_ccitt.h"
#include "Unitree_user.h"

#define SATURATE(_IN, _MIN, _MAX) {\
 if (_IN < _MIN)\
 _IN = _MIN;\
 else if (_IN > _MAX)\
 _IN = _MAX;\
 }

/**
 * 发送数据预处理
 * @param motor_s 电机发送数据包结构体指针
 * @return
 */
int modify_data(MOTOR_send *motor_s)
{
    motor_s->hex_len = 17;
    motor_s->motor_send_data.head[0] = 0xFE;
    motor_s->motor_send_data.head[1] = 0xEE;
	
		SATURATE(motor_s->id,   0,    15);
		SATURATE(motor_s->mode, 0,    7);
		SATURATE(motor_s->K_P,  0.0f,   25.599f);
		SATURATE(motor_s->K_W,  0.0f,   25.599f);
		SATURATE(motor_s->T,   -127.99f,  127.99f);
		SATURATE(motor_s->W,   -804.00f,  804.00f);
		SATURATE(motor_s->Pos, -411774.0f,  411774.0f);

    motor_s->motor_send_data.mode.id   = motor_s->id;
    motor_s->motor_send_data.mode.status  = motor_s->mode;
    motor_s->motor_send_data.comd.k_pos  = motor_s->K_P/25.6f*32768;
    motor_s->motor_send_data.comd.k_spd  = motor_s->K_W/25.6f*32768;
    motor_s->motor_send_data.comd.pos_des  = motor_s->Pos/6.2832f*32768;
    motor_s->motor_send_data.comd.spd_des  = motor_s->W/6.2832f*256;
    motor_s->motor_send_data.comd.tor_des  = motor_s->T*256;
    motor_s->motor_send_data.CRC16 = crc_ccitt(0, (uint8_t *)&motor_s->motor_send_data, 15);
    return 0;
}

/**
 * 接收数据解包函数
 * @param motor_r
 * @return
 */
int extract_data(MOTOR_recv *motor_r)
{
    if(motor_r->motor_recv_data.CRC16 !=
        crc_ccitt(0, (uint8_t *)&motor_r->motor_recv_data, 14)){
        // printf("[WARNING] Receive data CRC error");
        motor_r->correct = 0;
        return motor_r->correct;
    }
    else
		{
        motor_r->motor_id = motor_r->motor_recv_data.mode.id;
        motor_r->mode = motor_r->motor_recv_data.mode.status;
        motor_r->Temp = motor_r->motor_recv_data.fbk.temp;
        motor_r->MError = motor_r->motor_recv_data.fbk.MError;
        motor_r->W = ((float)motor_r->motor_recv_data.fbk.speed/256)*6.2832f/6.33;
        motor_r->T = ((float)motor_r->motor_recv_data.fbk.torque) / 256;
        motor_r->Pos = 6.2832f*((float)motor_r->motor_recv_data.fbk.pos) / 32768 /6.33;
				motor_r->footForce = motor_r->motor_recv_data.fbk.force;
				motor_r->correct = 1;
        return motor_r->correct;
    }
}
/*
HAL_StatusTypeDef SERVO_Send_recv(MOTOR_send *pData, MOTOR_recv *rData)
{
    uint16_t rxlen = 0;

    modify_data(pData);
    
		SET_485_DE_UP();
		SET_485_RE_UP();
    HAL_UART_Transmit(&huart6, (uint8_t *)pData, sizeof(pData->motor_send_data), 10);
		

		SET_485_RE_DOWN();
		SET_485_DE_DOWN();
    HAL_UARTEx_ReceiveToIdle(&huart6, (uint8_t *)rData, sizeof(rData->motor_recv_data), &rxlen, 100);
    HAL_UART_Transmit(&huart8,(uint8_t *)rData,sizeof(rData->motor_recv_data),0xfff);

    if(rxlen == 0)

      return HAL_TIMEOUT;

    if(rxlen != sizeof(rData->motor_recv_data))
			return HAL_ERROR;

    uint8_t *rp = (uint8_t *)&rData->motor_recv_data;
    if(rp[0] == 0xFE && rp[1] == 0xEE)
    {
        rData->correct = 1;
        extract_data(rData);
        return HAL_OK;
    }
    
    return HAL_BUSY;
}
*/

/**
 * 发送并接收函数
 * @param pData 待发送数据结构体
 * @param rData 待接收数据结构体
 * @return 如果成功接收 返回HAL_OK  否则返回HAL_ERROR
 */
HAL_StatusTypeDef SERVO_Send_recv(UART_HandleTypeDef *usartx,MOTOR_send *pData, MOTOR_recv *rData)
{
    modify_data(pData);

    SET_485_DE_UP();
    SET_485_RE_UP();
    HAL_UART_Transmit(usartx, (uint8_t *)pData, sizeof(pData->motor_send_data), 10);


    SET_485_RE_DOWN();
    SET_485_DE_DOWN();

    HAL_UARTEx_ReceiveToIdle_DMA(usartx, (uint8_t *)rData, sizeof(rData->motor_recv_data));
    //HAL_UART_Transmit(&huart8,(uint8_t *)rData,sizeof(rData->motor_recv_data),0xff);  调试

    uint8_t *rp = (uint8_t *)&rData->motor_recv_data;
    if(rp[0] == 0xFD && rp[1] == 0xEE)
    {
        rData->correct = 1;
        extract_data(rData);
        return HAL_OK;
    }

    return HAL_ERROR;
}
