/* Guard macros to avoid multiple inclusions. */

#ifndef MEALY_SET_STATE_OUT_H
    #define MEALY_SET_STATE_OUT_H





/* Including required headers. */

#include "../../../include/mealy/mealy_elem/mealy_state.h"
#include "../../../include/mealy/mealy_elem/mealy_unit.h"










/* Pushes a string as output to particular Mealy machine state. */

bool mealy_set_state_out(
    mealy *target_mealy,
    int cur_state_index,        // Current state index
    char *output,               // Output string
    bool debug                  // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif