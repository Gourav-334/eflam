/* Setting guards to avoid multiple inclusions. */

#ifndef DFA_UNIT_H
    #define DFA_UNIT_H





/* List of included headers. */

#include "dfa_unit.h"

#include <stdbool.h>        // For using `bool` keyword.










/* Structure representing whole DFA, enclosing its states. */

typedef struct dfa {
    struct dfa_state *start_state;          // Initial/start state of the DFA
    int total_states;                       // Number of states that the DFA contains
    struct dfa_state *states;               // Array of states that DFA encloses
} dfa;










/* Closing guard macros. */

#endif