/* Guard macros to avoid multiple inclusions. */

#ifndef MEALY_TRANS_STATE_INSP_H
    #define MEALY_TRANS_STATE_INSP_H





/* Including required headers. */

#include "../../moore/moore_elem/moore_unit.h"
#include "../../moore/moore_elem/moore_state.h"

#include <stdbool.h>            // To use boolean return types










/* Checks if a transition state exists or needs to be created. */

bool moore_trans_state_insp(
    moore *target_moore,                // Target Moore
    int cur_state_index,                // Relative index of current state
    char *trans_state_name,             // Name of transition state
    int *total_sym,                     // Total symbols to be pushed
    bool debug                          // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif