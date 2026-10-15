/* Guard macros to avoid multiple inclusions. */

#ifndef SYM_TAPE_LL_H
    #define SYM_TAPE_LL_H





/* Including required headers. */

#include "sym_tape_cell.h"










/* Tape controller containing details and entry to tape. */

typedef struct sym_tape_ll {
    struct sym_tape_cell *head;             // Pointer to head of linked list
    struct sym_tape_cell *tail;             // Pointer to tail of linked list
    int total_cells;                        // Total number of cells in tape
} sym_tape_ll;










/* Closing guard macros. */

#endif