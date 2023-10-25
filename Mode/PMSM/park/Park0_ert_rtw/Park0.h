/*
 * File: Park0.h
 *
 * Code generated for Simulink model 'Park0'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Oct 25 13:24:28 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Park0_h_
#define RTW_HEADER_Park0_h_
#include <float.h>
#include <math.h>
#ifndef Park0_COMMON_INCLUDES_
#define Park0_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Park0_COMMON_INCLUDES_ */

/* Model Code Variants */
#include "mw_cmsis.h"

/* Macros for accessing real-time model data structure */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S4>/Unit Delay' */
  real32_T UnitDelay_DSTATE_j;         /* '<S11>/Unit Delay' */
} DW;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T ualpha;                     /* '<Root>/ualpha' */
  real32_T ubeta;                      /* '<Root>/ubeta' */
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
extern real32_T ia;                    /* '<S6>/Sin' */
extern real32_T ib;                    /* '<S6>/Sin1' */
extern real32_T ic;                    /* '<S6>/Sin2' */
extern real32_T ialpha;                /* '<S3>/Add1' */
extern real32_T ibeta;                 /* '<S3>/Gain2' */
extern real32_T id;                    /* '<S5>/Subtract' */
extern real32_T iq;                    /* '<S5>/Subtract1' */

/* Model entry point functions */
extern void Park0_initialize(void);
extern void Park0_step(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope2' : Unused code path elimination
 * Block '<S6>/Scope1' : Unused code path elimination
 * Block '<S1>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * hilite_system('park/Park')    - opens subsystem park/Park
 * hilite_system('park/Park/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'park'
 * '<S1>'   : 'park/Park'
 * '<S2>'   : 'park/Park/AntiPark'
 * '<S3>'   : 'park/Park/Clark'
 * '<S4>'   : 'park/Park/FreqGenerator'
 * '<S5>'   : 'park/Park/Park'
 * '<S6>'   : 'park/Park/ThreeCurrentGenerator'
 * '<S7>'   : 'park/Park/FreqGenerator/RangeLimit'
 * '<S8>'   : 'park/Park/FreqGenerator/RangeLimit/If Action Subsystem1'
 * '<S9>'   : 'park/Park/FreqGenerator/RangeLimit/If Action Subsystem2'
 * '<S10>'  : 'park/Park/FreqGenerator/RangeLimit/If Action Subsystem3'
 * '<S11>'  : 'park/Park/ThreeCurrentGenerator/FreqGenerator'
 * '<S12>'  : 'park/Park/ThreeCurrentGenerator/FreqGenerator/RangeLimit'
 * '<S13>'  : 'park/Park/ThreeCurrentGenerator/FreqGenerator/RangeLimit/If Action Subsystem1'
 * '<S14>'  : 'park/Park/ThreeCurrentGenerator/FreqGenerator/RangeLimit/If Action Subsystem2'
 * '<S15>'  : 'park/Park/ThreeCurrentGenerator/FreqGenerator/RangeLimit/If Action Subsystem3'
 */
#endif                                 /* RTW_HEADER_Park0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
