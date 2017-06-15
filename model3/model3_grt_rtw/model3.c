/*
 * model3.c
 *
 * Code generation for model "model3".
 *
 * Model version              : 1.17
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Apr 18 18:33:11 2016
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Specified
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "model3.h"
#include "model3_private.h"

/* Block signals (auto storage) */
B_model3_T model3_B;

/* Continuous states */
X_model3_T model3_X;

/* Block states (auto storage) */
DW_model3_T model3_DW;

/* Real-time model */
RT_MODEL_model3_T model3_M_;
RT_MODEL_model3_T *const model3_M = &model3_M_;

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 8;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  model3_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  model3_step();
  model3_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  model3_step();
  model3_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  model3_step();
  model3_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void model3_step(void)
{
  /* local block i/o variables */
  real_T rtb_Fcn;
  real_T rtb_Integrator5;
  if (rtmIsMajorTimeStep(model3_M)) {
    /* set solver stop time */
    if (!(model3_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&model3_M->solverInfo,
                            ((model3_M->Timing.clockTickH0 + 1) *
        model3_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&model3_M->solverInfo, ((model3_M->Timing.clockTick0
        + 1) * model3_M->Timing.stepSize0 + model3_M->Timing.clockTickH0 *
        model3_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(model3_M)) {
    model3_M->Timing.t[0] = rtsiGetT(&model3_M->solverInfo);
  }

  {
    real_T *lastU;
    real_T rtb_ManualSwitch;

    /* Integrator: '<Root>/1//s' */
    model3_B.s = model3_X.s_CSTATE;

    /* Integrator: '<Root>/1//s1' */
    model3_B.s1 = model3_X.s1_CSTATE;

    /* Derivative: '<S1>/Derivative' */
    if ((model3_DW.TimeStampA >= model3_M->Timing.t[0]) && (model3_DW.TimeStampB
         >= model3_M->Timing.t[0])) {
      rtb_ManualSwitch = 0.0;
    } else {
      rtb_ManualSwitch = model3_DW.TimeStampA;
      lastU = &model3_DW.LastUAtTimeA;
      if (model3_DW.TimeStampA < model3_DW.TimeStampB) {
        if (model3_DW.TimeStampB < model3_M->Timing.t[0]) {
          rtb_ManualSwitch = model3_DW.TimeStampB;
          lastU = &model3_DW.LastUAtTimeB;
        }
      } else {
        if (model3_DW.TimeStampA >= model3_M->Timing.t[0]) {
          rtb_ManualSwitch = model3_DW.TimeStampB;
          lastU = &model3_DW.LastUAtTimeB;
        }
      }

      rtb_ManualSwitch = (model3_B.s1 - *lastU) / (model3_M->Timing.t[0] -
        rtb_ManualSwitch);
    }

    /* End of Derivative: '<S1>/Derivative' */

    /* Integrator: '<S1>/Integrator2' */
    model3_B.Integrator2 = model3_X.Integrator2_CSTATE;

    /* Fcn: '<S1>/Fcn' incorporates:
     *  Integrator: '<S1>/Integrator3'
     */
    rtb_Fcn = -model3_B.s1 * cos(model3_X.Integrator3_CSTATE) *
      model3_B.Integrator2 - sin(model3_X.Integrator3_CSTATE) * rtb_ManualSwitch;

    /* Integrator: '<S1>/Integrator4' */
    model3_B.Integrator4 = model3_X.Integrator4_CSTATE;

    /* Integrator: '<S1>/Integrator5' */
    rtb_Integrator5 = model3_X.Integrator5_CSTATE;

    /* Integrator: '<S1>/Integrator6' */
    model3_B.Integrator6 = model3_X.Integrator6_CSTATE;

    /* MATLAB Function: '<Root>/controller' */
    /* MATLAB Function 'controller': '<S2>:1' */
    /* '<S2>:1:3' */
    /* '<S2>:1:4' */
    /* '<S2>:1:5' */
    /* '<S2>:1:6' */
    /* '<S2>:1:7' */
    model3_B.ddu1 = (rtNaN);

    /* ManualSwitch: '<S1>/Manual Switch' incorporates:
     *  Constant: '<S1>/Constant'
     *  Sin: '<S1>/Sine Wave'
     */
    if (model3_P.ManualSwitch_CurrentSetting == 1) {
      rtb_ManualSwitch = sin(model3_P.SineWave_Freq * model3_M->Timing.t[0] +
        model3_P.SineWave_Phase) * model3_P.SineWave_Amp +
        model3_P.SineWave_Bias;
    } else {
      rtb_ManualSwitch = model3_P.Constant_Value;
    }

    /* End of ManualSwitch: '<S1>/Manual Switch' */

    /* Sum: '<S1>/Sum' incorporates:
     *  MATLAB Function: '<Root>/controller'
     */
    model3_B.Sum = (rtNaN) + rtb_ManualSwitch;

    /* MATLAB Function: '<S1>/pvtol diff equation' incorporates:
     *  Integrator: '<S1>/Integrator3'
     */
    /* MATLAB Function 'PVTOL/pvtol diff equation': '<S5>:1' */
    /* '<S5>:1:3' */
    model3_B.ddx = -model3_B.s1 * sin(model3_X.Integrator3_CSTATE);

    /* '<S5>:1:4' */
    model3_B.ddy = model3_B.s1 * cos(model3_X.Integrator3_CSTATE) - 1.0;
    if (rtmIsMajorTimeStep(model3_M)) {
    }
  }

  if (rtmIsMajorTimeStep(model3_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(model3_M->rtwLogInfo, (model3_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(model3_M)) {
    real_T *lastU;

    /* Update for Derivative: '<S1>/Derivative' */
    if (model3_DW.TimeStampA == (rtInf)) {
      model3_DW.TimeStampA = model3_M->Timing.t[0];
      lastU = &model3_DW.LastUAtTimeA;
    } else if (model3_DW.TimeStampB == (rtInf)) {
      model3_DW.TimeStampB = model3_M->Timing.t[0];
      lastU = &model3_DW.LastUAtTimeB;
    } else if (model3_DW.TimeStampA < model3_DW.TimeStampB) {
      model3_DW.TimeStampA = model3_M->Timing.t[0];
      lastU = &model3_DW.LastUAtTimeA;
    } else {
      model3_DW.TimeStampB = model3_M->Timing.t[0];
      lastU = &model3_DW.LastUAtTimeB;
    }

    *lastU = model3_B.s1;

    /* End of Update for Derivative: '<S1>/Derivative' */
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(model3_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(model3_M)!=-1) &&
          !((rtmGetTFinal(model3_M)-(((model3_M->Timing.clockTick1+
               model3_M->Timing.clockTickH1* 4294967296.0)) * 0.001)) >
            (((model3_M->Timing.clockTick1+model3_M->Timing.clockTickH1*
               4294967296.0)) * 0.001) * (DBL_EPSILON))) {
        rtmSetErrorStatus(model3_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&model3_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++model3_M->Timing.clockTick0)) {
      ++model3_M->Timing.clockTickH0;
    }

    model3_M->Timing.t[0] = rtsiGetSolverStopTime(&model3_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      model3_M->Timing.clockTick1++;
      if (!model3_M->Timing.clockTick1) {
        model3_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void model3_derivatives(void)
{
  XDot_model3_T *_rtXdot;
  _rtXdot = ((XDot_model3_T *) model3_M->ModelData.derivs);

  /* Derivatives for Integrator: '<Root>/1//s' */
  _rtXdot->s_CSTATE = model3_B.ddu1;

  /* Derivatives for Integrator: '<Root>/1//s1' */
  _rtXdot->s1_CSTATE = model3_B.s;

  /* Derivatives for Integrator: '<S1>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = model3_B.Integrator2;

  /* Derivatives for Integrator: '<S1>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = model3_B.Sum;

  /* Derivatives for Integrator: '<S1>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = model3_B.ddx;

  /* Derivatives for Integrator: '<S1>/Integrator5' */
  _rtXdot->Integrator5_CSTATE = model3_B.Integrator4;

  /* Derivatives for Integrator: '<S1>/Integrator6' */
  _rtXdot->Integrator6_CSTATE = model3_B.ddy;

  /* Derivatives for Integrator: '<S1>/Integrator7' */
  _rtXdot->Integrator7_CSTATE = model3_B.Integrator6;
}

/* Model initialize function */
void model3_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)model3_M, 0,
                sizeof(RT_MODEL_model3_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&model3_M->solverInfo, &model3_M->Timing.simTimeStep);
    rtsiSetTPtr(&model3_M->solverInfo, &rtmGetTPtr(model3_M));
    rtsiSetStepSizePtr(&model3_M->solverInfo, &model3_M->Timing.stepSize0);
    rtsiSetdXPtr(&model3_M->solverInfo, &model3_M->ModelData.derivs);
    rtsiSetContStatesPtr(&model3_M->solverInfo, (real_T **)
                         &model3_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&model3_M->solverInfo,
      &model3_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&model3_M->solverInfo, (&rtmGetErrorStatus(model3_M)));
    rtsiSetRTModelPtr(&model3_M->solverInfo, model3_M);
  }

  rtsiSetSimTimeStep(&model3_M->solverInfo, MAJOR_TIME_STEP);
  model3_M->ModelData.intgData.y = model3_M->ModelData.odeY;
  model3_M->ModelData.intgData.f[0] = model3_M->ModelData.odeF[0];
  model3_M->ModelData.intgData.f[1] = model3_M->ModelData.odeF[1];
  model3_M->ModelData.intgData.f[2] = model3_M->ModelData.odeF[2];
  model3_M->ModelData.intgData.f[3] = model3_M->ModelData.odeF[3];
  model3_M->ModelData.contStates = ((X_model3_T *) &model3_X);
  rtsiSetSolverData(&model3_M->solverInfo, (void *)&model3_M->ModelData.intgData);
  rtsiSetSolverName(&model3_M->solverInfo,"ode4");
  rtmSetTPtr(model3_M, &model3_M->Timing.tArray[0]);
  rtmSetTFinal(model3_M, 20.0);
  model3_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    model3_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(model3_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(model3_M->rtwLogInfo, (NULL));
    rtliSetLogT(model3_M->rtwLogInfo, "tout");
    rtliSetLogX(model3_M->rtwLogInfo, "");
    rtliSetLogXFinal(model3_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(model3_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(model3_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(model3_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(model3_M->rtwLogInfo, 1);
    rtliSetLogY(model3_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(model3_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(model3_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &model3_B), 0,
                sizeof(B_model3_T));

  /* states (continuous) */
  {
    (void) memset((void *)&model3_X, 0,
                  sizeof(X_model3_T));
  }

  /* states (dwork) */
  (void) memset((void *)&model3_DW, 0,
                sizeof(DW_model3_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(model3_M->rtwLogInfo, 0.0, rtmGetTFinal
    (model3_M), model3_M->Timing.stepSize0, (&rtmGetErrorStatus(model3_M)));

  /* InitializeConditions for Integrator: '<Root>/1//s' */
  model3_X.s_CSTATE = model3_P.s_IC;

  /* InitializeConditions for Integrator: '<Root>/1//s1' */
  model3_X.s1_CSTATE = model3_P.s1_IC;

  /* InitializeConditions for Derivative: '<S1>/Derivative' */
  model3_DW.TimeStampA = (rtInf);
  model3_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Integrator: '<S1>/Integrator3' */
  model3_X.Integrator3_CSTATE = model3_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator2' */
  model3_X.Integrator2_CSTATE = model3_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator4' */
  model3_X.Integrator4_CSTATE = model3_P.Integrator4_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator5' */
  model3_X.Integrator5_CSTATE = model3_P.Integrator5_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator6' */
  model3_X.Integrator6_CSTATE = model3_P.Integrator6_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator7' */
  model3_X.Integrator7_CSTATE = model3_P.Integrator7_IC;
}

/* Model terminate function */
void model3_terminate(void)
{
  /* (no terminate code required) */
}
