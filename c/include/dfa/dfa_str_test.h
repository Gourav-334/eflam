/* Guard macros to avoid multiple inclusions. */

#ifndef DFA_STR_TESTER_H
    #define DFA_STR_TESTER_H





/* Including required headers. */

#include "dfa_elem/dfa_unit.h"
#include "dfa_elem/dfa_state.h"

#include <stdbool.h>            // To direct debug requests specifically










/* Passes a string through DFA byte processor to check where it stops. */

dfa_state *dfa_str_test(
    dfa target_dfa,                 // Target DFA
    char *symbols[],                // Array of strings
    int total_sym,                  // Total number of strings
    bool debug                      // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif