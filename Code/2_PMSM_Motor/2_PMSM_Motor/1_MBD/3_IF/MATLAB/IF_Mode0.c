/*
 * File: IF_Mode0.c
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

#include "IF_Mode0.h"
#include "rtwtypes.h"
#include <math.h>
#include <float.h>
#include <stddef.h>

/* Named constants for Chart: '<S1>/Chart' */
#define IN_AlignStage                  ((uint8_T)1U)
#define IN_IDLE                        ((uint8_T)2U)
#define IN_OpenStage                   ((uint8_T)3U)
#define IN_RunStage                    ((uint8_T)4U)
#define NumBitsPerChar                 8U
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */

/* Exported block signals */
real32_T i_alpha;                      /* '<S5>/Add2' */
real32_T ThetaOpen;                    /* '<S1>/Merge' */
real32_T i_beta;                       /* '<S5>/Gain2' */
real32_T i_d;                          /* '<S9>/Add' */
real32_T i_q;                          /* '<S9>/Add1' */

/* Exported data definition */

/* Definition for custom storage class: Struct */
Motor_type Motor = {
  /* Pn */
  4.0F
};

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real32_T rt_modf_snf(real32_T u0, real32_T u1);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);

#define NOT_USING_NONFINITE_LITERALS   1

extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static void rt_InitInfAndNaN(size_t realSize);
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
static real_T rtGetInf(void);
static real32_T rtGetInfF(void);
static real_T rtGetMinusInf(void);
static real32_T rtGetMinusInfF(void);

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0.0F } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
static void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  boolean_T result = (boolean_T) 0;
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  if (bitsPerReal == 32U) {
    result = rtIsNaNF((real32_T)value);
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.fltVal = value;
    result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                         ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                          (tmpVal.bitVal.words.wordL != 0) ));
  }

  return result;
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  IEEESingle tmp;
  tmp.wordL.wordLreal = value;
  return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                     (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

real32_T rt_modf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  y = u0;
  if (u1 == 0.0F) {
    if (u0 == 0.0F) {
      y = u1;
    }
  } else if (rtIsNaNF(u0) || rtIsNaNF(u1) || rtIsInfF(u0)) {
    y = (rtNaNF);
  } else if (u0 == 0.0F) {
    y = 0.0F / u1;
  } else if (rtIsInfF(u1)) {
    if ((u1 < 0.0F) != (u0 < 0.0F)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmodf(u0, u1);
    yEq = (y == 0.0F);
    if ((!yEq) && (u1 > floorf(u1))) {
      real32_T q;
      q = fabsf(u0 / u1);
      yEq = !(fabsf(q - floorf(q + 0.5F)) > FLT_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0F;
    } else if ((u0 < 0.0F) != (u1 < 0.0F)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void IF_Mode0_step(void)
{
  int32_T rtb_Add;
  real32_T rtb_Add2;
  real32_T rtb_DeadZone;
  real32_T rtb_Divide1;
  real32_T rtb_Divide_i;
  real32_T rtb_Divide_j;
  real32_T rtb_Gain2_f;
  real32_T rtb_IProdOut;
  real32_T rtb_Saturation;
  int16_T rtb_IProdOut_d;
  int8_T tmp;
  int8_T tmp_0;
  boolean_T rtb_AND3_b;

  /* Outputs for Atomic SubSystem: '<Root>/IF_Mode' */
  /* Chart: '<S1>/Chart' incorporates:
   *  Inport: '<Root>/Motor_OnOff'
   */
  if (rtDW.temporalCounter_i1 < 32767U) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.is_active_c3_IF_Mode0 == 0U) {
    rtDW.is_active_c3_IF_Mode0 = 1U;
    rtDW.is_c3_IF_Mode0 = IN_IDLE;
  } else {
    switch (rtDW.is_c3_IF_Mode0) {
     case IN_AlignStage:
      if (rtDW.temporalCounter_i1 >= 1000) {
        rtDW.is_c3_IF_Mode0 = IN_OpenStage;
        rtDW.temporalCounter_i1 = 0U;
      } else if (rtU.Motor_OnOff == 0.0F) {
        rtDW.is_c3_IF_Mode0 = IN_IDLE;
      } else {
        rtDW.Motor_state = 2.0;
      }
      break;

     case IN_IDLE:
      if (rtU.Motor_OnOff == 1.0F) {
        rtDW.is_c3_IF_Mode0 = IN_AlignStage;
        rtDW.temporalCounter_i1 = 0U;
      } else {
        rtDW.Motor_state = 1.0;
      }
      break;

     case IN_OpenStage:
      if (rtU.Motor_OnOff == 0.0F) {
        rtDW.is_c3_IF_Mode0 = IN_IDLE;
      } else if (rtDW.temporalCounter_i1 >= 30000) {
        rtDW.is_c3_IF_Mode0 = IN_RunStage;
      } else {
        rtDW.Motor_state = 3.0;
      }
      break;

     default:
      /* case IN_RunStage: */
      if (rtU.Motor_OnOff == 0.0F) {
        rtDW.is_c3_IF_Mode0 = IN_IDLE;
      } else {
        rtDW.Motor_state = 4.0;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Chart' */

  /* SwitchCase: '<S1>/Switch Case' */
  switch ((int32_T)rtDW.Motor_state) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/IDLE' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S7>/Constant'
     *  SignalConversion generated from: '<S7>/theta_fd'
     */
    ThetaOpen = 0.0F;

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S7>/Constant1'
     *  SignalConversion generated from: '<S7>/iq_ref'
     */
    rtDW.Merge1 = 0.0F;

    /* End of Outputs for SubSystem: '<S1>/IDLE' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S1>/Align' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S2>/Constant'
     *  SignalConversion generated from: '<S2>/theta_fd'
     */
    ThetaOpen = 0.0F;

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S2>/Constant1'
     *  SignalConversion generated from: '<S2>/iq_ref'
     */
    rtDW.Merge1 = 2.0F;

    /* End of Outputs for SubSystem: '<S1>/Align' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S1>/Open' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S8>/Constant1'
     *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator1'
     *  Math: '<S8>/Mod'
     */
    ThetaOpen = rt_modf_snf(rtDW.DiscreteTimeIntegrator1_DSTAT_j, 6.28318548F);

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S1>/Constant5'
     *  SignalConversion generated from: '<S8>/iq_ref'
     */
    rtDW.Merge1 = 1.0F;

    /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator'
     */
    rtDW.DiscreteTimeIntegrator1_DSTAT_j += 0.0001F *
      rtDW.DiscreteTimeIntegrator_DSTATE;

    /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S8>/Gain'
     *  Product: '<S8>/Product'
     */
    rtDW.DiscreteTimeIntegrator_DSTATE += Motor.Pn * 62.8318558F * 0.333333343F *
      0.0001F;

    /* End of Outputs for SubSystem: '<S1>/Open' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S1>/Run' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S10>/Constant1'
     *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator1'
     *  Math: '<S10>/Mod'
     */
    ThetaOpen = rt_modf_snf(rtDW.DiscreteTimeIntegrator1_DSTATE, 6.28318548F);

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S1>/Constant8'
     *  SignalConversion generated from: '<S10>/iq_ref'
     */
    rtDW.Merge1 = 1.0F;

    /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator1' incorporates:
     *  Gain: '<S10>/Gain'
     */
    rtDW.DiscreteTimeIntegrator1_DSTATE += Motor.Pn * 62.8318558F * 0.0001F;

    /* End of Outputs for SubSystem: '<S1>/Run' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* Sum: '<S5>/Add2' incorporates:
   *  Gain: '<S5>/Gain'
   *  Gain: '<S5>/Gain1'
   *  Inport: '<Root>/I_a'
   *  Inport: '<Root>/I_b'
   *  Inport: '<Root>/I_c'
   *  Sum: '<S5>/Add'
   */
  i_alpha = 0.666666687F * rtU.I_a - (rtU.I_b + rtU.I_c) * 0.333333343F;

  /* Trigonometry: '<S9>/Trigonometric Function1' incorporates:
   *  Trigonometry: '<S3>/Trigonometric Function1'
   */
  rtb_Divide1 = cosf(ThetaOpen);

  /* Gain: '<S5>/Gain2' incorporates:
   *  Inport: '<Root>/I_b'
   *  Inport: '<Root>/I_c'
   *  Sum: '<S5>/Add1'
   */
  i_beta = (rtU.I_b - rtU.I_c) * 0.577350259F;

  /* Trigonometry: '<S9>/Trigonometric Function' incorporates:
   *  Trigonometry: '<S3>/Trigonometric Function'
   */
  rtb_Divide_j = sinf(ThetaOpen);

  /* Sum: '<S9>/Add' incorporates:
   *  Product: '<S9>/Product'
   *  Product: '<S9>/Product1'
   *  Trigonometry: '<S9>/Trigonometric Function'
   *  Trigonometry: '<S9>/Trigonometric Function1'
   */
  i_d = i_alpha * rtb_Divide1 + i_beta * rtb_Divide_j;

  /* Sum: '<S56>/Sum' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant3'
   *  DiscreteIntegrator: '<S47>/Integrator'
   *  Product: '<S52>/PProd Out'
   *  Sum: '<S6>/Sum1'
   */
  rtb_DeadZone = (0.0F - i_d) * 0.17F + (real32_T)rtDW.Integrator_DSTATE_l *
    0.0001F;

  /* Saturate: '<S54>/Saturation' */
  if (rtb_DeadZone > 12.4707661F) {
    rtb_Saturation = 12.4707661F;
  } else if (rtb_DeadZone < -12.4707661F) {
    rtb_Saturation = -12.4707661F;
  } else {
    rtb_Saturation = rtb_DeadZone;
  }

  /* End of Saturate: '<S54>/Saturation' */

  /* Sum: '<S9>/Add1' incorporates:
   *  Product: '<S9>/Product2'
   *  Product: '<S9>/Product3'
   *  Trigonometry: '<S9>/Trigonometric Function'
   *  Trigonometry: '<S9>/Trigonometric Function1'
   */
  i_q = i_beta * rtb_Divide1 - i_alpha * rtb_Divide_j;

  /* Sum: '<S6>/Sum7' */
  rtb_IProdOut = rtDW.Merge1 - i_q;

  /* Sum: '<S106>/Sum' incorporates:
   *  Constant: '<S6>/Constant1'
   *  DiscreteIntegrator: '<S97>/Integrator'
   *  Product: '<S102>/PProd Out'
   */
  rtb_Gain2_f = rtb_IProdOut * 0.17F + rtDW.Integrator_DSTATE;

  /* Saturate: '<S104>/Saturation' */
  if (rtb_Gain2_f > 12.4707661F) {
    rtb_Add2 = 12.4707661F;
  } else if (rtb_Gain2_f < -12.4707661F) {
    rtb_Add2 = -12.4707661F;
  } else {
    rtb_Add2 = rtb_Gain2_f;
  }

  /* End of Saturate: '<S104>/Saturation' */

  /* Sum: '<S3>/Add' incorporates:
   *  Product: '<S3>/Product'
   *  Product: '<S3>/Product3'
   */
  rtb_Divide_i = rtb_Saturation * rtb_Divide1 - rtb_Add2 * rtb_Divide_j;

  /* Sum: '<S3>/Add1' incorporates:
   *  Product: '<S3>/Product1'
   *  Product: '<S3>/Product2'
   */
  rtb_Divide1 = rtb_Saturation * rtb_Divide_j + rtb_Add2 * rtb_Divide1;

  /* DeadZone: '<S40>/DeadZone' */
  if (rtb_DeadZone > 12.4707661F) {
    rtb_DeadZone -= 12.4707661F;
  } else if (rtb_DeadZone >= -12.4707661F) {
    rtb_DeadZone = 0.0F;
  } else {
    rtb_DeadZone -= -12.4707661F;
  }

  /* End of DeadZone: '<S40>/DeadZone' */

  /* Product: '<S44>/IProd Out' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant4'
   *  Sum: '<S6>/Sum1'
   */
  rtb_IProdOut_d = (int16_T)floorf((0.0F - i_d) * 35.0F);

  /* DeadZone: '<S90>/DeadZone' */
  if (rtb_Gain2_f > 12.4707661F) {
    rtb_Gain2_f -= 12.4707661F;
  } else if (rtb_Gain2_f >= -12.4707661F) {
    rtb_Gain2_f = 0.0F;
  } else {
    rtb_Gain2_f -= -12.4707661F;
  }

  /* End of DeadZone: '<S90>/DeadZone' */

  /* Product: '<S94>/IProd Out' incorporates:
   *  Constant: '<S6>/Constant2'
   */
  rtb_IProdOut *= 35.0F;

  /* Switch: '<S88>/Switch1' incorporates:
   *  Constant: '<S88>/Clamping_zero'
   *  Constant: '<S88>/Constant'
   *  Constant: '<S88>/Constant2'
   *  RelationalOperator: '<S88>/fix for DT propagation issue'
   */
  if (rtb_Gain2_f > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S88>/Switch2' incorporates:
   *  Constant: '<S88>/Clamping_zero'
   *  Constant: '<S88>/Constant3'
   *  Constant: '<S88>/Constant4'
   *  RelationalOperator: '<S88>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Logic: '<S88>/AND3' incorporates:
   *  Constant: '<S88>/Clamping_zero'
   *  RelationalOperator: '<S88>/Equal1'
   *  RelationalOperator: '<S88>/Relational Operator'
   *  Switch: '<S88>/Switch1'
   *  Switch: '<S88>/Switch2'
   */
  rtb_AND3_b = ((rtb_Gain2_f != 0.0F) && (tmp == tmp_0));

  /* Gain: '<S114>/Gain1' incorporates:
   *  Inport: '<Root>/T_pwm'
   */
  rtb_Add2 = 0.25F * rtU.T_pwm;

  /* Gain: '<S115>/Gain' incorporates:
   *  Gain: '<S117>/Gain1'
   */
  rtb_Gain2_f = 0.866025388F * rtb_Divide_i;

  /* Gain: '<S115>/Gain1' incorporates:
   *  Gain: '<S117>/Gain2'
   */
  rtb_Divide_i = 0.5F * rtb_Divide1;

  /* Sum: '<S115>/Add' incorporates:
   *  Gain: '<S115>/Gain'
   *  Gain: '<S115>/Gain1'
   *  Gain: '<S115>/Gain2'
   *  Gain: '<S115>/Gain3'
   *  Sum: '<S115>/Add1'
   *  Sum: '<S115>/Add2'
   *  Switch: '<S115>/ A Switch'
   *  Switch: '<S115>/ B Switch'
   *  Switch: '<S115>/ C Switch'
   */
  rtb_Add = (((rtb_Gain2_f - rtb_Divide_i > 0.0F) << 1) + (rtb_Divide1 > 0.0F))
    + (((0.0F - rtb_Gain2_f) - rtb_Divide_i > 0.0F) << 2);

  /* Product: '<S117>/Divide' incorporates:
   *  Gain: '<S117>/Gain'
   *  Inport: '<Root>/T_pwm'
   *  Inport: '<Root>/u_dc'
   */
  rtb_Divide_j = 1.73205078F * rtU.T_pwm / rtU.u_dc;

  /* MultiPortSwitch: '<S116>/T4 Switch' incorporates:
   *  Gain: '<S116>/Gain'
   *  Gain: '<S116>/Gain1'
   *  Gain: '<S116>/Gain2'
   *  Product: '<S117>/Product'
   *  Product: '<S117>/Product1'
   *  Product: '<S117>/Product2'
   *  Sum: '<S117>/Add'
   *  Sum: '<S117>/Add1'
   */
  switch (rtb_Add) {
   case 1:
    rtb_Saturation = (rtb_Divide_i - rtb_Gain2_f) * rtb_Divide_j;

    /* MultiPortSwitch: '<S116>/T6 Switch' incorporates:
     *  Product: '<S117>/Product1'
     *  Product: '<S117>/Product2'
     *  Sum: '<S117>/Add'
     *  Sum: '<S117>/Add1'
     */
    rtb_Gain2_f = (rtb_Gain2_f + rtb_Divide_i) * rtb_Divide_j;
    break;

   case 2:
    rtb_Saturation = (rtb_Gain2_f + rtb_Divide_i) * rtb_Divide_j;

    /* MultiPortSwitch: '<S116>/T6 Switch' incorporates:
     *  Gain: '<S116>/Gain'
     *  Product: '<S117>/Product'
     *  Product: '<S117>/Product1'
     *  Sum: '<S117>/Add'
     */
    rtb_Gain2_f = -(rtb_Divide1 * rtb_Divide_j);
    break;

   case 3:
    rtb_Saturation = -((rtb_Divide_i - rtb_Gain2_f) * rtb_Divide_j);

    /* MultiPortSwitch: '<S116>/T6 Switch' incorporates:
     *  Gain: '<S116>/Gain2'
     *  Product: '<S117>/Product'
     *  Product: '<S117>/Product2'
     *  Sum: '<S117>/Add1'
     */
    rtb_Gain2_f = rtb_Divide1 * rtb_Divide_j;
    break;

   case 4:
    rtb_Saturation = -(rtb_Divide1 * rtb_Divide_j);

    /* MultiPortSwitch: '<S116>/T6 Switch' incorporates:
     *  Gain: '<S116>/Gain'
     *  Product: '<S117>/Product'
     *  Product: '<S117>/Product2'
     *  Sum: '<S117>/Add1'
     */
    rtb_Gain2_f = (rtb_Divide_i - rtb_Gain2_f) * rtb_Divide_j;
    break;

   case 5:
    rtb_Saturation = rtb_Divide1 * rtb_Divide_j;

    /* MultiPortSwitch: '<S116>/T6 Switch' incorporates:
     *  Gain: '<S116>/Gain1'
     *  Product: '<S117>/Product'
     *  Product: '<S117>/Product1'
     *  Sum: '<S117>/Add'
     */
    rtb_Gain2_f = -((rtb_Gain2_f + rtb_Divide_i) * rtb_Divide_j);
    break;

   default:
    rtb_Saturation = -((rtb_Gain2_f + rtb_Divide_i) * rtb_Divide_j);

    /* MultiPortSwitch: '<S116>/T6 Switch' incorporates:
     *  Gain: '<S116>/Gain1'
     *  Gain: '<S116>/Gain2'
     *  Product: '<S117>/Product1'
     *  Product: '<S117>/Product2'
     *  Sum: '<S117>/Add'
     *  Sum: '<S117>/Add1'
     */
    rtb_Gain2_f = -((rtb_Divide_i - rtb_Gain2_f) * rtb_Divide_j);
    break;
  }

  /* End of MultiPortSwitch: '<S116>/T4 Switch' */

  /* Sum: '<S116>/Add1' incorporates:
   *  Sum: '<S116>/Add'
   */
  rtb_Divide_i = rtb_Saturation + rtb_Gain2_f;

  /* Product: '<S116>/Divide' incorporates:
   *  Inport: '<Root>/T_pwm'
   *  Sum: '<S116>/Add1'
   */
  rtb_Divide_j = rtU.T_pwm / rtb_Divide_i;

  /* Sum: '<S116>/Add' incorporates:
   *  Inport: '<Root>/T_pwm'
   */
  rtb_Divide_i -= rtU.T_pwm;

  /* Switch: '<S116>/Switch' incorporates:
   *  Product: '<S116>/Product'
   *  Product: '<S116>/Product1'
   *  Switch: '<S116>/Switch1'
   */
  if (rtb_Divide_i > 0.0F) {
    rtb_Saturation *= rtb_Divide_j;
    rtb_Gain2_f *= rtb_Divide_j;
  }

  /* Gain: '<S114>/Gain' incorporates:
   *  Switch: '<S116>/Switch'
   */
  rtb_Divide1 = 0.25F * rtb_Saturation;

  /* Gain: '<S114>/Gain2' incorporates:
   *  Switch: '<S116>/Switch1'
   */
  rtb_Divide_i = 0.25F * rtb_Gain2_f;

  /* Sum: '<S114>/Add' */
  rtb_Gain2_f = (rtb_Add2 - rtb_Divide1) - rtb_Divide_i;

  /* Sum: '<S114>/Add1' incorporates:
   *  Sum: '<S114>/Add2'
   */
  rtb_Divide1 += rtb_Add2;
  rtb_Saturation = rtb_Divide1 - rtb_Divide_i;

  /* Sum: '<S114>/Add2' */
  rtb_Add2 = rtb_Divide1 + rtb_Divide_i;

  /* MultiPortSwitch: '<S114>/Ta Switch' */
  switch (rtb_Add) {
   case 1:
    rtb_Divide_i = rtb_Saturation;
    break;

   case 2:
    rtb_Divide_i = rtb_Gain2_f;
    break;

   case 3:
    rtb_Divide_i = rtb_Gain2_f;
    break;

   case 4:
    rtb_Divide_i = rtb_Add2;
    break;

   case 5:
    rtb_Divide_i = rtb_Add2;
    break;

   default:
    rtb_Divide_i = rtb_Saturation;
    break;
  }

  /* End of MultiPortSwitch: '<S114>/Ta Switch' */

  /* Product: '<S114>/Divide' incorporates:
   *  Inport: '<Root>/T_pwm'
   */
  rtb_Divide_i /= rtU.T_pwm;

  /* MultiPortSwitch: '<S114>/Tc Switch' */
  switch (rtb_Add) {
   case 1:
    rtb_Divide1 = rtb_Add2;
    break;

   case 2:
    rtb_Divide1 = rtb_Saturation;
    break;

   case 3:
    rtb_Divide1 = rtb_Add2;
    break;

   case 4:
    rtb_Divide1 = rtb_Gain2_f;
    break;

   case 5:
    rtb_Divide1 = rtb_Saturation;
    break;

   default:
    rtb_Divide1 = rtb_Gain2_f;
    break;
  }

  /* End of MultiPortSwitch: '<S114>/Tc Switch' */

  /* Product: '<S114>/Divide1' incorporates:
   *  Inport: '<Root>/T_pwm'
   */
  rtb_Divide1 /= rtU.T_pwm;

  /* MultiPortSwitch: '<S114>/Tb Switch' */
  switch (rtb_Add) {
   case 1:
    rtb_Add2 = rtb_Gain2_f;
    break;

   case 2:
    break;

   case 3:
    rtb_Add2 = rtb_Saturation;
    break;

   case 4:
    rtb_Add2 = rtb_Saturation;
    break;

   case 5:
    rtb_Add2 = rtb_Gain2_f;
    break;
  }

  /* End of MultiPortSwitch: '<S114>/Tb Switch' */

  /* Switch: '<S38>/Switch1' incorporates:
   *  Constant: '<S38>/Constant'
   *  Constant: '<S38>/Constant2'
   *  RelationalOperator: '<S38>/fix for DT propagation issue'
   */
  if (rtb_DeadZone > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S38>/Switch2' incorporates:
   *  Constant: '<S38>/Clamping_zero'
   *  Constant: '<S38>/Constant3'
   *  Constant: '<S38>/Constant4'
   *  RelationalOperator: '<S38>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut_d > 0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S38>/Switch' incorporates:
   *  Constant: '<S38>/Constant1'
   *  Logic: '<S38>/AND3'
   *  RelationalOperator: '<S38>/Equal1'
   *  RelationalOperator: '<S38>/Relational Operator'
   *  Switch: '<S38>/Switch1'
   *  Switch: '<S38>/Switch2'
   */
  if ((rtb_DeadZone != 0.0F) && (tmp == tmp_0)) {
    rtb_IProdOut_d = 0;
  }

  /* Update for DiscreteIntegrator: '<S47>/Integrator' incorporates:
   *  Switch: '<S38>/Switch'
   */
  rtDW.Integrator_DSTATE_l += rtb_IProdOut_d;

  /* Switch: '<S88>/Switch' incorporates:
   *  Constant: '<S88>/Constant1'
   */
  if (rtb_AND3_b) {
    rtb_IProdOut = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S97>/Integrator' incorporates:
   *  Switch: '<S88>/Switch'
   */
  rtDW.Integrator_DSTATE += 0.0001F * rtb_IProdOut;

  /* Outport: '<Root>/Duty' incorporates:
   *  Constant: '<S11>/Constant'
   *  Gain: '<S11>/Gain'
   *  Inport: '<Root>/T_pwm'
   *  Product: '<S114>/Divide2'
   *  Sum: '<S11>/Sum'
   */
  rtY.Duty[0] = 1.0 - 2.0F * rtb_Divide_i;
  rtY.Duty[1] = 1.0 - rtb_Add2 / rtU.T_pwm * 2.0F;
  rtY.Duty[2] = 1.0 - 2.0F * rtb_Divide1;

  /* End of Outputs for SubSystem: '<Root>/IF_Mode' */
}

/* Model initialize function */
void IF_Mode0_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
