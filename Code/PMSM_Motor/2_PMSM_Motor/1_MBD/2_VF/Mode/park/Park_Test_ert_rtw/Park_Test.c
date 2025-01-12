/*
 * File: Park_Test.c
 *
 * Code generated for Simulink model 'Park_Test'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Aug  5 16:14:48 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Park_Test.h"
#include "rtwtypes.h"
#include "mw_cmsis.h"
#include <math.h>
#include <float.h>

/* Exported block signals */
real32_T electric_theta;               /* '<S5>/Mod' */
real32_T i_a;                          /* '<S5>/Sin' */
real32_T i_b;                          /* '<S5>/Sin1' */
real32_T i_c;                          /* '<S5>/Sin2' */
real32_T i_alpha;                      /* '<S3>/Add2' */
real32_T i_beta;                       /* '<S3>/Gain2' */
real32_T i_d;                          /* '<S4>/Add' */
real32_T i_q;                          /* '<S4>/Add1' */

/* Block signals and states (default storage) */
DW rtDW;

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
void Park_Test_step(void)
{
  real32_T rtb_Sum;
  real32_T rtb_TrigonometricFunction1_p_tm;
  real32_T rtb_TrigonometricFunction_tmp;

  /* Outputs for Atomic SubSystem: '<Root>/Park_Test' */
  /* Sum: '<S6>/Sum' incorporates:
   *  UnitDelay: '<S6>/Unit Delay'
   */
  rtb_Sum = rtDW.UnitDelay_DSTATE + 0.00125663704F;

  /* If: '<S7>/If' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   *  RelationalOperator: '<S7>/Relational Operator'
   *  RelationalOperator: '<S7>/Relational Operator1'
   *  Sum: '<S6>/Sum'
   *  UnitDelay: '<S6>/Unit Delay'
   */
  if (rtDW.UnitDelay_DSTATE + 0.00125663704F > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S7>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Sum: '<S8>/Sum' incorporates:
     *  Constant: '<S8>/Constant'
     */
    rtb_Sum = (rtDW.UnitDelay_DSTATE + 0.00125663704F) - 6.28318548F;

    /* End of Outputs for SubSystem: '<S7>/If Action Subsystem1' */
  } else if (rtDW.UnitDelay_DSTATE + 0.00125663704F < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S7>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* Sum: '<S10>/Sum' incorporates:
     *  Constant: '<S10>/Constant'
     */
    rtb_Sum = (rtDW.UnitDelay_DSTATE + 0.00125663704F) + 6.28318548F;

    /* End of Outputs for SubSystem: '<S7>/If Action Subsystem3' */
  }

  /* End of If: '<S7>/If' */

  /* Math: '<S5>/Mod' incorporates:
   *  Constant: '<S5>/Constant'
   *  Sum: '<S5>/Add1'
   */
  electric_theta = rt_modf(rtb_Sum, 6.28318548F);

  /* Trigonometry: '<S5>/Sin' incorporates:
   *  Gain: '<S5>/Gain'
   */
  i_a = arm_sin_f32(-electric_theta);

  /* Trigonometry: '<S5>/Sin1' incorporates:
   *  Constant: '<S5>/Constant'
   *  Gain: '<S5>/Gain1'
   *  Math: '<S5>/Mod3'
   *  Sum: '<S5>/Add2'
   */
  i_b = arm_sin_f32(-rt_modf(rtb_Sum - 2.09439516F, 6.28318548F));

  /* Trigonometry: '<S5>/Sin2' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S5>/Constant3'
   *  Gain: '<S5>/Gain2'
   *  Math: '<S5>/Mod4'
   *  Sum: '<S5>/Add3'
   */
  i_c = arm_sin_f32(-rt_modf(rtb_Sum + 2.09439516F, 6.28318548F));

  /* Sum: '<S3>/Add2' incorporates:
   *  Gain: '<S3>/Gain'
   *  Gain: '<S3>/Gain1'
   *  Sum: '<S3>/Add'
   */
  i_alpha = 0.666666687F * i_a - (i_b + i_c) * 0.333333343F;

  /* Trigonometry: '<S4>/Trigonometric Function1' incorporates:
   *  Trigonometry: '<S2>/Trigonometric Function1'
   */
  rtb_TrigonometricFunction1_p_tm = cosf(electric_theta);

  /* Gain: '<S3>/Gain2' incorporates:
   *  Sum: '<S3>/Add1'
   */
  i_beta = (i_b - i_c) * 0.577350259F;

  /* Trigonometry: '<S4>/Trigonometric Function' incorporates:
   *  Trigonometry: '<S2>/Trigonometric Function'
   */
  rtb_TrigonometricFunction_tmp = sinf(electric_theta);

  /* Sum: '<S4>/Add' incorporates:
   *  Product: '<S4>/Product'
   *  Product: '<S4>/Product1'
   *  Trigonometry: '<S4>/Trigonometric Function'
   *  Trigonometry: '<S4>/Trigonometric Function1'
   */
  i_d = i_alpha * rtb_TrigonometricFunction1_p_tm + i_beta *
    rtb_TrigonometricFunction_tmp;

  /* Sum: '<S4>/Add1' incorporates:
   *  Product: '<S4>/Product2'
   *  Product: '<S4>/Product3'
   *  Trigonometry: '<S4>/Trigonometric Function'
   *  Trigonometry: '<S4>/Trigonometric Function1'
   */
  i_q = i_beta * rtb_TrigonometricFunction1_p_tm - i_alpha *
    rtb_TrigonometricFunction_tmp;

  /* Update for UnitDelay: '<S6>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtb_Sum;

  /* Outport: '<Root>/u_alpha' incorporates:
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product3'
   *  Sum: '<S2>/Add'
   */
  rtY.u_alpha = i_d * rtb_TrigonometricFunction1_p_tm - i_q *
    rtb_TrigonometricFunction_tmp;

  /* Outport: '<Root>/u_beta' incorporates:
   *  Product: '<S2>/Product1'
   *  Product: '<S2>/Product2'
   *  Sum: '<S2>/Add1'
   */
  rtY.u_beta = i_d * rtb_TrigonometricFunction_tmp + i_q *
    rtb_TrigonometricFunction1_p_tm;

  /* End of Outputs for SubSystem: '<Root>/Park_Test' */
}

/* Model initialize function */
void Park_Test_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
