/* Including required headers. */

#include "../../include/moore/moore_erase.h"
#include "../../include/moore/moore_map/moore_map_view.h"

#include <stdio.h>              // To access basic I/O functions
#include <stdlib.h>             // To free memory using pointers










/* Erases everything related to the particular moore. */

moore *moore_erase(moore *target_moore, bool debug)
{
    /* Variables & constants */

    char *file = "moore_erase.c";
    moore_map_node *cur=NULL, *next=NULL;





    /* Freeing everything within every state. */

    for (int i=0; i<target_moore->total_states; i++)
    {
        cur = ((target_moore -> states) + i) -> map.head;
        

        if (debug==true)
        {
            printf(
                "STAT (%s):%d :: Freeing memory for state \"%s\" (%d transitions).\n",
                file, __LINE__, ((target_moore->states)+i)->name, ((target_moore->states)+i)->total_trans
            );
        }



        /* Freeing everything within every map node. */

        for (int j=0; j<((target_moore->states)+i)->total_trans; j++)
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

        if (((target_moore->states)+i)->name!=NULL)
            free(((target_moore->states)+i)->name);
        
        else if (((target_moore->states)+i)->output!=NULL)
            free(((target_moore->states)+i)->output);
    }



    /* Freeing pointer members inside the moore. */

    free(target_moore->states);
    target_moore -> total_states = 0;





    /* Returning address of target moore. */

    return target_moore;
}