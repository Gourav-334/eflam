/* Setting guards to avoid multiple inclusions. */

#ifndef MOORE_STATE_H
    #define MOORE_STATE_H

#define START_STATE 0           // Index for START state configuration.
#define ACCEPT_STATE 1          // Index for ACCEPT state configuration.
#define TOTAL_TYPES 2           // Total types of states.





/* List of included headers. */

#include "../moore_map/moore_map_ll.h"

#include <stdbool.h>        // For using `bool` keyword.










/* Structure from which created instances represent unit state. */

typedef struct moore_state {
    char *name;                             // States where the current state makes transition to
    char *output;                           // Output string for current state
    bool type[TOTAL_TYPES];                 // Tells if the state is accept state or not
    moore_map_ll map;                       // Symbols to state transition map
    int else_trans;                         // Index of ELSE transition symbol
    int total_trans;                        // Number of transitions current state makes
} moore_state;










/* Closing guard macros. */

#endif