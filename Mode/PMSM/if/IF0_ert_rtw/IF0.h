/*
 * File: IF0.h
 *
 * Code generated for Simulink model 'IF0'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri Oct 27 20:37:16 2023
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
  real_T Motor_state;                  /* '<S1>/Chart' */
  real32_T Merge1;                     /* '<S1>/Merge1' */
  real32_T Integrator_DSTATE;          /* '<S100>/Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S8>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator1_DSTAT_l;/* '<S7>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S7>/Discrete-Time Integrator' */
  int16_T Integrator_DSTATE_j;         /* '<S50>/Integrator' */
  uint16_T temporalCounter_i1;         /* '<S1>/Chart' */
  uint8_T is_active_c3_IF0;            /* '<S1>/Chart' */
  uint8_T is_c3_IF0;                   /* '<S1>/Chart' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T ia;                         /* '<Root>/ia' */
  real32_T ib;                         /* '<Root>/ib' */
  real32_T ic;                         /* '<Root>/ic' */
  real32_T v_bus;                      /* '<Root>/v_bus' */
  real32_T Motor_OnOff;                /* '<Root>/Motor_OnOff' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Dutyout[3];                   /* '<Root>/Dutyout' */
} ExtY;

/* Type definition for custom storage class: Struct */
typedef struct motor_tag {
  real32_T Pn;                         /* Referenced by:
                                        * '<S7>/Gain'
                                        * '<S8>/Gain'
                                        */
} motor_type;

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

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T theta;                 /* '<S1>/Merge' */

/* Model entry point functions */
extern void IF0_initialize(void);
extern void IF0_step(void);

/* Exported data declaration */

