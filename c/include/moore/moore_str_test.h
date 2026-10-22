/* Guard macros to avoid multiple inclusions. */

#ifndef MOORE_STR_TESTER_H
    #define MOORE_STR_TESTER_H





/* Including required headers. */

#include "moore_elem/moore_unit.h"
#include "moore_elem/moore_state.h"
#include "../utils/sym_tape/sym_tape_ll.h"

#include <stdbool.h>            // To direct debug requests specifically










/* Passes a string through Moore byte processor to check where it stops. */

moore_state *moore_str_test(
    moore target_moore,             // Target Moore
    char *symbols[],                // Array of strings
    sym_tape_ll *tape,              // Tape to write output on
    int total_sym,                  // Total number of strings
    bool debug                      // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif