/* Guard macros to avoid multiple inclusions. */

#ifndef DFA_TRANS_STATE_INSP_H
    #define DFA_TRANS_STATE_INSP_H





/* Including required headers. */

#include "../../dfa/dfa_elem/dfa_unit.h"
#include "../../dfa/dfa_elem/dfa_state.h"

#include <stdbool.h>            // To use boolean return types










/* Checks if a transition state exists or need to be created. */

bool dfa_trans_state_insp(
    dfa *target_dfa,                    // Target DFA
    dfa_state *cur_state_addr,          // Current state's address
    char *trans_state_name,             // Name of transition state
    int *total_sym,                     // Total symbols to be pushed
    bool debug                          // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif