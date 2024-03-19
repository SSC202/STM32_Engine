/*
 * File: IF0.h
 *
 * Code generated for Simulink model 'IF0'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Mon Dec 18 15:46:35 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_IF0_h_
#define RTW_HEADER_IF0_h_
#include <stddef.h>
#include <float.h>
#include <math.h>
#ifndef IF0_COMMON_INCLUDES_
#define IF0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* IF0_COMMON_INCLUDES_ */

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
  real_T Merge;                        /* '<S1>/Merge' */
  real_T Merge1;                       /* '<S1>/Merge1' */
  real_T Motor_State;                  /* '<S1>/Chart' */
  real_T Integrator_DSTATE;            /* '<S98>/Integrator' */
  real_T Integrator_DSTATE_l;          /* '<S48>/Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S12>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S11>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTAT_h;/* '<S11>/Discrete-Time Integrator1' */
  uint16_T temporalCounter_i1;         /* '<S1>/Chart' */
  uint8_T is_active_c3_IF0;            /* '<S1>/Chart' */
  uint8_T is_c3_IF0;                   /* '<S1>/Chart' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T ia;                         /* '<Root>/ia' */
  real32_T ib;                         /* '<Root>/ib' */
  real32_T ic;                         /* '<Root>/ic' */
  real_T u_bus;                        /* '<Root>/u_bus' */
  real_T Motor_OnOff;                  /* '<Root>/Motor_OnOff' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T DutyOut[3];                   /* '<Root>/DutyOut' */
} ExtY;

/* Type definition for custom storage class: Struct */
typedef struct Motor_tag {
  real32_T Pn;                         /* Referenced by:
                                        * '<S11>/Gain1'
                                        * '<S12>/Gain1'
                                        */
} Motor_type;

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
extern void IF0_initialize(void);
extern void IF0_step(void);

/* Exported data declaration */

