/*
 * File: VF_Mode.h
 *
 * Code generated for Simulink model 'VF_Mode'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Aug  5 17:10:43 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_VF_Mode_h_
#define RTW_HEADER_VF_Mode_h_
#ifndef VF_Mode_COMMON_INCLUDES_
#define VF_Mode_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* VF_Mode_COMMON_INCLUDES_ */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S9>/Unit Delay' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T u_d;                          /* '<Root>/u_d' */
  real_T u_q;                          /* '<Root>/u_q' */
  real_T T_pwm;                        /* '<Root>/T_pwm' */
  real_T Freq;                         /* '<Root>/Freq' */
  real_T u_dc;                         /* '<Root>/u_dc' */
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
extern real32_T electric_theta;        /* '<S4>/Mod' */

/* Model entry point functions */
extern void VF_Mode_initialize(void);
extern void VF_Mode_step(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Scope' : Unused code path elimination
 * Block '<S5>/Scope' : Unused code path elimination
 * Block '<S5>/Scope1' : Unused code path elimination
 * Block '<S6>/Scope' : Unused code path elimination
 * Block '<S7>/Scope' : Unused code path elimination
 * Block '<S7>/Scope1' : Unused code path elimination
 * Block '<S8>/Scope' : Unused code path elimination
 * Block '<S4>/Add2' : Unused code path elimination
 * Block '<S4>/Add3' : Unused code path elimination
 * Block '<S4>/Constant1' : Unused code path elimination
 * Block '<S4>/Constant3' : Unused code path elimination
 * Block '<S4>/Data Type Conversion1' : Unused code path elimination
 * Block '<S4>/Data Type Conversion2' : Unused code path elimination
 * Block '<S4>/Mod3' : Unused code path elimination
 * Block '<S4>/Mod4' : Unused code path elimination
 * Block '<S4>/Scope1' : Unused code path elimination
 * Block '<S4>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * hilite_system('svpwm/VF_Mode')    - opens subsystem svpwm/VF_Mode
 * hilite_system('svpwm/VF_Mode/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'svpwm'
 * '<S1>'   : 'svpwm/VF_Mode'
 * '<S2>'   : 'svpwm/VF_Mode/AntiPark'
 * '<S3>'   : 'svpwm/VF_Mode/SVPWM'
 * '<S4>'   : 'svpwm/VF_Mode/ThreePhaseCurrGenerator'
 * '<S5>'   : 'svpwm/VF_Mode/SVPWM/Duty_Caculator'
 * '<S6>'   : 'svpwm/VF_Mode/SVPWM/Sector_Select'
 * '<S7>'   : 'svpwm/VF_Mode/SVPWM/T4_T6_Caculator'
 * '<S8>'   : 'svpwm/VF_Mode/SVPWM/X_Y_Z_Caculator'
 * '<S9>'   : 'svpwm/VF_Mode/ThreePhaseCurrGenerator/FreqGenerator'
 * '<S10>'  : 'svpwm/VF_Mode/ThreePhaseCurrGenerator/FreqGenerator/RangeLimit'
 * '<S11>'  : 'svpwm/VF_Mode/ThreePhaseCurrGenerator/FreqGenerator/RangeLimit/If Action Subsystem1'
 * '<S12>'  : 'svpwm/VF_Mode/ThreePhaseCurrGenerator/FreqGenerator/RangeLimit/If Action Subsystem2'
 * '<S13>'  : 'svpwm/VF_Mode/ThreePhaseCurrGenerator/FreqGenerator/RangeLimit/If Action Subsystem3'
 */
#endif                                 /* RTW_HEADER_VF_Mode_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
