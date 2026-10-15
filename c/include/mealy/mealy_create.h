/* Guard macros to avoid multiple inclusions. */

#ifndef MEALY_CREATE_H
    #define MEALY_CREATE_H





/* Including required headers. */

#include "mealy_elem/mealy_unit.h"

#include <stdbool.h>        // For using boolean parameters in function.










/* Used for loading contents of target EFLAM files into the buffer. */

bool mealy_create(
    mealy *target_mealy,        // Target Mealy for loading the language.
    char *filepaths[],          // Array of file paths passed linearly.
    int file_count,             // Total number of files connected to connector file.
    bool debug                  // Debugging option for getting runtime information.
);










/* Closing guard macros. */

#endif