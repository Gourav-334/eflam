/* Including guards to avoid multiple inclusions. */

#ifndef MEALY_CUR_STATE_INSP_H
    #define MEALY_CUR_STATE_INSP_H





#include "../mealy_elem/mealy_unit.h"
#include "../mealy_elem/mealy_state.h"

#include <stdbool.h>        // To allow using boolean return type.










/* Used for creating a state if it doesn't exist yet. */

bool mealy_cur_state_insp(
    mealy *target_mealy,                            // Target MEALY machine
    char *cur_state_name,                       // Current state name
    int *cur_state_index,                       // Relative index of current state
    bool debug                                  // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif