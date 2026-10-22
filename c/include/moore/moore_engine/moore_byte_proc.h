/* Setting guards to avoid multiple inclusions. */

#ifndef MOORE_MACHINE_H
    #define MOORE_MACHINE_H





/* List of included headers. */

#include "../moore_elem/moore_unit.h"

#include <stdbool.h>        // For using `bool` keyword.










/* Checks the Moore as per user given rules. */

int moore_byte_proc(
    moore *target_moore,            // Address to target Moore structure
    char *filepath,                 // Name of the particular file/ its path
    char *fstream,                  // Pointer to fstream containing Moore rules
    bool debug                      // Tells if debugging logs are required
);










/* Closing guard macros. */

#endif