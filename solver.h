//
// Created by ready on 12.09.2019.
//

#ifndef TASK1_SQUAREEQUATION_SOLVESQUAREEQUATION_H
#define TASK1_SQUAREEQUATION_SOLVESQUAREEQUATION_H

#include <assert.h>
#include <cmath>
#include <math.h>
#include <stdio.h>

/// Infinite number of roots
#define SSE_INF_ROOTS -1


int SolveLinearEquation (const double a, const double b,
                         double *const x);


int SolveSquareEquation (const double a, const double b, const double c,
                         double *const x1, double *const x2);


void SSEUnitTests();

#endif //TASK1_SQUAREEQUATION_SOLVESQUAREEQUATION_H



