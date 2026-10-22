/* Guard macros to avoid multiple inclusions. */

#ifndef MEALY_STR_TESTER_H
    #define MEALY_STR_TESTER_H





/* Including required headers. */

#include "mealy_elem/mealy_unit.h"
#include "mealy_elem/mealy_state.h"

#include <stdbool.h>            // To direct debug requests specifically










/* Passes a string through MEALY byte processor to check where it stops. */

mealy_state *mealy_str_test(
    mealy target_mealy,             // Target MEALY
    char *symbols[],                // Array of strings
    int total_sym,                  // Total number of strings
    bool debug                      // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif