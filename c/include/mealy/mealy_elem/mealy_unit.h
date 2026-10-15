/* Setting guards to avoid multiple inclusions. */

#ifndef MEALY_UNIT_H
    #define MEALY_UNIT_H





/* List of included headers. */

#include "mealy_unit.h"

#include <stdbool.h>        // For using `bool` keyword.










/* Structure representing whole Mealy, enclosing its states. */

typedef struct mealy {
    int start_state;                        // Index of initial/start state of the Mealy
    int total_states;                       // Number of states that the Mealy contains
    struct mealy_state *states;             // Array of states that Mealy encloses
} mealy;










/* Closing guard macros. */

#endif