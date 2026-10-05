/* Including required headers. */

#include "../include/dfa/dfa_create.h"
#include "../include/dfa/dfa_elem/dfa_unit.h"
#include "../include/dfa/dfa_elem/dfa_state.h"

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

    char *filepaths[] = {"eflam_codes/print.eflam"};
    dfa_create(&my_dfa, filepaths, 1, true);




    





    /* Returning normal status. */

    return 0;
}