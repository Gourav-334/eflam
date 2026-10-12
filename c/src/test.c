/* Including required headers. */

#include "../include/eflam_dfa.h"

#include <stdio.h>





/* Main function for testing. */

int main(int argc, char *argv[])
{
    /* Code to be tested. */

    dfa my_dfa = {
        .start_state = -1,
        .total_states = 0,
        .states = NULL
    };

    dfa_state *output = NULL;
    char *filepaths[] = {"eflam_codes/print.eflam"};

    dfa_create(&my_dfa, filepaths, 1, true);




    





    /* Returning normal status. */

    return 0;
}