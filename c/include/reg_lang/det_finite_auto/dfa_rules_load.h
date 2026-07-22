/* Setting guards to avoid multiple inclusions. */

#ifndef DFA_RULES_LOAD_H
    #define DFA_RULES_LOAD_H





/* List of included headers. */

#include <stdio.h>          // For using `FILE` pointer.
#include <stdbool.h>        // For using `bool` keyword.
#include "dfa_units.h"      // For using DFA state and machine.










/* Loads the rules given by users and creates the DFA. */

bool dfa_rules_load(
    char dfa_rules[],                   // Pointer to file containing DFA rules
    struct dfa_state *target_dfa,       // Address to target DFA structure
    bool debug                          // Tells if debugging logs are required
);










/* Closing guard macros. */

#endif