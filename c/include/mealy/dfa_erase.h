/* Guard macros to avoid multiple inclusions. */

#ifndef DFA_ERASE_H
    #define DFA_ERASE_H





/* Including required headers. */

#include "dfa_elem/dfa_unit.h"
#include "dfa_elem/dfa_state.h"
#include "dfa_map/dfa_map_ll.h"
#include "dfa_map/dfa_map_node.h"










/* Erases everything related to the particular DFA. */

dfa *dfa_erase(
    dfa *target_dfa,            // Target DFA
    bool debug                  // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif