/* Guard macros to avoid multiple inclusions. */

#ifndef MEALY_SYM_PUMP_INSP_H
    #define MEALY_SYM_PUMP_INSP_H





/* Including required headers. */

#include "../moore_elem/moore_state.h"
#include "../moore_elem/moore_unit.h"

#include <stdbool.h>            // To use boolean return type.










/* Used for checking if a supplied symbol already exists & adding if not. */

bool moore_sym_pump_insp(
    moore *target_moore,                    // Target Moore
    int cur_state_index,                    // Relative index of current state
    char *sym,                              // String representing symbol
    int *total_sym,                         // Count of total symbols for the transition
    bool debug                              // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif