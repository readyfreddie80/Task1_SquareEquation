//
// Created by ready on 25.09.2020.
//

#ifndef TASK1_SQUAREEQUATION_PRINTPROGRAMTITLE_H
#define TASK1_SQUAREEQUATION_PRINTPROGRAMTITLE_H

#include <stdio.h>

#define FPRINTF_ERROR(...) \
    fprintf(stderr, "error: %s:%d: ", __FILE__, __LINE__); \
    fprintf(stderr, __VA_ARGS__);


/*!
     \brief This struct contains the program information: title, author, date of creation, description.

     All the char fields have to have a '\0' symbol.
 */
struct ProgramInfo {
    const char *title;        /**< title of the program */
    const char *author;       /**< author of the program */
    const char *date;         /**< date of the program's creation */
    const char *description;  /**< description of the program */
};

/*!
     \brief Writes the program information (title, author, date of creation, description) to stdout

     The format of the output:

     # [title]
     # (c) [author], [date]
     #
     # [description]

     \return On success, returns the total number of characters written to stdout;
     If an error occurs, a negative number is returned.

     \param[in]  info   the struct ProgramInfo that contains all the program information to be written to stdout

 */
int PrintProgramInfo (const ProgramInfo *info);


/*!
     \brief Reads a long double from the stream using strtold()

     \param[in]  stream   the pointer initialized with the stream
     \return a long double read



 */
long double ReadLongDouble (FILE *stream);


#endif //TASK1_SQUAREEQUATION_PRINTPROGRAMTITLE_H


