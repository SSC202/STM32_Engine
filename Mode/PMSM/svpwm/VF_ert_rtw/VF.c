/*
 * File: VF.c
 *
 * Code generated for Simulink model 'VF'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Oct 25 22:40:40 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "VF.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void VF_step(void)
{
  real_T rtb_MathFunction;
  real_T rtb_MathFunction_h;
  real_T rtb_MultiportSwitch;
  real_T rtb_MultiportSwitch1;
  real_T rtb_MultiportSwitch1_l;
  real_T rtb_Subtract1_l;
  int32_T rtb_Subtract2;
  real32_T rtb_MathFunction_j;
  real32_T rtb_SinCos4;
  real32_T rtb_Sum;

  /* Sum: '<S4>/Sum' incorporates:
   *  Gain: '<S4>/Gain'
   *  Inport: '<Root>/Freq'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  rtb_Sum = (real32_T)(0.00062831853071795862 * rtU.Freq) +
    rtDW.UnitDelay_DSTATE;

  /* If: '<S6>/If' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  RelationalOperator: '<S6>/Relational Operator'
   *  RelationalOperator: '<S6>/Relational Operator1'
   */
  if (rtb_Sum > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Sum: '<S7>/Sum' incorporates:
     *  Constant: '<S7>/Constant'
     */
    rtb_Sum -= 6.28318548F;

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem1' */
  } else if (rtb_Sum < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Sum: '<S9>/Sum' incorporates:
     *  Constant: '<S9>/Constant'
     */
    rtb_Sum += 6.28318548F;

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem3' */
  }

  /* End of If: '<S6>/If' */

  /* Trigonometry: '<S1>/SinCos4' */
  rtb_SinCos4 = arm_sin_f32(rtb_Sum);

  /* Trigonometry: '<S1>/SinCos5' */
  rtb_MathFunction_j = arm_cos_f32(rtb_Sum);

  /* Sum: '<S2>/Subtract1' incorporates:
   *  Inport: '<Root>/ud'
   *  Inport: '<Root>/uq'
   *  Product: '<S2>/Product2'
   *  Product: '<S2>/Product3'
   */
  rtb_Subtract1_l = rtU.ud * rtb_SinCos4 + rtU.uq * rtb_MathFunction_j;

  /* Sum: '<S2>/Subtract' incorporates:
   *  Inport: '<Root>/ud'
   *  Inport: '<Root>/uq'
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product1'
   */
  rtb_MathFunction_h = rtU.ud * rtb_MathFunction_j - rtU.uq * rtb_SinCos4;

  /* Gain: '<S10>/Gain4' */
  rtb_MultiportSwitch = 0.86602538824081421 * rtb_MathFunction_h;

  /* Gain: '<S10>/Gain1' */
  rtb_MultiportSwitch1_l = 0.5 * rtb_Subtract1_l;

  /* Sum: '<S10>/Subtract2' incorporates:
   *  Gain: '<S10>/Gain2'
   *  Gain: '<S10>/Gain3'
   *  Sum: '<S10>/Subtract'
   *  Sum: '<S10>/Subtract1'
   *  Switch: '<S10>/Switch'
   *  Switch: '<S10>/Switch1'
   *  Switch: '<S10>/Switch2'
   */
  rtb_Subtract2 = (((rtb_MultiportSwitch - rtb_MultiportSwitch1_l >= 0.0) << 1)
                   + (rtb_Subtract1_l >= 0.0)) + (((0.0 - rtb_MultiportSwitch) -
    rtb_MultiportSwitch1_l >= 0.0) << 2);

  /* Math: '<S1>/Math Function' incorporates:
   *  Inport: '<Root>/Freq'
   *
   * About '<S1>/Math Function':
   *  Operator: reciprocal
   */
  rtb_MathFunction = 1.0 / rtU.Freq;

  /* Gain: '<S13>/Gain2' */
  rtb_MultiportSwitch1 = 0.8660254037844386 * rtb_Subtract1_l;

  /* Gain: '<S13>/Gain' */
  rtb_MathFunction_h *= 1.5;

  /* Product: '<S13>/Product' incorporates:
   *  Inport: '<Root>/ubus'
   *  Math: '<S13>/Math Function'
   *
   * About '<S13>/Math Function':
   *  Operator: reciprocal
   */
  rtb_MultiportSwitch1_l = 1.0F / rtU.ubus * rtb_MathFunction;

  /* MultiPortSwitch: '<S11>/Multiport Switch' incorporates:
   *  Gain: '<S11>/Gain'
   *  Gain: '<S11>/Gain1'
   *  Gain: '<S11>/Gain2'
   *  Gain: '<S13>/Gain1'
   *  Product: '<S13>/Product1'
   *  Product: '<S13>/Product2'
   *  Product: '<S13>/Product3'
   *  Sum: '<S13>/Add'
   *  Sum: '<S13>/Subtract'
   */
  switch (rtb_Subtract2) {
   case 1:
    rtb_MultiportSwitch = (rtb_MultiportSwitch1 - rtb_MathFunction_h) *
      rtb_MultiportSwitch1_l;

    /* MultiPortSwitch: '<S11>/Multiport Switch1' incorporates:
     *  Product: '<S13>/Product2'
     *  Product: '<S13>/Product3'
     *  Sum: '<S13>/Add'
     *  Sum: '<S13>/Subtract'
     */
    rtb_MultiportSwitch1 = (rtb_MultiportSwitch1 + rtb_MathFunction_h) *
      rtb_MultiportSwitch1_l;
    break;

   case 2:
    rtb_MultiportSwitch = (rtb_MultiportSwitch1 + rtb_MathFunction_h) *
      rtb_MultiportSwitch1_l;

    /* MultiPortSwitch: '<S11>/Multiport Switch1' incorporates:
     *  Gain: '<S11>/Gain1'
     *  Gain: '<S13>/Gain1'
     *  Product: '<S13>/Product1'
     *  Product: '<S13>/Product2'
     *  Sum: '<S13>/Add'
     */
    rtb_MultiportSwitch1 = -(1.7320508075688772 * rtb_Subtract1_l *
      rtb_MultiportSwitch1_l);
    break;

   case 3:
    rtb_MultiportSwitch = -((rtb_MultiportSwitch1 - rtb_MathFunction_h) *
      rtb_MultiportSwitch1_l);

    /* MultiPortSwitch: '<S11>/Multiport Switch1' incorporates:
     *  Gain: '<S11>/Gain'
     *  Gain: '<S13>/Gain1'
     *  Product: '<S13>/Product1'
     *  Product: '<S13>/Product3'
     *  Sum: '<S13>/Subtract'
     */
    rtb_MultiportSwitch1 = 1.7320508075688772 * rtb_Subtract1_l *
      rtb_MultiportSwitch1_l;
    break;

   case 4:
    rtb_MultiportSwitch = -(1.7320508075688772 * rtb_Subtract1_l *
      rtb_MultiportSwitch1_l);

    /* MultiPortSwitch: '<S11>/Multiport Switch1' incorporates:
     *  Gain: '<S11>/Gain1'
     *  Gain: '<S13>/Gain1'
     *  Product: '<S13>/Product1'
     *  Product: '<S13>/Product3'
     *  Sum: '<S13>/Subtract'
     */
    rtb_MultiportSwitch1 = (rtb_MultiportSwitch1 - rtb_MathFunction_h) *
      rtb_MultiportSwitch1_l;
    break;

   case 5:
    rtb_MultiportSwitch = 1.7320508075688772 * rtb_Subtract1_l *
      rtb_MultiportSwitch1_l;

    /* MultiPortSwitch: '<S11>/Multiport Switch1' incorporates:
     *  Gain: '<S11>/Gain2'
     *  Gain: '<S13>/Gain1'
     *  Product: '<S13>/Product1'
     *  Product: '<S13>/Product2'
     *  Sum: '<S13>/Add'
     */
    rtb_MultiportSwitch1 = -((rtb_MultiportSwitch1 + rtb_MathFunction_h) *
      rtb_MultiportSwitch1_l);
    break;

   default:
    rtb_MultiportSwitch = -((rtb_MultiportSwitch1 + rtb_MathFunction_h) *
      rtb_MultiportSwitch1_l);

    /* MultiPortSwitch: '<S11>/Multiport Switch1' incorporates:
     *  Gain: '<S11>/Gain'
     *  Gain: '<S11>/Gain2'
     *  Product: '<S13>/Product2'
     *  Product: '<S13>/Product3'
     *  Sum: '<S13>/Add'
     *  Sum: '<S13>/Subtract'
     */
    rtb_MultiportSwitch1 = -((rtb_MultiportSwitch1 - rtb_MathFunction_h) *
      rtb_MultiportSwitch1_l);
    break;
  }

  /* End of MultiPortSwitch: '<S11>/Multiport Switch' */

  /* Switch: '<S11>/Switch' incorporates:
   *  Product: '<S11>/Divide'
   *  Product: '<S11>/Divide1'
   *  Product: '<S11>/Product'
   *  Product: '<S11>/Product1'
   *  Sum: '<S11>/Add'
   *  Sum: '<S11>/Add1'
   *  Switch: '<S11>/Switch1'
   */
  if ((rtb_MathFunction - rtb_MultiportSwitch) - rtb_MultiportSwitch1 > 0.0) {
    rtb_MultiportSwitch1_l = rtb_MultiportSwitch;
  } else {
    /* Sum: '<S11>/Add' incorporates:
     *  Sum: '<S11>/Add2'
     */
    rtb_Subtract1_l = rtb_MultiportSwitch + rtb_MultiportSwitch1;
    rtb_MultiportSwitch1_l = rtb_MultiportSwitch * rtb_MathFunction /
      rtb_Subtract1_l;
    rtb_MultiportSwitch1 = rtb_MultiportSwitch1 * rtb_MathFunction /
      rtb_Subtract1_l;
  }

  /* End of Switch: '<S11>/Switch' */

  /* Gain: '<S12>/Gain1' incorporates:
   *  Sum: '<S12>/Add1'
   */
  rtb_Subtract1_l = ((rtb_MultiportSwitch1_l - rtb_MultiportSwitch1) +
                     rtb_MathFunction) * 0.25;

  /* Gain: '<S12>/Gain' incorporates:
   *  Sum: '<S12>/Add'
   */
  rtb_MultiportSwitch = ((rtb_MathFunction - rtb_MultiportSwitch1_l) -
    rtb_MultiportSwitch1) * 0.25;

  /* Gain: '<S12>/Gain2' incorporates:
   *  Sum: '<S12>/Add2'
   */
  rtb_MathFunction_h = ((rtb_MultiportSwitch1_l + rtb_MultiportSwitch1) +
                        rtb_MathFunction) * 0.25;

  /* MultiPortSwitch: '<S12>/Multiport Switch' incorporates:
   *  Gain: '<S12>/Gain1'
   *  Gain: '<S12>/Gain2'
   *  Sum: '<S12>/Add1'
   *  Sum: '<S12>/Add2'
   */
  switch (rtb_Subtract2) {
   case 1:
    rtb_MultiportSwitch1 = ((rtb_MultiportSwitch1_l - rtb_MultiportSwitch1) +
      rtb_MathFunction) * 0.25;

    /* MultiPortSwitch: '<S12>/Multiport Switch1' incorporates:
     *  Gain: '<S12>/Gain'
     *  Gain: '<S12>/Gain1'
     *  Sum: '<S12>/Add1'
     */
    rtb_MultiportSwitch1_l = rtb_MultiportSwitch;

    /* MultiPortSwitch: '<S12>/Multiport Switch2' incorporates:
     *  Gain: '<S12>/Gain2'
     */
    rtb_MultiportSwitch = rtb_MathFunction_h;
    break;

   case 2:
    rtb_MultiportSwitch1 = rtb_MultiportSwitch;

    /* MultiPortSwitch: '<S12>/Multiport Switch1' incorporates:
     *  Gain: '<S12>/Gain2'
     */
    rtb_MultiportSwitch1_l = rtb_MathFunction_h;

    /* MultiPortSwitch: '<S12>/Multiport Switch2' incorporates:
     *  Gain: '<S12>/Gain1'
     */
    rtb_MultiportSwitch = rtb_Subtract1_l;
    break;

   case 3:
    rtb_MultiportSwitch1 = rtb_MultiportSwitch;

    /* MultiPortSwitch: '<S12>/Multiport Switch1' incorporates:
     *  Gain: '<S12>/Gain1'
     */
    rtb_MultiportSwitch1_l = rtb_Subtract1_l;

    /* MultiPortSwitch: '<S12>/Multiport Switch2' incorporates:
     *  Gain: '<S12>/Gain2'
     */
    rtb_MultiportSwitch = rtb_MathFunction_h;
    break;

   case 4:
    rtb_MultiportSwitch1 = ((rtb_MultiportSwitch1_l + rtb_MultiportSwitch1) +
      rtb_MathFunction) * 0.25;

    /* MultiPortSwitch: '<S12>/Multiport Switch1' incorporates:
     *  Gain: '<S12>/Gain1'
     *  Gain: '<S12>/Gain2'
     *  Sum: '<S12>/Add2'
     */
    rtb_MultiportSwitch1_l = rtb_Subtract1_l;
    break;

   case 5:
    rtb_MultiportSwitch1 = ((rtb_MultiportSwitch1_l + rtb_MultiportSwitch1) +
      rtb_MathFunction) * 0.25;

    /* MultiPortSwitch: '<S12>/Multiport Switch1' incorporates:
     *  Gain: '<S12>/Gain'
     *  Gain: '<S12>/Gain2'
     *  Sum: '<S12>/Add2'
     */
    rtb_MultiportSwitch1_l = rtb_MultiportSwitch;

    /* MultiPortSwitch: '<S12>/Multiport Switch2' incorporates:
     *  Gain: '<S12>/Gain1'
     */
    rtb_MultiportSwitch = rtb_Subtract1_l;
    break;

   default:
    rtb_MultiportSwitch1 = ((rtb_MultiportSwitch1_l - rtb_MultiportSwitch1) +
      rtb_MathFunction) * 0.25;

    /* MultiPortSwitch: '<S12>/Multiport Switch1' incorporates:
     *  Gain: '<S12>/Gain1'
     *  Gain: '<S12>/Gain2'
     *  Sum: '<S12>/Add1'
     */
    rtb_MultiportSwitch1_l = rtb_MathFunction_h;
    break;
  }

  /* End of MultiPortSwitch: '<S12>/Multiport Switch' */

  /* Math: '<S3>/Math Function'
   *
   * About '<S3>/Math Function':
   *  Operator: reciprocal
   */
  rtb_MathFunction_h = 1.0 / rtb_MathFunction;

  /* Outport: '<Root>/DutyOut' incorporates:
   *  Product: '<S3>/Product'
   */
  rtY.DutyOut[0] = rtb_MultiportSwitch1 * rtb_MathFunction_h;
  rtY.DutyOut[1] = rtb_MultiportSwitch1_l * rtb_MathFunction_h;
  rtY.DutyOut[2] = rtb_MultiportSwitch * rtb_MathFunction_h;

  /* Update for UnitDelay: '<S4>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtb_Sum;
}

/* Model initialize function */
void VF_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
