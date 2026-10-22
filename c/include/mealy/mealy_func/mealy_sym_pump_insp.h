/* Guard macros to avoid multiple inclusions. */

#ifndef MEALY_SYM_PUMP_INSP_H
    #define MEALY_SYM_PUMP_INSP_H





/* Including required headers. */

#include "../mealy_elem/mealy_state.h"
#include "../mealy_elem/mealy_unit.h"

#include <stdbool.h>            // To use boolean return type.










/* Used for checking if a supplied symbol already exists & adding if not. */

bool mealy_sym_pump_insp(
    mealy *target_mealy,                        // Target MEALY
    int cur_state_index,                    // Relative index of current state
    char *sym,                              // String representing symbol
    int *total_sym,                         // Count of total symbols for the transition
    bool debug                              // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif