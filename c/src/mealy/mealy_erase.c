/* Including required headers. */

#include "../../include/mealy/mealy_erase.h"
#include "../../include/mealy/mealy_map/mealy_map_view.h"

#include <stdio.h>              // To access basic I/O functions
#include <stdlib.h>             // To free memory using pointers










/* Erases everything related to the particular mealy. */

mealy *mealy_erase(mealy *target_mealy, bool debug)
{
    /* Variables & constants */

    char *file = "mealy_erase.c";
    mealy_map_node *cur=NULL, *next=NULL;





    /* Freeing everything within every state. */

    for (int i=0; i<target_mealy->total_states; i++)
    {
        cur = ((target_mealy -> states) + i) -> map.head;
        

        if (debug==true)
        {
            printf(
                "STAT (%s):%d :: Freeing memory for state \"%s\" (%d transitions).\n",
                file, __LINE__, ((target_mealy->states)+i)->name, ((target_mealy->states)+i)->total_trans
            );
        }



        /* Freeing everything within every map node. */

        for (int j=0; j<((target_mealy->states)+i)->total_trans; j++)
        {
            /* Freeing members and setting next node. */

            next = cur -> next;


            if (debug==true)
            {
                printf(
                    "STAT (%s):%d :: Reviewing transition state \"%s\":next=%p.\n",
                    file, __LINE__, cur->sym, cur->next
                );
            }


            if (cur->sym!=NULL) free(cur->sym);
            free(cur);

            cur = next;
        }



        /* Freeing pointer members inside this state. */

        if (((target_mealy->states)+i)->name!=NULL)
            free(((target_mealy->states)+i)->name);
        
        else if (((target_mealy->states)+i)->output!=NULL)
            free(((target_mealy->states)+i)->output);
    }



    /* Freeing pointer members inside the mealy. */

    free(target_mealy->states);
    target_mealy -> total_states = 0;





    /* Returning address of target mealy. */

    return target_mealy;
}