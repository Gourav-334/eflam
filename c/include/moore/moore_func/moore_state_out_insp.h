/* Guard macros to avoid multiple inclusions. */

#ifndef MOORE_OUT_INSP_H
    #define MOORE_OUT_INSP_H





/* Including required headers. */

#include "../moore_elem/moore_unit.h"

#include <stdbool.h>                // To use boolean data type in program










/* Inspects and makes sure that every state produces an output. */

bool moore_state_out_insp(
    moore *target_moore,            // Target Moore
    bool debug                      // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif