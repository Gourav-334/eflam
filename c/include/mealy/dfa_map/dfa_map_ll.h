/* Guard macros to avoid multiple inclusions. */

#ifndef DFA_MAP_LL_H
    #define DFA_MAP_LL_H





/* Including required headers. */

#include "dfa_map_node.h"










/* Linked list that maps DFA transitions. */

typedef struct dfa_map_ll {
    dfa_map_node *head;         // Pointer to head of linked list
    dfa_map_node *tail;         // Pointer to tail of linked list
    int total_nodes;            // Total count of nodes
} dfa_map_ll;










/* Closing guard macros. */

#endif