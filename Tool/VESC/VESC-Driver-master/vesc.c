#include "vesc.h"
#include <math.h>
/**************************************
 * crc校验表
 **************************************/
static const unsigned short crc16_tab[] = { 
0x0000, 0x1021, 0x2042, 0x3063, 0x4084,
0x50a5, 0x60c6, 0x70e7, 0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad,
0xe1ce, 0xf1ef, 0x1231, 0x0210, 0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7,
0x62d6, 0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c, 0xf3ff, 0xe3de,
0x2462, 0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485, 0xa56a,
0xb54b, 0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d, 0x3653, 0x2672,
0x1611, 0x0630, 0x76d7, 0x66f6, 0x5695, 0x46b4, 0xb75b, 0xa77a, 0x9719,
0x8738, 0xf7df, 0xe7fe, 0xd79d, 0xc7bc, 0x48c4, 0x58e5, 0x6886, 0x78a7,
0x0840, 0x1861, 0x2802, 0x3823, 0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948,
0x9969, 0xa90a, 0xb92b, 0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50,
0x3a33, 0x2a12, 0xdbfd, 0xcbdc, 0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b,
0xab1a, 0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41,
0xedae, 0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49, 0x7e97,
0x6eb6, 0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70, 0xff9f, 0xefbe,
0xdfdd, 0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78, 0x9188, 0x81a9, 0xb1ca,
0xa1eb, 0xd10c, 0xc12d, 0xf14e, 0xe16f, 0x1080, 0x00a1, 0x30c2, 0x20e3,
0x5004, 0x4025, 0x7046, 0x6067, 0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d,
0xd31c, 0xe37f, 0xf35e, 0x02b1, 0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214,
0x6277, 0x7256, 0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c,
0xc50d, 0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
0xa7db, 0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e, 0xc71d, 0xd73c, 0x26d3,
0x36f2, 0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634, 0xd94c, 0xc96d,
0xf90e, 0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab, 0x5844, 0x4865, 0x7806,
0x6827, 0x18c0, 0x08e1, 0x3882, 0x28a3, 0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e,
0x8bf9, 0x9bd8, 0xabbb, 0xbb9a, 0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1,
0x1ad0, 0x2ab3, 0x3a92, 0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b,
0x9de8, 0x8dc9, 0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0,
0x0cc1, 0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8,
0x6e17, 0x7e36, 0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1, 0x1ef0 };

unsigned short crc16(unsigned char *buf, unsigned int len){
	unsigned int i;
	unsigned short cksum = 0;
	for (i = 0; i < len; i++) 
	{
		cksum = crc16_tab[(((cksum >> 8) ^ *buf++) & 0xFF)] ^ (cksum << 8);
	}
	return cksum;
}

/**************************************
 * 类型转换辅助函数
 **************************************/
int16_t buffer_get_int16(uint8_t* buf,int32_t *index){
	int16_t result= ((uint16_t)buf[*index]) <<8 | ((uint16_t)buf[*index+1]);
	(*index)+=2;
	return result;
}
uint16_t buffer_get_uint16(uint8_t* buf,int32_t *index){
	uint16_t result= ((uint16_t)buf[*index]) <<8 | ((uint16_t)buf[*index+1]);
	(*index)+=2;	
	return result;
}
int32_t buffer_get_int32(uint8_t* buf,int32_t *index){
	int32_t result= ((uint32_t)buf[*index]) <<24 |
									((uint32_t)buf[*index+1]) <<16 |
									((uint32_t)buf[*index+2]) <<8  |
									((uint32_t)buf[*index+3]);
	(*index)+=4;
	return result;
}
float buffer_get_float16(uint8_t* buf,int32_t *index){
	return (float)buffer_get_int16(buf,index);
}
float buffer_get_float32(uint8_t* buf,int32_t *index){
	return (float)buffer_get_int32(buf,index);
}







/**************************************
 * 限幅函数
 **************************************/
void assert_param_duty(float *duty){
	if( fabsf(*duty) > wtrcfg_VESC_COMMAND_DUTY_MAX )
		*duty = *duty > 0 ? wtrcfg_VESC_COMMAND_DUTY_MAX : - wtrcfg_VESC_COMMAND_DUTY_MAX ;
}
void assert_param_current(float *current){
	if( fabsf(*current) > wtrcfg_VESC_COMMAND_CURRENT_MAX )
		*current = *current > 0 ? wtrcfg_VESC_COMMAND_CURRENT_MAX : - wtrcfg_VESC_COMMAND_CURRENT_MAX ;
}
void assert_param_rpm(float *rpm){
	if( fabsf(*rpm) > wtrcfg_VESC_COMMAND_ERPM_MAX )
		*rpm = *rpm > 0 ? wtrcfg_VESC_COMMAND_ERPM_MAX : - wtrcfg_VESC_COMMAND_ERPM_MAX ;
}
void assert_param_pos(float *pos){
	if( fabsf(*pos) > wtrcfg_VESC_COMMAND_POS_MAX )
		*pos = *pos > 0 ? wtrcfg_VESC_COMMAND_POS_MAX : - wtrcfg_VESC_COMMAND_POS_MAX ;
}














/******************************************************************************************************
 *	uart报文格式如下
 * 		STX 	 			| 			DLEN 				| 		INFO		 | 	DATA 	| 				BCC				 | 		ETX 		|
 *	0x02/0x03     		len(info+data)    comm/ack/mes		 N				2=CRC(info+data)			0x03
 ******************************************************************************************************/
#ifdef __VESC_UART_ENABLE
HAL_StatusTypeDef uart_send_command(VESC_t *hvesc, const COMM_PACKET_ID id, float value, uint32_t timeout){
	uint8_t txbuf[20]={0x02};
	uint16_t bcc;
	switch(id){
		case COMM_GET_VALUES:{
			txbuf[1]=0x01;//len
			txbuf[2]=id;//info
			//data is empty
			bcc=crc16(&(txbuf[2]),1);
			txbuf[3]=bcc>>8;
			txbuf[4]=bcc;
			txbuf[5]=0x03;
			return HAL_UART_Transmit(hvesc->huartn,txbuf,6,timeout);
			break;
		}
		case COMM_SET_DUTY:{
			txbuf[1]=0x05;
			txbuf[2]=id;
			assert_param_duty(&value);
			int duty=(int)(value*1e3f);
			txbuf[3]=duty>>24;
			txbuf[4]=duty>>16;
			txbuf[5]=duty>>8;
			txbuf[6]=duty;
			bcc=crc16(&(txbuf[2]),5);
			txbuf[7]=bcc>>8;
			txbuf[8]=bcc;
			txbuf[9]=0x03;
			return HAL_UART_Transmit(hvesc->huartn,txbuf,10,timeout);
			break;
		}
		case COMM_SET_CURRENT:{
			txbuf[1]=0x05;
			txbuf[2]=id;
			assert_param_current(&value); 
			int current=(int)(value*1e3f);
			txbuf[3]=current>>24;
			txbuf[4]=current>>16;
			txbuf[5]=current>>8;
			txbuf[6]=current;
			bcc=crc16(&(txbuf[2]),5);
			txbuf[7]=bcc>>8;
			txbuf[8]=bcc;
			txbuf[9]=0x03;
			return HAL_UART_Transmit(hvesc->huartn,txbuf,10,timeout);
			break;
		}
		case COMM_SET_RPM:{
			txbuf[1]=0x05;
			txbuf[2]=id;
			assert_param_rpm(&value); 
			int prm=(int)(value);
			txbuf[3]=prm>>24;
			txbuf[4]=prm>>16;
			txbuf[5]=prm>>8;
			txbuf[6]=prm;
			bcc=crc16(&(txbuf[2]),5);
			txbuf[7]=bcc>>8;
			txbuf[8]=bcc;
			txbuf[9]=0x03;
			return HAL_UART_Transmit(hvesc->huartn,txbuf,10,timeout);
			break;
		}
		case COMM_SET_POS:{
			txbuf[1]=0x05;
			txbuf[2]=id;
			assert_param_pos(&value);
			int pos=(int)(value*1e6f);
			txbuf[3]=pos>>24;
			txbuf[4]=pos>>16;
			txbuf[5]=pos>>8;
			txbuf[6]=pos;
			bcc=crc16(&(txbuf[2]),5);
			txbuf[7]=bcc>>8;
			txbuf[8]=bcc;
			txbuf[9]=0x03;
			return HAL_UART_Transmit(hvesc->huartn,txbuf,10,timeout);
			break;
		}
		default:{
			return HAL_ERROR;
			break;
		}
	}
}


#endif
/******************************************************************************************************
 *	can报文格式如下
 * 解释：| ID格式 | 帧格式 | 数据长度 |           扩展ID 29位            | 数据0byte  |...| 数据3byte  |
 * 位置：|   IDE  |   RTR  |    DLC   |              ExtId               | value高8位 |...| value低8位 |
 * 值  ：|   EXT  |  DATA  |    8     | 低八位为vesc_id,第八位以上为指令 | data >> 24 |...|    data    |
 ******************************************************************************************************/
#ifdef __VESC_CAN_ENABLE
static uint32_t txmailbox;
HAL_StatusTypeDef can_send_command(VESC_t *hvesc, const CAN_PACKET_ID id, float value,int all){
	uint8_t txbuf[8];
	int32_t data;
	CAN_TxHeaderTypeDef TxMessage;
		
	TxMessage.DLC = (uint8_t)8 ; /* --- can set to 4 --- */
	TxMessage.RTR = CAN_RTR_DATA ;
	TxMessage.IDE = CAN_ID_EXT ;
	if( all )
		TxMessage.ExtId = ( (uint32_t) ( (id) << 8) | hvesc->controller_id ) ;
	else 
		TxMessage.ExtId = ( (uint32_t) ( (id) << 8) | 0XFF ) ;
	
	switch( id )
	{
		case CAN_PACKET_SET_DUTY:{
		  /* --- duty: 1e6f ~ 1.0 ~ 100% --- */
		  /* --- value: [-100,100] 1(%) --- */
			assert_param_duty(&value);
			data = (int32_t)(value * 1e3f ) ;
			txbuf[0] = data >> 24 ;
			txbuf[1] = data >> 16 ;
			txbuf[2] = data >> 8 ;
			txbuf[3] = data ;
			break;
		}
		case CAN_PACKET_SET_CURRENT:{
			/* --- current: 1e3f ~ 1 A --- */
			/* --- value: [-current_max,-current_max] 1A --- */
			assert_param_current(&value);
			data = (int32_t)(value * 1e3f ) ;
			txbuf[0] = data >> 24 ;
			txbuf[1] = data >> 16 ;
			txbuf[2] = data >> 8 ;
			txbuf[3] = data ;
			break;
		}
		case CAN_PACKET_SET_RPM:{
			/* --- erpm: 1 ~ 1 rpm --- */
			/* --- value: [-erpm_max,erpm_max] 1rpm --- */
			assert_param_rpm(&value);
			data = (int32_t)(value) ;
			txbuf[0] = data >> 24 ;
			txbuf[1] = data >> 16 ;
			txbuf[2] = data >> 8 ;
			txbuf[3] = data ;
			break;
		}
		case CAN_PACKET_SET_POS:{
			/* --- pos: 1e6f ~ 1 degree --- */
			/* --- value: [-inf,+inf] 1degree --- */
			assert_param_pos(&value);
			data = (int32_t)(value * 1e6f) ;
			txbuf[0] = data >> 24 ;
			txbuf[1] = data >> 16 ;
			txbuf[2] = data >> 8 ;
			txbuf[3] = data ;
			break;
		}
		default:
			break;
	}
	if(HAL_CAN_AddTxMessage(hvesc->hcann,&TxMessage,txbuf,&txmailbox)!=HAL_OK){
		 Error_Handler(); 
	}	
	return HAL_OK ;
}








#endif
/**************************************
 * 接收
 **************************************/
#ifdef __VESC_UART_ENABLE
void uart_get_command(uint8_t rxbuf[],const COMM_PACKET_ID id, void *data){
	switch(id){
		case COMM_GET_VALUES:
		{
			MOTOR_PROPERTY * value = (MOTOR_PROPERTY *)data;	
			int32_t index=3;
			value->temp_fet 					= buffer_get_float16(rxbuf,&index)/1e1f;
			value->temp_motor 				= buffer_get_float16(rxbuf,&index)/1e1f;
			value->current 						= buffer_get_float32(rxbuf,&index)/1e2f;
			value->current_input 			= buffer_get_float32(rxbuf,&index)/1e2f;
			value->id									=	buffer_get_float32(rxbuf,&index)/1e2f;
			value->iq									=	buffer_get_float32(rxbuf,&index)/1e2f;
			value->duty								=	buffer_get_float16(rxbuf,&index)/1e3f; /* --- uint 1%--- */
			value->erpm								=	buffer_get_float32(rxbuf,&index)/1e0f;
			value->voltage_input			=	buffer_get_float16(rxbuf,&index)/1e1f;
			value->A_hours_draw				=	buffer_get_float32(rxbuf,&index)/1e4f;
			value->A_hours_charge			=	buffer_get_float32(rxbuf,&index)/1e4f;
			value->Watt_hours_draw		=	buffer_get_float32(rxbuf,&index)/1e4f;
			value->Watt_hours_draw		=	buffer_get_float32(rxbuf,&index)/1e4f;
			value->tachometer					=	buffer_get_int32(rxbuf,&index);
			value->tachometer_abs			=	buffer_get_int32(rxbuf,&index);
			value->error_code					=	rxbuf[index++];
			value->pos								=	buffer_get_float32(rxbuf,&index)/1e6f;
			value->controller_id			=	rxbuf[index++];
			return HAL_OK;
			break;
		}
		default:
			break;
	}
}
#endif
#ifdef __VESC_CAN_ENABLE
void can_get_command(CAN_RxHeaderTypeDef  *RxHeader,uint8_t rxbuf[], void *data){
	if(RxHeader->IDE != CAN_ID_EXT)
		return ;
	uint32_t id = (RxHeader->ExtId)<<8;
	switch(id)
	{
		case CAN_PACKET_STATUS:{
			int idx=0;
			MOTOR_PROPERTY * value = (MOTOR_PROPERTY *)data ;
			value->controller_id   = RxHeader->ExtId ;
			value->erpm					   = buffer_get_int32(rxbuf,&idx) ;
/*Get the motor current. The sign of this value will
 * represent whether the motor is drawing (positive) or generating
 * (negative) current. This is the q-axis current which produces torque.
 * The motor current. */
			value->current         = (float)(buffer_get_int16(rxbuf,&idx)/10.0f) ;
			value->duty            = (float)(buffer_get_int16(rxbuf,&idx)/10.0f) ;
			break;
		}
		default:{
			break;
		}
	}
}
#endif















