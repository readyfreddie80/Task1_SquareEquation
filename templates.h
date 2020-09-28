//
// Created by freddie on 27.09.20.
//

#ifndef TASK1_SQUAREEQUATION_TEMPLATES_H
#define TASK1_SQUAREEQUATION_TEMPLATES_H

#define CAT(X,Y) X##_##Y

/*!Macro for composing names of functions  in which
 * FUNC_NAME is the first part of the name of the function (describes what the function does)
 * TEMPLATE_TYPE is the identificator of #define which rename a type
 */
#define TEMPLATE(FUNC_NAME, TEMPLATE_TYPE) CAT(X,Y)


/*!Macro for composing names TYPE_LIMIT of consts
 * from limits.h (such as INT_MAX) and from float.h (LDBL_MIN)
 * where TYPE: LDBL, DBL, FLT, INT, CHAR
 *       LIMIT: MAX, MIN
 */
#define GET_TYPE_LIMIT(TYPE, LIMIT) CAT(TYPE, LIMIT)


/*! These typedefs are needed so that
 * macro TEMPLATE work correctly together with GET_TYPE_LIMIT
 *
 *
 * T TEMPLATE(ReadValue,T) (const char *valueName) this function needs them
 */
typedef long double LDBL;
typedef double DBL;
typedef float FLT;
typedef int INT;
typedef char CHAR;

#endif //TASK1_SQUAREEQUATION_TEMPLATES_H
