/*
 * File: VF.h
 *
 * Code generated for Simulink model 'VF'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Oct 25 22:40:40 2023
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
#ifndef VF_COMMON_INCLUDES_
#define VF_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* VF_COMMON_INCLUDES_ */

/* Model Code Variants */
#include "mw_cmsis.h"

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
  real32_T UnitDelay_DSTATE;           /* '<S4>/Unit Delay' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T ud;                           /* '<Root>/ud' */
  real_T uq;                           /* '<Root>/uq' */
  real_T Freq;                         /* '<Root>/Freq' */
  real32_T ubus;                       /* '<Root>/ubus' */
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
 * Block '<S5>/Scope1' : Unused code path elimination
 * Block '<S5>/Scope3' : Unused code path elimination
 * Block '<S12>/Scope' : Unused code path elimination
 * Block '<S12>/Scope1' : Unused code path elimination
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope2' : Unused code path elimination
 * Block '<S1>/Data Type Conversion5' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion6' : Eliminate redundant data type conversion
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
 * hilite_system('svpwm/FOC_Openloop/VF')    - opens subsystem svpwm/FOC_Openloop/VF
 * hilite_system('svpwm/FOC_Openloop/VF/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'svpwm/FOC_Openloop'
 * '<S1>'   : 'svpwm/FOC_Openloop/VF'
 * '<S2>'   : 'svpwm/FOC_Openloop/VF/AntiPark'
 * '<S3>'   : 'svpwm/FOC_Openloop/VF/Duty'
 * '<S4>'   : 'svpwm/FOC_Openloop/VF/FreqGenerator'
 * '<S5>'   : 'svpwm/FOC_Openloop/VF/SVPWM'
 * '<S6>'   : 'svpwm/FOC_Openloop/VF/FreqGenerator/RangeLimit'
 * '<S7>'   : 'svpwm/FOC_Openloop/VF/FreqGenerator/RangeLimit/If Action Subsystem1'
 * '<S8>'   : 'svpwm/FOC_Openloop/VF/FreqGenerator/RangeLimit/If Action Subsystem2'
 * '<S9>'   : 'svpwm/FOC_Openloop/VF/FreqGenerator/RangeLimit/If Action Subsystem3'
 * '<S10>'  : 'svpwm/FOC_Openloop/VF/SVPWM/N_Sector'
 * '<S11>'  : 'svpwm/FOC_Openloop/VF/SVPWM/T1_T2_cal'
 * '<S12>'  : 'svpwm/FOC_Openloop/VF/SVPWM/T_cal'
 * '<S13>'  : 'svpwm/FOC_Openloop/VF/SVPWM/XYZ'
 */
#endif                                 /* RTW_HEADER_VF_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
