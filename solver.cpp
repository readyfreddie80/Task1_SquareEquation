//
// Created by ready on 14.09.2019.
//

#include "solver.h"

#include <assert.h>
#include <cmath>
#include <math.h>
#include <stdio.h>


void swapDouble (double *x, double *y){
    double z = *x;
    *x = *y;
    *y = z;
}

/*!
    \brief Solve linear equation

    Find roots for linear equation ax + b = 0

    \param[in] a b coefficient
    \param[in] b c coefficient
    \param[out] x pointer to root location
    \return number of roots or #SSE_INF_ROOTS
 */
int SolveLinearEquation (const double a, const double b,
                         double *const x) {
    assert (std::isfinite (a));
    assert (std::isfinite (b));

    assert (x != NULL);

    if (a == 0) {
        if (b == 0) {
            return SSE_INF_ROOTS;
        }
        else { /* if (b != 0) */
            return 0;
        }
    }
    else { /* if (a != 0) */
        *x = -b/a;
        return 1;
    }
}

/*!
     \brief Solve square equation

     Finds the roots x1<= x2 of the equation ax^2+bx+c=0

     \param[in] a a coefficient
     \param[in] b b coefficient
     \param[in] c c coefficient
     \param[out] x1 pointer to first root location
     \param[out] x2 pointer to second root location

     \return number of roots or #SSE_INF_ROOTS
 */
 int SolveSquareEquation (const double a, const double b, const double c,
                         double *const x1, double *const x2) {
    assert (std::isfinite(a));
    assert (std::isfinite(b));
    assert (std::isfinite(c));

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (a == 0) {
        return SolveLinearEquation(b, c, x1);
    }

    if (c == 0) {
        *x1 = 0;

        if (b == 0) {
            return 1;
        }

        SolveLinearEquation(a, b, x2);

        if (*x1 > *x2) {
            swapDouble(x1, x2);
        }
        return 2;
    }

    double D = b * b - 4 * a * c;

    if (D < 0) {
        return 0;
    }

    double denominator = 2 * a;

    if (D == 0) {
        *x1 = -b / denominator;
        return 1;
    }
    else { /* if (D != 0) */
        double sqrtD = sqrt(D);
        *x1 = (-b - sqrtD) / denominator;
        *x2 = (-b + sqrtD) / denominator;
        return 2;
    }
}

/*!
     \brief Unit test function

     Compares expected values with the result of SolveSquareEquation() that solves square equation

     \param[in] a a coefficient
     \param[in] b b coefficient
     \param[in] c c coefficient
     \param[in] expetedNRoots expected number of roots
     \param[in] expectedX1 expected first root value
     \param[in] expectedX2 expected second root value
 */
int SolveSquareEquationUnitTest (const double a, const double b, const double c, const int expetedNRoots,
                                 double expectedX1 = NAN, double expectedX2 = NAN) {


    if (expetedNRoots == 2 && expectedX1 > expectedX2) {
        swapDouble(&expectedX1, &expectedX2);
    }

    double x1 = NAN, x2 = NAN;

    int nRoots = SolveSquareEquation (a, b, c, &x1, &x2);


    bool isFailure = false;

    if (nRoots != expetedNRoots) {
        isFailure = true;
    }
    else if (nRoots != SSE_INF_ROOTS) {
        if (nRoots > 0 && x1 != expectedX1) {
            isFailure = true;
        }
        else if (nRoots > 1 && x2 != expectedX2) {
            isFailure = true;
        }
    }


    if (isFailure) {
        printf("# SolveSquareEquationUnitTest(): ERROR\n"
               "# If a = %lf, b = %lf, c = %lf\n\n", a, b, c);

        printf("# Expected value: nRoots = %d\n"
               "# Actual value:   nRoota = %d\n\n",
               expetedNRoots, nRoots);

        printf("# Expected value: x1 = %lf\n"
               "# Actual value:   x1 = %lf\n\n",
               x1, expectedX1);

        printf("# Expected value: x2 = %lf\n"
               "# Actual value:   x2 = %lf\n\n",
               x2, expectedX2);

        abort();
    }

    return  0;
}

void SSEUnitTests() {

    SolveSquareEquationUnitTest(0, 0, 0, SSE_INF_ROOTS);

    SolveSquareEquationUnitTest(1, 0, 0, 1, 0);

    SolveSquareEquationUnitTest(0, 1, 0, 1, 0);

    SolveSquareEquationUnitTest(0, 0, 1, 0);

    SolveSquareEquationUnitTest(0, 1, 1, 1, -1);

    SolveSquareEquationUnitTest(1, 0, 1, 0);

    SolveSquareEquationUnitTest(1, 0, -1, 2, -1, 1);

    SolveSquareEquationUnitTest(1, 1, 0, 2, -1, 0);

    SolveSquareEquationUnitTest(1, 2, -3, 2, -3, 1);

    SolveSquareEquationUnitTest(4, -2, 0.25, 1, 0.25);

    SolveSquareEquationUnitTest(3, 4, 5, 0, 0);
}