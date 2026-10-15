/* Including required headers */

#include "../../../include/dfa/dfa_func/dfa_trans_state_insp.h"
#include "../../../include/dfa/dfa_map/dfa_add_trans.h"

#include <stdio.h>          // To get access to basic I/O functions
#include <stdlib.h>         // To manage dynamically allocated memory
#include <string.h>         // To copy & measure length of string










/* Checks if a transition state exists or need to be created. */

bool dfa_trans_state_insp(
    dfa *target_dfa, int cur_state_index,
    char *trans_state_name, int *total_sym,
    bool debug
)
{
    /* Variables & constants */

    char *file = "dfa_trans_state_insp.c";
    bool exists = false;                    // Indicates if a state already exists or not.
    void *alloc_ret = NULL;                 // Allocation return value checker.
    int trans_state_index;                  // Relative index of transition state.
    dfa_state *cur_state_addr = (target_dfa -> states) + cur_state_index;
    dfa_state *trans_state_addr = NULL;





    /* Copying data for future references. */

    for (int i=0; i<target_dfa->total_states; i++)
    {
        /* If state is found already existing in DFA. */

        if (!strcmp(((target_dfa->states)+i)->name, trans_state_name))
        {
            trans_state_index = i;

            if (debug==true)
            {
                printf("STAT (%s):%d :: State \"%s\" already exists.\n", file, __LINE__, trans_state_name);
            }

            exists = true;
            break;
        }
        else if (debug==true)
        {
            printf("OK (%s):%d :: State \"%s\" not found yet on [%d] attempts.\n", file, __LINE__, trans_state_name, i);
        }
    }





    /* Proceeding as per whether the state exists or not. */

    if (exists==false)
    {
        /* Checking if its first state in DFA or not. */

        if (target_dfa->total_states==0)
        {
            /* Creating the first state. */

            target_dfa -> states = malloc(sizeof(dfa_state));


            /* Sending debugging information. */

            if (target_dfa->states==NULL)
            {
                printf("ERROR (%s):%d :: Memory allocation failed for first state \"%s\"!\n", file, __LINE__, trans_state_name);
                
                return false;
            }
            else if (debug==true)
            {
                printf("OK (%s):%d :: Memory allocation successful for first state \"%s\".\n", file, __LINE__, trans_state_name);
            }
        }
        else
        {
            /* Extending the number of states. */

            alloc_ret = realloc(
                target_dfa->states,
                (size_t)((target_dfa->total_states)+1)*sizeof(dfa_state)
            );


            /* Sending debugging information. */

            if (alloc_ret==NULL)
            {
                printf("ERROR (%s):%d :: Memory allocation failed for new state \"%s\"!\n", file, __LINE__, trans_state_name);

                return false;
            }
            else
            {
                /* Making sure that `target_dfa->states` reflects new address. */

                target_dfa -> states = alloc_ret;       // Ultimate NIGHTMARE!
                cur_state_addr = (target_dfa -> states) + cur_state_index;


                if (debug==true)
                {
                    printf("OK (%s):%d :: Memory allocation successful for new state \"%s\".\n", file, __LINE__, trans_state_name);
                }
            }
        }



        /* Setting up the state with attributes. */

        (target_dfa -> total_states)++;     // Incrementing total state counts
        trans_state_index = (target_dfa -> total_states) - 1;
        trans_state_addr = (target_dfa -> states) + trans_state_index;



        /* Giving name to the new state. */

        trans_state_addr -> name = malloc(sizeof(char)*(size_t)(strlen(trans_state_name)+1));

        if (trans_state_addr->name==NULL)
        {
            printf("ERROR (%s):%d :: Memory allocation failed for state name \"%s\"!\n", file, __LINE__, trans_state_name);

            return false;
        }
        else if (debug==true)
        {
            printf("OK (%s):%d :: Memory allocation successful for state name \"%s\".\n", file, __LINE__, trans_state_name);
        }

        strncpy(trans_state_addr->name, trans_state_name, (size_t)(strlen(trans_state_name)+1));



        /* Setting up state type. */

        trans_state_addr -> type[START_STATE] = 0;
        trans_state_addr -> type[ACCEPT_STATE] = 0;



        /* Setting pointers initially to NULL. */

        trans_state_addr -> map.head = NULL;
        trans_state_addr -> map.tail = NULL;
        trans_state_addr -> else_trans = -1;
        trans_state_addr -> total_trans = 0;
    }





    /* Allocating memory to append index to transitioning state. */

    dfa_add_trans(
        &(cur_state_addr->map),
        trans_state_index,
        (cur_state_addr->total_trans)-(*total_sym),
        (cur_state_addr->total_trans)-1,
        debug
    );


    /* Incrementing number of transitions. */

    *total_sym = 0;



    /* Final debug information. */

    if (debug==true)
    {
        printf("STAT (%s):%d :: total_trans=%d\n", file, __LINE__, cur_state_addr->total_trans);
    }



    

    /* Returning TRUE for successful execution. */

    return true;
}