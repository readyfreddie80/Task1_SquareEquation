#include <assert.h>
#include <iostream>
#include <math.h>
#include <string.h>


#include "programio.h"
#include "solver.h"
#include "templates.h"

/*!
    \brief Main function
    Gets the source data and prints the result.
 */
int main () {
    /// Number of input variables
    const size_t M_INPUT_VAR_NUMBER = 3;

    const char TITLE_OF_THE_PROGRAM[]       = "Square equation solver";
    const char AUTHOR_OF_THE_PROGRAM[]      = "Sklyarova E V";
    const char DATE_OF_THE_PROGRAM[]        = "2020";
    const char DESCRIPTION_OF_THE_PROGRAM[] = "This program finds and prints the roots of the equation ax^2 + bx + c = 0, "
                                              "where a, b, c are real numbers";

    const ProgramInfo program = {
            TITLE_OF_THE_PROGRAM,
            AUTHOR_OF_THE_PROGRAM,
            DATE_OF_THE_PROGRAM,
            DESCRIPTION_OF_THE_PROGRAM
    };

    PrintProgramInfo (&program);

    SSEUnitTests ();

    const char *coefNames[M_INPUT_VAR_NUMBER] = {"a", "b", "c"};
    T a = NAN, b = NAN, c = NAN;
    T *coefs[M_INPUT_VAR_NUMBER] = {&a, &b, &c};

    for (int i = 0; i < M_INPUT_VAR_NUMBER; i++) {
        *coefs[i] = TEMPLATE (ReadValue, T)(coefNames[i]);

        printf ("# Entered value: %s = %Lf\n",
                coefNames[i], (LDBL)*coefs[i]);
    }

    T x1 = NAN, x2 = NAN;

    SSE_ROOTS_NUMBER rootsNumber = SolveSquareEquation (a, b, c, &x1, &x2);

    printf ("# If a = %Lf, b = %Lf, c=%Lf\n", (LDBL)a, (LDBL)b, (LDBL)c);

    switch (rootsNumber) {
        case NO_ROOTS:
            printf ("# Equation ax^2 + bx + c = 0 has no roots\n");
            break;
        case ONE_ROOT:
            printf ("# Equation ax^2 + bx + c = 0 has one root: x = %Lf\n", (LDBL)x1);
            break;
        case TWO_ROOTS:
            printf ("# Equation ax^2 + bx + c = 0 has two roots: x1 = %Lf, x2 = %Lf\n", (LDBL)x1, (LDBL)x2);
            break;
        case INF_ROOTS:
            printf ("# Equation ax^2 + bx + c = 0 has infinite number of roots\n");
            break;
        default:
            printf ("# main(): ERROR: rootsNumber = %d\n", rootsNumber);
            break;
    }

    return 0;
}




