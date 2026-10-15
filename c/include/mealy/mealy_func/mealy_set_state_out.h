/* Guard macros to avoid multiple inclusions. */

#ifndef MEALY_SET_STATE_OUT_H
    #define MEALY_SET_STATE_OUT_H





/* Including required headers. */

#include "../../../include/mealy/mealy_elem/mealy_state.h"










/* Pushes a string as output to particular Mealy machine state. */

bool mealy_set_state_out(
    mealy_state *cur_state_addr,        // Current state address
    char *output,                       // Output string
    bool debug                          // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif