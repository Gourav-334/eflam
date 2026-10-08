/* Guard macros to avoid multiple inclusions. */

#ifndef DFA_MAP_NODE_H
    #define DFA_MAP_NODE_H










/* Node that contains a DFA mapping. */

typedef struct dfa_map_node {
    char *sym;                  // Symbol string
    int trans;                  // Transition state index
    struct dfa_map_node *next;         // Pointer to next node
} dfa_map_node;










/* Closing guard macros. */

#endif