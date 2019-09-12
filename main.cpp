#include <assert.h>
#include <iostream>
#include <math.h>
#include <string.h>


#include "PrintProgramTitle.h"

#define M_INPUT_VAR_NUMBER 3

int main () {

    const char title[] = "Square equation solver";
    const char author[] = "Sklyarova E V";
    const char date[] = "2019";
    const char description[] = "Finds and prints solutions of the equation ax^2 + bx + c = 0, "
                               "where a, b, c - real numbers";

    PrintProgramTitle(title, author, date, description);

    char *inputVariablesNames[M_INPUT_VAR_NUMBER] = {"a", "b", "c"};
    double a = NAN, b = NAN, c = NAN;
    double *inputVariables[M_INPUT_VAR_NUMBER] = {&a, &b, &c};

    for (int i = 0; i < M_INPUT_VAR_NUMBER;) {
        if(ScanAndCheckVariableDouble(inputVariables[i],
                                      inputVariablesNames[i]))
            i++;
    }

    double x1 = NAN, x2 = NAN;

    int rootsNumber = SolveSquareEquation(a, b, c, &x1, &x2);

    return 0;
}

