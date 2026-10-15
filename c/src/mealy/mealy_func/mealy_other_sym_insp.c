/* Including required headers. */

#include "../../../include/mealy/mealy_func/mealy_other_sym_insp.h"

#include <stdio.h>              // To access basic I/O functions
#include <stdlib.h>             // To dynamically allocate memories
#include <string.h>             // To copy & measure string names










/* Sets transition to a state for the remaining symbols. */

bool mealy_other_sym_insp (
    mealy *target_mealy, int cur_state_index,
    char *trans_state_name,
    bool debug
)
{
    /* Variables & constants */

    char *file = "mealy_other_sym_insp.c";
    bool exists = false;                    // Indicates if a state already exists or not.
    void *alloc_ret = NULL;                 // Allocation return value checker.
    int trans_state_index;                  // Relative index of transition state.
    mealy_state *cur_state_addr = (target_mealy -> states) + cur_state_index;
    mealy_state *trans_state_addr = NULL;





    /* Checking if ELSE transition already exists. */

    if (cur_state_addr->else_trans<0)
    {
        /* Copying data for future references. */

        for (int i=0; i<target_mealy->total_states; i++)
        {
            /* If state is found already existing in mealy. */

            if (!strcmp(((target_mealy->states)+i)->name, trans_state_name))
            {
                trans_state_index = i;

                if (debug==true)
                {
                    printf("STAT (%s):%d :: State \"%s\" already exists.\n", file, __LINE__, trans_state_name);
                }

                exists = true;
                break;
            }
        }



        /* Proceeding as per whether the state exists or not. */

        if (exists==false)
        {
            /* Checking if its first state in mealy or not. */

            if (target_mealy->total_states==0)
            {
                /* Creating the first state. */

                target_mealy -> states = malloc(sizeof(mealy_state));


                /* Sending debugging information. */

                if (target_mealy->states==NULL)
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
                    target_mealy->states,
                    (size_t)((target_mealy->total_states)+1)*sizeof(mealy_state)
                );


                /* Sending debugging information. */

                if (alloc_ret==NULL)
                {
                    printf("ERROR (%s):%d :: Memory allocation failed for new state \"%s\"!\n", file, __LINE__, trans_state_name);

                    return false;
                }
                else
                {
                    /* Making sure that `target_mealy->states` reflects new address. */

                    target_mealy -> states = alloc_ret;       // Ultimate NIGHTMARE!
                    cur_state_addr = (target_mealy -> states) + cur_state_index;


                    if (debug==true)
                    {
                        printf("OK (%s):%d :: Memory allocation successful for new state \"%s\".\n", file, __LINE__, trans_state_name);
                    }
                }
            }



            /* Setting up the state with attributes. */

            (target_mealy -> total_states)++;     // Incrementing total state counts
            trans_state_index = (target_mealy -> total_states) - 1;
            trans_state_addr = (target_mealy -> states) + trans_state_index;



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





        /* Setting the state as ELSE transition of current state. */

        cur_state_addr -> else_trans = trans_state_index;



        /* Final debugging information. */

        if (debug==true)
        {
            printf("OK (%s):%d :: ELSE transition for state \"%s\" set up.\n", file, __LINE__, cur_state_addr->name);
        }
    }
    else
    {
        printf("ERROR (%s):%d :: ELSE transition for state \"%s\" already exists!\n", file, __LINE__, cur_state_addr->name);

        return false;
    }





    /* Returning TRUE for successful execution. */

    return true;
}