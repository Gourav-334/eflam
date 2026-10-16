/* Guard macros to avoid multiple inclusions. */

#ifndef MEALY_MAP_LL_H
    #define MEALY_MAP_LL_H





/* Including required headers. */

#include "moore_map_node.h"










/* Linked list that maps Moore transitions. */

typedef struct moore_map_ll {
    struct moore_map_node *head;         // Pointer to head of linked list
    struct moore_map_node *tail;         // Pointer to tail of linked list
    int total_nodes;                     // Total count of nodes
} moore_map_ll;










/* Closing guard macros. */

#endif