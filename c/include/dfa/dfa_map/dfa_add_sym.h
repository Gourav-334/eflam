/* Guard macros to avoid multiple inclusion. */

#ifndef DFA_ADD_SYM_H
    #define DFA_ADD_SYM_H





/* Including required headers. */

#include "dfa_map_ll.h"
#include "dfa_map_node.h"

#include <stdbool.h>            // To enable debugging options










/* Adds a node with symbol to the DFA map. */

dfa_map_node *dfa_add_sym(
    dfa_map_ll *map,            // Address to DFA map linked list
    char *sym,                  // Symbol string to add
    bool debug                  // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif