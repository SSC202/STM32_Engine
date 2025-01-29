/*
 * File: FOC_Mode.h
 *
 * Code generated for Simulink model 'FOC_Mode'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Aug 15 22:20:44 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FOC_Mode_h_
#define RTW_HEADER_FOC_Mode_h_
#ifndef FOC_Mode_COMMON_INCLUDES_
#define FOC_Mode_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* FOC_Mode_COMMON_INCLUDES_ */

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
  real_T Motor_state;                  /* '<S2>/Chart' */
  real_T ZReset;                       /* '<S2>/Chart' */
  real_T cnt;                          /* '<S2>/Chart' */
  real32_T Merge1;                     /* '<S2>/Merge1' */
  real32_T Integrator_DSTATE;          /* '<S154>/Integrator' */
  real32_T Integrator_DSTATE_p;        /* '<S99>/Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S10>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S10>/Discrete-Time Integrator1' */
  int16_T Integrator_DSTATE_ps;        /* '<S49>/Integrator' */
  uint16_T temporalCounter_i1;         /* '<S2>/Chart' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S10>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S10>/Discrete-Time Integrator1' */
  uint8_T is_c3_FOC_Mode;              /* '<S2>/Chart' */
  uint8_T is_active_c3_FOC_Mode;       /* '<S2>/Chart' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T I_a;                        /* '<Root>/I_a' */
  real32_T I_b;                        /* '<Root>/I_b' */
  real32_T I_c;                        /* '<Root>/I_c' */
  real32_T T_pwm;                      /* '<Root>/T_pwm' */
  real32_T u_dc;                       /* '<Root>/u_dc' */
  real32_T Motor_OnOff;                /* '<Root>/Motor_OnOff' */
  real_T SpeedRef;                     /* '<Root>/SpeedRef' */
  real32_T theta;                      /* '<Root>/theta' */
  real32_T SpeedFd;                    /* '<Root>/SpeedFd' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Duty[3];                      /* '<Root>/Duty' */
} ExtY;

/* Type definition for custom storage class: Struct */
typedef struct Motor_tag {
  real32_T Pn;                         /* Referenced by: '<S10>/Gain' */
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
extern real32_T i_alpha;               /* '<S7>/Add2' */
extern real32_T ThetaOpen;             /* '<S2>/Merge' */
extern real32_T i_beta;                /* '<S7>/Gain2' */
extern real32_T i_q;                   /* '<S11>/Add1' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real32_T spd_ki;                /* Variable: spd_ki
                                        * Referenced by: '<S151>/Integral Gain'
                                        */
extern real32_T spd_kp;                /* Variable: spd_kp
                                        * Referenced by: '<S159>/Proportional Gain'
                                        */

/* Model entry point functions */
extern void FOC_Mode_initialize(void);
extern void FOC_Mode_step(void);

/* Exported data declaration */

/* Declaration for custom storage class: Struct */
extern Motor_type Motor;

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Scope' : Unused code path elimination
 * Block '<S8>/Scope' : Unused code path elimination
 * Block '<S11>/Scope' : Unused code path elimination
 * Block '<S116>/Scope' : Unused code path elimination
 * Block '<S116>/Scope1' : Unused code path elimination
 * Block '<S117>/Scope' : Unused code path elimination
 * Block '<S118>/Scope' : Unused code path elimination
 * Block '<S118>/Scope1' : Unused code path elimination
 * Block '<S119>/Scope' : Unused code path elimination
 * Block '<S2>/Scope1' : Unused code path elimination
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
 * hilite_system('FOC/FOC_Mode')    - opens subsystem FOC/FOC_Mode
 * hilite_system('FOC/FOC_Mode/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FOC'
 * '<S1>'   : 'FOC/FOC_Mode'
 * '<S2>'   : 'FOC/FOC_Mode/IF_Mode'
 * '<S3>'   : 'FOC/FOC_Mode/Speed_PI_Controller'
 * '<S4>'   : 'FOC/FOC_Mode/IF_Mode/Align'
 * '<S5>'   : 'FOC/FOC_Mode/IF_Mode/AntiPark'
 * '<S6>'   : 'FOC/FOC_Mode/IF_Mode/Chart'
 * '<S7>'   : 'FOC/FOC_Mode/IF_Mode/Clark'
 * '<S8>'   : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller'
 * '<S9>'   : 'FOC/FOC_Mode/IF_Mode/IDLE'
 * '<S10>'  : 'FOC/FOC_Mode/IF_Mode/Open'
 * '<S11>'  : 'FOC/FOC_Mode/IF_Mode/Park'
 * '<S12>'  : 'FOC/FOC_Mode/IF_Mode/Run'
 * '<S13>'  : 'FOC/FOC_Mode/IF_Mode/SVPWM'
 * '<S14>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1'
 * '<S15>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2'
 * '<S16>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Anti-windup'
 * '<S17>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/D Gain'
 * '<S18>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Filter'
 * '<S19>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Filter ICs'
 * '<S20>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/I Gain'
 * '<S21>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Ideal P Gain'
 * '<S22>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Ideal P Gain Fdbk'
 * '<S23>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Integrator'
 * '<S24>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Integrator ICs'
 * '<S25>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/N Copy'
 * '<S26>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/N Gain'
 * '<S27>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/P Copy'
 * '<S28>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Parallel P Gain'
 * '<S29>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Reset Signal'
 * '<S30>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Saturation'
 * '<S31>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Saturation Fdbk'
 * '<S32>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Sum'
 * '<S33>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Sum Fdbk'
 * '<S34>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Tracking Mode'
 * '<S35>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Tracking Mode Sum'
 * '<S36>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Tsamp - Integral'
 * '<S37>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Tsamp - Ngain'
 * '<S38>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/postSat Signal'
 * '<S39>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/preSat Signal'
 * '<S40>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S41>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S42>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S43>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/D Gain/Disabled'
 * '<S44>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Filter/Disabled'
 * '<S45>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Filter ICs/Disabled'
 * '<S46>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/I Gain/External Parameters'
 * '<S47>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Ideal P Gain/Passthrough'
 * '<S48>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S49>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Integrator/Discrete'
 * '<S50>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Integrator ICs/Internal IC'
 * '<S51>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S52>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/N Gain/Disabled'
 * '<S53>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/P Copy/Disabled'
 * '<S54>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Parallel P Gain/External Parameters'
 * '<S55>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Reset Signal/Disabled'
 * '<S56>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Saturation/Enabled'
 * '<S57>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Saturation Fdbk/Disabled'
 * '<S58>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Sum/Sum_PI'
 * '<S59>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Sum Fdbk/Disabled'
 * '<S60>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Tracking Mode/Disabled'
 * '<S61>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S62>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S63>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S64>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/postSat Signal/Forward_Path'
 * '<S65>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller1/preSat Signal/Forward_Path'
 * '<S66>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Anti-windup'
 * '<S67>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/D Gain'
 * '<S68>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Filter'
 * '<S69>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Filter ICs'
 * '<S70>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/I Gain'
 * '<S71>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Ideal P Gain'
 * '<S72>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Ideal P Gain Fdbk'
 * '<S73>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Integrator'
 * '<S74>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Integrator ICs'
 * '<S75>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/N Copy'
 * '<S76>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/N Gain'
 * '<S77>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/P Copy'
 * '<S78>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Parallel P Gain'
 * '<S79>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Reset Signal'
 * '<S80>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Saturation'
 * '<S81>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Saturation Fdbk'
 * '<S82>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Sum'
 * '<S83>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Sum Fdbk'
 * '<S84>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Tracking Mode'
 * '<S85>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Tracking Mode Sum'
 * '<S86>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Tsamp - Integral'
 * '<S87>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Tsamp - Ngain'
 * '<S88>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/postSat Signal'
 * '<S89>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/preSat Signal'
 * '<S90>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel'
 * '<S91>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S92>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S93>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/D Gain/Disabled'
 * '<S94>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Filter/Disabled'
 * '<S95>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Filter ICs/Disabled'
 * '<S96>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/I Gain/External Parameters'
 * '<S97>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Ideal P Gain/Passthrough'
 * '<S98>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S99>'  : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Integrator/Discrete'
 * '<S100>' : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Integrator ICs/Internal IC'
 * '<S101>' : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S102>' : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/N Gain/Disabled'
 * '<S103>' : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/P Copy/Disabled'
 * '<S104>' : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Parallel P Gain/External Parameters'
 * '<S105>' : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Reset Signal/Disabled'
 * '<S106>' : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Saturation/Enabled'
 * '<S107>' : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Saturation Fdbk/Disabled'
 * '<S108>' : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Sum/Sum_PI'
 * '<S109>' : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Sum Fdbk/Disabled'
 * '<S110>' : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Tracking Mode/Disabled'
 * '<S111>' : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S112>' : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S113>' : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S114>' : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/postSat Signal/Forward_Path'
 * '<S115>' : 'FOC/FOC_Mode/IF_Mode/Curr_PI_Controller/PID Controller2/preSat Signal/Forward_Path'
 * '<S116>' : 'FOC/FOC_Mode/IF_Mode/SVPWM/Duty_Caculator'
 * '<S117>' : 'FOC/FOC_Mode/IF_Mode/SVPWM/Sector_Select'
 * '<S118>' : 'FOC/FOC_Mode/IF_Mode/SVPWM/T4_T6_Caculator'
 * '<S119>' : 'FOC/FOC_Mode/IF_Mode/SVPWM/X_Y_Z_Caculator'
 * '<S120>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3'
 * '<S121>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Anti-windup'
 * '<S122>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/D Gain'
 * '<S123>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Filter'
 * '<S124>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Filter ICs'
 * '<S125>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/I Gain'
 * '<S126>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Ideal P Gain'
 * '<S127>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Ideal P Gain Fdbk'
 * '<S128>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Integrator'
 * '<S129>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Integrator ICs'
 * '<S130>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/N Copy'
 * '<S131>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/N Gain'
 * '<S132>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/P Copy'
 * '<S133>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Parallel P Gain'
 * '<S134>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Reset Signal'
 * '<S135>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Saturation'
 * '<S136>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Saturation Fdbk'
 * '<S137>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Sum'
 * '<S138>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Sum Fdbk'
 * '<S139>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Tracking Mode'
 * '<S140>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Tracking Mode Sum'
 * '<S141>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Tsamp - Integral'
 * '<S142>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Tsamp - Ngain'
 * '<S143>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/postSat Signal'
 * '<S144>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/preSat Signal'
 * '<S145>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Anti-windup/Disc. Clamping Parallel'
 * '<S146>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S147>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S148>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/D Gain/Disabled'
 * '<S149>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Filter/Disabled'
 * '<S150>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Filter ICs/Disabled'
 * '<S151>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/I Gain/Internal Parameters'
 * '<S152>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Ideal P Gain/Passthrough'
 * '<S153>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S154>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Integrator/Discrete'
 * '<S155>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Integrator ICs/Internal IC'
 * '<S156>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/N Copy/Disabled wSignal Specification'
 * '<S157>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/N Gain/Disabled'
 * '<S158>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/P Copy/Disabled'
 * '<S159>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S160>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Reset Signal/Disabled'
 * '<S161>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Saturation/Enabled'
 * '<S162>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Saturation Fdbk/Disabled'
 * '<S163>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Sum/Sum_PI'
 * '<S164>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Sum Fdbk/Disabled'
 * '<S165>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Tracking Mode/Disabled'
 * '<S166>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S167>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Tsamp - Integral/Passthrough'
 * '<S168>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S169>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/postSat Signal/Forward_Path'
 * '<S170>' : 'FOC/FOC_Mode/Speed_PI_Controller/PID Controller3/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_FOC_Mode_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
