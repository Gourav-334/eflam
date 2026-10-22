/* Guard macros to avoid multiple inclusions. */

#ifndef MEALY_TRANS_STATE_INSP_H
    #define MEALY_TRANS_STATE_INSP_H





/* Including required headers. */

#include "../../mealy/mealy_elem/mealy_unit.h"
#include "../../mealy/mealy_elem/mealy_state.h"

#include <stdbool.h>            // To use boolean return types










/* Checks if a transition state exists or need to be created. */

bool mealy_trans_state_insp(
    mealy *target_mealy,                    // Target MEALY
    int cur_state_index,                // Relative index of current state
    char *trans_state_name,             // Name of transition state
    int *total_sym,                     // Total symbols to be pushed
    bool debug                          // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif