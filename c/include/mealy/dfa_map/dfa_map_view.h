/* Guard macros to avoid multiple inclusions. */

#ifndef DFA_MAP_VIEW_H
    #define DFA_MAP_VIEW_H





/* Including required headers. */

#include "dfa_map_ll.h"

#include <stdbool.h>                // To return boolean value with function










/* Used for viewing everything that the map contains. */

bool dfa_map_view(
    dfa_map_ll map              // The linked list map containing transitions
);










/* Closing guard macros. */

#endif