/* Declaration for custom storage class: Struct */
extern motor_type motor;

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S11>/Scope' : Unused code path elimination
 * Block '<S1>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion4' : Eliminate redundant data type conversion
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
 * hilite_system('IF/IF')    - opens subsystem IF/IF
 * hilite_system('IF/IF/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'IF'
 * '<S1>'   : 'IF/IF'
 * '<S2>'   : 'IF/IF/AntiPark'
 * '<S3>'   : 'IF/IF/Chart'
 * '<S4>'   : 'IF/IF/Clark'
 * '<S5>'   : 'IF/IF/If Action Subsystem'
 * '<S6>'   : 'IF/IF/If Action Subsystem1'
 * '<S7>'   : 'IF/IF/If Action Subsystem2'
 * '<S8>'   : 'IF/IF/If Action Subsystem3'
 * '<S9>'   : 'IF/IF/Park'
 * '<S10>'  : 'IF/IF/SVPWM'
 * '<S11>'  : 'IF/IF/idq_Controller'
 * '<S12>'  : 'IF/IF/SVPWM/AntiClark'
 * '<S13>'  : 'IF/IF/SVPWM/Subsystem'
 * '<S14>'  : 'IF/IF/SVPWM/ei_t'
 * '<S15>'  : 'IF/IF/idq_Controller/PID Controller1'
 * '<S16>'  : 'IF/IF/idq_Controller/PID Controller2'
 * '<S17>'  : 'IF/IF/idq_Controller/PID Controller1/Anti-windup'
 * '<S18>'  : 'IF/IF/idq_Controller/PID Controller1/D Gain'
 * '<S19>'  : 'IF/IF/idq_Controller/PID Controller1/Filter'
 * '<S20>'  : 'IF/IF/idq_Controller/PID Controller1/Filter ICs'
 * '<S21>'  : 'IF/IF/idq_Controller/PID Controller1/I Gain'
 * '<S22>'  : 'IF/IF/idq_Controller/PID Controller1/Ideal P Gain'
 * '<S23>'  : 'IF/IF/idq_Controller/PID Controller1/Ideal P Gain Fdbk'
 * '<S24>'  : 'IF/IF/idq_Controller/PID Controller1/Integrator'
 * '<S25>'  : 'IF/IF/idq_Controller/PID Controller1/Integrator ICs'
 * '<S26>'  : 'IF/IF/idq_Controller/PID Controller1/N Copy'
 * '<S27>'  : 'IF/IF/idq_Controller/PID Controller1/N Gain'
 * '<S28>'  : 'IF/IF/idq_Controller/PID Controller1/P Copy'
 * '<S29>'  : 'IF/IF/idq_Controller/PID Controller1/Parallel P Gain'
 * '<S30>'  : 'IF/IF/idq_Controller/PID Controller1/Reset Signal'
 * '<S31>'  : 'IF/IF/idq_Controller/PID Controller1/Saturation'
 * '<S32>'  : 'IF/IF/idq_Controller/PID Controller1/Saturation Fdbk'
 * '<S33>'  : 'IF/IF/idq_Controller/PID Controller1/Sum'
 * '<S34>'  : 'IF/IF/idq_Controller/PID Controller1/Sum Fdbk'
 * '<S35>'  : 'IF/IF/idq_Controller/PID Controller1/Tracking Mode'
 * '<S36>'  : 'IF/IF/idq_Controller/PID Controller1/Tracking Mode Sum'
 * '<S37>'  : 'IF/IF/idq_Controller/PID Controller1/Tsamp - Integral'
 * '<S38>'  : 'IF/IF/idq_Controller/PID Controller1/Tsamp - Ngain'
 * '<S39>'  : 'IF/IF/idq_Controller/PID Controller1/postSat Signal'
 * '<S40>'  : 'IF/IF/idq_Controller/PID Controller1/preSat Signal'
 * '<S41>'  : 'IF/IF/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S42>'  : 'IF/IF/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S43>'  : 'IF/IF/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S44>'  : 'IF/IF/idq_Controller/PID Controller1/D Gain/Disabled'
 * '<S45>'  : 'IF/IF/idq_Controller/PID Controller1/Filter/Disabled'
 * '<S46>'  : 'IF/IF/idq_Controller/PID Controller1/Filter ICs/Disabled'
 * '<S47>'  : 'IF/IF/idq_Controller/PID Controller1/I Gain/External Parameters'
 * '<S48>'  : 'IF/IF/idq_Controller/PID Controller1/Ideal P Gain/Passthrough'
 * '<S49>'  : 'IF/IF/idq_Controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S50>'  : 'IF/IF/idq_Controller/PID Controller1/Integrator/Discrete'
 * '<S51>'  : 'IF/IF/idq_Controller/PID Controller1/Integrator ICs/Internal IC'
 * '<S52>'  : 'IF/IF/idq_Controller/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S53>'  : 'IF/IF/idq_Controller/PID Controller1/N Gain/Disabled'
 * '<S54>'  : 'IF/IF/idq_Controller/PID Controller1/P Copy/Disabled'
 * '<S55>'  : 'IF/IF/idq_Controller/PID Controller1/Parallel P Gain/External Parameters'
 * '<S56>'  : 'IF/IF/idq_Controller/PID Controller1/Reset Signal/Disabled'
 * '<S57>'  : 'IF/IF/idq_Controller/PID Controller1/Saturation/Enabled'
 * '<S58>'  : 'IF/IF/idq_Controller/PID Controller1/Saturation Fdbk/Disabled'
 * '<S59>'  : 'IF/IF/idq_Controller/PID Controller1/Sum/Sum_PI'
 * '<S60>'  : 'IF/IF/idq_Controller/PID Controller1/Sum Fdbk/Disabled'
 * '<S61>'  : 'IF/IF/idq_Controller/PID Controller1/Tracking Mode/Disabled'
 * '<S62>'  : 'IF/IF/idq_Controller/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S63>'  : 'IF/IF/idq_Controller/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S64>'  : 'IF/IF/idq_Controller/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S65>'  : 'IF/IF/idq_Controller/PID Controller1/postSat Signal/Forward_Path'
 * '<S66>'  : 'IF/IF/idq_Controller/PID Controller1/preSat Signal/Forward_Path'
 * '<S67>'  : 'IF/IF/idq_Controller/PID Controller2/Anti-windup'
 * '<S68>'  : 'IF/IF/idq_Controller/PID Controller2/D Gain'
 * '<S69>'  : 'IF/IF/idq_Controller/PID Controller2/Filter'
 * '<S70>'  : 'IF/IF/idq_Controller/PID Controller2/Filter ICs'
 * '<S71>'  : 'IF/IF/idq_Controller/PID Controller2/I Gain'
 * '<S72>'  : 'IF/IF/idq_Controller/PID Controller2/Ideal P Gain'
 * '<S73>'  : 'IF/IF/idq_Controller/PID Controller2/Ideal P Gain Fdbk'
 * '<S74>'  : 'IF/IF/idq_Controller/PID Controller2/Integrator'
 * '<S75>'  : 'IF/IF/idq_Controller/PID Controller2/Integrator ICs'
 * '<S76>'  : 'IF/IF/idq_Controller/PID Controller2/N Copy'
 * '<S77>'  : 'IF/IF/idq_Controller/PID Controller2/N Gain'
 * '<S78>'  : 'IF/IF/idq_Controller/PID Controller2/P Copy'
 * '<S79>'  : 'IF/IF/idq_Controller/PID Controller2/Parallel P Gain'
 * '<S80>'  : 'IF/IF/idq_Controller/PID Controller2/Reset Signal'
 * '<S81>'  : 'IF/IF/idq_Controller/PID Controller2/Saturation'
 * '<S82>'  : 'IF/IF/idq_Controller/PID Controller2/Saturation Fdbk'
 * '<S83>'  : 'IF/IF/idq_Controller/PID Controller2/Sum'
 * '<S84>'  : 'IF/IF/idq_Controller/PID Controller2/Sum Fdbk'
 * '<S85>'  : 'IF/IF/idq_Controller/PID Controller2/Tracking Mode'
 * '<S86>'  : 'IF/IF/idq_Controller/PID Controller2/Tracking Mode Sum'
 * '<S87>'  : 'IF/IF/idq_Controller/PID Controller2/Tsamp - Integral'
 * '<S88>'  : 'IF/IF/idq_Controller/PID Controller2/Tsamp - Ngain'
 * '<S89>'  : 'IF/IF/idq_Controller/PID Controller2/postSat Signal'
 * '<S90>'  : 'IF/IF/idq_Controller/PID Controller2/preSat Signal'
 * '<S91>'  : 'IF/IF/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel'
 * '<S92>'  : 'IF/IF/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S93>'  : 'IF/IF/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S94>'  : 'IF/IF/idq_Controller/PID Controller2/D Gain/Disabled'
 * '<S95>'  : 'IF/IF/idq_Controller/PID Controller2/Filter/Disabled'
 * '<S96>'  : 'IF/IF/idq_Controller/PID Controller2/Filter ICs/Disabled'
 * '<S97>'  : 'IF/IF/idq_Controller/PID Controller2/I Gain/External Parameters'
 * '<S98>'  : 'IF/IF/idq_Controller/PID Controller2/Ideal P Gain/Passthrough'
 * '<S99>'  : 'IF/IF/idq_Controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S100>' : 'IF/IF/idq_Controller/PID Controller2/Integrator/Discrete'
 * '<S101>' : 'IF/IF/idq_Controller/PID Controller2/Integrator ICs/Internal IC'
 * '<S102>' : 'IF/IF/idq_Controller/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S103>' : 'IF/IF/idq_Controller/PID Controller2/N Gain/Disabled'
 * '<S104>' : 'IF/IF/idq_Controller/PID Controller2/P Copy/Disabled'
 * '<S105>' : 'IF/IF/idq_Controller/PID Controller2/Parallel P Gain/External Parameters'
 * '<S106>' : 'IF/IF/idq_Controller/PID Controller2/Reset Signal/Disabled'
 * '<S107>' : 'IF/IF/idq_Controller/PID Controller2/Saturation/Enabled'
 * '<S108>' : 'IF/IF/idq_Controller/PID Controller2/Saturation Fdbk/Disabled'
 * '<S109>' : 'IF/IF/idq_Controller/PID Controller2/Sum/Sum_PI'
 * '<S110>' : 'IF/IF/idq_Controller/PID Controller2/Sum Fdbk/Disabled'
 * '<S111>' : 'IF/IF/idq_Controller/PID Controller2/Tracking Mode/Disabled'
 * '<S112>' : 'IF/IF/idq_Controller/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S113>' : 'IF/IF/idq_Controller/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S114>' : 'IF/IF/idq_Controller/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S115>' : 'IF/IF/idq_Controller/PID Controller2/postSat Signal/Forward_Path'
 * '<S116>' : 'IF/IF/idq_Controller/PID Controller2/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_IF0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
