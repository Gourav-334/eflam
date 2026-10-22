/* Including guards to avoid multiple inclusions. */

#ifndef MOORE_CUR_STATE_INSP_H
    #define MOORE_CUR_STATE_INSP_H





#include "../moore_elem/moore_unit.h"
#include "../moore_elem/moore_state.h"

#include <stdbool.h>        // To allow using boolean return type.










/* Used for creating a state if it doesn't exist yet. */

bool moore_cur_state_insp(
    moore *target_moore,                        // Target Moore machine
    char *cur_state_name,                       // Current state name
    int *cur_state_index,                       // Relative index of current state
    bool debug                                  // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif