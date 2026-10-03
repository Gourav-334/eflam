/* Including required headers. */

#include "../include/dfa/dfa_func/dfa_state_type_insp.h"

#include <stdio.h>





/* Main function for testing. */

int main(int argc, char *argv[])
{
    /* Code to be tested. */

    dfa_state my_state = {
        .name = NULL,
        .type[0] = 0,
        .type[1] = 1,
        .symbols = NULL,
        .trans = NULL,
        .else_trans = NULL,
        .total_trans = 0
    };

    dfa_state_type_insp(&my_state, "accept", true);
    dfa_state_type_insp(&my_state, "A", true);
    dfa_state_type_insp(&my_state, "start", true);
    dfa_state_type_insp(&my_state, "S", true);



    





    /* Returning normal status. */

    return 0;
}