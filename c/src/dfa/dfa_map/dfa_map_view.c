/* Including required headers. */

#include "../../../include/dfa/dfa_map/dfa_map_view.h"

#include <stdio.h>              // To access basic I/O functions










/* Used for viewing everything that the map contains. */

bool dfa_map_view(dfa_map_ll map)
{
    /* Variables & constants */

    char *file = "dfa_map_view.c";
    dfa_map_node *cur_node = map.head;





    /* Checking if data are corrupted in anyway. */

    if (map.total_nodes<0)
    {
        printf(
            "ERROR (%s):%d :: Total nodes can\'t be less than %d, data corrupted!\n",
            file, __LINE__, 0
        );

        return false;
    }
    else if (map.total_nodes==0 && (map.head!=NULL || map.tail!=NULL))
    {
        printf(
            "ERROR (%s):%d :: Pointers must be NULL when there are no nodes, data corrupted!\n",
            file, __LINE__
        );

        return false;
    }
    else if (map.total_nodes>0 && (map.head==NULL || map.tail==NULL))
    {
        printf(
            "ERROR (%s):%d :: Pointers can't be NULL when there are nodes, data corrupted!\n",
            file, __LINE__
        );

        return false;
    }
    else
    {
        printf("\n------------------------- START ----------------------------\n\n");


        for (int i=0; i<map.total_nodes; i++)
        {
            /* Displaying the symbol and transition state index contained. */

            printf("Symbol = \"%s\"\n", cur_node->sym);
            printf("Transition index = %d\n", cur_node->trans);
            printf("Next = %p\n\n", cur_node->next);


            /* Moving to next node in series. */

            if (cur_node->next!=NULL) {cur_node = cur_node -> next;}
        }


        printf("------------------------- FINISH ----------------------------\n\n");
    }



    return true;
}