//
// Created by ready on 12.09.2019.
//

#ifndef TASK1_SQUAREEQUATION_SOLVESQUAREEQUATION_H
#define TASK1_SQUAREEQUATION_SOLVESQUAREEQUATION_H

#include <assert.h>
#include <cmath>
#include <math.h>
#include <stdio.h>

#define INF -1


void swapDouble (double *x, double *y){
    double z = *x;
    *x = *y;
    *y = z;
}

// Finds the solution of the equation ax + b = 0
int SolveLinearEquation (const double a, const double b, double *const x) {
    assert (std::isfinite (a));
    assert (std::isfinite (b));

    assert (x != NULL);

    if (a == 0) {
        if (b == 0) {
            return INF;
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

// Finds the solution of the equation ax^2 + bx + c = 0
int SolveSquareEquation (const double a, const double b, const double c,
                         double *const x1, double *const x2) {
    assert (std::isfinite (a));
    assert (std::isfinite (b));
    assert (std::isfinite (c));

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

        if(*x1 > *x2) {
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
        double sqrtD = sqrt (D);
        *x1 = (-b - sqrtD) / denominator;
        *x2 = (-b + sqrtD) / denominator;
        return 2;
    }
}


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
    else if (nRoots != INF) {
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

void UnitTests () {

    SolveSquareEquationUnitTest(0, 0, 0, INF);

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

#endif //TASK1_SQUAREEQUATION_SOLVESQUAREEQUATION_H



