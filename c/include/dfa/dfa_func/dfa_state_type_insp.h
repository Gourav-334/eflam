/* Guard macros to avoid multiple inclusion. */

#ifndef DFA_STATE_TYPE_INSP_H
    #define DFA_STATE_TYPE_INSP_H





/* Including required headers. */

#include "../dfa_elem/dfa_state.h"

#include <stdbool.h>            // To return boolean results for functions.










/* Used for checking if the state types are valid, and add valid ones. */

bool dfa_state_type_insp(
    dfa_state *cur_state_addr,              // Address of current state
    char *type,                             // String showing state type
    bool debug                              // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif