/* Setting guards to avoid multiple inclusions. */

#ifndef MEALY_STATE_H
    #define MEALY_STATE_H

#define START_STATE 0           // Index for START state configuration.
#define ACCEPT_STATE 1          // Index for ACCEPT state configuration.
#define TOTAL_TYPES 2           // Total types of states.





/* List of included headers. */

#include "../mealy_map/mealy_map_ll.h"

#include <stdbool.h>        // For using `bool` keyword.










/* Structure from which created instances represent unit state. */

typedef struct mealy_state {
    char *name;                             // States where the current state makes transition to
    char *output;                           // Output string for current state
    bool type[TOTAL_TYPES];                 // Tells if the state is accept state or not
    mealy_map_ll map;                       // Symbols to state transition map
    int else_trans;                         // Index of ELSE transition symbol
    int total_trans;                        // Number of transitions current state makes
} mealy_state;










/* Closing guard macros. */

#endif