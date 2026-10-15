/* Guard macros to avoid multiple inclusions. */

#ifndef MEALY_OUT_INSP_H
    #define MEALY_OUT_INSP_H





/* Including required headers. */

#include "../mealy_elem/mealy_unit.h"

#include <stdbool.h>                // To use boolean data type in program










/* Inspects and makes sure that every state produces an output. */

bool mealy_state_out_insp(
    char *filepaths[],              // Path to all the target files
    mealy target_mealy,             // Target Mealy
    bool debug                      // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif