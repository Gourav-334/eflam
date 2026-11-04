/* Guard macros to avoid multiple inclusions. */

#ifndef MEALY_ADD_OUT_H
    #define MEALY_ADD_OUT_H





/* Including required headers. */

#include "../mealy_map/mealy_map_node.h"
#include "../mealy_map/mealy_map_ll.h"

#include <stdbool.h>            // Specifically to access debugging info










/* Used for adding output of a transition to map's node. */

mealy_map_node *mealy_add_out(
    mealy_map_ll *map,          // The linked list map containing transitions
    char *output,               // Transition output to fill nodes with
    int out_start,              // Start point to fill with output
    int out_finish,             // Finish point to fill with output
    bool debug                  // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif