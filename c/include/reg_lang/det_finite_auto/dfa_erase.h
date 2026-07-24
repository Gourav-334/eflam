/* Setting guards to avoid multiple inclusions. */

#ifndef DFA_ERASE_H
    #define DFA_ERASE_H





/* List of included headers. */

#include "dfa_units.h"          // Using DFA and DFA states structs










/* Function to erase all memory for the given DFA. */

void dfa_erase(
    dfa *target_dfa,
    char *str
);










/* Closing guard macros. */

#endif