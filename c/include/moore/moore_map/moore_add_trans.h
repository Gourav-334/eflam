/* Guard macros to avoid multiple inclusions. */

#ifndef MOORE_ADD_TRANS_H
    #define MOORE_ADD_TRANS_H





/* Including required headers. */

#include "moore_map_ll.h"
#include "moore_map_node.h"

#include <stdbool.h>                // To enable debugging information specifically










/* Used for adding index of a transition state to map's node. */

moore_map_node *moore_add_trans(
    moore_map_ll *map,          // The linked list map containing transitions
    int trans,                  // Transition state index to fill nodes with
    int trans_start,            // Start point to fill with transition state index
    int trans_finish,           // Finish point to fill with transition state index
    bool debug                  // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif