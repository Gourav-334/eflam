/* Guard macros to avoid multiple inclusions. */

#ifndef MEALY_MAP_NODE_H
    #define MEALY_MAP_NODE_H










/* Node that contains a Moore mapping. */

typedef struct moore_map_node {
    char *sym;                              // Symbol string
    int trans;                              // Transition state index
    struct moore_map_node *next;            // Pointer to next node
} moore_map_node;










/* Closing guard macros. */

#endif