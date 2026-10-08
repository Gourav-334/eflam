/* Guard macros to avoid multiple inclusions. */

#ifndef DFA_ADD_TRANS_H
    #define DFA_ADD_TRANS_H





/* Including required headers. */

#include "dfa_map_ll.h"
#include "dfa_map_node.h"

#include <stdbool.h>                // To enable debugging information specifically










/* Used for adding index of a transition state to map's node. */

dfa_map_node *dfa_add_trans(
    dfa_map_ll *map,            // The linked list map containing transitions
    int trans,                  // Transition state index to fill nodes with
    int trans_start,            // Start point to fill with transition state index
    int trans_finish,           // Finish point to fill with transition state index
    bool debug                  // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif