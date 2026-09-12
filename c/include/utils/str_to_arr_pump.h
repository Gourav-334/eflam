/* Including guard macros to avoid multiple inclusion. */

#ifndef STR_TO_ARR_PUMP
    #define STR_TO_ARR_PUMP





/* Including required headers. */

#include <stdbool.h>            // For using boolean return type in functions.










/* Used for pushing strings to array of strings. */

bool str_to_arr_pump(
    char *str,              // String to be pushed to array
    char ***str_arr,        // Array that contains strings
    int *str_count,         // Number of strings currently in array
    bool debug              // Debugging option for getting runtime information.
);










/* Closing guard macros. */

#endif