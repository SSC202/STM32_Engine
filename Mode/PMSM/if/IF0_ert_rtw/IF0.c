/*
 * File: IF0.c
 *
 * Code generated for Simulink model 'IF0'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri Oct 27 20:37:16 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "IF0.h"

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
real32_T theta;                        /* '<S1>/Merge' */

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
static void SVPWM(real32_T rtu_Valpha, real32_T rtu_Vbeta, real32_T rtu_v_bus,
                  real_T rty_DutyOut[3]);
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

/* Output and update for atomic system: '<S1>/SVPWM' */
static void SVPWM(real32_T rtu_Valpha, real32_T rtu_Vbeta, real32_T rtu_v_bus,
                  real_T rty_DutyOut[3])
{
  real32_T rtb_Min;
  real32_T rtb_Sum1_n;
  real32_T rtb_Sum_a;

  /* Gain: '<S12>/Gain' */
  rtb_Min = -0.5F * rtu_Valpha;

  /* Gain: '<S12>/Gain1' */
  rtb_Sum1_n = 0.866025388F * rtu_Vbeta;

  /* Sum: '<S12>/Sum' */
  rtb_Sum_a = rtb_Min + rtb_Sum1_n;

  /* Sum: '<S12>/Sum1' */
  rtb_Sum1_n = rtb_Min - rtb_Sum1_n;

  /* Gain: '<S14>/Gain' incorporates:
   *  MinMax: '<S14>/Min'
   *  MinMax: '<S14>/Min1'
   *  Sum: '<S14>/Sum'
   */
  rtb_Min = (fminf(fminf(rtu_Valpha, rtb_Sum_a), rtb_Sum1_n) + fmaxf(fmaxf
              (rtu_Valpha, rtb_Sum_a), rtb_Sum1_n)) * -0.5F;

  /* Sum: '<S13>/Sum1' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S13>/Constant'
   *  Gain: '<S10>/Gain'
   *  Gain: '<S10>/PWM_HalfPeriod'
   *  Gain: '<S13>/Gain'
   *  Gain: '<S13>/Gain1'
   *  Product: '<S10>/Divide'
   *  Sum: '<S10>/Sum'
   *  Sum: '<S10>/Sum1'
   *  Sum: '<S13>/Sum'
   */
  rty_DutyOut[0] = -((-(rtb_Min + rtu_Valpha) / rtu_v_bus + 0.5F) * 8000.0F *
                     0.000125F - 0.5) + 0.5;
  rty_DutyOut[1] = -((-(rtb_Min + rtb_Sum_a) / rtu_v_bus + 0.5F) * 8000.0F *
                     0.000125F - 0.5) + 0.5;
  rty_DutyOut[2] = -((-(rtb_Min + rtb_Sum1_n) / rtu_v_bus + 0.5F) * 8000.0F *
                     0.000125F - 0.5) + 0.5;
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
void IF0_step(void)
{
  real32_T rtb_IProdOut;
  real32_T rtb_Integrator;
  real32_T rtb_Saturation;
  real32_T rtb_SignPreIntegrator;
  real32_T rtb_SignPreSat;
  real32_T rtb_SinCos;
  real32_T rtb_SinCos1;
  real32_T rtb_Sum1_b;
  int16_T rtb_IProdOut_a;
  int16_T rtb_IProdOut_h;

  /* Sum: '<S4>/Add1' incorporates:
   *  Gain: '<S4>/Gain'
   *  Gain: '<S4>/Gain1'
   *  Inport: '<Root>/ia'
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ic'
   *  Sum: '<S4>/Add'
   */
  rtb_Integrator = 0.666666687F * rtU.ia - (rtU.ib + rtU.ic) * 0.333333343F;

  /* Chart: '<S1>/Chart' incorporates:
   *  Inport: '<Root>/Motor_OnOff'
   */
  if (rtDW.temporalCounter_i1 < 32767U) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.is_active_c3_IF0 == 0U) {
    rtDW.is_active_c3_IF0 = 1U;
    rtDW.is_c3_IF0 = IN_IDLE;
  } else {
    switch (rtDW.is_c3_IF0) {
     case IN_AlignStage:
      if (rtDW.temporalCounter_i1 >= 1000) {
        rtDW.is_c3_IF0 = IN_OpenStage;
        rtDW.temporalCounter_i1 = 0U;
      } else if (rtU.Motor_OnOff == 0.0F) {
        rtDW.is_c3_IF0 = IN_IDLE;
      } else {
        rtDW.Motor_state = 2.0;
      }
      break;

     case IN_IDLE:
      if (rtU.Motor_OnOff == 1.0F) {
        rtDW.is_c3_IF0 = IN_AlignStage;
        rtDW.temporalCounter_i1 = 0U;
      } else {
        rtDW.Motor_state = 1.0;
      }
      break;

     case IN_OpenStage:
      if (rtU.Motor_OnOff == 0.0F) {
        rtDW.is_c3_IF0 = IN_IDLE;
      } else if (rtDW.temporalCounter_i1 >= 30000) {
        rtDW.is_c3_IF0 = IN_RunStage;
      } else {
        rtDW.Motor_state = 3.0;
      }
      break;

     default:
      /* case IN_RunStage: */
      if (rtU.Motor_OnOff == 0.0F) {
        rtDW.is_c3_IF0 = IN_IDLE;
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
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S5>/Constant'
     *  SignalConversion generated from: '<S5>/theta_fd'
     */
    theta = 0.0F;

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S5>/Constant1'
     *  SignalConversion generated from: '<S5>/iq_ref'
     */
    rtDW.Merge1 = 0.0F;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S6>/Constant'
     *  SignalConversion generated from: '<S6>/theta_fd'
     */
    theta = 0.0F;

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S6>/Constant1'
     *  SignalConversion generated from: '<S6>/iq_ref'
     */
    rtDW.Merge1 = 2.0F;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem1' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S7>/Constant1'
     *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator1'
     *  Math: '<S7>/Mod'
     */
    theta = rt_modf_snf(rtDW.DiscreteTimeIntegrator1_DSTAT_l, 6.28318548F);

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S1>/Constant5'
     *  Inport: '<S7>/iq_ref'
     */
    rtDW.Merge1 = 1.0F;

    /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
     */
    rtDW.DiscreteTimeIntegrator1_DSTAT_l += 0.0001F *
      rtDW.DiscreteTimeIntegrator_DSTATE;

    /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S7>/Gain'
     *  Product: '<S7>/Product'
     */
    rtDW.DiscreteTimeIntegrator_DSTATE += motor.Pn * 83.7758F * 0.333333343F *
      0.0001F;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem2' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S8>/Constant1'
     *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator1'
     *  Math: '<S8>/Mod'
     */
    theta = rt_modf_snf(rtDW.DiscreteTimeIntegrator1_DSTATE, 6.28318548F);

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S1>/Constant8'
     *  Inport: '<S8>/iq_ref'
     */
    rtDW.Merge1 = 1.0F;

    /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' incorporates:
     *  Gain: '<S8>/Gain'
     */
    rtDW.DiscreteTimeIntegrator1_DSTATE += motor.Pn * 83.7758F * 0.0001F;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem3' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* Trigonometry: '<S1>/SinCos1' */
  rtb_SinCos1 = cosf(theta);

  /* Gain: '<S4>/Gain2' incorporates:
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ic'
   *  Sum: '<S4>/Add2'
   */
  rtb_IProdOut = (rtU.ib - rtU.ic) * 0.577350259F;

  /* Trigonometry: '<S1>/SinCos' */
  rtb_SinCos = sinf(theta);

  /* Sum: '<S11>/Sum1' incorporates:
   *  Constant: '<S11>/Constant'
   *  Product: '<S9>/Product'
   *  Product: '<S9>/Product1'
   *  Sum: '<S9>/Add'
   */
  rtb_Sum1_b = 0.0F - (rtb_Integrator * rtb_SinCos1 + rtb_IProdOut * rtb_SinCos);

  /* Sum: '<S59>/Sum' incorporates:
   *  Constant: '<S11>/Constant3'
   *  DiscreteIntegrator: '<S50>/Integrator'
   *  Product: '<S55>/PProd Out'
   */
  rtb_SignPreSat = rtb_Sum1_b * 0.17F + (real32_T)rtDW.Integrator_DSTATE_j *
    0.0001F;

  /* Saturate: '<S57>/Saturation' */
  if (rtb_SignPreSat > 12.4707661F) {
    rtb_Saturation = 12.4707661F;
  } else if (rtb_SignPreSat < -12.4707661F) {
    rtb_Saturation = -12.4707661F;
  } else {
    rtb_Saturation = rtb_SignPreSat;
  }

  /* End of Saturate: '<S57>/Saturation' */

  /* Sum: '<S11>/Sum7' incorporates:
   *  Product: '<S9>/Product2'
   *  Product: '<S9>/Product3'
   *  Sum: '<S9>/Add1'
   */
  rtb_IProdOut = rtDW.Merge1 - (rtb_IProdOut * rtb_SinCos1 - rtb_Integrator *
    rtb_SinCos);

  /* Sum: '<S109>/Sum' incorporates:
   *  Constant: '<S11>/Constant1'
   *  DiscreteIntegrator: '<S100>/Integrator'
   *  Product: '<S105>/PProd Out'
   */
  rtb_Integrator = rtb_IProdOut * 0.17F + rtDW.Integrator_DSTATE;

  /* Saturate: '<S107>/Saturation' */
  if (rtb_Integrator > 12.4707661F) {
    rtb_SignPreIntegrator = 12.4707661F;
  } else if (rtb_Integrator < -12.4707661F) {
    rtb_SignPreIntegrator = -12.4707661F;
  } else {
    rtb_SignPreIntegrator = rtb_Integrator;
  }

  /* End of Saturate: '<S107>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S1>/SVPWM' */
  /* Sum: '<S2>/Add' incorporates:
   *  Inport: '<Root>/v_bus'
   *  Outport: '<Root>/Dutyout'
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product1'
   *  Product: '<S2>/Product2'
   *  Product: '<S2>/Product3'
   *  Sum: '<S2>/Add1'
   */
  SVPWM(rtb_Saturation * rtb_SinCos1 - rtb_SignPreIntegrator * rtb_SinCos,
        rtb_Saturation * rtb_SinCos + rtb_SignPreIntegrator * rtb_SinCos1,
        rtU.v_bus, rtY.Dutyout);

  /* End of Outputs for SubSystem: '<S1>/SVPWM' */

  /* Gain: '<S41>/ZeroGain' */
  rtb_SinCos1 = 0.0F * rtb_SignPreSat;

  /* DeadZone: '<S43>/DeadZone' */
  if (rtb_SignPreSat > 12.4707661F) {
    rtb_SignPreSat -= 12.4707661F;
  } else if (rtb_SignPreSat >= -12.4707661F) {
    rtb_SignPreSat = 0.0F;
  } else {
    rtb_SignPreSat -= -12.4707661F;
  }

  /* End of DeadZone: '<S43>/DeadZone' */

  /* Product: '<S47>/IProd Out' incorporates:
   *  Constant: '<S11>/Constant4'
   */
  rtb_IProdOut_h = (int16_T)floorf(rtb_Sum1_b * 35.0F);

  /* Gain: '<S91>/ZeroGain' */
  rtb_Sum1_b = 0.0F * rtb_Integrator;

  /* DeadZone: '<S93>/DeadZone' */
  if (rtb_Integrator > 12.4707661F) {
    rtb_Integrator -= 12.4707661F;
  } else if (rtb_Integrator >= -12.4707661F) {
    rtb_Integrator = 0.0F;
  } else {
    rtb_Integrator -= -12.4707661F;
  }

  /* End of DeadZone: '<S93>/DeadZone' */

  /* Product: '<S97>/IProd Out' incorporates:
   *  Constant: '<S11>/Constant2'
   */
  rtb_IProdOut *= 35.0F;

  /* Signum: '<S41>/SignPreSat' */
  if (rtb_SignPreSat < 0.0F) {
    rtb_SinCos = -1.0F;
  } else if (rtb_SignPreSat > 0.0F) {
    rtb_SinCos = 1.0F;
  } else if (rtb_SignPreSat == 0.0F) {
    rtb_SinCos = 0.0F;
  } else {
    rtb_SinCos = (rtNaNF);
  }

  /* End of Signum: '<S41>/SignPreSat' */

  /* Signum: '<S41>/SignPreIntegrator' */
  if (rtb_IProdOut_h < 0) {
    rtb_IProdOut_a = -1;
  } else {
    rtb_IProdOut_a = (int16_T)(rtb_IProdOut_h > 0);
  }

  /* End of Signum: '<S41>/SignPreIntegrator' */

  /* Switch: '<S41>/Switch' incorporates:
   *  Constant: '<S41>/Constant1'
   *  DataTypeConversion: '<S41>/DataTypeConv1'
   *  DataTypeConversion: '<S41>/DataTypeConv2'
   *  Logic: '<S41>/AND3'
   *  RelationalOperator: '<S41>/Equal1'
   *  RelationalOperator: '<S41>/NotEqual'
   */
  if ((rtb_SinCos1 != rtb_SignPreSat) && ((int8_T)rtb_SinCos == rtb_IProdOut_a))
  {
    rtb_IProdOut_h = 0;
  }

  /* End of Switch: '<S41>/Switch' */

  /* Update for DiscreteIntegrator: '<S50>/Integrator' */
  rtDW.Integrator_DSTATE_j += rtb_IProdOut_h;

  /* Signum: '<S91>/SignPreSat' */
  if (rtb_Integrator < 0.0F) {
    rtb_SinCos1 = -1.0F;
  } else if (rtb_Integrator > 0.0F) {
    rtb_SinCos1 = 1.0F;
  } else if (rtb_Integrator == 0.0F) {
    rtb_SinCos1 = 0.0F;
  } else {
    rtb_SinCos1 = (rtNaNF);
  }

  /* End of Signum: '<S91>/SignPreSat' */

  /* Signum: '<S91>/SignPreIntegrator' */
  if (rtb_IProdOut < 0.0F) {
    rtb_SignPreSat = -1.0F;
  } else if (rtb_IProdOut > 0.0F) {
    rtb_SignPreSat = 1.0F;
  } else if (rtb_IProdOut == 0.0F) {
    rtb_SignPreSat = 0.0F;
  } else {
    rtb_SignPreSat = (rtNaNF);
  }

  /* End of Signum: '<S91>/SignPreIntegrator' */

  /* Switch: '<S91>/Switch' incorporates:
   *  Constant: '<S91>/Constant1'
   *  DataTypeConversion: '<S91>/DataTypeConv1'
   *  DataTypeConversion: '<S91>/DataTypeConv2'
   *  Logic: '<S91>/AND3'
   *  RelationalOperator: '<S91>/Equal1'
   *  RelationalOperator: '<S91>/NotEqual'
   */
  if ((rtb_Sum1_b != rtb_Integrator) && ((int8_T)rtb_SinCos1 == (int8_T)
       rtb_SignPreSat)) {
    rtb_IProdOut = 0.0F;
  }

  /* End of Switch: '<S91>/Switch' */

  /* Update for DiscreteIntegrator: '<S100>/Integrator' */
  rtDW.Integrator_DSTATE += 0.0001F * rtb_IProdOut;
}

/* Model initialize function */
void IF0_initialize(void)
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
