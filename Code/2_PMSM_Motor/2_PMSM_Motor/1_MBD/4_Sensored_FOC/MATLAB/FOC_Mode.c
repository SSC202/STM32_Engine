/*
 * File: FOC_Mode.c
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

#include "FOC_Mode.h"
#include "rtwtypes.h"
#include <math.h>
#include <float.h>
#include <stddef.h>

/* Named constants for Chart: '<S2>/Chart' */
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
real32_T i_alpha;                      /* '<S7>/Add2' */
real32_T ThetaOpen;                    /* '<S2>/Merge' */
real32_T i_beta;                       /* '<S7>/Gain2' */
real32_T i_q;                          /* '<S11>/Add1' */

/* Exported block parameters */
real32_T spd_ki = 0.0144F;             /* Variable: spd_ki
                                        * Referenced by: '<S151>/Integral Gain'
                                        */
real32_T spd_kp = 0.3389F;             /* Variable: spd_kp
                                        * Referenced by: '<S159>/Proportional Gain'
                                        */

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
void FOC_Mode_step(void)
{
  int32_T rtb_Add;
  real32_T rtb_Add2;
  real32_T rtb_DeadZone;
  real32_T rtb_DeadZone_k;
  real32_T rtb_DiscreteTimeIntegrator;
  real32_T rtb_Divide_d;
  real32_T rtb_Divide_o;
  real32_T rtb_Gain2_c;
  real32_T rtb_IntegralGain;
  real32_T rtb_Integrator_g;
  real32_T rtb_Saturation_h;
  real32_T rtb_Sum1;
  int16_T rtb_IProdOut_f;
  int8_T tmp;
  int8_T tmp_0;
  int8_T tmp_1;
  int8_T tmp_2;

  /* Outputs for Atomic SubSystem: '<Root>/FOC_Mode' */
  /* Sum: '<S3>/Sum2' incorporates:
   *  Inport: '<Root>/SpeedFd'
   *  Inport: '<Root>/SpeedRef'
   */
  rtb_IntegralGain = (real32_T)rtU.SpeedRef - rtU.SpeedFd;

  /* Sum: '<S163>/Sum' incorporates:
   *  DiscreteIntegrator: '<S154>/Integrator'
   *  Gain: '<S159>/Proportional Gain'
   */
  rtb_DeadZone = spd_kp * rtb_IntegralGain + rtDW.Integrator_DSTATE;

  /* Outputs for Atomic SubSystem: '<S1>/IF_Mode' */
  /* Chart: '<S2>/Chart' incorporates:
   *  Inport: '<Root>/Motor_OnOff'
   */
  if (rtDW.temporalCounter_i1 < 32767U) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.is_active_c3_FOC_Mode == 0U) {
    rtDW.is_active_c3_FOC_Mode = 1U;
    rtDW.is_c3_FOC_Mode = IN_IDLE;
  } else {
    switch (rtDW.is_c3_FOC_Mode) {
     case IN_AlignStage:
      if (rtDW.temporalCounter_i1 >= 2000) {
        rtDW.is_c3_FOC_Mode = IN_OpenStage;
        rtDW.temporalCounter_i1 = 0U;
        rtDW.ZReset = 0.0;
        rtDW.cnt = 0.0;
      } else if (rtU.Motor_OnOff == 0.0F) {
        rtDW.is_c3_FOC_Mode = IN_IDLE;
      } else {
        rtDW.Motor_state = 2.0;
      }
      break;

     case IN_IDLE:
      if (rtU.Motor_OnOff == 1.0F) {
        rtDW.is_c3_FOC_Mode = IN_AlignStage;
        rtDW.temporalCounter_i1 = 0U;
      } else {
        rtDW.Motor_state = 1.0;
      }
      break;

     case IN_OpenStage:
      if (rtU.Motor_OnOff == 0.0F) {
        rtDW.is_c3_FOC_Mode = IN_IDLE;
      } else if (rtDW.temporalCounter_i1 >= 20000) {
        rtDW.is_c3_FOC_Mode = IN_RunStage;
      } else {
        if (rtDW.cnt == 1.0) {
          rtDW.ZReset = 1.0;
        }

        rtDW.cnt = 1.0;
        rtDW.Motor_state = 3.0;
      }
      break;

     default:
      /* case IN_RunStage: */
      if (rtU.Motor_OnOff == 0.0F) {
        rtDW.is_c3_FOC_Mode = IN_IDLE;
      } else {
        rtDW.Motor_state = 4.0;
      }
      break;
    }
  }

  /* End of Chart: '<S2>/Chart' */

  /* SwitchCase: '<S2>/Switch Case' */
  switch ((int32_T)rtDW.Motor_state) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S2>/IDLE' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Constant: '<S9>/Constant'
     *  SignalConversion generated from: '<S9>/theta_fd'
     */
    ThetaOpen = 0.0F;

    /* Merge: '<S2>/Merge1' incorporates:
     *  Constant: '<S9>/Constant1'
     *  SignalConversion generated from: '<S9>/iq_ref'
     */
    rtDW.Merge1 = 0.0F;

    /* End of Outputs for SubSystem: '<S2>/IDLE' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S2>/Align' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Constant: '<S4>/Constant'
     *  SignalConversion generated from: '<S4>/theta_fd'
     */
    ThetaOpen = 0.0F;

    /* Merge: '<S2>/Merge1' incorporates:
     *  Constant: '<S4>/Constant1'
     *  SignalConversion generated from: '<S4>/iq_ref'
     */
    rtDW.Merge1 = 2.0F;

    /* End of Outputs for SubSystem: '<S2>/Align' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S2>/Open' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */
    if ((rtDW.ZReset > 0.0) && (rtDW.DiscreteTimeIntegrator_PrevRese <= 0)) {
      rtDW.DiscreteTimeIntegrator_DSTATE = 0.0F;
    }

    rtb_DiscreteTimeIntegrator = rtDW.DiscreteTimeIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */

    /* DiscreteIntegrator: '<S10>/Discrete-Time Integrator1' */
    if ((rtDW.ZReset > 0.0) && (rtDW.DiscreteTimeIntegrator1_PrevRes <= 0)) {
      rtDW.DiscreteTimeIntegrator1_DSTATE = 0.0F;
    }

    /* Merge: '<S2>/Merge' incorporates:
     *  Constant: '<S10>/Constant1'
     *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator1'
     *  Math: '<S10>/Mod'
     */
    ThetaOpen = rt_modf_snf(rtDW.DiscreteTimeIntegrator1_DSTATE, 6.28318548F);

    /* Merge: '<S2>/Merge1' incorporates:
     *  Constant: '<S2>/Constant5'
     *  SignalConversion generated from: '<S10>/iq_ref'
     */
    rtDW.Merge1 = 1.0F;

    /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S10>/Gain'
     *  Product: '<S10>/Product'
     */
    rtDW.DiscreteTimeIntegrator_DSTATE += Motor.Pn * 62.8318558F * 0.333333343F *
      0.0001F;
    if (rtDW.ZReset > 0.0) {
      rtDW.DiscreteTimeIntegrator_PrevRese = 1;
    } else if (rtDW.ZReset < 0.0) {
      rtDW.DiscreteTimeIntegrator_PrevRese = -1;
    } else if (rtDW.ZReset == 0.0) {
      rtDW.DiscreteTimeIntegrator_PrevRese = 0;
    } else {
      rtDW.DiscreteTimeIntegrator_PrevRese = 2;
    }

    /* End of Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator1' */
    rtDW.DiscreteTimeIntegrator1_DSTATE += 0.0001F * rtb_DiscreteTimeIntegrator;
    if (rtDW.ZReset > 0.0) {
      rtDW.DiscreteTimeIntegrator1_PrevRes = 1;
    } else if (rtDW.ZReset < 0.0) {
      rtDW.DiscreteTimeIntegrator1_PrevRes = -1;
    } else if (rtDW.ZReset == 0.0) {
      rtDW.DiscreteTimeIntegrator1_PrevRes = 0;
    } else {
      rtDW.DiscreteTimeIntegrator1_PrevRes = 2;
    }

    /* End of Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator1' */
    /* End of Outputs for SubSystem: '<S2>/Open' */
    break;

   case 4:
    /* Saturate: '<S161>/Saturation' */
    if (rtb_DeadZone > 3.0F) {
      /* Outputs for IfAction SubSystem: '<S2>/Run' incorporates:
       *  ActionPort: '<S12>/Action Port'
       */
      /* Merge: '<S2>/Merge1' incorporates:
       *  SignalConversion generated from: '<S12>/iq_ref'
       */
      rtDW.Merge1 = 3.0F;

      /* End of Outputs for SubSystem: '<S2>/Run' */
    } else if (rtb_DeadZone < -3.0F) {
      /* Outputs for IfAction SubSystem: '<S2>/Run' incorporates:
       *  ActionPort: '<S12>/Action Port'
       */
      /* Merge: '<S2>/Merge1' incorporates:
       *  SignalConversion generated from: '<S12>/iq_ref'
       */
      rtDW.Merge1 = -3.0F;

      /* End of Outputs for SubSystem: '<S2>/Run' */
    } else {
      /* Outputs for IfAction SubSystem: '<S2>/Run' incorporates:
       *  ActionPort: '<S12>/Action Port'
       */
      /* Merge: '<S2>/Merge1' incorporates:
       *  SignalConversion generated from: '<S12>/iq_ref'
       */
      rtDW.Merge1 = rtb_DeadZone;

      /* End of Outputs for SubSystem: '<S2>/Run' */
    }

    /* End of Saturate: '<S161>/Saturation' */

    /* Outputs for IfAction SubSystem: '<S2>/Run' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Inport: '<Root>/theta'
     *  SignalConversion generated from: '<S12>/theta'
     */
    ThetaOpen = rtU.theta;

    /* End of Outputs for SubSystem: '<S2>/Run' */
    break;
  }

  /* End of SwitchCase: '<S2>/Switch Case' */

  /* Sum: '<S7>/Add2' incorporates:
   *  Gain: '<S7>/Gain'
   *  Gain: '<S7>/Gain1'
   *  Inport: '<Root>/I_a'
   *  Inport: '<Root>/I_b'
   *  Inport: '<Root>/I_c'
   *  Sum: '<S7>/Add'
   */
  i_alpha = 0.666666687F * rtU.I_a - (rtU.I_b + rtU.I_c) * 0.333333343F;

  /* Trigonometry: '<S11>/Trigonometric Function1' */
  rtb_Integrator_g = cosf(ThetaOpen);

  /* Gain: '<S7>/Gain2' incorporates:
   *  Inport: '<Root>/I_b'
   *  Inport: '<Root>/I_c'
   *  Sum: '<S7>/Add1'
   */
  i_beta = (rtU.I_b - rtU.I_c) * 0.577350259F;

  /* Trigonometry: '<S11>/Trigonometric Function' */
  rtb_DiscreteTimeIntegrator = sinf(ThetaOpen);

  /* Sum: '<S8>/Sum1' incorporates:
   *  Constant: '<S8>/Constant'
   *  Product: '<S11>/Product'
   *  Product: '<S11>/Product1'
   *  Sum: '<S11>/Add'
   */
  rtb_Sum1 = 0.0F - (i_alpha * rtb_Integrator_g + i_beta *
                     rtb_DiscreteTimeIntegrator);

  /* Sum: '<S58>/Sum' incorporates:
   *  Constant: '<S8>/Constant3'
   *  DiscreteIntegrator: '<S49>/Integrator'
   *  Product: '<S54>/PProd Out'
   */
  rtb_DeadZone_k = rtb_Sum1 * 0.17F + (real32_T)rtDW.Integrator_DSTATE_ps *
    0.0001F;

  /* Saturate: '<S56>/Saturation' */
  if (rtb_DeadZone_k > 12.4707661F) {
    rtb_Saturation_h = 12.4707661F;
  } else if (rtb_DeadZone_k < -12.4707661F) {
    rtb_Saturation_h = -12.4707661F;
  } else {
    rtb_Saturation_h = rtb_DeadZone_k;
  }

  /* End of Saturate: '<S56>/Saturation' */

  /* Trigonometry: '<S5>/Trigonometric Function1' */
  rtb_Divide_d = cosf(ThetaOpen);

  /* Sum: '<S11>/Add1' incorporates:
   *  Product: '<S11>/Product2'
   *  Product: '<S11>/Product3'
   */
  i_q = i_beta * rtb_Integrator_g - i_alpha * rtb_DiscreteTimeIntegrator;

  /* Sum: '<S8>/Sum7' */
  rtb_DiscreteTimeIntegrator = rtDW.Merge1 - i_q;

  /* Sum: '<S108>/Sum' incorporates:
   *  Constant: '<S8>/Constant1'
   *  DiscreteIntegrator: '<S99>/Integrator'
   *  Product: '<S104>/PProd Out'
   */
  rtb_Gain2_c = rtb_DiscreteTimeIntegrator * 0.17F + rtDW.Integrator_DSTATE_p;

  /* Saturate: '<S106>/Saturation' */
  if (rtb_Gain2_c > 12.4707661F) {
    rtb_Add2 = 12.4707661F;
  } else if (rtb_Gain2_c < -12.4707661F) {
    rtb_Add2 = -12.4707661F;
  } else {
    rtb_Add2 = rtb_Gain2_c;
  }

  /* End of Saturate: '<S106>/Saturation' */

  /* Trigonometry: '<S5>/Trigonometric Function' */
  rtb_Integrator_g = sinf(ThetaOpen);

  /* Sum: '<S5>/Add' incorporates:
   *  Product: '<S5>/Product'
   *  Product: '<S5>/Product3'
   */
  rtb_Divide_o = rtb_Saturation_h * rtb_Divide_d - rtb_Add2 * rtb_Integrator_g;

  /* Sum: '<S5>/Add1' incorporates:
   *  Product: '<S5>/Product1'
   *  Product: '<S5>/Product2'
   */
  rtb_Integrator_g = rtb_Saturation_h * rtb_Integrator_g + rtb_Add2 *
    rtb_Divide_d;

  /* DeadZone: '<S42>/DeadZone' */
  if (rtb_DeadZone_k > 12.4707661F) {
    rtb_DeadZone_k -= 12.4707661F;
  } else if (rtb_DeadZone_k >= -12.4707661F) {
    rtb_DeadZone_k = 0.0F;
  } else {
    rtb_DeadZone_k -= -12.4707661F;
  }

  /* End of DeadZone: '<S42>/DeadZone' */

  /* Product: '<S46>/IProd Out' incorporates:
   *  Constant: '<S8>/Constant4'
   */
  rtb_IProdOut_f = (int16_T)floorf(rtb_Sum1 * 35.0F);

  /* DeadZone: '<S92>/DeadZone' */
  if (rtb_Gain2_c > 12.4707661F) {
    rtb_Gain2_c -= 12.4707661F;
  } else if (rtb_Gain2_c >= -12.4707661F) {
    rtb_Gain2_c = 0.0F;
  } else {
    rtb_Gain2_c -= -12.4707661F;
  }

  /* End of DeadZone: '<S92>/DeadZone' */

  /* Product: '<S96>/IProd Out' incorporates:
   *  Constant: '<S8>/Constant2'
   */
  rtb_DiscreteTimeIntegrator *= 35.0F;

  /* Switch: '<S90>/Switch1' incorporates:
   *  Constant: '<S90>/Clamping_zero'
   *  Constant: '<S90>/Constant'
   *  Constant: '<S90>/Constant2'
   *  RelationalOperator: '<S90>/fix for DT propagation issue'
   */
  if (rtb_Gain2_c > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S90>/Switch2' incorporates:
   *  Constant: '<S90>/Clamping_zero'
   *  Constant: '<S90>/Constant3'
   *  Constant: '<S90>/Constant4'
   *  RelationalOperator: '<S90>/fix for DT propagation issue1'
   */
  if (rtb_DiscreteTimeIntegrator > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Gain: '<S116>/Gain1' incorporates:
   *  Inport: '<Root>/T_pwm'
   */
  rtb_Add2 = 0.25F * rtU.T_pwm;

  /* Gain: '<S117>/Gain' incorporates:
   *  Gain: '<S119>/Gain1'
   */
  rtb_Saturation_h = 0.866025388F * rtb_Divide_o;

  /* Gain: '<S117>/Gain1' incorporates:
   *  Gain: '<S119>/Gain2'
   */
  rtb_Divide_o = 0.5F * rtb_Integrator_g;

  /* Sum: '<S117>/Add' incorporates:
   *  Gain: '<S117>/Gain'
   *  Gain: '<S117>/Gain1'
   *  Gain: '<S117>/Gain2'
   *  Gain: '<S117>/Gain3'
   *  Sum: '<S117>/Add1'
   *  Sum: '<S117>/Add2'
   *  Switch: '<S117>/ A Switch'
   *  Switch: '<S117>/ B Switch'
   *  Switch: '<S117>/ C Switch'
   */
  rtb_Add = (((rtb_Saturation_h - rtb_Divide_o > 0.0F) << 1) + (rtb_Integrator_g
              > 0.0F)) + (((0.0F - rtb_Saturation_h) - rtb_Divide_o > 0.0F) << 2);

  /* Product: '<S119>/Divide' incorporates:
   *  Gain: '<S119>/Gain'
   *  Inport: '<Root>/T_pwm'
   *  Inport: '<Root>/u_dc'
   */
  rtb_Divide_d = 1.73205078F * rtU.T_pwm / rtU.u_dc;

  /* MultiPortSwitch: '<S118>/T4 Switch' incorporates:
   *  Gain: '<S118>/Gain'
   *  Gain: '<S118>/Gain1'
   *  Gain: '<S118>/Gain2'
   *  Product: '<S119>/Product'
   *  Product: '<S119>/Product1'
   *  Product: '<S119>/Product2'
   *  Sum: '<S119>/Add'
   *  Sum: '<S119>/Add1'
   */
  switch (rtb_Add) {
   case 1:
    rtb_Sum1 = (rtb_Divide_o - rtb_Saturation_h) * rtb_Divide_d;

    /* MultiPortSwitch: '<S118>/T6 Switch' incorporates:
     *  Product: '<S119>/Product1'
     *  Product: '<S119>/Product2'
     *  Sum: '<S119>/Add'
     *  Sum: '<S119>/Add1'
     */
    rtb_Divide_d *= rtb_Saturation_h + rtb_Divide_o;
    break;

   case 2:
    rtb_Sum1 = (rtb_Saturation_h + rtb_Divide_o) * rtb_Divide_d;

    /* MultiPortSwitch: '<S118>/T6 Switch' incorporates:
     *  Gain: '<S118>/Gain'
     *  Product: '<S119>/Product'
     *  Product: '<S119>/Product1'
     *  Sum: '<S119>/Add'
     */
    rtb_Divide_d = -(rtb_Integrator_g * rtb_Divide_d);
    break;

   case 3:
    rtb_Sum1 = -((rtb_Divide_o - rtb_Saturation_h) * rtb_Divide_d);

    /* MultiPortSwitch: '<S118>/T6 Switch' incorporates:
     *  Gain: '<S118>/Gain2'
     *  Product: '<S119>/Product'
     *  Product: '<S119>/Product2'
     *  Sum: '<S119>/Add1'
     */
    rtb_Divide_d *= rtb_Integrator_g;
    break;

   case 4:
    rtb_Sum1 = -(rtb_Integrator_g * rtb_Divide_d);

    /* MultiPortSwitch: '<S118>/T6 Switch' incorporates:
     *  Gain: '<S118>/Gain'
     *  Product: '<S119>/Product'
     *  Product: '<S119>/Product2'
     *  Sum: '<S119>/Add1'
     */
    rtb_Divide_d *= rtb_Divide_o - rtb_Saturation_h;
    break;

   case 5:
    rtb_Sum1 = rtb_Integrator_g * rtb_Divide_d;

    /* MultiPortSwitch: '<S118>/T6 Switch' incorporates:
     *  Gain: '<S118>/Gain1'
     *  Product: '<S119>/Product'
     *  Product: '<S119>/Product1'
     *  Sum: '<S119>/Add'
     */
    rtb_Divide_d = -((rtb_Saturation_h + rtb_Divide_o) * rtb_Divide_d);
    break;

   default:
    rtb_Sum1 = -((rtb_Saturation_h + rtb_Divide_o) * rtb_Divide_d);

    /* MultiPortSwitch: '<S118>/T6 Switch' incorporates:
     *  Gain: '<S118>/Gain1'
     *  Gain: '<S118>/Gain2'
     *  Product: '<S119>/Product1'
     *  Product: '<S119>/Product2'
     *  Sum: '<S119>/Add'
     *  Sum: '<S119>/Add1'
     */
    rtb_Divide_d = -((rtb_Divide_o - rtb_Saturation_h) * rtb_Divide_d);
    break;
  }

  /* End of MultiPortSwitch: '<S118>/T4 Switch' */

  /* Sum: '<S118>/Add1' incorporates:
   *  Sum: '<S118>/Add'
   */
  rtb_Integrator_g = rtb_Sum1 + rtb_Divide_d;

  /* Product: '<S118>/Divide' incorporates:
   *  Inport: '<Root>/T_pwm'
   *  Sum: '<S118>/Add1'
   */
  rtb_Saturation_h = rtU.T_pwm / rtb_Integrator_g;

  /* Switch: '<S118>/Switch' incorporates:
   *  Inport: '<Root>/T_pwm'
   *  Product: '<S118>/Product'
   *  Product: '<S118>/Product1'
   *  Sum: '<S118>/Add'
   *  Switch: '<S118>/Switch1'
   */
  if (rtb_Integrator_g - rtU.T_pwm > 0.0F) {
    rtb_Sum1 *= rtb_Saturation_h;
    rtb_Divide_d *= rtb_Saturation_h;
  }

  /* Gain: '<S116>/Gain' incorporates:
   *  Switch: '<S118>/Switch'
   */
  rtb_Integrator_g = 0.25F * rtb_Sum1;

  /* Gain: '<S116>/Gain2' incorporates:
   *  Switch: '<S118>/Switch1'
   */
  rtb_Divide_o = 0.25F * rtb_Divide_d;

  /* Sum: '<S116>/Add' */
  rtb_Divide_d = (rtb_Add2 - rtb_Integrator_g) - rtb_Divide_o;

  /* Sum: '<S116>/Add1' incorporates:
   *  Sum: '<S116>/Add2'
   */
  rtb_Add2 += rtb_Integrator_g;
  rtb_Sum1 = rtb_Add2 - rtb_Divide_o;

  /* Sum: '<S116>/Add2' */
  rtb_Add2 += rtb_Divide_o;

  /* MultiPortSwitch: '<S116>/Ta Switch' */
  switch (rtb_Add) {
   case 1:
    rtb_Divide_o = rtb_Sum1;
    break;

   case 2:
    rtb_Divide_o = rtb_Divide_d;
    break;

   case 3:
    rtb_Divide_o = rtb_Divide_d;
    break;

   case 4:
    rtb_Divide_o = rtb_Add2;
    break;

   case 5:
    rtb_Divide_o = rtb_Add2;
    break;

   default:
    rtb_Divide_o = rtb_Sum1;
    break;
  }

  /* End of MultiPortSwitch: '<S116>/Ta Switch' */

  /* Product: '<S116>/Divide' incorporates:
   *  Inport: '<Root>/T_pwm'
   */
  rtb_Divide_o /= rtU.T_pwm;

  /* MultiPortSwitch: '<S116>/Tc Switch' */
  switch (rtb_Add) {
   case 1:
    rtb_Integrator_g = rtb_Add2;
    break;

   case 2:
    rtb_Integrator_g = rtb_Sum1;
    break;

   case 3:
    rtb_Integrator_g = rtb_Add2;
    break;

   case 4:
    rtb_Integrator_g = rtb_Divide_d;
    break;

   case 5:
    rtb_Integrator_g = rtb_Sum1;
    break;

   default:
    rtb_Integrator_g = rtb_Divide_d;
    break;
  }

  /* End of MultiPortSwitch: '<S116>/Tc Switch' */

  /* Product: '<S116>/Divide1' incorporates:
   *  Inport: '<Root>/T_pwm'
   */
  rtb_Integrator_g /= rtU.T_pwm;

  /* MultiPortSwitch: '<S116>/Tb Switch' */
  switch (rtb_Add) {
   case 1:
    rtb_Add2 = rtb_Divide_d;
    break;

   case 2:
    break;

   case 3:
    rtb_Add2 = rtb_Sum1;
    break;

   case 4:
    rtb_Add2 = rtb_Sum1;
    break;

   case 5:
    rtb_Add2 = rtb_Divide_d;
    break;
  }

  /* End of MultiPortSwitch: '<S116>/Tb Switch' */

  /* Switch: '<S40>/Switch1' incorporates:
   *  Constant: '<S40>/Constant'
   *  Constant: '<S40>/Constant2'
   *  RelationalOperator: '<S40>/fix for DT propagation issue'
   */
  if (rtb_DeadZone_k > 0.0F) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  /* Switch: '<S40>/Switch2' incorporates:
   *  Constant: '<S40>/Clamping_zero'
   *  Constant: '<S40>/Constant3'
   *  Constant: '<S40>/Constant4'
   *  RelationalOperator: '<S40>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut_f > 0) {
    tmp_2 = 1;
  } else {
    tmp_2 = -1;
  }

  /* Switch: '<S40>/Switch' incorporates:
   *  Constant: '<S40>/Constant1'
   *  Logic: '<S40>/AND3'
   *  RelationalOperator: '<S40>/Equal1'
   *  RelationalOperator: '<S40>/Relational Operator'
   *  Switch: '<S40>/Switch1'
   *  Switch: '<S40>/Switch2'
   */
  if ((rtb_DeadZone_k != 0.0F) && (tmp_1 == tmp_2)) {
    rtb_IProdOut_f = 0;
  }

  /* Update for DiscreteIntegrator: '<S49>/Integrator' incorporates:
   *  Switch: '<S40>/Switch'
   */
  rtDW.Integrator_DSTATE_ps += rtb_IProdOut_f;

  /* Switch: '<S90>/Switch' incorporates:
   *  Constant: '<S90>/Clamping_zero'
   *  Constant: '<S90>/Constant1'
   *  Logic: '<S90>/AND3'
   *  RelationalOperator: '<S90>/Equal1'
   *  RelationalOperator: '<S90>/Relational Operator'
   *  Switch: '<S90>/Switch1'
   *  Switch: '<S90>/Switch2'
   */
  if ((rtb_Gain2_c != 0.0F) && (tmp == tmp_0)) {
    rtb_DiscreteTimeIntegrator = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S99>/Integrator' incorporates:
   *  Switch: '<S90>/Switch'
   */
  rtDW.Integrator_DSTATE_p += 0.0001F * rtb_DiscreteTimeIntegrator;

  /* End of Outputs for SubSystem: '<S1>/IF_Mode' */

  /* DeadZone: '<S147>/DeadZone' */
  if (rtb_DeadZone > 3.0F) {
    rtb_DeadZone -= 3.0F;
  } else if (rtb_DeadZone >= -3.0F) {
    rtb_DeadZone = 0.0F;
  } else {
    rtb_DeadZone -= -3.0F;
  }

  /* End of DeadZone: '<S147>/DeadZone' */

  /* Gain: '<S151>/Integral Gain' */
  rtb_IntegralGain *= spd_ki;

  /* Switch: '<S145>/Switch1' incorporates:
   *  Constant: '<S145>/Clamping_zero'
   *  Constant: '<S145>/Constant'
   *  Constant: '<S145>/Constant2'
   *  RelationalOperator: '<S145>/fix for DT propagation issue'
   */
  if (rtb_DeadZone > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S145>/Switch2' incorporates:
   *  Constant: '<S145>/Clamping_zero'
   *  Constant: '<S145>/Constant3'
   *  Constant: '<S145>/Constant4'
   *  RelationalOperator: '<S145>/fix for DT propagation issue1'
   */
  if (rtb_IntegralGain > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S145>/Switch' incorporates:
   *  Constant: '<S145>/Clamping_zero'
   *  Constant: '<S145>/Constant1'
   *  Logic: '<S145>/AND3'
   *  RelationalOperator: '<S145>/Equal1'
   *  RelationalOperator: '<S145>/Relational Operator'
   *  Switch: '<S145>/Switch1'
   *  Switch: '<S145>/Switch2'
   */
  if ((rtb_DeadZone != 0.0F) && (tmp == tmp_0)) {
    rtb_IntegralGain = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S154>/Integrator' incorporates:
   *  Switch: '<S145>/Switch'
   */
  rtDW.Integrator_DSTATE += 0.0001F * rtb_IntegralGain;

  /* Outputs for Atomic SubSystem: '<S1>/IF_Mode' */
  /* Outport: '<Root>/Duty' incorporates:
   *  Constant: '<S13>/Constant'
   *  Gain: '<S13>/Gain'
   *  Inport: '<Root>/T_pwm'
   *  Product: '<S116>/Divide2'
   *  Sum: '<S13>/Sum'
   */
  rtY.Duty[0] = 1.0 - 2.0F * rtb_Divide_o;
  rtY.Duty[1] = 1.0 - rtb_Add2 / rtU.T_pwm * 2.0F;
  rtY.Duty[2] = 1.0 - 2.0F * rtb_Integrator_g;

  /* End of Outputs for SubSystem: '<S1>/IF_Mode' */
  /* End of Outputs for SubSystem: '<Root>/FOC_Mode' */
}

/* Model initialize function */
void FOC_Mode_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* SystemInitialize for Atomic SubSystem: '<Root>/FOC_Mode' */
  /* SystemInitialize for Atomic SubSystem: '<S1>/IF_Mode' */
  /* SystemInitialize for IfAction SubSystem: '<S2>/Open' */
  /* InitializeConditions for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S10>/Discrete-Time Integrator1' */
  rtDW.DiscreteTimeIntegrator1_PrevRes = 2;

  /* End of SystemInitialize for SubSystem: '<S2>/Open' */
  /* End of SystemInitialize for SubSystem: '<S1>/IF_Mode' */
  /* End of SystemInitialize for SubSystem: '<Root>/FOC_Mode' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
