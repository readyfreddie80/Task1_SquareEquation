//
// Created by freddie on 25.09.20.
//

#include <assert.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <float.h>
#include <cmath>

#include "programio.h"


const size_t RLD_MAX_DIGITS = 3 + LDBL_MANT_DIG - LDBL_MIN_EXP; /**<for ReadLongDouble():
                                                                 * max number of digits long double
                                                                 */


int PrintProgramInfo (const ProgramInfo *info) {
    assert (info->title       != nullptr);
    assert (info->author      != nullptr);
    assert (info->date        != nullptr);
    assert (info->description != nullptr);

    return printf (
            "# %s\n"
            "# (c) %s, %s\n"
            "#\n"
            "# %s\n",
            info->title,
            info->author,
            info->date,
            info->description);
}

long double ReadLongDouble (FILE *stream) {
    char inputBuffer[RLD_MAX_DIGITS] = {0};
    char *endptr = nullptr;

    fgets(inputBuffer, RLD_MAX_DIGITS, stream);

    errno = 0;

    long double value = strtold(inputBuffer, &endptr);

    if (inputBuffer == endptr) {
        FPRINTF_ERROR ("input is invalid (no digits found in \"%s\"\n) "
                       "advice: input should be started with a number\n", inputBuffer);
    }
    else if (errno == ERANGE) {
        FPRINTF_ERROR ("value : %Lf  invalid  (underflow or overflow occurred)\n", value);
    }
    else if (errno != 0 && value == 0) {
        FPRINTF_ERROR ("value : %Lf invalid  (unspecified error occurred)\n", value);
    }
    else {
        return value;
    }

    exit(errno);
}

