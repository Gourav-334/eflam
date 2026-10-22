/* Setting guards to avoid multiple inclusions. */

#ifndef MOORE_UNIT_H
    #define MOORE_UNIT_H





/* List of included headers. */

#include "moore_unit.h"

#include <stdbool.h>        // For using `bool` keyword.










/* Structure representing whole Moore, enclosing its states. */

typedef struct moore {
    int start_state;                        // Index of initial/start state of the Moore
    int total_states;                       // Number of states that the Moore contains
    struct moore_state *states;             // Array of states that Moore encloses
} moore;










/* Closing guard macros. */

#endif