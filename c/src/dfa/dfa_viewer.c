/* Including required headers. */

#include "../../include/dfa/dfa_viewer.h"
#include "../../include/dfa/dfa_elem/dfa_state.h"

#include <stdio.h>              // To access basic I/O functions










/* Views the complete DFA at a given instant. */

void dfa_viewer(dfa target_dfa)
{
    /* Variables & constants */

    char *file = "dfa_viewer.c";
    char *model = "Deterministic Finite Automata (DFA)";
    dfa_state *cur_state_addr = NULL;





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
        printf("State name = \"%s\"\n", cur_state_addr->name);
        printf("Total transitions = %d\n", cur_state_addr->total_trans);


        /* Every transition that the state contains. */

        for (int j=0; j<cur_state_addr->total_trans; j++)
        {
            printf(
                "[%d] \"%s\" -> \"\"\n",
                j, *((cur_state_addr->symbols)+j),
                ((target_dfa.states)+(*((cur_state_addr->trans)+j)))->name
            );
        }
    }





    /* Closing decoration for clarity. */

    printf("--------------------------------------------------------------\n\n");
}