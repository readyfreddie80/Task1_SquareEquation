//
// Created by freddie on 28.09.20.
//


#ifdef T

#include "templatefuncs.h"

#include "templatefuncs.h"
#include "programio.h"
#include "templates.h"

#include <assert.h>
#include <limits.h>
#include <float.h>
#include <errno.h>
#include <cmath>

void TEMPLATE(swap,T) (T *x, T *y) {
    T z = *x;
    *x = *y;
    *y = z;
}

/// Checks if ldValue is out of range [TYPE_MIN_LIMIT; TYPE_MAX_LIMIT]
int isOutOfTypeRange (
        long double ldValue,
        T TYPE_MIN_LIMIT,
        T TYPE_MAX_LIMIT) {

    if (TYPE_MIN_LIMIT <= 0) {
        return ldValue < TYPE_MIN_LIMIT || ldValue > TYPE_MAX_LIMIT;
    } else {
        return abs(ldValue) > TYPE_MAX_LIMIT || abs(ldValue) < TYPE_MIN_LIMIT;
    }

}


/*!
     \brief Asks the user to enter to stdin a value that has the particular name and reads it

     If the user inputs characters after a number and before pushing Enter,
     the function skips all the leftover characters in stdin

     This function says "# Please, enter [valueName] = ", and waits until
     the user enters a double value, then returns it

     \param[in]  valueName    the name of the value (c-string ending with '\0')
 */

T TEMPLATE(ReadValue,T) (const char *valueName) {
    assert (valueName != nullptr);

    printf ("# Please, enter %s = ", valueName);

    long double ldValue = ReadLongDouble(stdin);

    const T TYPE_MAX_LIMIT = GET_TYPE_LIMIT(T, MAX);
    const T TYPE_MIN_LIMIT = GET_TYPE_LIMIT(T, MIN);

    if (ldValue != 0) {
        bool isOutOfTypeRange = false;

        if (TYPE_MIN_LIMIT <= 0) {
            isOutOfTypeRange = ldValue < TYPE_MIN_LIMIT || ldValue > TYPE_MAX_LIMIT;
        } else {
            isOutOfTypeRange =  abs(ldValue) > TYPE_MAX_LIMIT || abs(ldValue) < TYPE_MIN_LIMIT;
        }

        if (isOutOfTypeRange) {
            FPRINTF_ERROR (
                "input value %Lf is out of range: [%Lf ; %Lf]\n",
                ldValue,
                (LDBL)TYPE_MIN_LIMIT,
                (LDBL)TYPE_MAX_LIMIT);
                errno = ERANGE;
                exit(errno);
        }
    }

    fflush(stdin);

    return (T)ldValue;
}

#endif
