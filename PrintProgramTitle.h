//
// Created by ready on 11.09.2019.
//

#ifndef TASK1_SQUAREEQUATION_PRINTPROGRAMTITLE_H
#define TASK1_SQUAREEQUATION_PRINTPROGRAMTITLE_H

#define POSITIVE_ANSWER "y"

#include <assert.h>
#include<stdio.h>


int PrintProgramTitle (const char *const title, const char *const author,
                       const char *const date, const char *const description);


void clearStdin (){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
};


int PrintProgramTitle (const char *const title, const char *const author,
                       const char *const date, const char *const description) {
    assert (title != NULL);
    assert (author != NULL);
    assert (date != NULL);
    assert (description != NULL);

    printf ("# %s\n"
            "# (c) %s, %s\n\n",
            title, author, date);

    printf ("# %s\n", description);

    return 0;
}



int ScanVariableDouble (double *const variable,
                        const char *const variableName) {
    assert (variable != NULL);
    assert (variableName != NULL);

    printf ("# Please, enter %s = ", variableName);
    scanf ("%lf", variable);
    clearStdin();

    return 0;
}


bool ScanAndCheckVariableDouble (double *const inputVariablePtr,
                                 const char *const inputVariablesName) {
    assert (inputVariablePtr != NULL);
    assert (inputVariablesName != NULL);

    ScanVariableDouble(inputVariablePtr,
                       inputVariablesName);


    printf ("# Entered value: %s = %lf\n",
            inputVariablesName, *inputVariablePtr);

    printf ("# Please, enter '%s', if the entered value is correct.\n"
            "# Otherwise, enter any other letter:\n",
            POSITIVE_ANSWER);

    char userAnswer[100] = "NaN";
    scanf ("%s", userAnswer);
    clearStdin();

    return strcmp(userAnswer, POSITIVE_ANSWER) == 0;
}


#endif //TASK1_SQUAREEQUATION_PRINTPROGRAMTITLE_H


