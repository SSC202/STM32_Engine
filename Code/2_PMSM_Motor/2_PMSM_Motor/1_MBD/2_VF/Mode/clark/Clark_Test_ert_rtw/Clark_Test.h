/*
 * File: Clark_Test.h
 *
 * Code generated for Simulink model 'Clark_Test'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Aug  5 15:58:11 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Clark_Test_h_
#define RTW_HEADER_Clark_Test_h_
#ifndef Clark_Test_COMMON_INCLUDES_
#define Clark_Test_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Clark_Test_COMMON_INCLUDES_ */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S4>/Unit Delay' */
} DW;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T i_alpha;                    /* '<Root>/i_alpha' */
  real32_T i_beta;                     /* '<Root>/i_beta' */
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
extern real32_T i_b;                   /* '<S3>/Sin1' */
extern real32_T i_c;                   /* '<S3>/Sin2' */
extern real32_T i_a;                   /* '<S3>/Sin' */

/* Model entry point functions */
extern void Clark_Test_initialize(void);
extern void Clark_Test_step(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S3>/Scope1' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * hilite_system('Clark/Clark_Test')    - opens subsystem Clark/Clark_Test
 * hilite_system('Clark/Clark_Test/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Clark'
 * '<S1>'   : 'Clark/Clark_Test'
 * '<S2>'   : 'Clark/Clark_Test/Clark'
 * '<S3>'   : 'Clark/Clark_Test/ThreePhaseCurrGenerator'
 * '<S4>'   : 'Clark/Clark_Test/ThreePhaseCurrGenerator/FreqGenerator'
 * '<S5>'   : 'Clark/Clark_Test/ThreePhaseCurrGenerator/FreqGenerator/RangeLimit'
 * '<S6>'   : 'Clark/Clark_Test/ThreePhaseCurrGenerator/FreqGenerator/RangeLimit/If Action Subsystem1'
 * '<S7>'   : 'Clark/Clark_Test/ThreePhaseCurrGenerator/FreqGenerator/RangeLimit/If Action Subsystem2'
 * '<S8>'   : 'Clark/Clark_Test/ThreePhaseCurrGenerator/FreqGenerator/RangeLimit/If Action Subsystem3'
 */
#endif                                 /* RTW_HEADER_Clark_Test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
