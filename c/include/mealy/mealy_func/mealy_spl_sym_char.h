/* Including guard macros to avoid multiple inclusions. */

#ifndef MEALY_SPL_SYM_CHAR_H
    #define MEALY_SPL_SYM_CHAR_H





/* Including required headers. */

#include <stdbool.h>        // To use boolean debugging option.










/* Used for decoding certain special characters in strings. */

char mealy_spl_sym_char(
    char spl_char,          // Special character found
    bool debug              // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif