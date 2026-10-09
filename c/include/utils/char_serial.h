/* Guard macros to avoid multiple inclusion. */

#ifndef CHAR_SERIAL_H
    #define CHAR_SERIAL_H





/* Including required headers. */

#include <stdbool.h>            // For using boolean return type in functions
#include <stddef.h>             // To use `size_t` as a return type










/* Used for serializing all characters in a string to multiple strings. */

size_t char_serial(
    char *str,              // String to be pushed to array
    char ***str_arr,        // Array that contains strings
    bool debug              // Debugging option for getting runtime information.
);










/* Closing guard macros. */

#endif