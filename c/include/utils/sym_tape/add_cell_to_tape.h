/* Guard macros to avoid multiple inclusions. */

#ifndef ADD_CELL_TO_TAPE_H
    #define ADD_CELL_TO_TAPE_H





/* Including required headers. */

#include "sym_tape_cell.h"
#include "sym_tape_ll.h"










/* Adds a cell to the tape along with the symbol. */

sym_tape_cell *add_cell_to_tape(
    sym_tape_ll *tape,                  // Tape to which cell has to be added
    char *sym,                          // Symbol to be written on the new cell
    bool debug                          // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif