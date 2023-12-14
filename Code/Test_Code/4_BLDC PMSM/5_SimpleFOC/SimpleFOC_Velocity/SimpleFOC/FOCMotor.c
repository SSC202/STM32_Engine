#include "Mymain.h"

float shaft_angle; //!< current motor angle
float electrical_angle;
float shaft_velocity;
float current_sp;
float shaft_velocity_sp;
float shaft_angle_sp;
DQVoltage_s voltage;
DQCurrent_s current;

TorqueControlType torque_controller;
MotionControlType controller;

float sensor_offset = 0;
float zero_electric_angle;

/**
 * @brief   计算机械角度
 */
float shaftAngle(void)
{
    // if no sensor linked return previous value ( for open loop )
    // if(!sensor) return shaft_angle;
    return sensor_direction * AS5600_GetAngle() - sensor_offset;
}

/**
 * @brief   计算机械度数
*/
float shaftVelocity(void)
{
    // if no sensor linked return previous value ( for open loop )
    // if(!sensor) return shaft_velocity;
    return sensor_direction * LPF_velocity(AS5600_GetVelocity());
}

/**
 * @brief 计算电角度
*/
float electricalAngle(void)
{
    return _normalizeAngle((shaft_angle + sensor_offset) * pole_pairs - zero_electric_angle);
}
