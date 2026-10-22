/* Including required headers. */

#include "../../include/mealy/mealy_machine_view.h"
#include "../../include/mealy/mealy_elem/mealy_state.h"
#include "../../include/mealy/mealy_map/mealy_map_node.h"
#include "../../include/mealy/mealy_map/mealy_map_ll.h"

#include <stdio.h>              // To access basic I/O functions










/* Views the complete MEALY at a given instant. */

void mealy_machine_view(mealy target_mealy)
{
    /* Variables & constants */

    char *file = "mealy_viewer.c";
    char *model = "Deterministic Finite Automata (MEALY)";
    mealy_state *cur_state_addr = NULL;
    mealy_map_node *trav = NULL;





    /* Displaying start state & total number of transitions from MEALY. */

    printf("\n--------------------------------------------------------------\n");


    printf("Model = %s\n", model);
    printf("Address = %p\n", &target_mealy);
    printf("Total states = %d\n", target_mealy.total_states);


    if (target_mealy.total_states==0)
    {
        printf("--------------------------------------------------------------\n\n");
        return;
    }


    printf("Start state = \"%s\"\n\n", (target_mealy.states + target_mealy.start_state)->name);





    /* Displaying transitions for each state. */

    for (int i=0; i<target_mealy.total_states; i++)
    {
        cur_state_addr = target_mealy.states + i;
        trav = cur_state_addr -> map.head;


        printf("State name = \"%s\"\n", cur_state_addr->name);
        printf("Total transitions = %d\n", cur_state_addr->total_trans);
        
        if (cur_state_addr->else_trans>=0)
        {
            printf("ELSE transition = \"%s\"\n", ((target_mealy.states)+(cur_state_addr->else_trans))->name);
        }



        /* Every transition that the state contains. */

        for (int j=0; j<cur_state_addr->total_trans; j++)
        {
            printf(
                "[%d]\"%s\" -> \"%s\"\n",
                j, trav->sym, ((target_mealy.states)+(trav->trans))->name
            );

            trav = trav -> next;
        }

        printf("\n");
    }





    /* Closing decoration for clarity. */

    printf("--------------------------------------------------------------\n\n");
}