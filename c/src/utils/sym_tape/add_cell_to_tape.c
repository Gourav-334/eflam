/* Including required headers. */

#include "../../../include/utils/sym_tape/add_cell_to_tape.h"

#include <stdio.h>              // For using basic I/O functionalities
#include <stdbool.h>            // Specifically for switching debugging mode










/* Adds a cell to the tape along with the symbol. */

sym_tape_cell *add_cell_to_tape(sym_tape_ll *tape, char *sym, bool debug)
{
    /* Variables & constants */

    char *file = "add_cell_to_tape.c";
    sym_tape_cell *new_cell = NULL;





    /* Creating a new node. */

    new_cell = malloc(sizeof(sym_tape_cell));
        

    if (new_cell==NULL)
    {
        printf("ERROR (%s):%d :: Memory allocation for Symbol Tape Cell failed!\n", file, __LINE__);
        return NULL;
    }
    else if (debug==true)
    {
        printf("OK (%s):%d :: Memory allocation for Symbol Tape Cell successful.\n", file, __LINE__);
    }





    /* Checking if node already exists. */

    if (tape->total_cells==0) {tape -> head = new_cell;}
    else if (tape->total_cells<0)
    {
        printf(
            "ERROR (%s):%d :: Total cells can\'t be less than %d, data corrupted!\n",
            file, __LINE__, 0
        );
    }
    else if (tape->total_cells>0)
    {
        tape -> tail -> next = new_cell;
    }



    /* Assigning the tail to point to newly created node. */

    tape -> tail = new_cell;
    (tape -> total_cells)++;





    /* Filling the string at node. */

    tape -> tail -> sym = malloc(sizeof(char)*((size_t)(strlen(sym))+1));


    if (tape->tail->sym==NULL)
    {
        printf("ERROR (%s):%d :: Memory allocation for symbol failed!\n", file, __LINE__);
        return NULL;
    }
    else if (debug==true)
    {
        printf("OK (%s):%d :: Memory allocation for symbol successful.\n", file, __LINE__);
    }


    strcpy(new_cell->sym, sym);        // Copying argument symbol to created node


    if (debug==true)
    {
        printf("STAT (%s):%d :: Symbol \"%s\" is added as a cell to tape.\n", file, __LINE__, new_cell->sym);
    }





    /* Returning address of the recently created node. */

    return (new_cell->next);
}