/*
 * File: IF_Mode0.h
 *
 * Code generated for Simulink model 'IF_Mode0'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Aug 15 20:42:47 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_IF_Mode0_h_
#define RTW_HEADER_IF_Mode0_h_
#ifndef IF_Mode0_COMMON_INCLUDES_
#define IF_Mode0_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* IF_Mode0_COMMON_INCLUDES_ */

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
  real32_T Integrator_DSTATE;          /* '<S97>/Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S10>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator1_DSTAT_j;/* '<S8>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S8>/Discrete-Time Integrator' */
  int16_T Integrator_DSTATE_l;         /* '<S47>/Integrator' */
  uint16_T temporalCounter_i1;         /* '<S1>/Chart' */
  uint8_T is_c3_IF_Mode0;              /* '<S1>/Chart' */
  uint8_T is_active_c3_IF_Mode0;       /* '<S1>/Chart' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T I_a;                        /* '<Root>/I_a' */
  real32_T I_b;                        /* '<Root>/I_b' */
  real32_T I_c;                        /* '<Root>/I_c' */
  real32_T T_pwm;                      /* '<Root>/T_pwm' */
  real32_T u_dc;                       /* '<Root>/u_dc' */
  real32_T Motor_OnOff;                /* '<Root>/Motor_OnOff' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Duty[3];                      /* '<Root>/Duty' */
} ExtY;

/* Type definition for custom storage class: Struct */
typedef struct Motor_tag {
  real32_T Pn;                         /* Referenced by:
                                        * '<S8>/Gain'
                                        * '<S10>/Gain'
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

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T i_alpha;               /* '<S5>/Add2' */
extern real32_T ThetaOpen;             /* '<S1>/Merge' */
extern real32_T i_beta;                /* '<S5>/Gain2' */
extern real32_T i_d;                   /* '<S9>/Add' */
extern real32_T i_q;                   /* '<S9>/Add1' */

/* Model entry point functions */
extern void IF_Mode0_initialize(void);
extern void IF_Mode0_step(void);

/* Exported data declaration */

/* Declaration for custom storage class: Struct */
extern Motor_type Motor;

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Scope' : Unused code path elimination
 * Block '<S6>/Scope' : Unused code path elimination
 * Block '<S9>/Scope' : Unused code path elimination
 * Block '<S114>/Scope' : Unused code path elimination
 * Block '<S114>/Scope1' : Unused code path elimination
 * Block '<S115>/Scope' : Unused code path elimination
 * Block '<S116>/Scope' : Unused code path elimination
 * Block '<S116>/Scope1' : Unused code path elimination
 * Block '<S117>/Scope' : Unused code path elimination
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
 * hilite_system('if_mode/IF_Mode')    - opens subsystem if_mode/IF_Mode
 * hilite_system('if_mode/IF_Mode/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'if_mode'
 * '<S1>'   : 'if_mode/IF_Mode'
 * '<S2>'   : 'if_mode/IF_Mode/Align'
 * '<S3>'   : 'if_mode/IF_Mode/AntiPark'
 * '<S4>'   : 'if_mode/IF_Mode/Chart'
 * '<S5>'   : 'if_mode/IF_Mode/Clark'
 * '<S6>'   : 'if_mode/IF_Mode/Curr_PI_Controller'
 * '<S7>'   : 'if_mode/IF_Mode/IDLE'
 * '<S8>'   : 'if_mode/IF_Mode/Open'
 * '<S9>'   : 'if_mode/IF_Mode/Park'
 * '<S10>'  : 'if_mode/IF_Mode/Run'
 * '<S11>'  : 'if_mode/IF_Mode/SVPWM'
 * '<S12>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1'
 * '<S13>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2'
 * '<S14>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Anti-windup'
 * '<S15>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/D Gain'
 * '<S16>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Filter'
 * '<S17>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Filter ICs'
 * '<S18>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/I Gain'
 * '<S19>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Ideal P Gain'
 * '<S20>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Ideal P Gain Fdbk'
 * '<S21>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Integrator'
 * '<S22>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Integrator ICs'
 * '<S23>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/N Copy'
 * '<S24>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/N Gain'
 * '<S25>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/P Copy'
 * '<S26>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Parallel P Gain'
 * '<S27>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Reset Signal'
 * '<S28>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Saturation'
 * '<S29>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Saturation Fdbk'
 * '<S30>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Sum'
 * '<S31>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Sum Fdbk'
 * '<S32>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Tracking Mode'
 * '<S33>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Tracking Mode Sum'
 * '<S34>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Tsamp - Integral'
 * '<S35>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Tsamp - Ngain'
 * '<S36>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/postSat Signal'
 * '<S37>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/preSat Signal'
 * '<S38>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S39>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S40>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S41>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/D Gain/Disabled'
 * '<S42>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Filter/Disabled'
 * '<S43>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Filter ICs/Disabled'
 * '<S44>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/I Gain/External Parameters'
 * '<S45>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Ideal P Gain/Passthrough'
 * '<S46>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S47>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Integrator/Discrete'
 * '<S48>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Integrator ICs/Internal IC'
 * '<S49>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S50>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/N Gain/Disabled'
 * '<S51>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/P Copy/Disabled'
 * '<S52>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Parallel P Gain/External Parameters'
 * '<S53>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Reset Signal/Disabled'
 * '<S54>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Saturation/Enabled'
 * '<S55>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Saturation Fdbk/Disabled'
 * '<S56>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Sum/Sum_PI'
 * '<S57>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Sum Fdbk/Disabled'
 * '<S58>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Tracking Mode/Disabled'
 * '<S59>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S60>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S61>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S62>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/postSat Signal/Forward_Path'
 * '<S63>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller1/preSat Signal/Forward_Path'
 * '<S64>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Anti-windup'
 * '<S65>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/D Gain'
 * '<S66>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Filter'
 * '<S67>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Filter ICs'
 * '<S68>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/I Gain'
 * '<S69>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Ideal P Gain'
 * '<S70>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Ideal P Gain Fdbk'
 * '<S71>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Integrator'
 * '<S72>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Integrator ICs'
 * '<S73>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/N Copy'
 * '<S74>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/N Gain'
 * '<S75>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/P Copy'
 * '<S76>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Parallel P Gain'
 * '<S77>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Reset Signal'
 * '<S78>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Saturation'
 * '<S79>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Saturation Fdbk'
 * '<S80>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Sum'
 * '<S81>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Sum Fdbk'
 * '<S82>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Tracking Mode'
 * '<S83>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Tracking Mode Sum'
 * '<S84>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Tsamp - Integral'
 * '<S85>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Tsamp - Ngain'
 * '<S86>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/postSat Signal'
 * '<S87>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/preSat Signal'
 * '<S88>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel'
 * '<S89>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S90>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S91>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/D Gain/Disabled'
 * '<S92>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Filter/Disabled'
 * '<S93>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Filter ICs/Disabled'
 * '<S94>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/I Gain/External Parameters'
 * '<S95>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Ideal P Gain/Passthrough'
 * '<S96>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S97>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Integrator/Discrete'
 * '<S98>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Integrator ICs/Internal IC'
 * '<S99>'  : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S100>' : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/N Gain/Disabled'
 * '<S101>' : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/P Copy/Disabled'
 * '<S102>' : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Parallel P Gain/External Parameters'
 * '<S103>' : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Reset Signal/Disabled'
 * '<S104>' : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Saturation/Enabled'
 * '<S105>' : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Saturation Fdbk/Disabled'
 * '<S106>' : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Sum/Sum_PI'
 * '<S107>' : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Sum Fdbk/Disabled'
 * '<S108>' : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Tracking Mode/Disabled'
 * '<S109>' : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S110>' : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S111>' : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S112>' : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/postSat Signal/Forward_Path'
 * '<S113>' : 'if_mode/IF_Mode/Curr_PI_Controller/PID Controller2/preSat Signal/Forward_Path'
 * '<S114>' : 'if_mode/IF_Mode/SVPWM/Duty_Caculator'
 * '<S115>' : 'if_mode/IF_Mode/SVPWM/Sector_Select'
 * '<S116>' : 'if_mode/IF_Mode/SVPWM/T4_T6_Caculator'
 * '<S117>' : 'if_mode/IF_Mode/SVPWM/X_Y_Z_Caculator'
 */
#endif                                 /* RTW_HEADER_IF_Mode0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
