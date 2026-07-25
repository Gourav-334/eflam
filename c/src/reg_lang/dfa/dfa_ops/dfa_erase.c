/* List of included headers. */

#include "../../../include/reg_lang/dfa/dfa_ops/dfa_erase.h"
#include <stdio.h>          // For using NULL










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
            free(((target_dfa->states+i)->name));
            free(((target_dfa->states+i)->symbols+i2));
            free(((target_dfa->states+i)->trans+i2));
            free(((target_dfa->states+i)->else_trans));
        }
    }


    /* Freeing the string and array of pointers to state. */

    if (target_dfa->start_state!=NULL) {free(target_dfa->start_state);}
    else if (target_dfa->states!=NULL) {free(target_dfa->states);}
    else if (str!=NULL) {free(str);}
}