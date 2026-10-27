/* Guard macros to avoid multiple inclusions. */

#ifndef MEALY_MAP_NODE_H
    #define MEALY_MAP_NODE_H





/* Including required headers. */

#include <stdbool.h>            // To use boolean member in state struct










/* Node that contains a MEALY mapping. */

typedef struct mealy_map_node {
    char *sym;                  // Symbol string
    int trans;                  // Transition state index
    char *output;               // Output for the particular transition
    bool *corresp;              // Tells if the correspondance rule is applied
    mealy_map_node *next;       // Pointer to next node
} mealy_map_node;










/* Closing guard macros. */

#endif