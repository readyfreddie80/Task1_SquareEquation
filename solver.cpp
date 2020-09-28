//
// Created by ready on 25.09.2020.
//

#include "solver.h"

#include <assert.h>
#include <cmath>
#include <math.h>
#include <stdio.h>

#include "templates.h"
#include "templatefuncs.cpp"


SSE_ROOTS_NUMBER SolveLinearEquation (
        T a,
        T b,
        T *x) {
    assert (std::isfinite (a));
    assert (std::isfinite (b));

    assert (x != nullptr);

    if (a == 0) {
        if (b == 0) {
            return INF_ROOTS;
        }
        else { /* if (b != 0) */
            return NO_ROOTS;
        }
    }
    else { /* if (a != 0) */
        *x = -b / a;
        return ONE_ROOT;
    }
}


SSE_ROOTS_NUMBER SolveSquareEquation (
        T a,
        T b,
        T c,
        T *x1,
        T *x2) {
    assert (std::isfinite(a));
    assert (std::isfinite(b));
    assert (std::isfinite(c));

    assert (x1 != nullptr);
    assert (x2 != nullptr);
    assert (x1 != x2);

    if (a == 0) {
        return SolveLinearEquation (b, c, x1);
    }

    if (c == 0) {
        *x1 = 0;

        if (b == 0) {
            return ONE_ROOT;
        }

        SolveLinearEquation (a, b, x2);

        if (*x1 > *x2) {
            TEMPLATE(swap, T) (x1, x2);
        }
        return TWO_ROOTS;
    }

    T D = b * b - 4 * a * c;

    if (D < 0) {
        return NO_ROOTS;
    }

    T denominator = 2 * a;

    if (D == 0) {
        *x1 = -b / denominator;
        return ONE_ROOT;
    }
    else { /* if (D != 0) */
        T sqrtD = sqrt(D);
        *x1 = (-b - sqrtD) / denominator;
        *x2 = (-b + sqrtD) / denominator;
        return TWO_ROOTS;
    }
}


/*!
     \brief Unit test function

     Compares expected values with the result of SolveSquareEquation() that solves square equation

     \param[in] a             a coefficient
     \param[in] b             b coefficient
     \param[in] c             c coefficient
     \param[in] expetedNRoots expected number of roots
     \param[in] expectedX1    expected first root value
     \param[in] expectedX2    expected second root value
 */
int SolveSquareEquationUnitTest (
        T      a,
        T      b,
        T      c,
        int    expetedNRoots,
        T      expectedX1 = NAN,
        T      expectedX2 = NAN) {


    if (expetedNRoots == 2 && expectedX1 > expectedX2) {
        TEMPLATE(swap, T) (&expectedX1, &expectedX2);
    }

    T x1 = NAN, x2 = NAN;

    SSE_ROOTS_NUMBER nRoots = SolveSquareEquation (a, b, c, &x1, &x2);


    bool isFailure = false;

    if (nRoots != expetedNRoots) {
        isFailure = true;
    }
    else if (nRoots != INF_ROOTS) {
        if (nRoots > 0 && x1 != expectedX1) {
            isFailure = true;
        }
        else if (nRoots > 1 && x2 != expectedX2) {
            isFailure = true;
        }
    }


    if (isFailure) {
        printf ("# SolveSquareEquationUnitTest(): ERROR\n"
                "# If a = %Lf, b = %Lf, c = %Lf\n\n", (LDBL)a, (LDBL)b, (LDBL)c);

        printf ("# Expected value: nRoots = %d\n"
                "# Actual value:   nRoota = %d\n\n",
                expetedNRoots, nRoots);

        printf ("# Expected value: x1 = %Lf\n"
                "# Actual value:   x1 = %Lf\n\n",
                (LDBL)x1, (LDBL)expectedX1);

        printf ("# Expected value: x2 = %Lf\n"
                "# Actual value:   x2 = %Lf\n\n",
                (LDBL)x2, (LDBL)expectedX2);

        abort ();
    }

    return  0;
}


void SSEUnitTests() {

    SolveSquareEquationUnitTest (0, 0, 0, INF_ROOTS);

    SolveSquareEquationUnitTest (1, 0, 0, 1, 0);

    SolveSquareEquationUnitTest (0, 1, 0, 1, 0);

    SolveSquareEquationUnitTest (0, 0, 1, 0);

    SolveSquareEquationUnitTest (0, 1, 1, 1, -1);

    SolveSquareEquationUnitTest (1, 0, 1, 0);

    SolveSquareEquationUnitTest (1, 0, -1, 2, -1, 1);

    SolveSquareEquationUnitTest (1, 1, 0, 2, -1, 0);

    SolveSquareEquationUnitTest (1, 2, -3, 2, -3, 1);

    SolveSquareEquationUnitTest (4, -2, 0.25, 1, 0.25);

    SolveSquareEquationUnitTest (3, 4, 5, 0, 0);
}