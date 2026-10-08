/* Including required headers. */

#include "../../include/dfa/dfa_machine_view.h"
#include "../../include/dfa/dfa_elem/dfa_state.h"
#include "../../include/dfa/dfa_map/dfa_map_node.h"
#include "../../include/dfa/dfa_map/dfa_map_ll.h"

#include <stdio.h>              // To access basic I/O functions










/* Views the complete DFA at a given instant. */

void dfa_machine_view(dfa target_dfa)
{
    /* Variables & constants */

    char *file = "dfa_viewer.c";
    char *model = "Deterministic Finite Automata (DFA)";
    dfa_state *cur_state_addr = NULL;
    dfa_map_node *trav = NULL;





    /* Displaying start state & total number of transitions from DFA. */

    printf("\n--------------------------------------------------------------\n");


    printf("Model = %s\n", model);
    printf("Address = %p\n", &target_dfa);
    printf("Total states = %d\n", target_dfa.total_states);


    if (target_dfa.total_states==0)
    {
        printf("--------------------------------------------------------------\n\n");
        return;
    }


    printf("Start state = \"%s\"\n\n", (target_dfa.states + target_dfa.start_state)->name);





    /* Displaying transitions for each state. */

    for (int i=0; i<target_dfa.total_states; i++)
    {
        cur_state_addr = target_dfa.states + i;
        trav = cur_state_addr -> map.head;


        printf("State name = \"%s\"\n", cur_state_addr->name);
        printf("Total transitions = %d\n", cur_state_addr->total_trans);
        printf("ELSE transition = \"%s\"\n", ((target_dfa.states)+(cur_state_addr->else_trans))->name);



        /* Every transition that the state contains. */

        for (int j=0; j<cur_state_addr->total_trans; j++)
        {
            printf(
                "[%d]\"%s\" -> \"%s\"\n",
                j, trav->sym, ((target_dfa.states)+(trav->trans))->name
            );

            trav = trav -> next;
        }

        printf("\n");
    }





    /* Closing decoration for clarity. */

    printf("--------------------------------------------------------------\n\n");
}