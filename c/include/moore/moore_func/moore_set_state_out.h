/* Guard macros to avoid multiple inclusions. */

#ifndef MOORE_SET_STATE_OUT_H
    #define MOORE_SET_STATE_OUT_H





/* Including required headers. */

#include "../../../include/moore/moore_elem/moore_state.h"
#include "../../../include/moore/moore_elem/moore_unit.h"










/* Pushes a string as output to particular Moore machine state. */

bool moore_set_state_out(
    moore *target_moore,
    int cur_state_index,        // Current state index
    char *output,               // Output string
    bool debug                  // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif