#include "usermain.h"

/**
 * @brief   用户函数
 */
void User_main(void)
{
    int pos          = 0;
    FEET_Servo servo = FEET_Servo(huart2);
    while (1) {
        servo.Servo_Write_PosEx(4000);
        HAL_Delay(1000);
        pos = servo.Servo_Read_Pos();
        printf("%d\r\n", pos);
        HAL_Delay(1000);
    }
}
