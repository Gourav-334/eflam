/* List of included headers. */

#include "../../../include/reg_lang/det_finite_auto/dfa_erase.h"










/* Function to erase all memory for the given DFA. */

void dfa_erase(dfa *target_dfa, char *str)
{
    /* Outermost loop which iterates over every state the DFA contains. */

    for (int i=0; i<(target_dfa->total_states); i++)
    {
        free((target_dfa->states+i)->name);


        /* Inner loop that iterates over every transitions that each state stores. */

        for (int i2=0; i2<(target_dfa->states+i)->total_trans; i2++)
        {
            free(((target_dfa->states+i)->symbols+i2));
            free(((target_dfa->states+i)->transitions+i2));
        }
    }


    /* Freeing the string and array of pointers to state. */

    free(target_dfa->states); free(str);
}