#include "usermain.h"

float angle;

void usermain(void)
{
    RetargetInit(&huart2);

    while (1) {
        angle = AS5600_Read_Angle();
        printf("%.2f\r\n", angle);
        HAL_Delay(1);
    }
}
