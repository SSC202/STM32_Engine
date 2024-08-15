/*
 * File: Currloop_Mode.h
 *
 * Code generated for Simulink model 'Currloop_Mode'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Aug 15 17:06:22 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Currloop_Mode_h_
#define RTW_HEADER_Currloop_Mode_h_
#ifndef Currloop_Mode_COMMON_INCLUDES_
#define Currloop_Mode_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Currloop_Mode_COMMON_INCLUDES_ */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real32_T Integrator_DSTATE;          /* '<S92>/Integrator' */
  int16_T Integrator_DSTATE_l;         /* '<S42>/Integrator' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T I_a;                        /* '<Root>/I_a' */
  real32_T I_b;                        /* '<Root>/I_b' */
  real32_T I_c;                        /* '<Root>/I_c' */
  real32_T electric_theta;             /* '<Root>/electric_theta' */
  real32_T iq_ref;                     /* '<Root>/iq_ref' */
  real32_T T_pwm;                      /* '<Root>/T_pwm' */
  real32_T u_dc;                       /* '<Root>/u_dc' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Duty[3];                      /* '<Root>/Duty' */
} ExtY;

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
extern real32_T i_alpha;               /* '<S3>/Add2' */
extern real32_T i_beta;                /* '<S3>/Gain2' */
extern real32_T i_d;                   /* '<S5>/Add' */
extern real32_T i_q;                   /* '<S5>/Add1' */

/* Model entry point functions */
extern void Currloop_Mode_initialize(void);
extern void Currloop_Mode_step(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Scope' : Unused code path elimination
 * Block '<S4>/Scope' : Unused code path elimination
 * Block '<S5>/Scope' : Unused code path elimination
 * Block '<S109>/Scope' : Unused code path elimination
 * Block '<S109>/Scope1' : Unused code path elimination
 * Block '<S110>/Scope' : Unused code path elimination
 * Block '<S111>/Scope' : Unused code path elimination
 * Block '<S111>/Scope1' : Unused code path elimination
 * Block '<S112>/Scope' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
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
 * hilite_system('if_mode/Currloop_Mode')    - opens subsystem if_mode/Currloop_Mode
 * hilite_system('if_mode/Currloop_Mode/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'if_mode'
 * '<S1>'   : 'if_mode/Currloop_Mode'
 * '<S2>'   : 'if_mode/Currloop_Mode/AntiPark'
 * '<S3>'   : 'if_mode/Currloop_Mode/Clark'
 * '<S4>'   : 'if_mode/Currloop_Mode/Curr_PI_Controller'
 * '<S5>'   : 'if_mode/Currloop_Mode/Park'
 * '<S6>'   : 'if_mode/Currloop_Mode/SVPWM'
 * '<S7>'   : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1'
 * '<S8>'   : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2'
 * '<S9>'   : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Anti-windup'
 * '<S10>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/D Gain'
 * '<S11>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Filter'
 * '<S12>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Filter ICs'
 * '<S13>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/I Gain'
 * '<S14>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Ideal P Gain'
 * '<S15>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Ideal P Gain Fdbk'
 * '<S16>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Integrator'
 * '<S17>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Integrator ICs'
 * '<S18>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/N Copy'
 * '<S19>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/N Gain'
 * '<S20>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/P Copy'
 * '<S21>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Parallel P Gain'
 * '<S22>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Reset Signal'
 * '<S23>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Saturation'
 * '<S24>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Saturation Fdbk'
 * '<S25>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Sum'
 * '<S26>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Sum Fdbk'
 * '<S27>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Tracking Mode'
 * '<S28>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Tracking Mode Sum'
 * '<S29>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Tsamp - Integral'
 * '<S30>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Tsamp - Ngain'
 * '<S31>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/postSat Signal'
 * '<S32>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/preSat Signal'
 * '<S33>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S34>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S35>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S36>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/D Gain/Disabled'
 * '<S37>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Filter/Disabled'
 * '<S38>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Filter ICs/Disabled'
 * '<S39>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/I Gain/External Parameters'
 * '<S40>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Ideal P Gain/Passthrough'
 * '<S41>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S42>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Integrator/Discrete'
 * '<S43>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Integrator ICs/Internal IC'
 * '<S44>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S45>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/N Gain/Disabled'
 * '<S46>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/P Copy/Disabled'
 * '<S47>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Parallel P Gain/External Parameters'
 * '<S48>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Reset Signal/Disabled'
 * '<S49>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Saturation/Enabled'
 * '<S50>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Saturation Fdbk/Disabled'
 * '<S51>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Sum/Sum_PI'
 * '<S52>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Sum Fdbk/Disabled'
 * '<S53>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Tracking Mode/Disabled'
 * '<S54>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S55>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S56>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S57>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/postSat Signal/Forward_Path'
 * '<S58>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller1/preSat Signal/Forward_Path'
 * '<S59>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Anti-windup'
 * '<S60>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/D Gain'
 * '<S61>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Filter'
 * '<S62>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Filter ICs'
 * '<S63>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/I Gain'
 * '<S64>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Ideal P Gain'
 * '<S65>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Ideal P Gain Fdbk'
 * '<S66>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Integrator'
 * '<S67>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Integrator ICs'
 * '<S68>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/N Copy'
 * '<S69>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/N Gain'
 * '<S70>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/P Copy'
 * '<S71>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Parallel P Gain'
 * '<S72>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Reset Signal'
 * '<S73>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Saturation'
 * '<S74>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Saturation Fdbk'
 * '<S75>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Sum'
 * '<S76>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Sum Fdbk'
 * '<S77>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Tracking Mode'
 * '<S78>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Tracking Mode Sum'
 * '<S79>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Tsamp - Integral'
 * '<S80>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Tsamp - Ngain'
 * '<S81>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/postSat Signal'
 * '<S82>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/preSat Signal'
 * '<S83>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel'
 * '<S84>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S85>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S86>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/D Gain/Disabled'
 * '<S87>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Filter/Disabled'
 * '<S88>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Filter ICs/Disabled'
 * '<S89>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/I Gain/External Parameters'
 * '<S90>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Ideal P Gain/Passthrough'
 * '<S91>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S92>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Integrator/Discrete'
 * '<S93>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Integrator ICs/Internal IC'
 * '<S94>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S95>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/N Gain/Disabled'
 * '<S96>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/P Copy/Disabled'
 * '<S97>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Parallel P Gain/External Parameters'
 * '<S98>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Reset Signal/Disabled'
 * '<S99>'  : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Saturation/Enabled'
 * '<S100>' : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Saturation Fdbk/Disabled'
 * '<S101>' : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Sum/Sum_PI'
 * '<S102>' : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Sum Fdbk/Disabled'
 * '<S103>' : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Tracking Mode/Disabled'
 * '<S104>' : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S105>' : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S106>' : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S107>' : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/postSat Signal/Forward_Path'
 * '<S108>' : 'if_mode/Currloop_Mode/Curr_PI_Controller/PID Controller2/preSat Signal/Forward_Path'
 * '<S109>' : 'if_mode/Currloop_Mode/SVPWM/Duty_Caculator'
 * '<S110>' : 'if_mode/Currloop_Mode/SVPWM/Sector_Select'
 * '<S111>' : 'if_mode/Currloop_Mode/SVPWM/T4_T6_Caculator'
 * '<S112>' : 'if_mode/Currloop_Mode/SVPWM/X_Y_Z_Caculator'
 */
#endif                                 /* RTW_HEADER_Currloop_Mode_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
