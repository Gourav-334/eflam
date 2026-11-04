/* Guard macros to avoid multiple inclusions. */

#ifndef MEALY_SET_ELSE_OUT_H
    #define MEALY_SET_ELSE_OUT_H





/* Including required headers. */

#include "../mealy_elem/mealy_unit.h"

#include <stdio.h>              // Specifically to access debug information










/* Sets ELSE output for given transition. */

bool mealy_set_else_out(
    mealy *target_mealy,                // Target MEALY
    char *output,                       // Output to configure
    int cur_state_index,                // Current state index
    bool debug                          // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif