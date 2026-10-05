/* Guard macros to avoid multiple inclusion. */

#ifndef DFA_OTHER_SYM_INSP_H
    #define DFA_OTHER_SYM_INSP_H





/* Including required headers. */

#include "../dfa_elem/dfa_state.h"
#include "../dfa_elem/dfa_unit.h"

#include <stdbool.h>                // To use boolean return type in functions










/* Sets transition to a state for the remaining symbols. */

bool dfa_other_sym_insp (
    dfa *target_dfa,                    // Target DFA
    dfa_state **cur_state_addr,         // Current state's address
    int cur_state_index,                // Relative index of current state
    char *trans_state_name,             // Name of transition state
    bool debug                          // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif