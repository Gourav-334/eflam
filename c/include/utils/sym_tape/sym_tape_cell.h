/* Guard macros to avoid multiple inclusions. */

#ifndef SYM_TAPE_CELL_H
    #define SYM_TAPE_CELL_H










/* Unit cell of a symbol tape. */

typedef struct sym_tape_cell {
    char *sym;                              // Symbol written on the cell
    struct sym_tape_cell *next;             // Address of next cell in tape
} sym_tape_cell;










/* Closing guard macros. */

#endif