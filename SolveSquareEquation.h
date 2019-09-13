//
// Created by ready on 12.09.2019.
//

#ifndef TASK1_SQUAREEQUATION_SOLVESQUAREEQUATION_H
#define TASK1_SQUAREEQUATION_SOLVESQUAREEQUATION_H

#include <assert.h>
#include <cmath>
#include <math.h>

#define INF -1


// Finds the solution of the equation ax + b = 0
int SolveLinearEquation (const double a, const double b, double *const x) {
    assert (std::isfinite (a));
    assert (std::isfinite (b));

    assert(x != NULL);

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
        SolveLinearEquation(a, b, x1);
        if (*x1 == 0) {
            return 1;
        }
        else { /* if (x1 != 0) */
            *x2 = 0;
            return 2;
        }

    }

    double D = b * b - 4 * a * c;

    if(D < 0) {
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

#endif //TASK1_SQUAREEQUATION_SOLVESQUAREEQUATION_H


