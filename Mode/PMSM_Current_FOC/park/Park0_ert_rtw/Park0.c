/*
 * File: Park0.c
 *
 * Code generated for Simulink model 'Park0'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Oct 25 13:24:28 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Park0.h"

/* Exported block signals */
real32_T ia;                           /* '<S6>/Sin' */
real32_T ib;                           /* '<S6>/Sin1' */
real32_T ic;                           /* '<S6>/Sin2' */
real32_T ialpha;                       /* '<S3>/Add1' */
real32_T ibeta;                        /* '<S3>/Gain2' */
real32_T id;                           /* '<S5>/Subtract' */
real32_T iq;                           /* '<S5>/Subtract1' */

/* Block signals and states (default storage) */
DW rtDW;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;
extern real32_T rt_modf(real32_T u0, real32_T u1);
static void IfActionSubsystem1(real32_T rtu_In1, real32_T *rty_Out1);
static void IfActionSubsystem3(real32_T rtu_In1, real32_T *rty_Out1);

/*
 * Output and update for action system:
 *    '<S7>/If Action Subsystem1'
 *    '<S12>/If Action Subsystem1'
 */
static void IfActionSubsystem1(real32_T rtu_In1, real32_T *rty_Out1)
{
  /* Sum: '<S8>/Sum' incorporates:
   *  Constant: '<S8>/Constant'
   */
  *rty_Out1 = rtu_In1 - 6.28318548F;
}

/*
 * Output and update for action system:
 *    '<S7>/If Action Subsystem3'
 *    '<S12>/If Action Subsystem3'
 */
static void IfActionSubsystem3(real32_T rtu_In1, real32_T *rty_Out1)
{
  /* Sum: '<S10>/Sum' incorporates:
   *  Constant: '<S10>/Constant'
   */
  *rty_Out1 = rtu_In1 + 6.28318548F;
}

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
void Park0_step(void)
{
  real32_T rtb_Merge_g;
  real32_T rtb_SinCos;
  real32_T rtb_Sum;
  real32_T rtb_Sum_p;

  /* Outputs for Atomic SubSystem: '<Root>/Park' */
  /* Sum: '<S4>/Sum' incorporates:
   *  UnitDelay: '<S4>/Unit Delay'
   */
  rtb_Sum = rtDW.UnitDelay_DSTATE + 0.000628318521F;

  /* If: '<S7>/If' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   *  Inport: '<S9>/In1'
   *  RelationalOperator: '<S7>/Relational Operator'
   *  RelationalOperator: '<S7>/Relational Operator1'
   *  Sum: '<S4>/Sum'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  if (rtDW.UnitDelay_DSTATE + 0.000628318521F > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S7>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    IfActionSubsystem1(rtDW.UnitDelay_DSTATE + 0.000628318521F, &rtb_Merge_g);

    /* End of Outputs for SubSystem: '<S7>/If Action Subsystem1' */
  } else if (rtDW.UnitDelay_DSTATE + 0.000628318521F < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S7>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    IfActionSubsystem3(rtDW.UnitDelay_DSTATE + 0.000628318521F, &rtb_Merge_g);

    /* End of Outputs for SubSystem: '<S7>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S7>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    rtb_Merge_g = rtDW.UnitDelay_DSTATE + 0.000628318521F;

    /* End of Outputs for SubSystem: '<S7>/If Action Subsystem2' */
  }

  /* End of If: '<S7>/If' */

  /* If: '<S12>/If' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S12>/Constant1'
   *  Inport: '<S14>/In1'
   *  RelationalOperator: '<S12>/Relational Operator'
   *  RelationalOperator: '<S12>/Relational Operator1'
   *  Sum: '<S11>/Sum'
   *  UnitDelay: '<S11>/Unit Delay'
   */
  if (rtDW.UnitDelay_DSTATE_j + 0.000628318521F > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    IfActionSubsystem1(rtDW.UnitDelay_DSTATE_j + 0.000628318521F, &rtb_Sum);

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem1' */
  } else if (rtDW.UnitDelay_DSTATE_j + 0.000628318521F < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    IfActionSubsystem3(rtDW.UnitDelay_DSTATE_j + 0.000628318521F, &rtb_Sum);

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    rtb_Sum = rtDW.UnitDelay_DSTATE_j + 0.000628318521F;

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem2' */
  }

  /* End of If: '<S12>/If' */

  /* Trigonometry: '<S6>/Sin' incorporates:
   *  Constant: '<S6>/Constant'
   *  Gain: '<S6>/Gain'
   *  Math: '<S6>/Mod'
   *  Sum: '<S6>/Add1'
   */
  ia = arm_sin_f32(-rt_modf(rtb_Sum, 6.28318548F));

  /* Trigonometry: '<S6>/Sin1' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Gain: '<S6>/Gain1'
   *  Math: '<S6>/Mod3'
   *  Sum: '<S6>/Add2'
   */
  ib = arm_sin_f32(-rt_modf(rtb_Sum + -2.09439516F, 6.28318548F));

  /* Trigonometry: '<S6>/Sin2' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant3'
   *  Gain: '<S6>/Gain2'
   *  Math: '<S6>/Mod4'
   *  Sum: '<S6>/Add3'
   */
  ic = arm_sin_f32(-rt_modf(rtb_Sum + 2.09439516F, 6.28318548F));

  /* Sum: '<S3>/Add1' incorporates:
   *  Gain: '<S3>/Gain'
   *  Gain: '<S3>/Gain1'
   *  Sum: '<S3>/Add'
   */
  ialpha = 0.666666687F * ia - (ib + ic) * 0.333333343F;

  /* Trigonometry: '<S1>/SinCos1' */
  rtb_Sum_p = arm_cos_f32(rtb_Merge_g);

  /* Gain: '<S3>/Gain2' incorporates:
   *  Sum: '<S3>/Add2'
   */
  ibeta = (ib - ic) * 0.577350259F;

  /* Trigonometry: '<S1>/SinCos' */
  rtb_SinCos = arm_sin_f32(rtb_Merge_g);

  /* Sum: '<S5>/Subtract' incorporates:
   *  Product: '<S5>/Product'
   *  Product: '<S5>/Product1'
   */
  id = ialpha * rtb_Sum_p + ibeta * rtb_SinCos;

  /* Sum: '<S5>/Subtract1' incorporates:
   *  Product: '<S5>/Product2'
   *  Product: '<S5>/Product3'
   */
  iq = ibeta * rtb_Sum_p - ialpha * rtb_SinCos;

  /* Update for UnitDelay: '<S4>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtb_Merge_g;

  /* Update for UnitDelay: '<S11>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_j = rtb_Sum;

  /* Outport: '<Root>/ualpha' incorporates:
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product1'
   *  Sum: '<S2>/Subtract'
   */
  rtY.ualpha = id * rtb_Sum_p - iq * rtb_SinCos;

  /* Outport: '<Root>/ubeta' incorporates:
   *  Product: '<S2>/Product2'
   *  Product: '<S2>/Product3'
   *  Sum: '<S2>/Subtract1'
   */
  rtY.ubeta = id * rtb_SinCos + iq * rtb_Sum_p;

  /* End of Outputs for SubSystem: '<Root>/Park' */
}

/* Model initialize function */
void Park0_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
