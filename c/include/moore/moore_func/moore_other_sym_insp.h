/* Guard macros to avoid multiple inclusion. */

#ifndef MEALY_OTHER_SYM_INSP_H
    #define MEALY_OTHER_SYM_INSP_H





/* Including required headers. */

#include "../moore_elem/moore_state.h"
#include "../moore_elem/moore_unit.h"

#include <stdbool.h>                // To use boolean return type in functions










/* Sets transition to a state for the remaining symbols. */

bool moore_other_sym_insp (
    moore *target_moore,                // Target Moore
    int cur_state_index,                // Relative index of current state
    char *trans_state_name,             // Name of transition state
    bool debug                          // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif