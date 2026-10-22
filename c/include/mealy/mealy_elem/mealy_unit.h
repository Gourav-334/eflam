/* Setting guards to avoid multiple inclusions. */

#ifndef MEALY_UNIT_H
    #define MEALY_UNIT_H





/* List of included headers. */

#include "mealy_unit.h"

#include <stdbool.h>        // For using `bool` keyword.










/* Structure representing whole MEALY, enclosing its states. */

typedef struct mealy {
    int start_state;                        // Index of initial/start state of the MEALY
    int total_states;                       // Number of states that the MEALY contains
    struct mealy_state *states;               // Array of states that MEALY encloses
} mealy;










/* Closing guard macros. */

#endif