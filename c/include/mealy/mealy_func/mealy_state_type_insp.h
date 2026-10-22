/* Guard macros to avoid multiple inclusion. */

#ifndef MEALY_STATE_TYPE_INSP_H
    #define MEALY_STATE_TYPE_INSP_H





/* Including required headers. */

#include "../mealy_elem/mealy_state.h"
#include "../mealy_elem/mealy_unit.h"

#include <stdbool.h>            // To return boolean results for functions.










/* Used for checking if the state types are valid, and add valid ones. */

bool mealy_state_type_insp(
    mealy *target_mealy,                        // Target MEALY
    int cur_state_index,                    // Relative index of current state
    char *type,                             // String showing state type
    bool debug                              // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif