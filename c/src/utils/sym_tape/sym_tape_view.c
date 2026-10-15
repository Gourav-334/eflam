/* Including required headers. */

#include "../../../include/utils/sym_tape/sym_tape_view.h"

#include <stdio.h>              // To access basic I/O functions










/* Used for viewing everything that the map contains. */

bool sym_tape_view(sym_tape_ll tape)
{
    /* Variables & constants */

    char *file = "sym_tape_view.c";
    sym_tape_cell *cur_cell = tape.head;





    /* Checking if data are corrupted in anyway. */

    if (tape.total_cells<0)
    {
        printf(
            "ERROR (%s):%d :: Total cells can\'t be less than %d, data corrupted!\n",
            file, __LINE__, 0
        );

        return false;
    }
    else if (tape.total_cells==0 && (tape.head!=NULL || tape.tail!=NULL))
    {
        printf(
            "ERROR (%s):%d :: Pointers must be NULL when there are no cells, data corrupted!\n",
            file, __LINE__
        );

        return false;
    }
    else if (tape.total_cells>0 && (tape.head==NULL || tape.tail==NULL))
    {
        printf(
            "ERROR (%s):%d :: Pointers can't be NULL when there are cells, data corrupted!\n",
            file, __LINE__
        );

        return false;
    }
    else
    {
        printf("\n------------------------- START ----------------------------\n\n");


        for (int i=0; i<tape.total_cells; i++)
        {
            /* Displaying the symbol and transition state index contained. */

            printf("Symbol = \"%s\"\n", cur_cell->sym);
            printf("Next = %p\n\n", cur_cell->next);


            /* Moving to next node in series. */

            if (cur_cell->next!=NULL) {cur_cell = cur_cell -> next;}
        }


        printf("------------------------- FINISH ----------------------------\n\n");
    }



    return true;
}