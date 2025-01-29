#ifndef WTR_VESC_H 
#define WTR_VESC_H


#include "WTRconfig.h"



#ifndef wtrcfg_VESC_MODE_CAN
#define __VESC_MODE_CAN 1
#endif

#ifndef wtrcfg_VESC_MODE_UART 
#define __VESC_MODE_UART 1
#endif

#if (__VESC_MODE_CAN ==1) || (wtrcfg_VESC_MODE_CAN == 1)
#define __VESC_CAN_ENABLE
#include "can.h"
#endif 

#if (__VESC_MODE_UART==1)  || (wtrcfg_VESC_MODE_UART == 1)
#define __VESC_UART_ENABLE
#include "usart.h"
#endif 

#if defined(__VESC_CAN_ENABLE) || defined(__VESC_UART_ENABLE)
#define __VESC_ENABLE
#endif

#ifndef __VESC_ENABLE
#error vesc disable, please select an interface to communicate  
#endif



#ifndef wtrcfg_VESC_COMMAND_DUTY_MAX
#define wtrcfg_VESC_COMMAND_DUTY_MAX 100
#endif 
#ifndef wtrcfg_VESC_COMMAND_CURRENT_MAX
#define wtrcfg_VESC_COMMAND_CURRENT_MAX 10
#endif 
#ifndef wtrcfg_VESC_COMMAND_POS_MAX
#define wtrcfg_VESC_COMMAND_POS_MAX 360
#endif 
#ifndef wtrcfg_VESC_COMMAND_ERPM_MAX
#define wtrcfg_VESC_COMMAND_ERPM_MAX 20000
#endif 
#ifndef wtrcfg_VESC_UART_TIMEOUT 
#define wtrcfg_VESC_UART_TIMEOUT 0xff
#endif
#ifdef __VESC_UART_ENABLE
typedef enum {
COMM_FW_VERSION = 0,
COMM_JUMP_TO_BOOTLOADER,
COMM_ERASE_NEW_APP,
COMM_WRITE_NEW_APP_DATA,
COMM_GET_VALUES,
COMM_SET_DUTY,
COMM_SET_CURRENT,
COMM_SET_CURRENT_BRAKE,
COMM_SET_RPM,
COMM_SET_POS,
COMM_SET_DETECT,
COMM_SET_SERVO_POS,
COMM_SET_MCCONF,
COMM_GET_MCCONF,
COMM_GET_MCCONF_DEFAULT,
COMM_SET_APPCONF,
COMM_GET_APPCONF,
COMM_GET_APPCONF_DEFAULT,
COMM_SAMPLE_PRINT,
COMM_TERMINAL_CMD,
COMM_PRINT,
COMM_ROTOR_POSITION,
COMM_EXPERIMENT_SAMPLE,
COMM_DETECT_MOTOR_PARAM,
COMM_DETECT_MOTOR_R_L,
COMM_DETECT_MOTOR_FLUX_LINKAGE,
COMM_DETECT_ENCODER,
COMM_DETECT_HALL_FOC,
COMM_REBOOT,
COMM_ALIVE,
COMM_GET_DECODED_PPM,
COMM_GET_DECODED_ADC,
COMM_GET_DECODED_CHUK,
COMM_FORWARD_CAN,
COMM_SET_CHUCK_DATA,
COMM_CUSTOM_APP_DATA
}
COMM_PACKET_ID;
#endif

#ifdef __VESC_CAN_ENABLE
typedef enum {
	CAN_PACKET_SET_DUTY = 0,
	CAN_PACKET_SET_CURRENT,
	CAN_PACKET_SET_CURRENT_BRAKE,
	CAN_PACKET_SET_RPM,
	CAN_PACKET_SET_POS,
	CAN_PACKET_FILL_RX_BUFFER,
	CAN_PACKET_FILL_RX_BUFFER_LONG,
	CAN_PACKET_PROCESS_RX_BUFFER,
	CAN_PACKET_PROCESS_SHORT_BUFFER,
	CAN_PACKET_STATUS,
	CAN_PACKET_SET_CURRENT_REL,
	CAN_PACKET_SET_CURRENT_BRAKE_REL,
	CAN_PACKET_SET_CURRENT_HANDBRAKE,
	CAN_PACKET_SET_CURRENT_HANDBRAKE_REL
}
CAN_PACKET_ID;
#endif


typedef enum {
FAULT_CODE_NONE = 0,
FAULT_CODE_OVER_VOLTAGE,
FAULT_CODE_UNDER_VOLTAGE,
FAULT_CODE_DRV8302,
FAULT_CODE_ABS_OVER_CURRENT,
FAULT_CODE_OVER_TEMP_FET,
FAULT_CODE_OVER_TEMP_MOTOR,
FAULT_CODE_END
}
mc_fault_code;

typedef struct{
	uint8_t error_code;
	uint8_t controller_id;
	
	float duty;
	float pos;
	float current;
	float erpm;

#ifdef __VESC_UART_ENABLE	
	int32_t tachometer;
	int32_t tachometer_abs;

	float current_input;
	float voltage_input;
	
	float id;
	float iq;
	float temp_fet;
	float temp_motor;
	float A_hours_draw;
	float A_hours_charge;
	float Watt_hours_draw;
	float Watt_hours_charge;
#endif
}
MOTOR_PROPERTY;


typedef struct{
#ifdef __VESC_CAN_ENABLE	
	CAN_HandleTypeDef * hcann;
	uint8_t controller_id;
#endif
#ifdef __VESC_UART_ENABLE
	UART_HandleTypeDef * huartn;
	
#endif
}VESC_t;


#ifdef __VESC_UART_ENABLE
HAL_StatusTypeDef uart_send_command(VESC_t *hvesc, const COMM_PACKET_ID id, float value, uint32_t timeout)；
void uart_get_command(uint8_t rxbuf[],const COMM_PACKET_ID id, void *data);

#define VESC_UART_SET_DUTY(hvesc,duty) uart_send_command(hvesc,COMM_SET_DUTY,duty,wtrcfg_VESC_UART_TIMEOUT)
#define VESC_UART_SET_CURRNENT(hvesc,current) uart_send_command(hvesc,COMM_SET_CURRENT,current,wtrcfg_VESC_UART_TIMEOUT)
#define VESC_UART_SET_ERPM(hvesc,rpm) uart_send_command(hvesc,COMM_SET_RPM,rpm,wtrcfg_VESC_UART_TIMEOUT)
#define VESC_UART_SET_POS(hvesc,pos) uart_send_command(hvesc,COMM_SET_POS,pos,wtrcfg_VESC_UART_TIMEOUT)
#endif


#ifdef __VESC_CAN_ENABLE	
HAL_StatusTypeDef can_send_command(VESC_t *hvesc, const CAN_PACKET_ID id, float value,int all);
void can_get_command(CAN_RxHeaderTypeDef  *RxHeader,uint8_t rxbuf[], void *data);

#define VESC_CAN_SET_DUTY(vesc,duty) 					can_send_command(vesc,CAN_PACKET_SET_DUTY,duty,0)
#define VESC_CAN_SET_CURRENT(vesc,current)  	can_send_command(vesc,CAN_PACKET_SET_CURRENT,current,0)
#define VESC_CAN_SET_ERPM(vesc,erpm)				  can_send_command(vesc,CAN_PACKET_SET_RPM,erpm,0)
#define VESC_CAN_SET_POS(vesc,pos) 				 	  can_send_command(vesc,CAN_PACKET_SET_POS,pos,0)

#endif

#endif



