/* Including required headers. */

#include "../include/eflam_mealy.h"
#include "../include/eflam_utils.h"

#include <stdio.h>





/* Main function for testing. */

int main(int argc, char *argv[])
{
    /* Code to be tested. */

    mealy my_mealy = {.start_state = -1, .total_states = 0, .states = NULL};
    sym_tape_ll tape = {.head = NULL, .tail = NULL, .total_cells = 0};

    char *filepaths[] = {"eflam_codes/print.eflam"};
    char *symbols1[] = {"print", "(", " ", "\t", "\"", "\""};
    char *symbols2[] = {"print", "\n", "(", " ", "\t", "\"", "let", "\"", ")", "\n", "print"};

    mealy_create(&my_mealy, filepaths, 1, true);
    mealy_machine_view(my_mealy);
    
    //mealy_str_test(my_mealy, symbols1, &tape, 6, true);
    mealy_str_test(my_mealy, symbols2, &tape, 11, true);
    sym_tape_view(tape);




    





    /* Returning normal status. */

    return 0;
}