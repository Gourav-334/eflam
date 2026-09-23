/* Setting guards to avoid multiple inclusions. */

#ifndef DFA_MACHINE_H
    #define DFA_MACHINE_H





/* List of included headers. */

#include "../dfa_elem/dfa_unit.h"

#include <stdbool.h>        // For using `bool` keyword.










/* Checks the DFA as per user given rules. */

int dfa_byte_proc(
    dfa *target_dfa,            // Address to target DFA structure
    char *fstream,              // Pointer to fstream containing DFA rules
    bool debug                  // Tells if debugging logs are required
);










/* Closing guard macros. */

#endif