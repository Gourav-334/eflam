/* Including required headers. */

#include "../include/dfa/dfa_func/dfa_sym_pump_insp.h"

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

    int total_sym = 0;

    dfa_sym_pump_insp(&my_state, "ALPHA", &total_sym, true);
    dfa_sym_pump_insp(&my_state, "BETA", &total_sym, true);
    dfa_sym_pump_insp(&my_state, "CHARLIE", &total_sym, true);
    dfa_sym_pump_insp(&my_state, "BETA", &total_sym, true);
    dfa_sym_pump_insp(&my_state, "ALPHA", &total_sym, true);
    dfa_sym_pump_insp(&my_state, "DELTA", &total_sym, true);



    





    /* Returning normal status. */

    return 0;
}