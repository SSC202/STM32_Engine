#ifndef __FOC_UTILS_H
#define __FOC_UTILS_H

#define _2_SQRT3 1.15470053838
#define _SQRT3   1.73205080757
#define _1_SQRT3 0.57735026919
#define _SQRT3_2 0.86602540378
#define _SQRT2   1.41421356237
#define _120_D2R 2.09439510239
#define _PI      3.14159265359
#define _PI_2    1.57079632679
#define _PI_3    1.0471975512
#define _2PI     6.28318530718
#define _3PI_2   4.71238898038
#define _PI_6    0.52359877559

// 用户函数
float _sin(float a);
float _cos(float a);
float _normalizeAngle(float angle);
float _electricalAngle(float _shaft_angle, int _pole_pairs);
float _sqrt(float number);

#endif