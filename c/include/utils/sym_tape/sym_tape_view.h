/* Guard macros to avoid multiple inclusions. */

#ifndef SYM_TAPE_VIEW_H
    #define SYM_TAPE_VIEW_H





/* Including required headers. */

#include "sym_tape_ll.h"

#include <stdbool.h>            // To return boolean value from function










/* Iterates through the tape and displays all the symbols it contains in series. */

bool sym_tape_view(
    sym_tape_ll tape              // The tape containing transitions
);










/* Closing guard macros. */

#endif