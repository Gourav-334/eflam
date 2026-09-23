/* Including required headers. */

#include "../include/dfa/dfa_create.h"

#include <stdio.h>
#include <stdlib.h>





/* Main function for testing. */

int main(int argc, char *argv[])
{
    /* Code to be tested. */

    dfa simple_lang = {
        .start_state = NULL,
        .states = NULL,
        .total_states = 0
    };

    char *filepaths[] = {"eflam_codes/print.eflam", "eflam_codes/operations.eflam"};

    dfa_create(&simple_lang, filepaths, 2, true);





    /* Returning normal status. */

    return 0;
}