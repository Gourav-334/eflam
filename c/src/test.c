/* Including required headers. */

#include "../include/dfa/dfa_create.h"
#include "../include/dfa/dfa_str_test.h"
#include "../include/dfa/dfa_viewer.h"
#include "../include/dfa/dfa_elem/dfa_unit.h"
#include "../include/dfa/dfa_elem/dfa_state.h"

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

    char *filepaths[] = {"eflam_codes/print.eflam"};

    char *symbols[] = {"print", "(", "\"", "GOURAV", "\"", ")"};
    char *symbols2[] = {"print", "\"", "KUMAR", "\"", ")"};
    char *symbols3[] = {"print", "(", "\"", "GOURAV", "\"", ")", ";"};
    char *symbols4[] = {"print", "(", "\"", "\"", ")"};
    char *symbols5[] = {"print", "(", "\"", "GOURAV", "\"", "\t", ")"};

    dfa_create(&my_dfa, filepaths, 1, true);
    
    for (int i=0; i<my_dfa.total_states; i++)
    {
        printf("(my_dfa.states + %d)->name = \"%s\"\n", i, (my_dfa.states + i)->name);
    }

    printf("\n");

    for (int i=0; i<10; i++)
    {
        printf(
            "*(((my_dfa.states + 0) -> symbols) + %d) = \"%s\"\n",
            i,
            *(((my_dfa.states + 0) -> symbols) + i)
        );
    }

    // dfa_str_test(my_dfa, symbols, 6, true);
    // dfa_str_test(my_dfa, symbols2, 5, true);
    // dfa_str_test(my_dfa, symbols3, 7, true);
    // dfa_str_test(my_dfa, symbols4, 5, true);
    // dfa_str_test(my_dfa, symbols5, 7, true);




    





    /* Returning normal status. */

    return 0;
}