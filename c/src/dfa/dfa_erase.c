/* Including required headers. */

#include "../../include/dfa/dfa_erase.h"
#include "../../include/dfa/dfa_map/dfa_map_view.h"

#include <stdio.h>              // To access basic I/O functions
#include <stdlib.h>             // To free memory using pointers










/* Erases everything related to the particular DFA. */

dfa *dfa_erase(dfa *target_dfa, bool debug)
{
    /* Variables & constants */

    char *file = "dfa_erase.c";
    dfa_map_node *cur=NULL, *next=NULL;





    /* Freeing everything within every state. */

    for (int i=0; i<target_dfa->total_states; i++)
    {
        cur = ((target_dfa -> states) + i) -> map.head;
        

        if (debug==true)
        {
            printf(
                "STAT (%s):%d :: Freeing memory for state \"%s\" (%d transitions).\n",
                file, __LINE__, ((target_dfa->states)+i)->name, ((target_dfa->states)+i)->total_trans
            );
        }



        /* Freeing everything within every map node. */

        for (int j=0; j<((target_dfa->states)+i)->total_trans; j++)
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

        if (((target_dfa->states)+i)->name!=NULL)
            free(((target_dfa->states)+i)->name);
    }



    /* Freeing pointer members inside the DFA. */

    free(target_dfa->states);
    target_dfa -> total_states = 0;





    /* Returning address of target DFA. */

    return target_dfa;
}