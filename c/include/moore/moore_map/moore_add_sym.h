/* Guard macros to avoid multiple inclusion. */

#ifndef MEALY_ADD_SYM_H
    #define MEALY_ADD_SYM_H





/* Including required headers. */

#include "moore_map_ll.h"
#include "moore_map_node.h"

#include <stdbool.h>            // To enable debugging options










/* Adds a node with symbol to the Moore map. */

moore_map_node *moore_add_sym(
    moore_map_ll *map,          // Address to Moore map linked list
    char *sym,                  // Symbol string to add
    bool debug                  // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif