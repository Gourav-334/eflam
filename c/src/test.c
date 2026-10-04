/* Including required headers. */

#include "../include/dfa/dfa_func/dfa_sym_pump_insp.h"
#include "../include/dfa/dfa_func/dfa_trans_state_insp.h"
#include "../include/dfa/dfa_func/dfa_other_sym_insp.h"

#include <stdio.h>





/* Main function for testing. */

int main(int argc, char *argv[])
{
    /* Code to be tested. */

    dfa_state my_state = {
        .name = "Duniya Ka Papa!",
        .type[0] = 0,
        .type[1] = 0,
        .symbols = NULL,
        .trans = NULL,
        .else_trans = NULL,
        .total_trans = 0
    };

    dfa my_dfa = {
        .start_state = NULL,
        .total_states = 0,
        .states = &my_state
    };

    int total_sym = 0;

    dfa_sym_pump_insp(&my_state, "ALPHA", &total_sym, false);
    dfa_sym_pump_insp(&my_state, "BETA", &total_sym, false);
    dfa_sym_pump_insp(&my_state, "CHARLIE", &total_sym, false);
    dfa_sym_pump_insp(&my_state, "BETA", &total_sym, false);
    dfa_sym_pump_insp(&my_state, "ALPHA", &total_sym, false);
    dfa_sym_pump_insp(&my_state, "DELTA", &total_sym, false);

    dfa_trans_state_insp(&my_dfa, &my_state, "q6", &total_sym, true);
    
    dfa_other_sym_insp(&my_dfa, &my_state, "q7", true);
    dfa_other_sym_insp(&my_dfa, &my_state, "q8", true);
    dfa_other_sym_insp(&my_dfa, &my_state, "q7", true);




    





    /* Returning normal status. */

    return 0;
}