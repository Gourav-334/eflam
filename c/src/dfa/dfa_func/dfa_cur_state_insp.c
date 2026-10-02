/* Including required headers. */

#include "../../../include/dfa/dfa_func/dfa_cur_state_insp.h"

#include <stdio.h>              // To allow usage of NULL.
#include <stdlib.h>             // To manage dynamic memory.
#include <string.h>             // To access string-related facilities.










/* Used for creating a state if it doesn't exist yet. */

bool dfa_cur_state_insp(
    dfa *target_dfa, char *cur_state_name, dfa_state **cur_state_addr,
    bool debug
)
{
    /* Variables & constants */

    char *file = "dfa_cur_state_insp.c\0";
    bool exists = false;        // Indicates if a state already exists or not.
    void *alloc_ret = NULL;     // Allocation return value checker.





    /* Copying data for future references. */

    for (int i=0; i<target_dfa->total_states; i++)
    {
        /* If state is found already existing in DFA. */

        if (!strcmp(((target_dfa->states)+i)->name,cur_state_name))
        {
            if (debug==true)
            {
                printf("STAT (%s):%d :: State \"%s\" already exists.\n", file, __LINE__, cur_state_name);
            }

            *cur_state_addr = (target_dfa -> states) + i;

            exists = true;
            break;
        }
    }





    /* Proceeding as per whether the state exists or not. */

    if (exists==false)
    {
        /* Checking if its first state in DFA or not. */

        if (target_dfa->total_states==0)
        {
            /* Creating the first state. */

            target_dfa -> states = malloc(sizeof(dfa_state*));


            /* Sending debugging information. */

            if (target_dfa->states==NULL)
            {
                printf("ERROR (%s):%d :: Memory allocation failed for first state \"%s\"!\n", file, __LINE__, cur_state_name);
            }
            else if (debug==true)
            {
                printf("OK (%s):%d :: Memory allocation successful for first state \"%s\".\n", file, __LINE__, cur_state_name);
            }
        }
        else
        {
            /* Extending the number of states. */

            alloc_ret = realloc(
                target_dfa->states,
                (size_t)((target_dfa->total_states)+1)*sizeof(dfa_state*)
            );


            /* Sending debugging information. */

            if (alloc_ret==NULL)
            {
                printf("ERROR (%s):%d :: Memory allocation failed for new state \"%s\"!\n", file, __LINE__, cur_state_name);
            }
            else if (debug==true)
            {
                printf("OK (%s):%d :: Memory allocation successful for new state \"%s\".\n", file, __LINE__, cur_state_name);
            }
        }



        /* Setting up the state with attributes. */

        (target_dfa -> total_states)++;     // Incrementing total state counts
        *cur_state_addr = (target_dfa -> states) + (target_dfa -> total_states - 1);



        /* Giving name to the new state. */

        (*cur_state_addr) -> name = malloc(sizeof(char)*(size_t)strlen(cur_state_name));

        if ((*cur_state_addr)->name==NULL)
        {
            printf("ERROR (%s):%d :: Memory allocation failed for state name \"%s\"!\n", file, __LINE__, cur_state_name);
        }
        else if (debug==true)
        {
            printf("OK (%s):%d :: Memory allocation successful for state name \"%s\".\n", file, __LINE__, cur_state_name);
        }

        strcpy((*cur_state_addr)->name, cur_state_name);



        /* Setting up state type. */

        (*cur_state_addr) -> type[START_STATE] = 0;
        (*cur_state_addr) -> type[ACCEPT_STATE] = 0;



        /* Setting pointers initially to NULL. */

        (*cur_state_addr) -> symbols = NULL;
        (*cur_state_addr) -> trans = NULL;
        (*cur_state_addr) -> else_trans = NULL;
        (*cur_state_addr) -> total_trans = 0;
    }
}