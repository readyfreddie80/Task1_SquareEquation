//
// Created by ready on 25.09.2020.
//

#ifndef TASK1_SQUAREEQUATION_SOLVESQUAREEQUATION_H
#define TASK1_SQUAREEQUATION_SOLVESQUAREEQUATION_H


/*! Type of roots
 * typedef long double LDBL;
 * typedef double DBL;
 * typedef float FLT;
 * typedef int INT;
 * typedef char CHAR;
 */
#define T LDBL

#include "templatefuncs.h"

enum SSE_ROOTS_NUMBER {
    INF_ROOTS = -2,
    NO_ROOTS  = 0,
    ONE_ROOT  = 1,
    TWO_ROOTS = 2
};

/*!
    \brief Solves linear equation

    Find roots for linear equation ax + b = 0

    \param[in]  a a coefficient
    \param[in]  b b coefficient
    \param[out] x pointer to the memory area to write the root to

    \return number of roots (SSE_ROOTS_NUMER)
 */
SSE_ROOTS_NUMBER SolveLinearEquation (
        T a,
        T b,
        T *x);



/*!
     \brief Solves square equation

     Finds the roots x1<= x2 of the equation ax^2+bx+c=0

     \param[in]  a  a coefficient
     \param[in]  b  b coefficient
     \param[in]  c  c coefficient
     \param[out] x1 pointer to the memory area to write the first root to
     \param[out] x2 pointer to the memory area to write the first root to

     \return number of roots (SSE_ROOTS_NUMER)
 */
SSE_ROOTS_NUMBER SolveSquareEquation (
        T a,
        T b,
        T c,
        T *x1,
        T *x2);


/// Runs a set of unit tests
void SSEUnitTests ();

#endif //TASK1_SQUAREEQUATION_SOLVESQUAREEQUATION_H



