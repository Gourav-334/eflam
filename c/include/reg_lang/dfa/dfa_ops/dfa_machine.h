/* Setting guards to avoid multiple inclusions. */

#ifndef DFA_MACHINE_H
    #define DFA_MACHINE_H





/* List of included headers. */

#include <stdbool.h>        // For using `bool` keyword.
#include "dfa_units.h"      // For using DFA state and machine.










/* Checks the DFA as per user given rules. */

bool dfa_machine(
    char *fstream,              // Pointer to fstream containing DFA rules
    dfa *target_dfa,            // Address to target DFA structure
    bool debug                  // Tells if debugging logs are required
);










/* Closing guard macros. */

#endif