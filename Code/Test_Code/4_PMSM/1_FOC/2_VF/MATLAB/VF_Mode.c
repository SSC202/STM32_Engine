/*
 * File: VF_Mode.c
 *
 * Code generated for Simulink model 'VF_Mode'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Aug  5 17:10:43 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "VF_Mode.h"
#include "rtwtypes.h"
#include <math.h>
#include <float.h>

/* Exported block signals */
real32_T electric_theta;               /* '<S4>/Mod' */

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;
extern real32_T rt_modf(real32_T u0, real32_T u1);
real32_T rt_modf(real32_T u0, real32_T u1)
{
  real32_T y;
  y = u0;
  if (u1 == 0.0F) {
    if (u0 == 0.0F) {
      y = u1;
    }
  } else if (u0 == 0.0F) {
    y = 0.0F / u1;
  } else {
    boolean_T yEq;
    y = fmodf(u0, u1);
    yEq = (y == 0.0F);
    if ((!yEq) && (u1 > floorf(u1))) {
      real32_T q;
      q = fabsf(u0 / u1);
      yEq = (fabsf(q - floorf(q + 0.5F)) <= FLT_EPSILON * q);
    }

    if (yEq) {
      y = 0.0F;
    } else if ((u0 < 0.0F) != (u1 < 0.0F)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void VF_Mode_step(void)
{
  real_T rtb_Add1_m;
  real_T rtb_Add2;
  real_T rtb_Divide1;
  real_T rtb_Divide_n;
  real_T rtb_Gain1_l;
  real_T rtb_T4Switch;
  int32_T rtb_Add;
  real32_T rtb_Sum_g;
  real32_T rtb_TrigonometricFunction;
  real32_T rtb_TrigonometricFunction1;

  /* Outputs for Atomic SubSystem: '<Root>/VF_Mode' */
  /* Sum: '<S9>/Sum' incorporates:
   *  Gain: '<S9>/Gain'
   *  Inport: '<Root>/Freq'
   *  UnitDelay: '<S9>/Unit Delay'
   */
  rtb_Sum_g = (real32_T)(0.00062831853071795862 * rtU.Freq) +
    rtDW.UnitDelay_DSTATE;

  /* If: '<S10>/If' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant1'
   *  RelationalOperator: '<S10>/Relational Operator'
   *  RelationalOperator: '<S10>/Relational Operator1'
   */
  if (rtb_Sum_g > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S10>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    /* Sum: '<S11>/Sum' incorporates:
     *  Constant: '<S11>/Constant'
     */
    rtb_Sum_g -= 6.28318548F;

    /* End of Outputs for SubSystem: '<S10>/If Action Subsystem1' */
  } else if (rtb_Sum_g < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S10>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    /* Sum: '<S13>/Sum' incorporates:
     *  Constant: '<S13>/Constant'
     */
    rtb_Sum_g += 6.28318548F;

    /* End of Outputs for SubSystem: '<S10>/If Action Subsystem3' */
  }

  /* End of If: '<S10>/If' */

  /* Math: '<S4>/Mod' incorporates:
   *  Constant: '<S4>/Constant'
   *  Sum: '<S4>/Add1'
   */
  electric_theta = rt_modf(rtb_Sum_g, 6.28318548F);

  /* Trigonometry: '<S2>/Trigonometric Function' */
  rtb_TrigonometricFunction = sinf(electric_theta);

  /* Trigonometry: '<S2>/Trigonometric Function1' */
  rtb_TrigonometricFunction1 = cosf(electric_theta);

  /* Sum: '<S2>/Add1' incorporates:
   *  Inport: '<Root>/u_d'
   *  Inport: '<Root>/u_q'
   *  Product: '<S2>/Product1'
   *  Product: '<S2>/Product2'
   */
  rtb_Add1_m = rtU.u_d * rtb_TrigonometricFunction + rtU.u_q *
    rtb_TrigonometricFunction1;

  /* Gain: '<S6>/Gain' incorporates:
   *  Gain: '<S8>/Gain1'
   *  Inport: '<Root>/u_d'
   *  Inport: '<Root>/u_q'
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product3'
   *  Sum: '<S2>/Add'
   */
  rtb_Gain1_l = (rtU.u_d * rtb_TrigonometricFunction1 - rtU.u_q *
                 rtb_TrigonometricFunction) * 0.8660254037844386;

  /* Gain: '<S6>/Gain1' incorporates:
   *  Gain: '<S8>/Gain2'
   */
  rtb_Divide1 = 0.5 * rtb_Add1_m;

  /* Sum: '<S6>/Add' incorporates:
   *  Gain: '<S6>/Gain'
   *  Gain: '<S6>/Gain1'
   *  Gain: '<S6>/Gain2'
   *  Gain: '<S6>/Gain3'
   *  Sum: '<S6>/Add1'
   *  Sum: '<S6>/Add2'
   *  Switch: '<S6>/ A Switch'
   *  Switch: '<S6>/ B Switch'
   *  Switch: '<S6>/ C Switch'
   */
  rtb_Add = (((rtb_Gain1_l - rtb_Divide1 > 0.0) << 1) + (rtb_Add1_m > 0.0)) +
    (((0.0 - rtb_Gain1_l) - rtb_Divide1 > 0.0) << 2);

  /* Gain: '<S5>/Gain1' incorporates:
   *  Inport: '<Root>/T_pwm'
   */
  rtb_Divide_n = 0.25 * rtU.T_pwm;

  /* Product: '<S8>/Divide' incorporates:
   *  Gain: '<S8>/Gain'
   *  Inport: '<Root>/T_pwm'
   *  Inport: '<Root>/u_dc'
   */
  rtb_Add2 = 1.7320508075688772 * rtU.T_pwm / rtU.u_dc;

  /* MultiPortSwitch: '<S7>/T4 Switch' incorporates:
   *  Gain: '<S7>/Gain'
   *  Gain: '<S7>/Gain1'
   *  Gain: '<S7>/Gain2'
   *  Product: '<S8>/Product'
   *  Product: '<S8>/Product1'
   *  Product: '<S8>/Product2'
   *  Sum: '<S8>/Add'
   *  Sum: '<S8>/Add1'
   */
  switch (rtb_Add) {
   case 1:
    rtb_T4Switch = (rtb_Divide1 - rtb_Gain1_l) * rtb_Add2;

    /* MultiPortSwitch: '<S7>/T6 Switch' incorporates:
     *  Product: '<S8>/Product1'
     *  Product: '<S8>/Product2'
     *  Sum: '<S8>/Add'
     *  Sum: '<S8>/Add1'
     */
    rtb_Add1_m = (rtb_Gain1_l + rtb_Divide1) * rtb_Add2;
    break;

   case 2:
    rtb_T4Switch = (rtb_Gain1_l + rtb_Divide1) * rtb_Add2;

    /* MultiPortSwitch: '<S7>/T6 Switch' incorporates:
     *  Gain: '<S7>/Gain'
     *  Product: '<S8>/Product'
     *  Product: '<S8>/Product1'
     *  Sum: '<S8>/Add'
     */
    rtb_Add1_m = -(rtb_Add1_m * rtb_Add2);
    break;

   case 3:
    rtb_T4Switch = -((rtb_Divide1 - rtb_Gain1_l) * rtb_Add2);

    /* MultiPortSwitch: '<S7>/T6 Switch' incorporates:
     *  Gain: '<S7>/Gain2'
     *  Product: '<S8>/Product'
     *  Product: '<S8>/Product2'
     *  Sum: '<S8>/Add1'
     */
    rtb_Add1_m *= rtb_Add2;
    break;

   case 4:
    rtb_T4Switch = -(rtb_Add1_m * rtb_Add2);

    /* MultiPortSwitch: '<S7>/T6 Switch' incorporates:
     *  Gain: '<S7>/Gain'
     *  Product: '<S8>/Product'
     *  Product: '<S8>/Product2'
     *  Sum: '<S8>/Add1'
     */
    rtb_Add1_m = (rtb_Divide1 - rtb_Gain1_l) * rtb_Add2;
    break;

   case 5:
    rtb_T4Switch = rtb_Add1_m * rtb_Add2;

    /* MultiPortSwitch: '<S7>/T6 Switch' incorporates:
     *  Gain: '<S7>/Gain1'
     *  Product: '<S8>/Product'
     *  Product: '<S8>/Product1'
     *  Sum: '<S8>/Add'
     */
    rtb_Add1_m = -((rtb_Gain1_l + rtb_Divide1) * rtb_Add2);
    break;

   default:
    rtb_T4Switch = -((rtb_Gain1_l + rtb_Divide1) * rtb_Add2);

    /* MultiPortSwitch: '<S7>/T6 Switch' incorporates:
     *  Gain: '<S7>/Gain1'
     *  Gain: '<S7>/Gain2'
     *  Product: '<S8>/Product1'
     *  Product: '<S8>/Product2'
     *  Sum: '<S8>/Add'
     *  Sum: '<S8>/Add1'
     */
    rtb_Add1_m = -((rtb_Divide1 - rtb_Gain1_l) * rtb_Add2);
    break;
  }

  /* End of MultiPortSwitch: '<S7>/T4 Switch' */

  /* Sum: '<S7>/Add1' incorporates:
   *  Sum: '<S7>/Add'
   */
  rtb_Add2 = rtb_T4Switch + rtb_Add1_m;

  /* Product: '<S7>/Divide' incorporates:
   *  Inport: '<Root>/T_pwm'
   *  Sum: '<S7>/Add1'
   */
  rtb_Gain1_l = rtU.T_pwm / rtb_Add2;

  /* Switch: '<S7>/Switch' incorporates:
   *  Inport: '<Root>/T_pwm'
   *  Product: '<S7>/Product'
   *  Product: '<S7>/Product1'
   *  Sum: '<S7>/Add'
   *  Switch: '<S7>/Switch1'
   */
  if (rtb_Add2 - rtU.T_pwm > 0.0) {
    rtb_T4Switch *= rtb_Gain1_l;
    rtb_Add1_m *= rtb_Gain1_l;
  }

  /* Gain: '<S5>/Gain' incorporates:
   *  Switch: '<S7>/Switch'
   */
  rtb_Add2 = 0.25 * rtb_T4Switch;

  /* Gain: '<S5>/Gain2' incorporates:
   *  Switch: '<S7>/Switch1'
   */
  rtb_Divide1 = 0.25 * rtb_Add1_m;

  /* Sum: '<S5>/Add' */
  rtb_T4Switch = (rtb_Divide_n - rtb_Add2) - rtb_Divide1;

  /* Sum: '<S5>/Add1' incorporates:
   *  Sum: '<S5>/Add2'
   */
  rtb_Divide_n += rtb_Add2;
  rtb_Add1_m = rtb_Divide_n - rtb_Divide1;

  /* Sum: '<S5>/Add2' */
  rtb_Add2 = rtb_Divide_n + rtb_Divide1;

  /* MultiPortSwitch: '<S5>/Ta Switch' */
  switch (rtb_Add) {
   case 1:
    rtb_Divide_n = rtb_Add1_m;
    break;

   case 2:
    rtb_Divide_n = rtb_T4Switch;
    break;

   case 3:
    rtb_Divide_n = rtb_T4Switch;
    break;

   case 4:
    rtb_Divide_n = rtb_Add2;
    break;

   case 5:
    rtb_Divide_n = rtb_Add2;
    break;

   default:
    rtb_Divide_n = rtb_Add1_m;
    break;
  }

  /* End of MultiPortSwitch: '<S5>/Ta Switch' */

  /* Product: '<S5>/Divide' incorporates:
   *  Inport: '<Root>/T_pwm'
   */
  rtb_Divide_n /= rtU.T_pwm;

  /* MultiPortSwitch: '<S5>/Tc Switch' */
  switch (rtb_Add) {
   case 1:
    rtb_Divide1 = rtb_Add2;
    break;

   case 2:
    rtb_Divide1 = rtb_Add1_m;
    break;

   case 3:
    rtb_Divide1 = rtb_Add2;
    break;

   case 4:
    rtb_Divide1 = rtb_T4Switch;
    break;

   case 5:
    rtb_Divide1 = rtb_Add1_m;
    break;

   default:
    rtb_Divide1 = rtb_T4Switch;
    break;
  }

  /* End of MultiPortSwitch: '<S5>/Tc Switch' */

  /* Product: '<S5>/Divide1' incorporates:
   *  Inport: '<Root>/T_pwm'
   */
  rtb_Divide1 /= rtU.T_pwm;

  /* MultiPortSwitch: '<S5>/Tb Switch' */
  switch (rtb_Add) {
   case 1:
    rtb_Add2 = rtb_T4Switch;
    break;

   case 2:
    break;

   case 3:
    rtb_Add2 = rtb_Add1_m;
    break;

   case 4:
    rtb_Add2 = rtb_Add1_m;
    break;

   case 5:
    rtb_Add2 = rtb_T4Switch;
    break;
  }

  /* End of MultiPortSwitch: '<S5>/Tb Switch' */

  /* Update for UnitDelay: '<S9>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtb_Sum_g;

  /* Outport: '<Root>/Duty' incorporates:
   *  Constant: '<S3>/Constant'
   *  Gain: '<S3>/Gain'
   *  Inport: '<Root>/T_pwm'
   *  Product: '<S5>/Divide2'
   *  Sum: '<S3>/Sum'
   */
  rtY.Duty[0] = 1.0 - 2.0 * rtb_Divide_n;
  rtY.Duty[1] = 1.0 - rtb_Add2 / rtU.T_pwm * 2.0;
  rtY.Duty[2] = 1.0 - 2.0 * rtb_Divide1;

  /* End of Outputs for SubSystem: '<Root>/VF_Mode' */
}

/* Model initialize function */
void VF_Mode_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
