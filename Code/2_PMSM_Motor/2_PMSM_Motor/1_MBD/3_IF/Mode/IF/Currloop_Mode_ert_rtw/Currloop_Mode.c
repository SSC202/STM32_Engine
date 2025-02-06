/*
 * File: Currloop_Mode.c
 *
 * Code generated for Simulink model 'Currloop_Mode'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Aug 15 17:06:22 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Currloop_Mode.h"
#include <math.h>
#include "rtwtypes.h"
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
real32_T i_alpha;                      /* '<S3>/Add2' */
real32_T i_beta;                       /* '<S3>/Gain2' */
real32_T i_d;                          /* '<S5>/Add' */
real32_T i_q;                          /* '<S5>/Add1' */

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Model step function */
void Currloop_Mode_step(void)
{
  int32_T rtb_Add;
  real32_T rtb_Add2;
  real32_T rtb_DeadZone;
  real32_T rtb_DeadZone_j;
  real32_T rtb_Divide1;
  real32_T rtb_Divide_i;
  real32_T rtb_Divide_j;
  real32_T rtb_Gain2_f;
  real32_T rtb_IProdOut;
  real32_T rtb_T4Switch;
  int16_T rtb_IProdOut_d;
  int8_T tmp;
  int8_T tmp_0;

  /* Outputs for Atomic SubSystem: '<Root>/Currloop_Mode' */
  /* Sum: '<S3>/Add2' incorporates:
   *  Gain: '<S3>/Gain'
   *  Gain: '<S3>/Gain1'
   *  Inport: '<Root>/I_a'
   *  Inport: '<Root>/I_b'
   *  Inport: '<Root>/I_c'
   *  Sum: '<S3>/Add'
   */
  i_alpha = 0.666666687F * rtU.I_a - (rtU.I_b + rtU.I_c) * 0.333333343F;

  /* Trigonometry: '<S5>/Trigonometric Function1' incorporates:
   *  Inport: '<Root>/electric_theta'
   *  Trigonometry: '<S2>/Trigonometric Function1'
   */
  rtb_Add2 = cosf(rtU.electric_theta);

  /* Gain: '<S3>/Gain2' incorporates:
   *  Inport: '<Root>/I_b'
   *  Inport: '<Root>/I_c'
   *  Sum: '<S3>/Add1'
   */
  i_beta = (rtU.I_b - rtU.I_c) * 0.577350259F;

  /* Trigonometry: '<S5>/Trigonometric Function' incorporates:
   *  Inport: '<Root>/electric_theta'
   *  Trigonometry: '<S2>/Trigonometric Function'
   */
  rtb_T4Switch = sinf(rtU.electric_theta);

  /* Sum: '<S5>/Add' incorporates:
   *  Product: '<S5>/Product'
   *  Product: '<S5>/Product1'
   *  Trigonometry: '<S5>/Trigonometric Function'
   *  Trigonometry: '<S5>/Trigonometric Function1'
   */
  i_d = i_alpha * rtb_Add2 + i_beta * rtb_T4Switch;

  /* Sum: '<S51>/Sum' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant3'
   *  DiscreteIntegrator: '<S42>/Integrator'
   *  Product: '<S47>/PProd Out'
   *  Sum: '<S4>/Sum1'
   */
  rtb_DeadZone = (0.0F - i_d) * 0.17F + (real32_T)rtDW.Integrator_DSTATE_l *
    0.0001F;

  /* Saturate: '<S49>/Saturation' */
  if (rtb_DeadZone > 12.4707661F) {
    rtb_Divide_j = 12.4707661F;
  } else if (rtb_DeadZone < -12.4707661F) {
    rtb_Divide_j = -12.4707661F;
  } else {
    rtb_Divide_j = rtb_DeadZone;
  }

  /* End of Saturate: '<S49>/Saturation' */

  /* Sum: '<S5>/Add1' incorporates:
   *  Product: '<S5>/Product2'
   *  Product: '<S5>/Product3'
   *  Trigonometry: '<S5>/Trigonometric Function'
   *  Trigonometry: '<S5>/Trigonometric Function1'
   */
  i_q = i_beta * rtb_Add2 - i_alpha * rtb_T4Switch;

  /* Sum: '<S4>/Sum7' incorporates:
   *  Inport: '<Root>/iq_ref'
   */
  rtb_IProdOut = rtU.iq_ref - i_q;

  /* Sum: '<S101>/Sum' incorporates:
   *  Constant: '<S4>/Constant1'
   *  DiscreteIntegrator: '<S92>/Integrator'
   *  Product: '<S97>/PProd Out'
   */
  rtb_DeadZone_j = rtb_IProdOut * 0.17F + rtDW.Integrator_DSTATE;

  /* Saturate: '<S99>/Saturation' */
  if (rtb_DeadZone_j > 12.4707661F) {
    rtb_Divide1 = 12.4707661F;
  } else if (rtb_DeadZone_j < -12.4707661F) {
    rtb_Divide1 = -12.4707661F;
  } else {
    rtb_Divide1 = rtb_DeadZone_j;
  }

  /* End of Saturate: '<S99>/Saturation' */

  /* Sum: '<S2>/Add1' incorporates:
   *  Product: '<S2>/Product1'
   *  Product: '<S2>/Product2'
   */
  rtb_Divide_i = rtb_Divide_j * rtb_T4Switch + rtb_Divide1 * rtb_Add2;

  /* Gain: '<S110>/Gain' incorporates:
   *  Gain: '<S112>/Gain1'
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product3'
   *  Sum: '<S2>/Add'
   */
  rtb_Gain2_f = (rtb_Divide_j * rtb_Add2 - rtb_Divide1 * rtb_T4Switch) *
    0.866025388F;

  /* Gain: '<S110>/Gain1' incorporates:
   *  Gain: '<S112>/Gain2'
   */
  rtb_Divide1 = 0.5F * rtb_Divide_i;

  /* Sum: '<S110>/Add' incorporates:
   *  Gain: '<S110>/Gain'
   *  Gain: '<S110>/Gain1'
   *  Gain: '<S110>/Gain2'
   *  Gain: '<S110>/Gain3'
   *  Sum: '<S110>/Add1'
   *  Sum: '<S110>/Add2'
   *  Switch: '<S110>/ A Switch'
   *  Switch: '<S110>/ B Switch'
   *  Switch: '<S110>/ C Switch'
   */
  rtb_Add = (((rtb_Gain2_f - rtb_Divide1 > 0.0F) << 1) + (rtb_Divide_i > 0.0F))
    + (((0.0F - rtb_Gain2_f) - rtb_Divide1 > 0.0F) << 2);

  /* Gain: '<S109>/Gain1' incorporates:
   *  Inport: '<Root>/T_pwm'
   */
  rtb_Add2 = 0.25F * rtU.T_pwm;

  /* Product: '<S112>/Divide' incorporates:
   *  Gain: '<S112>/Gain'
   *  Inport: '<Root>/T_pwm'
   *  Inport: '<Root>/u_dc'
   */
  rtb_Divide_j = 1.73205078F * rtU.T_pwm / rtU.u_dc;

  /* MultiPortSwitch: '<S111>/T4 Switch' incorporates:
   *  Gain: '<S111>/Gain'
   *  Gain: '<S111>/Gain1'
   *  Gain: '<S111>/Gain2'
   *  Product: '<S112>/Product'
   *  Product: '<S112>/Product1'
   *  Product: '<S112>/Product2'
   *  Sum: '<S112>/Add'
   *  Sum: '<S112>/Add1'
   */
  switch (rtb_Add) {
   case 1:
    rtb_T4Switch = (rtb_Divide1 - rtb_Gain2_f) * rtb_Divide_j;

    /* MultiPortSwitch: '<S111>/T6 Switch' incorporates:
     *  Product: '<S112>/Product1'
     *  Product: '<S112>/Product2'
     *  Sum: '<S112>/Add'
     *  Sum: '<S112>/Add1'
     */
    rtb_Divide_j *= rtb_Gain2_f + rtb_Divide1;
    break;

   case 2:
    rtb_T4Switch = (rtb_Gain2_f + rtb_Divide1) * rtb_Divide_j;

    /* MultiPortSwitch: '<S111>/T6 Switch' incorporates:
     *  Gain: '<S111>/Gain'
     *  Product: '<S112>/Product'
     *  Product: '<S112>/Product1'
     *  Sum: '<S112>/Add'
     */
    rtb_Divide_j = -(rtb_Divide_i * rtb_Divide_j);
    break;

   case 3:
    rtb_T4Switch = -((rtb_Divide1 - rtb_Gain2_f) * rtb_Divide_j);

    /* MultiPortSwitch: '<S111>/T6 Switch' incorporates:
     *  Gain: '<S111>/Gain2'
     *  Product: '<S112>/Product'
     *  Product: '<S112>/Product2'
     *  Sum: '<S112>/Add1'
     */
    rtb_Divide_j *= rtb_Divide_i;
    break;

   case 4:
    rtb_T4Switch = -(rtb_Divide_i * rtb_Divide_j);

    /* MultiPortSwitch: '<S111>/T6 Switch' incorporates:
     *  Gain: '<S111>/Gain'
     *  Product: '<S112>/Product'
     *  Product: '<S112>/Product2'
     *  Sum: '<S112>/Add1'
     */
    rtb_Divide_j *= rtb_Divide1 - rtb_Gain2_f;
    break;

   case 5:
    rtb_T4Switch = rtb_Divide_i * rtb_Divide_j;

    /* MultiPortSwitch: '<S111>/T6 Switch' incorporates:
     *  Gain: '<S111>/Gain1'
     *  Product: '<S112>/Product'
     *  Product: '<S112>/Product1'
     *  Sum: '<S112>/Add'
     */
    rtb_Divide_j = -((rtb_Gain2_f + rtb_Divide1) * rtb_Divide_j);
    break;

   default:
    rtb_T4Switch = -((rtb_Gain2_f + rtb_Divide1) * rtb_Divide_j);

    /* MultiPortSwitch: '<S111>/T6 Switch' incorporates:
     *  Gain: '<S111>/Gain1'
     *  Gain: '<S111>/Gain2'
     *  Product: '<S112>/Product1'
     *  Product: '<S112>/Product2'
     *  Sum: '<S112>/Add'
     *  Sum: '<S112>/Add1'
     */
    rtb_Divide_j = -((rtb_Divide1 - rtb_Gain2_f) * rtb_Divide_j);
    break;
  }

  /* End of MultiPortSwitch: '<S111>/T4 Switch' */

  /* Sum: '<S111>/Add1' incorporates:
   *  Sum: '<S111>/Add'
   */
  rtb_Divide1 = rtb_T4Switch + rtb_Divide_j;

  /* Product: '<S111>/Divide' incorporates:
   *  Inport: '<Root>/T_pwm'
   *  Sum: '<S111>/Add1'
   */
  rtb_Gain2_f = rtU.T_pwm / rtb_Divide1;

  /* Switch: '<S111>/Switch' incorporates:
   *  Inport: '<Root>/T_pwm'
   *  Product: '<S111>/Product'
   *  Product: '<S111>/Product1'
   *  Sum: '<S111>/Add'
   *  Switch: '<S111>/Switch1'
   */
  if (rtb_Divide1 - rtU.T_pwm > 0.0F) {
    rtb_T4Switch *= rtb_Gain2_f;
    rtb_Divide_j *= rtb_Gain2_f;
  }

  /* Gain: '<S109>/Gain' incorporates:
   *  Switch: '<S111>/Switch'
   */
  rtb_Divide1 = 0.25F * rtb_T4Switch;

  /* Gain: '<S109>/Gain2' incorporates:
   *  Switch: '<S111>/Switch1'
   */
  rtb_Divide_i = 0.25F * rtb_Divide_j;

  /* Sum: '<S109>/Add' */
  rtb_Divide_j = (rtb_Add2 - rtb_Divide1) - rtb_Divide_i;

  /* Sum: '<S109>/Add1' incorporates:
   *  Sum: '<S109>/Add2'
   */
  rtb_Add2 += rtb_Divide1;
  rtb_T4Switch = rtb_Add2 - rtb_Divide_i;

  /* Sum: '<S109>/Add2' */
  rtb_Add2 += rtb_Divide_i;

  /* MultiPortSwitch: '<S109>/Ta Switch' */
  switch (rtb_Add) {
   case 1:
    rtb_Divide_i = rtb_T4Switch;
    break;

   case 2:
    rtb_Divide_i = rtb_Divide_j;
    break;

   case 3:
    rtb_Divide_i = rtb_Divide_j;
    break;

   case 4:
    rtb_Divide_i = rtb_Add2;
    break;

   case 5:
    rtb_Divide_i = rtb_Add2;
    break;

   default:
    rtb_Divide_i = rtb_T4Switch;
    break;
  }

  /* End of MultiPortSwitch: '<S109>/Ta Switch' */

  /* Product: '<S109>/Divide' incorporates:
   *  Inport: '<Root>/T_pwm'
   */
  rtb_Divide_i /= rtU.T_pwm;

  /* MultiPortSwitch: '<S109>/Tc Switch' */
  switch (rtb_Add) {
   case 1:
    rtb_Divide1 = rtb_Add2;
    break;

   case 2:
    rtb_Divide1 = rtb_T4Switch;
    break;

   case 3:
    rtb_Divide1 = rtb_Add2;
    break;

   case 4:
    rtb_Divide1 = rtb_Divide_j;
    break;

   case 5:
    rtb_Divide1 = rtb_T4Switch;
    break;

   default:
    rtb_Divide1 = rtb_Divide_j;
    break;
  }

  /* End of MultiPortSwitch: '<S109>/Tc Switch' */

  /* Product: '<S109>/Divide1' incorporates:
   *  Inport: '<Root>/T_pwm'
   */
  rtb_Divide1 /= rtU.T_pwm;

  /* MultiPortSwitch: '<S109>/Tb Switch' */
  switch (rtb_Add) {
   case 1:
    rtb_Add2 = rtb_Divide_j;
    break;

   case 2:
    break;

   case 3:
    rtb_Add2 = rtb_T4Switch;
    break;

   case 4:
    rtb_Add2 = rtb_T4Switch;
    break;

   case 5:
    rtb_Add2 = rtb_Divide_j;
    break;
  }

  /* End of MultiPortSwitch: '<S109>/Tb Switch' */

  /* DeadZone: '<S85>/DeadZone' */
  if (rtb_DeadZone_j > 12.4707661F) {
    rtb_DeadZone_j -= 12.4707661F;
  } else if (rtb_DeadZone_j >= -12.4707661F) {
    rtb_DeadZone_j = 0.0F;
  } else {
    rtb_DeadZone_j -= -12.4707661F;
  }

  /* End of DeadZone: '<S85>/DeadZone' */

  /* Product: '<S89>/IProd Out' incorporates:
   *  Constant: '<S4>/Constant2'
   */
  rtb_IProdOut *= 35.0F;

  /* DeadZone: '<S35>/DeadZone' */
  if (rtb_DeadZone > 12.4707661F) {
    rtb_DeadZone -= 12.4707661F;
  } else if (rtb_DeadZone >= -12.4707661F) {
    rtb_DeadZone = 0.0F;
  } else {
    rtb_DeadZone -= -12.4707661F;
  }

  /* End of DeadZone: '<S35>/DeadZone' */

  /* Product: '<S39>/IProd Out' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant4'
   *  Sum: '<S4>/Sum1'
   */
  rtb_IProdOut_d = (int16_T)floorf((0.0F - i_d) * 35.0F);

  /* Switch: '<S33>/Switch1' incorporates:
   *  Constant: '<S33>/Constant'
   *  Constant: '<S33>/Constant2'
   *  RelationalOperator: '<S33>/fix for DT propagation issue'
   */
  if (rtb_DeadZone > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S33>/Switch2' incorporates:
   *  Constant: '<S33>/Clamping_zero'
   *  Constant: '<S33>/Constant3'
   *  Constant: '<S33>/Constant4'
   *  RelationalOperator: '<S33>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut_d > 0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S33>/Switch' incorporates:
   *  Constant: '<S33>/Constant1'
   *  Logic: '<S33>/AND3'
   *  RelationalOperator: '<S33>/Equal1'
   *  RelationalOperator: '<S33>/Relational Operator'
   *  Switch: '<S33>/Switch1'
   *  Switch: '<S33>/Switch2'
   */
  if ((rtb_DeadZone != 0.0F) && (tmp == tmp_0)) {
    rtb_IProdOut_d = 0;
  }

  /* Update for DiscreteIntegrator: '<S42>/Integrator' incorporates:
   *  Switch: '<S33>/Switch'
   */
  rtDW.Integrator_DSTATE_l += rtb_IProdOut_d;

  /* Switch: '<S83>/Switch1' incorporates:
   *  Constant: '<S83>/Clamping_zero'
   *  Constant: '<S83>/Constant'
   *  Constant: '<S83>/Constant2'
   *  RelationalOperator: '<S83>/fix for DT propagation issue'
   */
  if (rtb_DeadZone_j > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S83>/Switch2' incorporates:
   *  Constant: '<S83>/Clamping_zero'
   *  Constant: '<S83>/Constant3'
   *  Constant: '<S83>/Constant4'
   *  RelationalOperator: '<S83>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S83>/Switch' incorporates:
   *  Constant: '<S83>/Clamping_zero'
   *  Constant: '<S83>/Constant1'
   *  Logic: '<S83>/AND3'
   *  RelationalOperator: '<S83>/Equal1'
   *  RelationalOperator: '<S83>/Relational Operator'
   *  Switch: '<S83>/Switch1'
   *  Switch: '<S83>/Switch2'
   */
  if ((rtb_DeadZone_j != 0.0F) && (tmp == tmp_0)) {
    rtb_IProdOut = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S92>/Integrator' incorporates:
   *  Switch: '<S83>/Switch'
   */
  rtDW.Integrator_DSTATE += 0.0001F * rtb_IProdOut;

  /* Outport: '<Root>/Duty' incorporates:
   *  Constant: '<S6>/Constant'
   *  Gain: '<S6>/Gain'
   *  Inport: '<Root>/T_pwm'
   *  Product: '<S109>/Divide2'
   *  Sum: '<S6>/Sum'
   */
  rtY.Duty[0] = 1.0 - 2.0F * rtb_Divide_i;
  rtY.Duty[1] = 1.0 - rtb_Add2 / rtU.T_pwm * 2.0F;
  rtY.Duty[2] = 1.0 - 2.0F * rtb_Divide1;

  /* End of Outputs for SubSystem: '<Root>/Currloop_Mode' */
}

/* Model initialize function */
void Currloop_Mode_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
