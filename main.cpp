#include <assert.h>
#include <iostream>
#include <math.h>
#include <string.h>


#include "PrintProgramTitle.h"
#include "SolveSquareEquation.h"

#define M_INPUT_VAR_NUMBER 3

int main () {

    const char title[] = "Square equation solver";
    const char author[] = "Sklyarova E V";
    const char date[] = "2019";
    const char description[] = "Finds and prints roots of the equation ax^2 + bx + c = 0, "
                               "where a, b, c - real numbers";

    PrintProgramTitle(title, author, date, description);

    char *inputVariablesNames[M_INPUT_VAR_NUMBER] = {"a", "b", "c"};
    double a = NAN, b = NAN, c = NAN;
    double *inputVariables[M_INPUT_VAR_NUMBER] = {&a, &b, &c};

    for (int i = 0; i < M_INPUT_VAR_NUMBER; i++) {
        ScanVariableDouble(inputVariables[i],
                           inputVariablesNames[i]);


        printf ("# Entered value: %s = %lf\n",
                inputVariablesNames[i],  *inputVariables[i]);
    }

    double x1 = NAN, x2 = NAN;

    int rootsNumber = SolveSquareEquation(a, b, c, &x1, &x2);

    printf("# If a = %lf, b = %lf, c=%lf\n", a, b, c);
    switch (rootsNumber) {
        case 0:
            printf("# Equation ax^2 + bx + c = 0 has no roots\n");
            break;
        case 1:
            printf("# Equation ax^2 + bx + c = 0 has one root: x = %lf\n", x1);
            break;
        case 2:
            printf("# Equation ax^2 + bx + c = 0 has two roots: x1 = %lf\n, x2 = %lf\n", x1, x2);
            break;
        case INF:
            printf("# Equation ax^2 + bx + c = 0 has infinite number of roots\n");
            break;
        default:
            printf("main(): ERROR: rootsNumber = %d\n", rootsNumber);
            break;
    }

    return 0;
}




