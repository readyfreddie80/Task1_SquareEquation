//
// Created by freddie on 27.09.20.
//

#ifndef TASK1_SQUAREEQUATION_TEMPLATES_H
#define TASK1_SQUAREEQUATION_TEMPLATES_H

#define CAT(X,Y) X##_##Y

#define TEMPLATE(X,Y) CAT(X,Y)

#define GET_TYPE_LIMIT(TPY, LIMIT) CAT(TPY, LIMIT)

typedef long double LDBL;
typedef double DBL;
typedef float FLT;
typedef int INT;
typedef char CHAR;

#endif //TASK1_SQUAREEQUATION_TEMPLATES_H
