/* Setting guards to avoid multiple inclusions. */

#ifndef DFA_UNITS_H
    #define DFA_UNITS_H





/* List of included headers. */

#include <stdbool.h>        // For using `bool` keyword.










/* Structure from which created instances represent unit state. */

struct dfa_state {
    bool type[2];                          // Tells if the state is accept state or not
    char **symbols;                         // Array of symbols from where this state transists
    char **states;                          // States where the current state makes transition to
    struct dfa_state *transitions[];        // Corresponding transitions for given symbols
};





/* Structure representing whole DFA, enclosing its states. */

struct dfa {
    struct dfa_state *start_state;          // Initial/start state of the DFA
    struct dfa_state *states[];             // Array of states that DFA encloses
};










/* Closing guard macros. */

#endif