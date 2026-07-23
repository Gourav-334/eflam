/* Setting guards to avoid multiple inclusions. */

#ifndef DFA_UNITS_H
    #define DFA_UNITS_H





/* List of included headers. */

#include <stdbool.h>        // For using `bool` keyword.










/* Structure from which created instances represent unit state. */

typedef struct dfa_state {
    char *name;                             // States where the current state makes transition to
    bool type[2];                           // Tells if the state is accept state or not
    char **symbols;                         // Array of symbols from where this state transists
    struct dfa_state **transitions;         // Corresponding transitions for given symbols
    int total_trans;                        // Number of transitions current state makes
} dfa_state;





/* Structure representing whole DFA, enclosing its states. */

typedef struct dfa {
    struct dfa_state *start_state;          // Initial/start state of the DFA
    int total_states;                       // Number of states that the DFA contains
    struct dfa_state *states;               // Array of states that DFA encloses
} dfa;










/* Closing guard macros. */

#endif