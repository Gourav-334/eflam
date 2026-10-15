/* Guard macros to avoid multiple inclusions. */

#ifndef MEALY_STR_TESTER_H
    #define MEALY_STR_TESTER_H





/* Including required headers. */

#include "mealy_elem/mealy_unit.h"
#include "mealy_elem/mealy_state.h"
#include "../utils/sym_tape/sym_tape_ll.h"

#include <stdbool.h>            // To direct debug requests specifically










/* Passes a string through Mealy byte processor to check where it stops. */

mealy_state *mealy_str_test(
    mealy target_mealy,             // Target Mealy
    char *symbols[],                // Array of strings
    sym_tape_ll *tape,              // Tape to write output on
    int total_sym,                  // Total number of strings
    bool debug                      // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif