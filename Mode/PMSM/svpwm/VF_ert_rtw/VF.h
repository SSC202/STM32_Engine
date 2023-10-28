/*
 * File: VF.h
 *
 * Code generated for Simulink model 'VF'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Oct 28 11:46:00 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_VF_h_
#define RTW_HEADER_VF_h_
#include <math.h>
#ifndef VF_COMMON_INCLUDES_
#define VF_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* VF_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S3>/Unit Delay' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T ud;                           /* '<Root>/ud' */
  real_T uq;                           /* '<Root>/uq' */
  real_T Freq;                         /* '<Root>/Freq' */
  real32_T u_bus;                      /* '<Root>/u_bus' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T DutyOut[3];                   /* '<Root>/DutyOut' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void VF_initialize(void);
extern void VF_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S10>/Scope' : Unused code path elimination
 * Block '<S10>/Scope1' : Unused code path elimination
 * Block '<S11>/Scope' : Unused code path elimination
 * Block '<S1>/Data Type Conversion5' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion6' : Eliminate redundant data type conversion
 * Block '<S10>/Gain' : Eliminated nontunable gain of 1
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('SVPWM/VF')    - opens subsystem SVPWM/VF
 * hilite_system('SVPWM/VF/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SVPWM'
 * '<S1>'   : 'SVPWM/VF'
 * '<S2>'   : 'SVPWM/VF/AntiPark'
 * '<S3>'   : 'SVPWM/VF/FreqGenerator'
 * '<S4>'   : 'SVPWM/VF/PWMOut'
 * '<S5>'   : 'SVPWM/VF/SVPWM'
 * '<S6>'   : 'SVPWM/VF/FreqGenerator/RangeLimit'
 * '<S7>'   : 'SVPWM/VF/FreqGenerator/RangeLimit/If Action Subsystem1'
 * '<S8>'   : 'SVPWM/VF/FreqGenerator/RangeLimit/If Action Subsystem2'
 * '<S9>'   : 'SVPWM/VF/FreqGenerator/RangeLimit/If Action Subsystem3'
 * '<S10>'  : 'SVPWM/VF/SVPWM/N'
 * '<S11>'  : 'SVPWM/VF/SVPWM/t4_t6'
 * '<S12>'  : 'SVPWM/VF/SVPWM/t_abc'
 */
#endif                                 /* RTW_HEADER_VF_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
