/* Including required headers. */

#include "../../include/moore/moore_machine_view.h"
#include "../../include/moore/moore_elem/moore_state.h"
#include "../../include/moore/moore_map/moore_map_node.h"
#include "../../include/moore/moore_map/moore_map_ll.h"

#include <stdio.h>              // To access basic I/O functions










/* Views the complete moore at a given instant. */

void moore_machine_view(moore target_moore)
{
    /* Variables & constants */

    char *file = "moore_machine_viewer.c";
    char *model = "Deterministic Finite Automata (moore)";
    moore_state *cur_state_addr = NULL;
    moore_map_node *trav = NULL;





    /* Displaying start state & total number of transitions from moore. */

    printf("\n--------------------------------------------------------------\n");


    printf("Model = %s\n", model);
    printf("Address = %p\n", &target_moore);
    printf("Total states = %d\n", target_moore.total_states);


    if (target_moore.total_states==0)
    {
        printf("--------------------------------------------------------------\n\n");
        return;
    }


    if (target_moore.start_state<0)
    {
        printf(
            "ERROR (%s):%d :: Moore machine doesn\'t contain any START state!\n",
            file, __LINE__
        );
        printf("--------------------------------------------------------------\n\n");
    }
    else
    {
        printf("Start state = \"%s\"\n\n", (target_moore.states + target_moore.start_state)->name);
    }





    /* Displaying transitions for each state. */

    for (int i=0; i<target_moore.total_states; i++)
    {
        cur_state_addr = target_moore.states + i;
        trav = cur_state_addr -> map.head;


        printf("State name = \"%s\"\n", cur_state_addr->name);
        printf("Output symbol = \"%s\"\n", cur_state_addr->output);
        printf("Total transitions = %d\n", cur_state_addr->total_trans);
        
        if (cur_state_addr->else_trans>=0)
        {
            printf("ELSE transition = \"%s\"\n", ((target_moore.states)+(cur_state_addr->else_trans))->name);
        }



        /* Every transition that the state contains. */

        for (int j=0; j<cur_state_addr->total_trans; j++)
        {
            printf(
                "[%d]\"%s\" -> \"%s\"\n",
                j, trav->sym, ((target_moore.states)+(trav->trans))->name
            );

            trav = trav -> next;
        }

        printf("\n");
    }





    /* Closing decoration for clarity. */

    printf("--------------------------------------------------------------\n\n");
}