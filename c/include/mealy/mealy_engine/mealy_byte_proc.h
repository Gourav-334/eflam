/* Setting guards to avoid multiple inclusions. */

#ifndef MEALY_MACHINE_H
    #define MEALY_MACHINE_H





/* List of included headers. */

#include "../mealy_elem/mealy_unit.h"

#include <stdbool.h>        // For using `bool` keyword.










/* Checks the Mealy as per user given rules. */

int mealy_byte_proc(
    mealy *target_mealy,            // Address to target Mealy structure
    char *filepath,                 // Name of the particular file/ its path
    char *fstream,                  // Pointer to fstream containing Mealy rules
    bool debug                      // Tells if debugging logs are required
);










/* Closing guard macros. */

#endif