//
// Created by ready on 11.09.2019.
//

#ifndef TASK1_SQUAREEQUATION_PRINTPROGRAMTITLE_H
#define TASK1_SQUAREEQUATION_PRINTPROGRAMTITLE_H

#define POSITIVE_ANSWER "y"


int PrintProgramTitle (const char *const title, const char *const author,
                       const char *const date, const char *const description);


int ScanVariableDouble (double *const variable,
                        const char *const variableName);


bool ScanAndCheckVariableDouble (double * inputVariablePtr,
                                 const char * inputVariablesName);


#endif //TASK1_SQUAREEQUATION_PRINTPROGRAMTITLE_H


