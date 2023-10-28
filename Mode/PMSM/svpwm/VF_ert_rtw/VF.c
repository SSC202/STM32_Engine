/*
 * File: VF.c
 *
 * Code generated for Simulink model 'VF'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Oct 28 11:46:00 2023
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
  real_T rtb_Divide4;
  real_T rtb_T4;
  real_T rtb_T6;
  real_T rtb_T6_tmp;
  real_T rtb_Tcm2;
  real32_T rtb_A;
  real32_T rtb_SinCos5;
  real32_T rtb_Sum_n;

  /* Outputs for Atomic SubSystem: '<Root>/VF' */
  /* Sum: '<S3>/Sum' incorporates:
   *  Gain: '<S3>/Gain'
   *  Inport: '<Root>/Freq'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  rtb_Sum_n = (real32_T)(0.00062831853071795862 * rtU.Freq) +
    rtDW.UnitDelay_DSTATE;

  /* If: '<S6>/If' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  RelationalOperator: '<S6>/Relational Operator'
   *  RelationalOperator: '<S6>/Relational Operator1'
   */
  if (rtb_Sum_n > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Sum: '<S7>/Sum' incorporates:
     *  Constant: '<S7>/Constant'
     */
    rtb_Sum_n -= 6.28318548F;

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem1' */
  } else if (rtb_Sum_n < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Sum: '<S9>/Sum' incorporates:
     *  Constant: '<S9>/Constant'
     */
    rtb_Sum_n += 6.28318548F;

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem3' */
  }

  /* End of If: '<S6>/If' */

  /* Trigonometry: '<S1>/SinCos4' */
  rtb_A = sinf(rtb_Sum_n);

  /* Trigonometry: '<S1>/SinCos5' */
  rtb_SinCos5 = cosf(rtb_Sum_n);

  /* Gain: '<S10>/Gain1' incorporates:
   *  Gain: '<S11>/Gain2'
   *  Inport: '<Root>/ud'
   *  Inport: '<Root>/uq'
   *  Product: '<S2>/Product2'
   *  Product: '<S2>/Product3'
   *  Sum: '<S2>/Subtract1'
   */
  rtb_T6 = (rtU.ud * rtb_SinCos5 - rtU.uq * rtb_A) * 0.8660254037844386;

  /* Sum: '<S2>/Subtract' incorporates:
   *  Inport: '<Root>/ud'
   *  Inport: '<Root>/uq'
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product1'
   */
  rtb_Tcm2 = rtU.ud * rtb_A + rtU.uq * rtb_SinCos5;

  /* Gain: '<S10>/Gain2' incorporates:
   *  Gain: '<S11>/Gain1'
   */
  rtb_T6_tmp = 0.5 * rtb_Tcm2;

  /* Sum: '<S10>/Add' incorporates:
   *  Gain: '<S10>/Gain1'
   *  Gain: '<S10>/Gain2'
   *  Gain: '<S10>/Gain3'
   *  Gain: '<S10>/Gain4'
   *  Gain: '<S10>/Gain5'
   *  Sum: '<S10>/Sum'
   *  Sum: '<S10>/Sum1'
   *  Switch: '<S10>/Switch'
   *  Switch: '<S10>/Switch1'
   *  Switch: '<S10>/Switch2'
   */
  rtb_A = (real32_T)((((-rtb_T6 - rtb_T6_tmp > 0.0) << 2) + ((rtb_T6 -
    rtb_T6_tmp > 0.0) << 1)) + (rtb_Tcm2 > 0.0));

  /* Product: '<S11>/Divide' incorporates:
   *  Inport: '<Root>/u_bus'
   */
  rtb_Divide4 = 1.7320508075688772 / rtU.u_bus;

  /* MultiPortSwitch: '<S11>/Multiport Switch' incorporates:
   *  Gain: '<S11>/Gain3'
   *  Gain: '<S11>/Gain4'
   *  Gain: '<S11>/Gain5'
   *  Gain: '<S11>/Gain6'
   *  Product: '<S11>/Divide1'
   *  Product: '<S11>/Divide2'
   *  Product: '<S11>/Divide3'
   *  Sum: '<S11>/Sum'
   *  Sum: '<S11>/Sum1'
   */
  switch ((int32_T)rtb_A) {
   case 1:
    rtb_T4 = (-rtb_T6 + rtb_T6_tmp) * rtb_Divide4;

    /* MultiPortSwitch: '<S11>/Multiport Switch1' incorporates:
     *  Gain: '<S11>/Gain3'
     *  Product: '<S11>/Divide2'
     *  Product: '<S11>/Divide3'
     *  Sum: '<S11>/Sum'
     *  Sum: '<S11>/Sum1'
     */
    rtb_T6 = (rtb_T6 + rtb_T6_tmp) * rtb_Divide4;
    break;

   case 2:
    rtb_T4 = (rtb_T6 + rtb_T6_tmp) * rtb_Divide4;

    /* MultiPortSwitch: '<S11>/Multiport Switch1' incorporates:
     *  Gain: '<S11>/Gain6'
     *  Product: '<S11>/Divide1'
     *  Product: '<S11>/Divide2'
     *  Sum: '<S11>/Sum'
     */
    rtb_T6 = -(rtb_Tcm2 * rtb_Divide4);
    break;

   case 3:
    rtb_T4 = -((-rtb_T6 + rtb_T6_tmp) * rtb_Divide4);

    /* MultiPortSwitch: '<S11>/Multiport Switch1' incorporates:
     *  Gain: '<S11>/Gain3'
     *  Gain: '<S11>/Gain4'
     *  Product: '<S11>/Divide1'
     *  Product: '<S11>/Divide3'
     *  Sum: '<S11>/Sum1'
     */
    rtb_T6 = rtb_Tcm2 * rtb_Divide4;
    break;

   case 4:
    rtb_T4 = -(rtb_Tcm2 * rtb_Divide4);

    /* MultiPortSwitch: '<S11>/Multiport Switch1' incorporates:
     *  Gain: '<S11>/Gain3'
     *  Gain: '<S11>/Gain6'
     *  Product: '<S11>/Divide1'
     *  Product: '<S11>/Divide3'
     *  Sum: '<S11>/Sum1'
     */
    rtb_T6 = (-rtb_T6 + rtb_T6_tmp) * rtb_Divide4;
    break;

   case 5:
    rtb_T4 = rtb_Tcm2 * rtb_Divide4;

    /* MultiPortSwitch: '<S11>/Multiport Switch1' incorporates:
     *  Gain: '<S11>/Gain5'
     *  Product: '<S11>/Divide1'
     *  Product: '<S11>/Divide2'
     *  Sum: '<S11>/Sum'
     */
    rtb_T6 = -((rtb_T6 + rtb_T6_tmp) * rtb_Divide4);
    break;

   default:
    rtb_T4 = -((rtb_T6 + rtb_T6_tmp) * rtb_Divide4);

    /* MultiPortSwitch: '<S11>/Multiport Switch1' incorporates:
     *  Gain: '<S11>/Gain3'
     *  Gain: '<S11>/Gain4'
     *  Gain: '<S11>/Gain5'
     *  Product: '<S11>/Divide2'
     *  Product: '<S11>/Divide3'
     *  Sum: '<S11>/Sum'
     *  Sum: '<S11>/Sum1'
     */
    rtb_T6 = -((-rtb_T6 + rtb_T6_tmp) * rtb_Divide4);
    break;
  }

  /* End of MultiPortSwitch: '<S11>/Multiport Switch' */

  /* Product: '<S11>/Divide4' incorporates:
   *  Sum: '<S11>/Subtract'
   */
  rtb_Divide4 = 1.0 / (rtb_T4 + rtb_T6);

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Product: '<S11>/Divide5'
   *  Product: '<S11>/Divide6'
   *  Sum: '<S11>/Add'
   *  Switch: '<S11>/Switch1'
   */
  if ((rtb_T4 - 1.0) + rtb_T6 > 0.0) {
    rtb_Tcm2 = rtb_T4 * rtb_Divide4;
    rtb_T6 *= rtb_Divide4;
  } else {
    rtb_Tcm2 = rtb_T4;
  }

  /* End of Switch: '<S11>/Switch' */

  /* Gain: '<S12>/Gain' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Sum: '<S12>/Add'
   */
  rtb_Divide4 = ((1.0 - rtb_Tcm2) - rtb_T6) * 0.25;

  /* Sum: '<S12>/Add1' incorporates:
   *  Gain: '<S12>/Gain1'
   */
  rtb_T4 = 0.5 * rtb_Tcm2 + rtb_Divide4;

  /* Sum: '<S12>/Add2' incorporates:
   *  Gain: '<S12>/Gain2'
   */
  rtb_T6_tmp = 0.5 * rtb_T6 + rtb_T4;

  /* MultiPortSwitch: '<S12>/Tcm1 ' incorporates:
   *  Gain: '<S12>/Gain2'
   *  Sum: '<S12>/Add2'
   */
  switch ((int32_T)rtb_A) {
   case 1:
    rtb_T6 = rtb_T4;

    /* MultiPortSwitch: '<S12>/Tcm2' */
    rtb_Tcm2 = rtb_Divide4;

    /* MultiPortSwitch: '<S12>/Tcm3' incorporates:
     *  Sum: '<S12>/Add2'
     */
    rtb_Divide4 = rtb_T6_tmp;
    break;

   case 2:
    rtb_T6 = rtb_Divide4;

    /* MultiPortSwitch: '<S12>/Tcm2' incorporates:
     *  Sum: '<S12>/Add2'
     */
    rtb_Tcm2 = rtb_T6_tmp;

    /* MultiPortSwitch: '<S12>/Tcm3' */
    rtb_Divide4 = rtb_T4;
    break;

   case 3:
    rtb_T6 = rtb_Divide4;

    /* MultiPortSwitch: '<S12>/Tcm2' */
    rtb_Tcm2 = rtb_T4;

    /* MultiPortSwitch: '<S12>/Tcm3' incorporates:
     *  Sum: '<S12>/Add2'
     */
    rtb_Divide4 = rtb_T6_tmp;
    break;

   case 4:
    rtb_T6 = 0.5 * rtb_T6 + rtb_T4;

    /* MultiPortSwitch: '<S12>/Tcm2' incorporates:
     *  Gain: '<S12>/Gain2'
     *  Sum: '<S12>/Add2'
     */
    rtb_Tcm2 = rtb_T4;
    break;

   case 5:
    rtb_T6 = 0.5 * rtb_T6 + rtb_T4;

    /* MultiPortSwitch: '<S12>/Tcm2' incorporates:
     *  Gain: '<S12>/Gain2'
     *  Sum: '<S12>/Add2'
     */
    rtb_Tcm2 = rtb_Divide4;

    /* MultiPortSwitch: '<S12>/Tcm3' */
    rtb_Divide4 = rtb_T4;
    break;

   default:
    rtb_T6 = rtb_T4;

    /* MultiPortSwitch: '<S12>/Tcm2' incorporates:
     *  Sum: '<S12>/Add2'
     */
    rtb_Tcm2 = rtb_T6_tmp;
    break;
  }

  /* End of MultiPortSwitch: '<S12>/Tcm1 ' */

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtb_Sum_n;

  /* Outport: '<Root>/DutyOut' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Gain: '<S4>/Gain'
   *  Sum: '<S4>/Add'
   *  Sum: '<S4>/Add1'
   *  Sum: '<S4>/Add2'
   */
  rtY.DutyOut[0] = 1.0 - 2.0 * rtb_T6;
  rtY.DutyOut[1] = 1.0 - 2.0 * rtb_Tcm2;
  rtY.DutyOut[2] = 1.0 - 2.0 * rtb_Divide4;

  /* End of Outputs for SubSystem: '<Root>/VF' */
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
