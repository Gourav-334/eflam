/* Including required headers. */

#include "../include/dfa/dfa_func/dfa_cur_state_insp.h"

#include <stdio.h>





/* Main function for testing. */

int main(int argc, char *argv[])
{
    /* Code to be tested. */

    /*
        bool dfa_cur_state_insp(
            dfa *target_dfa,                            // Target DFA machine
            char *cur_state_name,                       // Current state name
            dfa_state **cur_state_addr,                 // Address of current state
            bool debug                                  // Debugging mode (ON/OFF)
        );
    */

    dfa target_dfa = {
        .start_state = NULL,
        .total_states = 0,
        .states = NULL
    };

    dfa_state *cur_state_addr = NULL;
    
    dfa_cur_state_insp(&target_dfa, "Gourav", &cur_state_addr, true);
    dfa_cur_state_insp(&target_dfa, "Kumar", &cur_state_addr, true);
    dfa_cur_state_insp(&target_dfa, "Mallick", &cur_state_addr, true);
    dfa_cur_state_insp(&target_dfa, "Kumar", &cur_state_addr, true);



    





    /* Returning normal status. */

    return 0;
}