/* Declaration for custom storage class: Struct */
extern Motor_type Motor;

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Scope' : Unused code path elimination
 * Block '<S115>/Scope' : Unused code path elimination
 * Block '<S115>/Scope1' : Unused code path elimination
 * Block '<S116>/Scope' : Unused code path elimination
 * Block '<S115>/Gain' : Eliminated nontunable gain of 1
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
 * hilite_system('currloop/IF')    - opens subsystem currloop/IF
 * hilite_system('currloop/IF/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'currloop'
 * '<S1>'   : 'currloop/IF'
 * '<S2>'   : 'currloop/IF/AntiPark'
 * '<S3>'   : 'currloop/IF/Chart'
 * '<S4>'   : 'currloop/IF/Clark'
 * '<S5>'   : 'currloop/IF/Curr_PID'
 * '<S6>'   : 'currloop/IF/PWMOut'
 * '<S7>'   : 'currloop/IF/Park'
 * '<S8>'   : 'currloop/IF/SVPWM'
 * '<S9>'   : 'currloop/IF/Switch Case Action Subsystem'
 * '<S10>'  : 'currloop/IF/Switch Case Action Subsystem1'
 * '<S11>'  : 'currloop/IF/Switch Case Action Subsystem2'
 * '<S12>'  : 'currloop/IF/Switch Case Action Subsystem3'
 * '<S13>'  : 'currloop/IF/Curr_PID/Discrete PID Controller'
 * '<S14>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1'
 * '<S15>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Anti-windup'
 * '<S16>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/D Gain'
 * '<S17>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Filter'
 * '<S18>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Filter ICs'
 * '<S19>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/I Gain'
 * '<S20>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Ideal P Gain'
 * '<S21>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S22>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Integrator'
 * '<S23>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Integrator ICs'
 * '<S24>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/N Copy'
 * '<S25>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/N Gain'
 * '<S26>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/P Copy'
 * '<S27>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Parallel P Gain'
 * '<S28>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Reset Signal'
 * '<S29>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Saturation'
 * '<S30>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Saturation Fdbk'
 * '<S31>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Sum'
 * '<S32>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Sum Fdbk'
 * '<S33>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Tracking Mode'
 * '<S34>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Tracking Mode Sum'
 * '<S35>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Tsamp - Integral'
 * '<S36>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Tsamp - Ngain'
 * '<S37>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/postSat Signal'
 * '<S38>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/preSat Signal'
 * '<S39>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S40>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S41>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S42>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/D Gain/Disabled'
 * '<S43>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Filter/Disabled'
 * '<S44>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Filter ICs/Disabled'
 * '<S45>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/I Gain/External Parameters'
 * '<S46>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S47>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S48>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Integrator/Discrete'
 * '<S49>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S50>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S51>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/N Gain/Disabled'
 * '<S52>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/P Copy/Disabled'
 * '<S53>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Parallel P Gain/External Parameters'
 * '<S54>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Reset Signal/Disabled'
 * '<S55>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Saturation/Enabled'
 * '<S56>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S57>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Sum/Sum_PI'
 * '<S58>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S59>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S60>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S61>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S62>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S63>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S64>'  : 'currloop/IF/Curr_PID/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S65>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Anti-windup'
 * '<S66>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/D Gain'
 * '<S67>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Filter'
 * '<S68>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Filter ICs'
 * '<S69>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/I Gain'
 * '<S70>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Ideal P Gain'
 * '<S71>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S72>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Integrator'
 * '<S73>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Integrator ICs'
 * '<S74>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/N Copy'
 * '<S75>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/N Gain'
 * '<S76>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/P Copy'
 * '<S77>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Parallel P Gain'
 * '<S78>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Reset Signal'
 * '<S79>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Saturation'
 * '<S80>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Saturation Fdbk'
 * '<S81>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Sum'
 * '<S82>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Sum Fdbk'
 * '<S83>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Tracking Mode'
 * '<S84>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Tracking Mode Sum'
 * '<S85>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Tsamp - Integral'
 * '<S86>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Tsamp - Ngain'
 * '<S87>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/postSat Signal'
 * '<S88>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/preSat Signal'
 * '<S89>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S90>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S91>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S92>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/D Gain/Disabled'
 * '<S93>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Filter/Disabled'
 * '<S94>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Filter ICs/Disabled'
 * '<S95>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/I Gain/External Parameters'
 * '<S96>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S97>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S98>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Integrator/Discrete'
 * '<S99>'  : 'currloop/IF/Curr_PID/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S100>' : 'currloop/IF/Curr_PID/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S101>' : 'currloop/IF/Curr_PID/Discrete PID Controller1/N Gain/Disabled'
 * '<S102>' : 'currloop/IF/Curr_PID/Discrete PID Controller1/P Copy/Disabled'
 * '<S103>' : 'currloop/IF/Curr_PID/Discrete PID Controller1/Parallel P Gain/External Parameters'
 * '<S104>' : 'currloop/IF/Curr_PID/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S105>' : 'currloop/IF/Curr_PID/Discrete PID Controller1/Saturation/Enabled'
 * '<S106>' : 'currloop/IF/Curr_PID/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S107>' : 'currloop/IF/Curr_PID/Discrete PID Controller1/Sum/Sum_PI'
 * '<S108>' : 'currloop/IF/Curr_PID/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S109>' : 'currloop/IF/Curr_PID/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S110>' : 'currloop/IF/Curr_PID/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S111>' : 'currloop/IF/Curr_PID/Discrete PID Controller1/Tsamp - Integral/Passthrough'
 * '<S112>' : 'currloop/IF/Curr_PID/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S113>' : 'currloop/IF/Curr_PID/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S114>' : 'currloop/IF/Curr_PID/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S115>' : 'currloop/IF/SVPWM/N'
 * '<S116>' : 'currloop/IF/SVPWM/t4_t6'
 * '<S117>' : 'currloop/IF/SVPWM/t_abc'
 */
#endif                                 /* RTW_HEADER_IF0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
