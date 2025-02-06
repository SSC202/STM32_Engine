/*
 * File: Park_Test.h
 *
 * Code generated for Simulink model 'Park_Test'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Aug  5 16:14:48 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Park_Test_h_
#define RTW_HEADER_Park_Test_h_
#ifndef Park_Test_COMMON_INCLUDES_
#define Park_Test_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Park_Test_COMMON_INCLUDES_ */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S6>/Unit Delay' */
} DW;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T u_alpha;                    /* '<Root>/u_alpha' */
  real32_T u_beta;                     /* '<Root>/u_beta' */
} ExtY;

/* Block signals and states (default storage) */
extern DW rtDW;

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
extern real32_T electric_theta;        /* '<S5>/Mod' */
extern real32_T i_a;                   /* '<S5>/Sin' */
extern real32_T i_b;                   /* '<S5>/Sin1' */
extern real32_T i_c;                   /* '<S5>/Sin2' */
extern real32_T i_alpha;               /* '<S3>/Add2' */
extern real32_T i_beta;                /* '<S3>/Gain2' */
extern real32_T i_d;                   /* '<S4>/Add' */
extern real32_T i_q;                   /* '<S4>/Add1' */

/* Model entry point functions */
extern void Park_Test_initialize(void);
extern void Park_Test_step(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Scope' : Unused code path elimination
 * Block '<S4>/Scope' : Unused code path elimination
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S1>/Scope2' : Unused code path elimination
 * Block '<S1>/Scope3' : Unused code path elimination
 * Block '<S5>/Scope1' : Unused code path elimination
 * Block '<S5>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S5>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S5>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * hilite_system('park/Park_Test')    - opens subsystem park/Park_Test
 * hilite_system('park/Park_Test/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'park'
 * '<S1>'   : 'park/Park_Test'
 * '<S2>'   : 'park/Park_Test/AntiPark'
 * '<S3>'   : 'park/Park_Test/Clark'
 * '<S4>'   : 'park/Park_Test/Park'
 * '<S5>'   : 'park/Park_Test/ThreePhaseCurrGenerator'
 * '<S6>'   : 'park/Park_Test/ThreePhaseCurrGenerator/FreqGenerator'
 * '<S7>'   : 'park/Park_Test/ThreePhaseCurrGenerator/FreqGenerator/RangeLimit'
 * '<S8>'   : 'park/Park_Test/ThreePhaseCurrGenerator/FreqGenerator/RangeLimit/If Action Subsystem1'
 * '<S9>'   : 'park/Park_Test/ThreePhaseCurrGenerator/FreqGenerator/RangeLimit/If Action Subsystem2'
 * '<S10>'  : 'park/Park_Test/ThreePhaseCurrGenerator/FreqGenerator/RangeLimit/If Action Subsystem3'
 */
#endif                                 /* RTW_HEADER_Park_Test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
