/* Guard macros to avoid multiple inclusions. */

#ifndef MEALY_MAP_LL_H
    #define MEALY_MAP_LL_H





/* Including required headers. */

#include "mealy_map_node.h"










/* Linked list that maps MEALY transitions. */

typedef struct mealy_map_ll {
    mealy_map_node *head;         // Pointer to head of linked list
    mealy_map_node *tail;         // Pointer to tail of linked list
    int total_nodes;            // Total count of nodes
} mealy_map_ll;










/* Closing guard macros. */

#endif