/* Including required headers. */

#include "../include/eflam_dfa.h"
#include "../include/eflam_moore.h"

#include <stdio.h>





/* Main function for testing. */

int main(int argc, char *argv[])
{
    /* Code to be tested. */

    moore my_moore = {.start_state = -1, .total_states = 0, .states = NULL};
    sym_tape_ll tape = {.head = NULL, .tail = NULL, .total_cells = 0};

    char *filepaths[] = {"eflam_codes/print.eflam"};
    char *symbols1[] = {"print", "(", " ", "\t", "\"", "\""};
    char *symbols2[] = {"print", "\n", "(", " ", "\t", "\"", "let", "\"", ")", "\n", "print"};

    moore_create(&my_moore, filepaths, 1, true);
    moore_machine_view(my_moore);
    
    //moore_str_test(my_moore, symbols1, &tape, 6, true);
    moore_str_test(my_moore, symbols2, &tape, 11, true);
    sym_tape_view(tape);




    





    /* Returning normal status. */

    return 0;
}