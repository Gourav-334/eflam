/* Guard macros to avoid multiple inclusions. */

#ifndef SYM_TAPE_TO_STR_ARR_H
    #define SYM_TAPE_TO_STR_ARR_H





/* Including required headers. */

#include "sym_tape_ll.h"

#include <stdbool.h>                // Specifically for debugging purposes










/* Converts series of symbols on symbol tape into a string array. */

int sym_tape_to_str_arr(
    sym_tape_ll target_tape,            // Target symbol tape
    char ***str_arr,                    // Target string array
    bool debug                          // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif