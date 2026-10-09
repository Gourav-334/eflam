/* Including required headers. */

#include "../include/dfa/dfa_create.h"
#include "../include/dfa/dfa_str_test.h"
#include "../include/dfa/dfa_machine_view.h"
#include "../include/dfa/dfa_elem/dfa_unit.h"
#include "../include/dfa/dfa_elem/dfa_state.h"
#include "../include/dfa/dfa_map/dfa_add_sym.h"
#include "../include/dfa/dfa_map/dfa_map_view.h"
#include "../include/dfa/dfa_map/dfa_add_trans.h"
#include "../include/utils/char_serial.h"

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