/* Guard macros to avoid multiple inclusions. */

#ifndef DFA_CREATE_H
    #define DFA_CREATE_H





/* Including required headers. */

#include "dfa_elem/dfa_unit.h"

#include <stdbool.h>        // For using boolean parameters in function.










/* Used for loading contents of target EFLAM files into the buffer. */

bool dfa_create(
    dfa *target_dfa,        // Target DFA for loading the language.
    char *filepaths[],      // Array of file paths passed linearly.
    int file_count,         // Total number of files connected to connector file.
    bool debug              // Debugging option for getting runtime information.
);










/* Closing guard macros. */

#endif