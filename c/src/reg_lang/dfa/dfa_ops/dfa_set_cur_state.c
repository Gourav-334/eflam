/* Including required headers. */

#include "../../../../include/reg_lang/dfa/dfa_ops/dfa_set_cur_state.h"

#include <stdio.h>              // To allow usage of NULL.










/* Used for creating a state if it doesn't exist yet. */

bool dfa_fix_cur_state(
    dfa *target_dfa, char *name, int *name_size,
    char *cur_state_name, int *cur_state_size, dfa_state *cur_state_addr,
    bool debug
)
{
    /* Variables & constants */

    bool exists = false;        // Indicates if a state already exists or not.
    void *alloc_ret = NULL;     // Allocation return value checker.





    /* Copying data for future references. */

    *cur_state_size = (int)strlen(name);                            // Storing name size of current state
    cur_state_name = malloc(sizeof(char)*(*cur_state_size + 1));    // Memalloc for storing name

    if (cur_state_name==NULL)
    {
        printf("ERROR (%s): Problem allocating memory for cur_state_name\n", __FILE__);
    }

    strcpy(cur_state_name,name);                                    // Storing current state name





    /* Checking if current state already exists. */

    for (int i=0; i<target_dfa->total_states; i++)
    {
        /* If existing state is found. */

        if (!strcmp(((target_dfa->states)+i)->name,name))
        {
            exists = true;                                  // Updating flag indicating state's existence.
            cur_state_addr = (target_dfa->states)+i;        // Recording address of current state.
        }
    }





    /* If the state is non-existing & thus new, create & initiate it. */

    if (exists==false)
    {
        /* Creating new state & updating DFA records. */

        cur_state_addr = malloc(sizeof(dfa_state));         // Memory allocation for new state.
        (target_dfa -> total_states)++;                     // Incrementing total number of states.


        /* Extending array of states that DFA contains & storing. */

        if (target_dfa->total_states==1)
        {
            target_dfa -> states = malloc(sizeof(dfa_state*));

            if (target_dfa->states==NULL)
            {
                printf("ERROR (%s): Memory allocation failure for (target_dfa->states).\n", __FILE__);
            }
        }
        else        /* If states already exist, requiring realloc(), not malloc(). */
        {
            alloc_ret = realloc(target_dfa->states, sizeof(dfa_state*)*(target_dfa->total_states));

            if (alloc_ret==NULL)
            {
                printf("ERROR (%s): Memory reallocation failure for (target_dfa->states).\n", __FILE__);
            }
        }



        /* Setting configuration for this newly created state. */

        cur_state_addr -> name = malloc(sizeof(char)*(*cur_state_size + 1));    // Malloc for storing name.

        if (cur_state_addr->name==NULL)
        {
            printf("ERROR (%s): Memory allocation failure for (cur_state_addr->name).\n", __FILE__);
        }


        cur_state_addr -> symbols = NULL;
        cur_state_addr -> trans = NULL;
        cur_state_addr -> else_trans = NULL;
        cur_state_addr -> total_trans = 0;
    }
}