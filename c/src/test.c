/* Including required headers. */

#include "../include/dfa/dfa_create.h"
#include "../include/dfa/dfa_str_test.h"
#include "../include/dfa/dfa_viewer.h"
#include "../include/dfa/dfa_elem/dfa_unit.h"
#include "../include/dfa/dfa_elem/dfa_state.h"
#include "../include/dfa/dfa_map/dfa_add_sym.h"
#include "../include/dfa/dfa_map/dfa_map_view.h"
#include "../include/dfa/dfa_map/dfa_add_trans.h"

#include <stdio.h>





/* Main function for testing. */

int main(int argc, char *argv[])
{
    /* Code to be tested. */

    // dfa my_dfa = {
    //     .start_state = -1,
    //     .total_states = 0,
    //     .states = NULL
    // };

    // char *filepaths[] = {"eflam_codes/print.eflam"};

    // char *symbols[] = {"print", "(", "\"", "GOURAV", "\"", ")"};
    // char *symbols2[] = {"print", "\"", "KUMAR", "\"", ")"};
    // char *symbols3[] = {"print", "(", "\"", "GOURAV", "\"", ")", ";"};
    // char *symbols4[] = {"print", "(", "\"", "\"", ")"};
    // char *symbols5[] = {"print", "(", "\"", "GOURAV", "\"", "\t", ")"};

    // dfa_create(&my_dfa, filepaths, 1, true);
    // dfa_viewer(my_dfa);

    // dfa_str_test(my_dfa, symbols, 6, true);
    // dfa_str_test(my_dfa, symbols2, 5, true);
    // dfa_str_test(my_dfa, symbols3, 7, true);
    // dfa_str_test(my_dfa, symbols4, 5, true);
    // dfa_str_test(my_dfa, symbols5, 7, true);





    dfa_map_ll my_map = {
        .head = NULL,
        .tail = NULL,
        .total_nodes = 0
    };

    dfa_add_sym(&my_map, "Mr.", false);
    dfa_add_sym(&my_map, "Gourav", false);
    dfa_add_sym(&my_map, "Kumar", false);
    dfa_add_sym(&my_map, "Mallick", false);
    dfa_map_view(my_map);

    dfa_add_trans(&my_map, 111, 1, 8, false);
    dfa_map_view(my_map);
    dfa_add_trans(&my_map, 222, 3, 1, false);
    dfa_map_view(my_map);
    dfa_add_trans(&my_map, 333, 1, 1, false);
    dfa_map_view(my_map);
    dfa_add_trans(&my_map, 444, 0, 2, false);
    dfa_map_view(my_map);
    dfa_add_trans(&my_map, 555, 0, 3, false);
    dfa_map_view(my_map);




    





    /* Returning normal status. */

    return 0;
}