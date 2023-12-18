/*
 * File: IF0.c
 *
 * Code generated for Simulink model 'IF0'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Mon Dec 18 15:46:35 2023
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
extern real_T rt_modd_snf(real_T u0, real_T u1);
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

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      real_T q;
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void IF0_step(void)
{
  real_T rtb_DiscreteTimeIntegrator;
  real_T rtb_Divide4;
  real_T rtb_Divide4_tmp;
  real_T rtb_IProdOut_a;
  real_T rtb_Saturation;
  real_T rtb_SignPreSat;
  real_T rtb_SignPreSat_e;
  real_T rtb_Subtract;
  real_T rtb_T4;
  real_T rtb_T6;
  real_T rtb_ZeroGain_f;
  real32_T rtb_A;
  real32_T rtb_Add2_c;
  real32_T rtb_Gain2_n;
  real32_T rtb_SinCos2;

  /* Outputs for Atomic SubSystem: '<Root>/IF' */
  /* Sum: '<S4>/Add2' incorporates:
   *  Gain: '<S4>/Gain'
   *  Gain: '<S4>/Gain1'
   *  Inport: '<Root>/ia'
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ic'
   *  Sum: '<S4>/Add'
   */
  rtb_Add2_c = 0.666666687F * rtU.ia - (rtU.ib + rtU.ic) * 0.333333343F;

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
      } else if (rtU.Motor_OnOff == 0.0) {
        rtDW.is_c3_IF0 = IN_IDLE;
      } else {
        rtDW.Motor_State = 2.0;
      }
      break;

     case IN_IDLE:
      if (rtU.Motor_OnOff == 1.0) {
        rtDW.is_c3_IF0 = IN_AlignStage;
        rtDW.temporalCounter_i1 = 0U;
      } else {
        rtDW.Motor_State = 1.0;
      }
      break;

     case IN_OpenStage:
      if (rtDW.temporalCounter_i1 >= 30000) {
        rtDW.is_c3_IF0 = IN_RunStage;
      } else if (rtU.Motor_OnOff == 0.0) {
        rtDW.is_c3_IF0 = IN_IDLE;
      } else {
        rtDW.Motor_State = 3.0;
      }
      break;

     default:
      /* case IN_RunStage: */
      if (rtU.Motor_OnOff == 0.0) {
        rtDW.is_c3_IF0 = IN_IDLE;
      } else {
        rtDW.Motor_State = 4.0;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Chart' */

  /* SwitchCase: '<S1>/Switch Case' */
  switch ((int32_T)rtDW.Motor_State) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S9>/Constant'
     *  SignalConversion generated from: '<S9>/theta_fdb'
     */
    rtDW.Merge = 0.0;

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S9>/Constant1'
     *  SignalConversion generated from: '<S9>/iq_ref'
     */
    rtDW.Merge1 = 0.0;

    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem1' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S10>/Constant'
     *  SignalConversion generated from: '<S10>/theta_fdb'
     */
    rtDW.Merge = 0.0;

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S10>/Constant1'
     *  SignalConversion generated from: '<S10>/iq_ref'
     */
    rtDW.Merge1 = 1.0;

    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem1' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem2' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
    rtb_DiscreteTimeIntegrator = rtDW.DiscreteTimeIntegrator_DSTATE;

    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S11>/Constant1'
     *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator1'
     *  Math: '<S11>/Mod'
     */
    rtDW.Merge = rt_modd_snf(rtDW.DiscreteTimeIntegrator1_DSTAT_h,
      6.2831853071795862);

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S1>/Constant6'
     *  Inport: '<S11>/iq_ref'
     */
    rtDW.Merge1 = 1.0;

    /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S11>/Gain1'
     *  Product: '<S11>/Product'
     */
    rtDW.DiscreteTimeIntegrator_DSTATE += Motor.Pn * 83.7758040957278 *
      0.33333333333333331 * 0.0001;

    /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
    rtDW.DiscreteTimeIntegrator1_DSTAT_h += 0.0001 * rtb_DiscreteTimeIntegrator;

    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem2' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem3' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    /* Merge: '<S1>/Merge' incorporates:
     *  Constant: '<S12>/Constant1'
     *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator1'
     *  Math: '<S12>/Mod'
     */
    rtDW.Merge = rt_modd_snf(rtDW.DiscreteTimeIntegrator1_DSTATE,
      6.2831853071795862);

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S1>/Constant7'
     *  Inport: '<S12>/iq_ref'
     */
    rtDW.Merge1 = 1.0;

    /* Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator1' incorporates:
     *  Gain: '<S12>/Gain1'
     */
    rtDW.DiscreteTimeIntegrator1_DSTATE += Motor.Pn * 83.7758040957278 * 0.0001;

    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem3' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* Trigonometry: '<S1>/SinCos2' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion4'
   */
  rtb_SinCos2 = cosf((real32_T)rtDW.Merge);

  /* Gain: '<S4>/Gain2' incorporates:
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ic'
   *  Sum: '<S4>/Add1'
   */
  rtb_Gain2_n = (rtU.ib - rtU.ic) * 0.577350259F;

  /* Trigonometry: '<S1>/SinCos1' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion3'
   */
  rtb_A = sinf((real32_T)rtDW.Merge);

  /* Sum: '<S5>/Sum1' incorporates:
   *  Constant: '<S5>/Constant5'
   *  Product: '<S7>/Product'
   *  Product: '<S7>/Product1'
   *  Sum: '<S7>/Subtract'
   */
  rtb_DiscreteTimeIntegrator = 0.0 - (rtb_Add2_c * rtb_SinCos2 + rtb_Gain2_n *
    rtb_A);

  /* Sum: '<S107>/Sum' incorporates:
   *  Constant: '<S5>/Constant4'
   *  DiscreteIntegrator: '<S98>/Integrator'
   *  Product: '<S103>/PProd Out'
   */
  rtb_SignPreSat = rtb_DiscreteTimeIntegrator * 0.17 + rtDW.Integrator_DSTATE;

  /* Saturate: '<S105>/Saturation' */
  if (rtb_SignPreSat > 13.856406460551019) {
    rtb_Saturation = 13.856406460551019;
  } else if (rtb_SignPreSat < -13.856406460551019) {
    rtb_Saturation = -13.856406460551019;
  } else {
    rtb_Saturation = rtb_SignPreSat;
  }

  /* End of Saturate: '<S105>/Saturation' */

  /* Sum: '<S5>/Sum' incorporates:
   *  Product: '<S7>/Product2'
   *  Product: '<S7>/Product3'
   *  Sum: '<S7>/Subtract1'
   */
  rtb_IProdOut_a = rtDW.Merge1 - (rtb_Gain2_n * rtb_SinCos2 - rtb_Add2_c * rtb_A);

  /* Sum: '<S57>/Sum' incorporates:
   *  Constant: '<S5>/Constant2'
   *  DiscreteIntegrator: '<S48>/Integrator'
   *  Product: '<S53>/PProd Out'
   */
  rtb_SignPreSat_e = rtb_IProdOut_a * 0.17 + rtDW.Integrator_DSTATE_l;

  /* Saturate: '<S55>/Saturation' */
  if (rtb_SignPreSat_e > 13.856406460551019) {
    rtb_Divide4 = 13.856406460551019;
  } else if (rtb_SignPreSat_e < -13.856406460551019) {
    rtb_Divide4 = -13.856406460551019;
  } else {
    rtb_Divide4 = rtb_SignPreSat_e;
  }

  /* End of Saturate: '<S55>/Saturation' */

  /* Sum: '<S2>/Subtract' incorporates:
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product1'
   */
  rtb_Subtract = rtb_Saturation * rtb_A + rtb_Divide4 * rtb_SinCos2;

  /* Sum: '<S2>/Subtract1' incorporates:
   *  Product: '<S2>/Product2'
   *  Product: '<S2>/Product3'
   */
  rtb_T6 = rtb_Saturation * rtb_SinCos2 - rtb_Divide4 * rtb_A;

  /* Gain: '<S89>/ZeroGain' */
  rtb_Saturation = 0.0 * rtb_SignPreSat;

  /* DeadZone: '<S91>/DeadZone' */
  if (rtb_SignPreSat > 13.856406460551019) {
    rtb_SignPreSat -= 13.856406460551019;
  } else if (rtb_SignPreSat >= -13.856406460551019) {
    rtb_SignPreSat = 0.0;
  } else {
    rtb_SignPreSat -= -13.856406460551019;
  }

  /* End of DeadZone: '<S91>/DeadZone' */

  /* Product: '<S95>/IProd Out' incorporates:
   *  Constant: '<S5>/Constant3'
   */
  rtb_DiscreteTimeIntegrator *= 35.0;

  /* Gain: '<S39>/ZeroGain' */
  rtb_ZeroGain_f = 0.0 * rtb_SignPreSat_e;

  /* DeadZone: '<S41>/DeadZone' */
  if (rtb_SignPreSat_e > 13.856406460551019) {
    rtb_SignPreSat_e -= 13.856406460551019;
  } else if (rtb_SignPreSat_e >= -13.856406460551019) {
    rtb_SignPreSat_e = 0.0;
  } else {
    rtb_SignPreSat_e -= -13.856406460551019;
  }

  /* End of DeadZone: '<S41>/DeadZone' */

  /* Product: '<S45>/IProd Out' incorporates:
   *  Constant: '<S5>/Constant'
   */
  rtb_IProdOut_a *= 35.0;

  /* Gain: '<S115>/Gain1' incorporates:
   *  Gain: '<S116>/Gain2'
   */
  rtb_T6 *= 0.8660254037844386;

  /* Gain: '<S115>/Gain2' incorporates:
   *  Gain: '<S116>/Gain1'
   */
  rtb_Divide4_tmp = 0.5 * rtb_Subtract;

  /* Sum: '<S115>/Add' incorporates:
   *  Gain: '<S115>/Gain1'
   *  Gain: '<S115>/Gain2'
   *  Gain: '<S115>/Gain3'
   *  Gain: '<S115>/Gain4'
   *  Gain: '<S115>/Gain5'
   *  Sum: '<S115>/Sum'
   *  Sum: '<S115>/Sum1'
   *  Switch: '<S115>/Switch'
   *  Switch: '<S115>/Switch1'
   *  Switch: '<S115>/Switch2'
   */
  rtb_Add2_c = (real32_T)((((-rtb_T6 - rtb_Divide4_tmp > 0.0) << 2) + ((rtb_T6 -
    rtb_Divide4_tmp > 0.0) << 1)) + (rtb_Subtract > 0.0));

  /* Product: '<S116>/Divide' incorporates:
   *  Inport: '<Root>/u_bus'
   */
  rtb_Divide4 = 1.0 / rtU.u_bus * 1.7320508075688772;

  /* MultiPortSwitch: '<S116>/Multiport Switch' incorporates:
   *  Gain: '<S116>/Gain3'
   *  Gain: '<S116>/Gain4'
   *  Gain: '<S116>/Gain5'
   *  Gain: '<S116>/Gain6'
   *  Product: '<S116>/Divide1'
   *  Product: '<S116>/Divide2'
   *  Product: '<S116>/Divide3'
   *  Sum: '<S116>/Sum'
   *  Sum: '<S116>/Sum1'
   */
  switch ((int32_T)rtb_Add2_c) {
   case 1:
    rtb_T4 = (-rtb_T6 + rtb_Divide4_tmp) * rtb_Divide4;

    /* MultiPortSwitch: '<S116>/Multiport Switch1' incorporates:
     *  Gain: '<S116>/Gain3'
     *  Product: '<S116>/Divide2'
     *  Product: '<S116>/Divide3'
     *  Sum: '<S116>/Sum'
     *  Sum: '<S116>/Sum1'
     */
    rtb_T6 = (rtb_T6 + rtb_Divide4_tmp) * rtb_Divide4;
    break;

   case 2:
    rtb_T4 = (rtb_T6 + rtb_Divide4_tmp) * rtb_Divide4;

    /* MultiPortSwitch: '<S116>/Multiport Switch1' incorporates:
     *  Gain: '<S116>/Gain6'
     *  Product: '<S116>/Divide1'
     *  Product: '<S116>/Divide2'
     *  Sum: '<S116>/Sum'
     */
    rtb_T6 = -(rtb_Subtract * rtb_Divide4);
    break;

   case 3:
    rtb_T4 = -((-rtb_T6 + rtb_Divide4_tmp) * rtb_Divide4);

    /* MultiPortSwitch: '<S116>/Multiport Switch1' incorporates:
     *  Gain: '<S116>/Gain3'
     *  Gain: '<S116>/Gain4'
     *  Product: '<S116>/Divide1'
     *  Product: '<S116>/Divide3'
     *  Sum: '<S116>/Sum1'
     */
    rtb_T6 = rtb_Subtract * rtb_Divide4;
    break;

   case 4:
    rtb_T4 = -(rtb_Subtract * rtb_Divide4);

    /* MultiPortSwitch: '<S116>/Multiport Switch1' incorporates:
     *  Gain: '<S116>/Gain3'
     *  Gain: '<S116>/Gain6'
     *  Product: '<S116>/Divide1'
     *  Product: '<S116>/Divide3'
     *  Sum: '<S116>/Sum1'
     */
    rtb_T6 = (-rtb_T6 + rtb_Divide4_tmp) * rtb_Divide4;
    break;

   case 5:
    rtb_T4 = rtb_Subtract * rtb_Divide4;

    /* MultiPortSwitch: '<S116>/Multiport Switch1' incorporates:
     *  Gain: '<S116>/Gain5'
     *  Product: '<S116>/Divide1'
     *  Product: '<S116>/Divide2'
     *  Sum: '<S116>/Sum'
     */
    rtb_T6 = -((rtb_T6 + rtb_Divide4_tmp) * rtb_Divide4);
    break;

   default:
    rtb_T4 = -((rtb_T6 + rtb_Divide4_tmp) * rtb_Divide4);

    /* MultiPortSwitch: '<S116>/Multiport Switch1' incorporates:
     *  Gain: '<S116>/Gain3'
     *  Gain: '<S116>/Gain4'
     *  Gain: '<S116>/Gain5'
     *  Product: '<S116>/Divide2'
     *  Product: '<S116>/Divide3'
     *  Sum: '<S116>/Sum'
     *  Sum: '<S116>/Sum1'
     */
    rtb_T6 = -((-rtb_T6 + rtb_Divide4_tmp) * rtb_Divide4);
    break;
  }

  /* End of MultiPortSwitch: '<S116>/Multiport Switch' */

  /* Product: '<S116>/Divide4' incorporates:
   *  Sum: '<S116>/Subtract'
   */
  rtb_Divide4 = 1.0 / (rtb_T4 + rtb_T6);

  /* Switch: '<S116>/Switch' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Product: '<S116>/Divide5'
   *  Product: '<S116>/Divide6'
   *  Sum: '<S116>/Add'
   *  Switch: '<S116>/Switch1'
   */
  if ((rtb_T4 - 1.0) + rtb_T6 > 0.0) {
    rtb_T4 *= rtb_Divide4;
    rtb_T6 *= rtb_Divide4;
  }

  /* End of Switch: '<S116>/Switch' */

  /* Gain: '<S117>/Gain' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Sum: '<S117>/Add'
   */
  rtb_Divide4 = ((1.0 - rtb_T4) - rtb_T6) * 0.25;

  /* Sum: '<S117>/Add1' incorporates:
   *  Gain: '<S117>/Gain1'
   */
  rtb_Subtract = 0.5 * rtb_T4 + rtb_Divide4;

  /* Sum: '<S117>/Add2' incorporates:
   *  Gain: '<S117>/Gain2'
   */
  rtb_Divide4_tmp = 0.5 * rtb_T6 + rtb_Subtract;

  /* MultiPortSwitch: '<S117>/Tcm1 ' incorporates:
   *  Gain: '<S117>/Gain2'
   *  Sum: '<S117>/Add2'
   */
  switch ((int32_T)rtb_Add2_c) {
   case 1:
    rtb_T6 = rtb_Subtract;

    /* MultiPortSwitch: '<S117>/Tcm2' */
    rtb_T4 = rtb_Divide4;

    /* MultiPortSwitch: '<S117>/Tcm3' incorporates:
     *  Sum: '<S117>/Add2'
     */
    rtb_Divide4 = rtb_Divide4_tmp;
    break;

   case 2:
    rtb_T6 = rtb_Divide4;

    /* MultiPortSwitch: '<S117>/Tcm2' incorporates:
     *  Sum: '<S117>/Add2'
     */
    rtb_T4 = rtb_Divide4_tmp;

    /* MultiPortSwitch: '<S117>/Tcm3' */
    rtb_Divide4 = rtb_Subtract;
    break;

   case 3:
    rtb_T6 = rtb_Divide4;

    /* MultiPortSwitch: '<S117>/Tcm2' */
    rtb_T4 = rtb_Subtract;

    /* MultiPortSwitch: '<S117>/Tcm3' incorporates:
     *  Sum: '<S117>/Add2'
     */
    rtb_Divide4 = rtb_Divide4_tmp;
    break;

   case 4:
    rtb_T6 = 0.5 * rtb_T6 + rtb_Subtract;

    /* MultiPortSwitch: '<S117>/Tcm2' incorporates:
     *  Gain: '<S117>/Gain2'
     *  Sum: '<S117>/Add2'
     */
    rtb_T4 = rtb_Subtract;
    break;

   case 5:
    rtb_T6 = 0.5 * rtb_T6 + rtb_Subtract;

    /* MultiPortSwitch: '<S117>/Tcm2' incorporates:
     *  Gain: '<S117>/Gain2'
     *  Sum: '<S117>/Add2'
     */
    rtb_T4 = rtb_Divide4;

    /* MultiPortSwitch: '<S117>/Tcm3' */
    rtb_Divide4 = rtb_Subtract;
    break;

   default:
    rtb_T6 = rtb_Subtract;

    /* MultiPortSwitch: '<S117>/Tcm2' incorporates:
     *  Sum: '<S117>/Add2'
     */
    rtb_T4 = rtb_Divide4_tmp;
    break;
  }

  /* End of MultiPortSwitch: '<S117>/Tcm1 ' */

  /* Signum: '<S89>/SignPreSat' */
  if (rtb_SignPreSat < 0.0) {
    rtb_Subtract = -1.0;
  } else if (rtb_SignPreSat > 0.0) {
    rtb_Subtract = 1.0;
  } else if (rtb_SignPreSat == 0.0) {
    rtb_Subtract = 0.0;
  } else {
    rtb_Subtract = (rtNaN);
  }

  /* End of Signum: '<S89>/SignPreSat' */

  /* Signum: '<S89>/SignPreIntegrator' */
  if (rtb_DiscreteTimeIntegrator < 0.0) {
    rtb_Divide4_tmp = -1.0;
  } else if (rtb_DiscreteTimeIntegrator > 0.0) {
    rtb_Divide4_tmp = 1.0;
  } else if (rtb_DiscreteTimeIntegrator == 0.0) {
    rtb_Divide4_tmp = 0.0;
  } else {
    rtb_Divide4_tmp = (rtNaN);
  }

  /* End of Signum: '<S89>/SignPreIntegrator' */

  /* Switch: '<S89>/Switch' incorporates:
   *  Constant: '<S89>/Constant1'
   *  DataTypeConversion: '<S89>/DataTypeConv1'
   *  DataTypeConversion: '<S89>/DataTypeConv2'
   *  Logic: '<S89>/AND3'
   *  RelationalOperator: '<S89>/Equal1'
   *  RelationalOperator: '<S89>/NotEqual'
   */
  if ((rtb_Saturation != rtb_SignPreSat) && ((int8_T)rtb_Subtract == (int8_T)
       rtb_Divide4_tmp)) {
    rtb_DiscreteTimeIntegrator = 0.0;
  }

  /* End of Switch: '<S89>/Switch' */

  /* Update for DiscreteIntegrator: '<S98>/Integrator' */
  rtDW.Integrator_DSTATE += 0.0001 * rtb_DiscreteTimeIntegrator;

  /* Signum: '<S39>/SignPreSat' */
  if (rtb_SignPreSat_e < 0.0) {
    rtb_DiscreteTimeIntegrator = -1.0;
  } else if (rtb_SignPreSat_e > 0.0) {
    rtb_DiscreteTimeIntegrator = 1.0;
  } else if (rtb_SignPreSat_e == 0.0) {
    rtb_DiscreteTimeIntegrator = 0.0;
  } else {
    rtb_DiscreteTimeIntegrator = (rtNaN);
  }

  /* End of Signum: '<S39>/SignPreSat' */

  /* Signum: '<S39>/SignPreIntegrator' */
  if (rtb_IProdOut_a < 0.0) {
    rtb_SignPreSat = -1.0;
  } else if (rtb_IProdOut_a > 0.0) {
    rtb_SignPreSat = 1.0;
  } else if (rtb_IProdOut_a == 0.0) {
    rtb_SignPreSat = 0.0;
  } else {
    rtb_SignPreSat = (rtNaN);
  }

  /* End of Signum: '<S39>/SignPreIntegrator' */

  /* Switch: '<S39>/Switch' incorporates:
   *  Constant: '<S39>/Constant1'
   *  DataTypeConversion: '<S39>/DataTypeConv1'
   *  DataTypeConversion: '<S39>/DataTypeConv2'
   *  Logic: '<S39>/AND3'
   *  RelationalOperator: '<S39>/Equal1'
   *  RelationalOperator: '<S39>/NotEqual'
   */
  if ((rtb_ZeroGain_f != rtb_SignPreSat_e) && ((int8_T)
       rtb_DiscreteTimeIntegrator == (int8_T)rtb_SignPreSat)) {
    rtb_IProdOut_a = 0.0;
  }

  /* End of Switch: '<S39>/Switch' */

  /* Update for DiscreteIntegrator: '<S48>/Integrator' */
  rtDW.Integrator_DSTATE_l += 0.0001 * rtb_IProdOut_a;

  /* Outport: '<Root>/DutyOut' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Gain: '<S6>/Gain'
   *  Sum: '<S6>/Add'
   *  Sum: '<S6>/Add1'
   *  Sum: '<S6>/Add2'
   */
  rtY.DutyOut[0] = 1.0 - 2.0 * rtb_T6;
  rtY.DutyOut[1] = 1.0 - 2.0 * rtb_T4;
  rtY.DutyOut[2] = 1.0 - 2.0 * rtb_Divide4;

  /* End of Outputs for SubSystem: '<Root>/IF' */
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
