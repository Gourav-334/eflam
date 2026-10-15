/* Guard macros to avoid multiple inclusion. */

#ifndef MEALY_ADD_SYM_H
    #define MEALY_ADD_SYM_H





/* Including required headers. */

#include "mealy_map_ll.h"
#include "mealy_map_node.h"

#include <stdbool.h>            // To enable debugging options










/* Adds a node with symbol to the Mealy map. */

mealy_map_node *mealy_add_sym(
    mealy_map_ll *map,          // Address to Mealy map linked list
    char *sym,                  // Symbol string to add
    bool debug                  // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif