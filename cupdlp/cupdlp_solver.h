//
// Created by chuwen on 23-11-27.
//

#ifndef CUPDLP_CUPDLP_SOLVER_H
#define CUPDLP_CUPDLP_SOLVER_H

// #include "cupdlp_linalg.h"
#include "cupdlp_defs.h"
// #include "cupdlp_scaling.h"
// #include "cupdlp_utils.h"
#include "glbopts.h"

#define CUPDLP_CHECK_TIMEOUT(pdhg)                               \
  {                                                              \
    PDHG_Compute_SolvingTime(pdhg);                              \
    if (pdhg->timers->dSolvingTime > pdhg->settings->dTimeLim) { \
      retcode = RETCODE_FAILED;                                  \
      goto exit_cleanup;                                         \
    }                                                            \
  }

void PDHG_Compute_Primal_Feasibility(CUPDLPwork *work, cupdlp_float *primalResidual,
                                     const cupdlp_float *ax, const cupdlp_float *x,
                                     cupdlp_float *dPrimalFeasibility,
                                     cupdlp_float *dPrimalObj);

void PDHG_Compute_Dual_Feasibility(CUPDLPwork *work, cupdlp_float *dualResidual,
                                   const cupdlp_float *aty, const cupdlp_float *x,
                                   const cupdlp_float *y, cupdlp_float *dDualFeasibility,
                                   cupdlp_float *dDualObj, cupdlp_float *dComplementarity);

void PDHG_Compute_Residuals(CUPDLPwork *work);

void PDHG_Init_Variables(CUPDLPwork *work);

void PDHG_Check_Data(CUPDLPwork *work);

cupdlp_bool PDHG_Check_Termination(CUPDLPwork *pdhg, cupdlp_int bool_print);

cupdlp_bool PDHG_Check_Termination_Average(CUPDLPwork *pdhg, cupdlp_int bool_print);

void PDHG_Print_Header(CUPDLPwork *pdhg);

void PDHG_Print_Iter(CUPDLPwork *pdhg);

void PDHG_Print_Iter_Average(CUPDLPwork *pdhg);

void PDHG_Compute_SolvingTime(CUPDLPwork *pdhg);

cupdlp_retcode PDHG_Solve(CUPDLPwork *pdhg);

void PDHG_PostSolve(CUPDLPwork *pdhg, cupdlp_int nCols_origin,
                    cupdlp_int *constraint_new_idx, cupdlp_float *x_origin,
                    cupdlp_float *y_origin);

cupdlp_retcode LP_SolvePDHG(CUPDLPwork *pdhg, cupdlp_bool *ifChangeIntParam,
                            cupdlp_int *intParam,
                            cupdlp_bool *ifChangeFloatParam,
                            cupdlp_float *floatParam, char *fp,
                            cupdlp_float *x_origin, cupdlp_int nCols_origin,
                            cupdlp_float *y_origin, cupdlp_bool ifSaveSol,
                            cupdlp_int *constraint_new_idx);

#endif  // CUPDLP_CUPDLP_SOLVER_H
