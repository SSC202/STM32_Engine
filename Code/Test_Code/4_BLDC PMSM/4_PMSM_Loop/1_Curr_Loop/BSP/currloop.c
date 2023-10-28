/*
 * File: currloop.c
 *
 * Code generated for Simulink model 'currloop'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Oct 28 19:50:01 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "currloop.h"

/* Named constants for Chart: '<S1>/State' */
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
real32_T ThetaOpen;                    /* '<S1>/Merge' */
real32_T id;                           /* '<S5>/Add' */
real32_T iq;                           /* '<S5>/Add1' */

/* Exported data definition */

/* Definition for custom storage class: Struct */
motor_type motor = {
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
void currloop_step(void)
{
  real_T rtb_Divide4;
  real_T rtb_T4;
  real_T rtb_T6;
  real_T rtb_Tb;
  real_T rtb_Tc_tmp_tmp;
  real32_T rtb_Add1_p;
  real32_T rtb_C;
  real32_T rtb_DiscreteTimeIntegrator;
  real32_T rtb_Gain1_p;
  real32_T rtb_Integrator;
  real32_T rtb_SignPreIntegrator;
  real32_T rtb_SignPreSat;
  real32_T rtb_Sum1_j;
  int16_T rtb_IProdOut_d;
  int16_T rtb_IProdOut_g;

  /* Outputs for Atomic SubSystem: '<Root>/currloop' */
  /* Sum: '<S3>/Add1' incorporates:
   *  Gain: '<S3>/Gain'
   *  Gain: '<S3>/Gain1'
   *  Inport: '<Root>/ia'
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ic'
   *  Sum: '<S3>/Add'
   */
  rtb_Integrator = 0.666666687F * rtU.ia - (rtU.ib + rtU.ic) * 0.333333343F;

  /* Chart: '<S1>/State' incorporates:
   *  Inport: '<Root>/Motor_OnOff'
   */
  if (rtDW.temporalCounter_i1 < 32767U) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.is_active_c3_currloop == 0U) {
    rtDW.is_active_c3_currloop = 1U;
    rtDW.is_c3_currloop = IN_IDLE;
  } else {
    switch (rtDW.is_c3_currloop) {
     case IN_AlignStage:
      if (rtU.Motor_OnOff == 0.0) {
        rtDW.is_c3_currloop = IN_IDLE;
      } else if (rtDW.temporalCounter_i1 >= 1000) {
        rtDW.is_c3_currloop = IN_OpenStage;
        rtDW.temporalCounter_i1 = 0U;
      } else {
        rtDW.Motor_State = 2.0;
      }
      break;

     case IN_IDLE:
      if (rtU.Motor_OnOff == 1.0) {
        rtDW.is_c3_currloop = IN_AlignStage;
        rtDW.temporalCounter_i1 = 0U;
      } else {
        rtDW.Motor_State = 1.0;
      }
      break;

     case IN_OpenStage:
      if (rtU.Motor_OnOff == 0.0) {
        rtDW.is_c3_currloop = IN_IDLE;
      } else if (rtDW.temporalCounter_i1 >= 30000) {
        rtDW.is_c3_currloop = IN_RunStage;
      } else {
        rtDW.Motor_State = 3.0;
      }
      break;

     default:
      /* case IN_RunStage: */
      if (rtU.Motor_OnOff == 0.0) {
        rtDW.is_c3_currloop = IN_IDLE;
      } else {
        rtDW.Motor_State = 4.0;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/State' */

  /* SwitchCase: '<S1>/Switch Case' */
  switch ((int32_T)rtDW.Motor_State) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S8>/Constant'
     *  SignalConversion generated from: '<S8>/theta_feedback'
     */
    ThetaOpen = 0.0F;

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S8>/Constant1'
     *  SignalConversion generated from: '<S8>/iq_ref'
     */
    rtDW.Merge1 = 0.0F;

    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem1' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S9>/Constant'
     *  SignalConversion generated from: '<S9>/theta_feedback'
     */
    ThetaOpen = 0.0F;

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S9>/Constant1'
     *  SignalConversion generated from: '<S9>/iq_ref'
     */
    rtDW.Merge1 = 1.0F;

    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem1' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem3' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    /* DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
    rtb_DiscreteTimeIntegrator = rtDW.DiscreteTimeIntegrator_DSTATE_l;

    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S16>/Constant1'
     *  DiscreteIntegrator: '<S16>/Discrete-Time Integrator1'
     *  Math: '<S16>/Mod'
     */
    ThetaOpen = rt_modf_snf(rtDW.DiscreteTimeIntegrator1_DSTATE, 6.28318548F);

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S1>/Constant5'
     *  Inport: '<S11>/iq_ref'
     */
    rtDW.Merge1 = 1.0F;

    /* Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S16>/Gain1'
     *  Product: '<S16>/Product'
     */
    rtDW.DiscreteTimeIntegrator_DSTATE_l += motor.Pn * 83.7758F * 0.333333343F *
      0.0001F;

    /* Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator1' */
    rtDW.DiscreteTimeIntegrator1_DSTATE += 0.0001F * rtb_DiscreteTimeIntegrator;

    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem3' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem2' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S10>/Constant1'
     *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator'
     *  Math: '<S10>/Mod'
     */
    ThetaOpen = rt_modf_snf(rtDW.DiscreteTimeIntegrator_DSTATE, 6.28318548F);

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S1>/Constant7'
     *  Inport: '<S10>/iq_ref'
     */
    rtDW.Merge1 = 1.0F;

    /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S10>/Gain1'
     */
    rtDW.DiscreteTimeIntegrator_DSTATE += motor.Pn * 83.7758F * 0.0001F;

    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem2' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* Trigonometry: '<S1>/SinCos1' */
  rtb_C = cosf(ThetaOpen);

  /* Gain: '<S3>/Gain2' incorporates:
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ic'
   *  Sum: '<S3>/Add2'
   */
  rtb_DiscreteTimeIntegrator = (rtU.ib - rtU.ic) * 0.577350259F;

  /* Trigonometry: '<S1>/SinCos' */
  rtb_Sum1_j = sinf(ThetaOpen);

  /* Sum: '<S5>/Add' incorporates:
   *  Product: '<S5>/Product'
   *  Product: '<S5>/Product1'
   */
  id = rtb_Integrator * rtb_C + rtb_DiscreteTimeIntegrator * rtb_Sum1_j;

  /* Sum: '<S61>/Sum' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S12>/Constant3'
   *  DiscreteIntegrator: '<S52>/Integrator'
   *  Product: '<S57>/PProd Out'
   *  Sum: '<S12>/Sum1'
   */
  rtb_SignPreSat = (0.0F - id) * 0.17F + (real32_T)rtDW.Integrator_DSTATE_n *
    0.0001F;

  /* Saturate: '<S59>/Saturation' */
  if (rtb_SignPreSat > 12.4707661F) {
    rtb_Gain1_p = 12.4707661F;
  } else if (rtb_SignPreSat < -12.4707661F) {
    rtb_Gain1_p = -12.4707661F;
  } else {
    rtb_Gain1_p = rtb_SignPreSat;
  }

  /* End of Saturate: '<S59>/Saturation' */

  /* Sum: '<S5>/Add1' incorporates:
   *  Product: '<S5>/Product2'
   *  Product: '<S5>/Product3'
   */
  iq = rtb_DiscreteTimeIntegrator * rtb_C - rtb_Integrator * rtb_Sum1_j;

  /* Sum: '<S12>/Sum7' */
  rtb_DiscreteTimeIntegrator = rtDW.Merge1 - iq;

  /* Sum: '<S111>/Sum' incorporates:
   *  Constant: '<S12>/Constant1'
   *  DiscreteIntegrator: '<S102>/Integrator'
   *  Product: '<S107>/PProd Out'
   */
  rtb_Integrator = rtb_DiscreteTimeIntegrator * 0.17F + rtDW.Integrator_DSTATE;

  /* Saturate: '<S109>/Saturation' */
  if (rtb_Integrator > 12.4707661F) {
    rtb_Add1_p = 12.4707661F;
  } else if (rtb_Integrator < -12.4707661F) {
    rtb_Add1_p = -12.4707661F;
  } else {
    rtb_Add1_p = rtb_Integrator;
  }

  /* End of Saturate: '<S109>/Saturation' */

  /* Sum: '<S2>/Add' incorporates:
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product1'
   */
  rtb_SignPreIntegrator = rtb_Gain1_p * rtb_C - rtb_Add1_p * rtb_Sum1_j;

  /* Sum: '<S2>/Add1' incorporates:
   *  Product: '<S2>/Product2'
   *  Product: '<S2>/Product3'
   */
  rtb_Add1_p = rtb_Gain1_p * rtb_Sum1_j + rtb_Add1_p * rtb_C;

  /* Gain: '<S13>/Gain1' incorporates:
   *  Gain: '<S14>/Gain2'
   */
  rtb_Gain1_p = 0.866025388F * rtb_SignPreIntegrator;

  /* Gain: '<S13>/Gain2' incorporates:
   *  Gain: '<S14>/Gain1'
   */
  rtb_Sum1_j = 0.5F * rtb_Add1_p;

  /* Sum: '<S13>/Add' incorporates:
   *  Gain: '<S13>/Gain1'
   *  Gain: '<S13>/Gain2'
   *  Gain: '<S13>/Gain3'
   *  Gain: '<S13>/Gain4'
   *  Gain: '<S13>/Gain5'
   *  Sum: '<S13>/Sum'
   *  Sum: '<S13>/Sum1'
   *  Switch: '<S13>/Switch'
   *  Switch: '<S13>/Switch1'
   *  Switch: '<S13>/Switch2'
   */
  rtb_C = (real32_T)((((-rtb_Gain1_p - rtb_Sum1_j > 0.0F) << 2) + ((rtb_Gain1_p
    - rtb_Sum1_j > 0.0F) << 1)) + (rtb_Add1_p > 0.0F));

  /* Product: '<S14>/Divide' incorporates:
   *  Inport: '<Root>/u_bus'
   */
  rtb_T6 = 1.7320508075688772 / rtU.u_bus;

  /* MultiPortSwitch: '<S14>/Multiport Switch' incorporates:
   *  Gain: '<S14>/Gain3'
   *  Gain: '<S14>/Gain4'
   *  Gain: '<S14>/Gain5'
   *  Gain: '<S14>/Gain6'
   *  Product: '<S14>/Divide1'
   *  Product: '<S14>/Divide2'
   *  Product: '<S14>/Divide3'
   *  Sum: '<S14>/Sum'
   *  Sum: '<S14>/Sum1'
   */
  switch ((int32_T)rtb_C) {
   case 1:
    rtb_T4 = (-rtb_Gain1_p + rtb_Sum1_j) * rtb_T6;

    /* MultiPortSwitch: '<S14>/Multiport Switch1' incorporates:
     *  Gain: '<S14>/Gain3'
     *  Product: '<S14>/Divide2'
     *  Product: '<S14>/Divide3'
     *  Sum: '<S14>/Sum'
     *  Sum: '<S14>/Sum1'
     */
    rtb_T6 *= rtb_Gain1_p + rtb_Sum1_j;
    break;

   case 2:
    rtb_T4 = (rtb_Gain1_p + rtb_Sum1_j) * rtb_T6;

    /* MultiPortSwitch: '<S14>/Multiport Switch1' incorporates:
     *  Gain: '<S14>/Gain6'
     *  Product: '<S14>/Divide1'
     *  Product: '<S14>/Divide2'
     *  Sum: '<S14>/Sum'
     */
    rtb_T6 = -(rtb_Add1_p * rtb_T6);
    break;

   case 3:
    rtb_T4 = -((-rtb_Gain1_p + rtb_Sum1_j) * rtb_T6);

    /* MultiPortSwitch: '<S14>/Multiport Switch1' incorporates:
     *  Gain: '<S14>/Gain3'
     *  Gain: '<S14>/Gain4'
     *  Product: '<S14>/Divide1'
     *  Product: '<S14>/Divide3'
     *  Sum: '<S14>/Sum1'
     */
    rtb_T6 *= rtb_Add1_p;
    break;

   case 4:
    rtb_T4 = -(rtb_Add1_p * rtb_T6);

    /* MultiPortSwitch: '<S14>/Multiport Switch1' incorporates:
     *  Gain: '<S14>/Gain3'
     *  Gain: '<S14>/Gain6'
     *  Product: '<S14>/Divide1'
     *  Product: '<S14>/Divide3'
     *  Sum: '<S14>/Sum1'
     */
    rtb_T6 *= -rtb_Gain1_p + rtb_Sum1_j;
    break;

   case 5:
    rtb_T4 = rtb_Add1_p * rtb_T6;

    /* MultiPortSwitch: '<S14>/Multiport Switch1' incorporates:
     *  Gain: '<S14>/Gain5'
     *  Product: '<S14>/Divide1'
     *  Product: '<S14>/Divide2'
     *  Sum: '<S14>/Sum'
     */
    rtb_T6 = -((rtb_Gain1_p + rtb_Sum1_j) * rtb_T6);
    break;

   default:
    rtb_T4 = -((rtb_Gain1_p + rtb_Sum1_j) * rtb_T6);

    /* MultiPortSwitch: '<S14>/Multiport Switch1' incorporates:
     *  Gain: '<S14>/Gain3'
     *  Gain: '<S14>/Gain4'
     *  Gain: '<S14>/Gain5'
     *  Product: '<S14>/Divide2'
     *  Product: '<S14>/Divide3'
     *  Sum: '<S14>/Sum'
     *  Sum: '<S14>/Sum1'
     */
    rtb_T6 = -((-rtb_Gain1_p + rtb_Sum1_j) * rtb_T6);
    break;
  }

  /* End of MultiPortSwitch: '<S14>/Multiport Switch' */

  /* Product: '<S14>/Divide4' incorporates:
   *  Sum: '<S14>/Subtract'
   */
  rtb_Divide4 = 1.0 / (rtb_T4 + rtb_T6);

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Product: '<S14>/Divide5'
   *  Product: '<S14>/Divide6'
   *  Sum: '<S14>/Add'
   *  Switch: '<S14>/Switch1'
   */
  if ((rtb_T4 - 1.0) + rtb_T6 > 0.0) {
    rtb_T4 *= rtb_Divide4;
    rtb_T6 *= rtb_Divide4;
  }

  /* End of Switch: '<S14>/Switch' */

  /* Gain: '<S15>/Gain' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Sum: '<S15>/Add'
   */
  rtb_Divide4 = ((1.0 - rtb_T4) - rtb_T6) * 0.25;

  /* Sum: '<S15>/Add1' incorporates:
   *  Gain: '<S15>/Gain1'
   */
  rtb_Tb = 0.5 * rtb_T4 + rtb_Divide4;

  /* Sum: '<S15>/Add2' incorporates:
   *  Gain: '<S15>/Gain2'
   */
  rtb_Tc_tmp_tmp = 0.5 * rtb_T6 + rtb_Tb;

  /* MultiPortSwitch: '<S15>/Tcm1 ' incorporates:
   *  Gain: '<S15>/Gain2'
   *  Sum: '<S15>/Add2'
   */
  switch ((int32_T)rtb_C) {
   case 1:
    rtb_T4 = rtb_Tb;

    /* MultiPortSwitch: '<S15>/Tcm2' */
    rtb_T6 = rtb_Divide4;

    /* MultiPortSwitch: '<S15>/Tcm3' incorporates:
     *  Sum: '<S15>/Add2'
     */
    rtb_Divide4 = rtb_Tc_tmp_tmp;
    break;

   case 2:
    rtb_T4 = rtb_Divide4;

    /* MultiPortSwitch: '<S15>/Tcm2' incorporates:
     *  Gain: '<S15>/Gain2'
     *  Sum: '<S15>/Add2'
     */
    rtb_T6 = 0.5 * rtb_T6 + rtb_Tb;

    /* MultiPortSwitch: '<S15>/Tcm3' */
    rtb_Divide4 = rtb_Tb;
    break;

   case 3:
    rtb_T4 = rtb_Divide4;

    /* MultiPortSwitch: '<S15>/Tcm2' */
    rtb_T6 = rtb_Tb;

    /* MultiPortSwitch: '<S15>/Tcm3' incorporates:
     *  Sum: '<S15>/Add2'
     */
    rtb_Divide4 = rtb_Tc_tmp_tmp;
    break;

   case 4:
    rtb_T4 = 0.5 * rtb_T6 + rtb_Tb;

    /* MultiPortSwitch: '<S15>/Tcm2' incorporates:
     *  Gain: '<S15>/Gain2'
     *  Sum: '<S15>/Add2'
     */
    rtb_T6 = rtb_Tb;
    break;

   case 5:
    rtb_T4 = 0.5 * rtb_T6 + rtb_Tb;

    /* MultiPortSwitch: '<S15>/Tcm2' incorporates:
     *  Gain: '<S15>/Gain2'
     *  Sum: '<S15>/Add2'
     */
    rtb_T6 = rtb_Divide4;

    /* MultiPortSwitch: '<S15>/Tcm3' */
    rtb_Divide4 = rtb_Tb;
    break;

   default:
    rtb_T4 = rtb_Tb;

    /* MultiPortSwitch: '<S15>/Tcm2' incorporates:
     *  Gain: '<S15>/Gain2'
     *  Sum: '<S15>/Add2'
     */
    rtb_T6 = 0.5 * rtb_T6 + rtb_Tb;
    break;
  }

  /* End of MultiPortSwitch: '<S15>/Tcm1 ' */

  /* Gain: '<S43>/ZeroGain' */
  rtb_Gain1_p = 0.0F * rtb_SignPreSat;

  /* DeadZone: '<S45>/DeadZone' */
  if (rtb_SignPreSat > 12.4707661F) {
    rtb_SignPreSat -= 12.4707661F;
  } else if (rtb_SignPreSat >= -12.4707661F) {
    rtb_SignPreSat = 0.0F;
  } else {
    rtb_SignPreSat -= -12.4707661F;
  }

  /* End of DeadZone: '<S45>/DeadZone' */

  /* Product: '<S49>/IProd Out' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S12>/Constant4'
   *  Sum: '<S12>/Sum1'
   */
  rtb_IProdOut_g = (int16_T)floorf((0.0F - id) * 35.0F);

  /* Gain: '<S93>/ZeroGain' */
  rtb_C = 0.0F * rtb_Integrator;

  /* DeadZone: '<S95>/DeadZone' */
  if (rtb_Integrator > 12.4707661F) {
    rtb_Integrator -= 12.4707661F;
  } else if (rtb_Integrator >= -12.4707661F) {
    rtb_Integrator = 0.0F;
  } else {
    rtb_Integrator -= -12.4707661F;
  }

  /* End of DeadZone: '<S95>/DeadZone' */

  /* Product: '<S99>/IProd Out' incorporates:
   *  Constant: '<S12>/Constant2'
   */
  rtb_DiscreteTimeIntegrator *= 35.0F;

  /* Signum: '<S43>/SignPreSat' */
  if (rtb_SignPreSat < 0.0F) {
    rtb_Add1_p = -1.0F;
  } else if (rtb_SignPreSat > 0.0F) {
    rtb_Add1_p = 1.0F;
  } else if (rtb_SignPreSat == 0.0F) {
    rtb_Add1_p = 0.0F;
  } else {
    rtb_Add1_p = (rtNaNF);
  }

  /* End of Signum: '<S43>/SignPreSat' */

  /* Signum: '<S43>/SignPreIntegrator' */
  if (rtb_IProdOut_g < 0) {
    rtb_IProdOut_d = -1;
  } else {
    rtb_IProdOut_d = (int16_T)(rtb_IProdOut_g > 0);
  }

  /* End of Signum: '<S43>/SignPreIntegrator' */

  /* Switch: '<S43>/Switch' incorporates:
   *  Constant: '<S43>/Constant1'
   *  DataTypeConversion: '<S43>/DataTypeConv1'
   *  DataTypeConversion: '<S43>/DataTypeConv2'
   *  Logic: '<S43>/AND3'
   *  RelationalOperator: '<S43>/Equal1'
   *  RelationalOperator: '<S43>/NotEqual'
   */
  if ((rtb_Gain1_p != rtb_SignPreSat) && ((int8_T)rtb_Add1_p == rtb_IProdOut_d))
  {
    rtb_IProdOut_g = 0;
  }

  /* End of Switch: '<S43>/Switch' */

  /* Update for DiscreteIntegrator: '<S52>/Integrator' */
  rtDW.Integrator_DSTATE_n += rtb_IProdOut_g;

  /* Signum: '<S93>/SignPreSat' */
  if (rtb_Integrator < 0.0F) {
    rtb_SignPreSat = -1.0F;
  } else if (rtb_Integrator > 0.0F) {
    rtb_SignPreSat = 1.0F;
  } else if (rtb_Integrator == 0.0F) {
    rtb_SignPreSat = 0.0F;
  } else {
    rtb_SignPreSat = (rtNaNF);
  }

  /* End of Signum: '<S93>/SignPreSat' */

  /* Signum: '<S93>/SignPreIntegrator' */
  if (rtb_DiscreteTimeIntegrator < 0.0F) {
    rtb_Gain1_p = -1.0F;
  } else if (rtb_DiscreteTimeIntegrator > 0.0F) {
    rtb_Gain1_p = 1.0F;
  } else if (rtb_DiscreteTimeIntegrator == 0.0F) {
    rtb_Gain1_p = 0.0F;
  } else {
    rtb_Gain1_p = (rtNaNF);
  }

  /* End of Signum: '<S93>/SignPreIntegrator' */

  /* Switch: '<S93>/Switch' incorporates:
   *  Constant: '<S93>/Constant1'
   *  DataTypeConversion: '<S93>/DataTypeConv1'
   *  DataTypeConversion: '<S93>/DataTypeConv2'
   *  Logic: '<S93>/AND3'
   *  RelationalOperator: '<S93>/Equal1'
   *  RelationalOperator: '<S93>/NotEqual'
   */
  if ((rtb_C != rtb_Integrator) && ((int8_T)rtb_SignPreSat == (int8_T)
       rtb_Gain1_p)) {
    rtb_DiscreteTimeIntegrator = 0.0F;
  }

  /* End of Switch: '<S93>/Switch' */

  /* Update for DiscreteIntegrator: '<S102>/Integrator' */
  rtDW.Integrator_DSTATE += 0.0001F * rtb_DiscreteTimeIntegrator;

  /* Outport: '<Root>/Dutyout' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Gain: '<S4>/Gain'
   *  Sum: '<S4>/Add'
   *  Sum: '<S4>/Add1'
   *  Sum: '<S4>/Add2'
   */
  rtY.Dutyout[0] = 1.0 - 2.0 * rtb_T4;
  rtY.Dutyout[1] = 1.0 - 2.0 * rtb_T6;
  rtY.Dutyout[2] = 1.0 - 2.0 * rtb_Divide4;

  /* End of Outputs for SubSystem: '<Root>/currloop' */
}

/* Model initialize function */
void currloop_initialize(void)
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
