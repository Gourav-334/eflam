/* Guard macros to avoid multiple inclusions. */

#ifndef DFA_SYM_PUMP_INSP_H
    #define DFA_SYM_PUMP_INSP_H





/* Including required headers. */

#include "../dfa_elem/dfa_state.h"

#include <stdbool.h>            // To use boolean return type.










/* Used for checking if a supplied symbol already exists & adding if not. */

bool dfa_sym_pump_insp(
    dfa_state *cur_state_addr,              // Address of current state
    char *sym,                              // String representing symbol
    int *total_sym,                         // Count of total symbols for the transition
    bool debug                              // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif