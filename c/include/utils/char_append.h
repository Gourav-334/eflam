/* Guard macros to avoid multiple inclusions. */

#ifndef CHAR_APPEND_H
    #define CHAR_APPEND_H





/* Including required headers. */

#include <stdbool.h>        // To use boolean type variables in function.










/* Used for fetching first letter in name of current state, with precautions. */

bool char_append(
    char *str,          // Target string to be updated
    char c,             // Character to be appended with
    int *str_size,      // Current size of string
    bool debug          // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif