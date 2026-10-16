/* Guard macros to avoid multiple inclusion. */

#ifndef MEALY_STATE_TYPE_INSP_H
    #define MEALY_STATE_TYPE_INSP_H





/* Including required headers. */

#include "../moore_elem/moore_state.h"
#include "../moore_elem/moore_unit.h"

#include <stdbool.h>            // To return boolean results for functions.










/* Used for checking if the state types are valid, and add valid ones. */

bool moore_state_type_insp(
    moore *target_moore,                    // Target Moore
    int cur_state_index,                    // Relative index of current state
    char *type,                             // String showing state type
    bool debug                              // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif