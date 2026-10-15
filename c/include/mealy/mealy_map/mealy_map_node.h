/* Guard macros to avoid multiple inclusions. */

#ifndef MEALY_MAP_NODE_H
    #define MEALY_MAP_NODE_H










/* Node that contains a Mealy mapping. */

typedef struct mealy_map_node {
    char *sym;                      // Symbol string
    int trans;                      // Transition state index
    mealy_map_node *next;           // Pointer to next node
} mealy_map_node;










/* Closing guard macros. */

#endif