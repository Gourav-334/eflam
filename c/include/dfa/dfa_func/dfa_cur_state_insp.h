/* Including guards to avoid multiple inclusions. */

#ifndef DFA_CUR_STATE_INSP_H
    #define DFA_CUR_STATE_INSP_H





#include "../dfa_elem/dfa_unit.h"
#include "../dfa_elem/dfa_state.h"

#include <stdbool.h>        // To allow using boolean return type.










/* Used for creating a state if it doesn't exist yet. */

bool dfa_cur_state_insp(
    dfa *target_dfa,                            // Target DFA machine
    char *cur_state_name,                       // Current state name
    dfa_state **cur_state_addr,                 // Address of current state
    bool debug                                  // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif