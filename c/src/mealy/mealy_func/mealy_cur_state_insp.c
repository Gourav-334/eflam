/* Including required headers. */

#include "../../../include/mealy/mealy_func/mealy_cur_state_insp.h"

#include <stdio.h>              // To allow usage of NULL.
#include <stdlib.h>             // To manage dynamic memory.
#include <string.h>             // To access string-related facilities.










/* Used for creating a state if it doesn't exist yet. */

bool mealy_cur_state_insp(
    mealy *target_mealy, char *cur_state_name, int *cur_state_index,
    bool debug
)
{
    /* Variables & constants */

    char *file = "mealy_cur_state_insp.c";
    bool exists = false;                // Indicates if a state already exists or not.
    void *alloc_ret = NULL;             // Allocation return value checker.
    mealy_state *cur_state_addr = NULL;   // Current state's address





    /* Copying data for future references. */

    for (int i=0; i<target_mealy->total_states; i++)
    {
        /* If state is found already existing in mealy. */

        if (!strcmp(((target_mealy->states)+i)->name, cur_state_name))
        {
            if (debug==true)
            {
                printf("STAT (%s):%d :: Current state \"%s\" already exists.\n", file, __LINE__, cur_state_name);
            }

            cur_state_addr = (target_mealy -> states) + i;
            *cur_state_index = i;

            exists = true;
            break;
        }
        else if (debug==true)
        {
            printf("OK (%s):%d :: Current state \"%s\" not found yet.\n", file, __LINE__, cur_state_name);
        }
    }





    /* Proceeding as per whether the state exists or not. */

    if (exists==false)
    {
        /* Setting current state index if new. */

        *cur_state_index = target_mealy -> total_states;



        /* Checking if its first state in mealy or not. */

        if (target_mealy->total_states==0)
        {
            /* Creating the first state. */

            target_mealy -> states = malloc(sizeof(mealy_state));


            /* Sending debugging information. */

            if (target_mealy->states==NULL)
            {
                printf("ERROR (%s):%d :: Memory allocation failed for first state \"%s\"!\n", file, __LINE__, cur_state_name);
                
                return false;
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
                target_mealy->states,
                (size_t)((target_mealy->total_states)+1)*sizeof(mealy_state)
            );


            /* Sending debugging information. */

            if (alloc_ret==NULL)
            {
                printf("ERROR (%s):%d :: Memory allocation failed for new state \"%s\"!\n", file, __LINE__, cur_state_name);

                return false;
            }
            else
            {
                /* Making sure that `target_mealy->states` reflects new address. */

                target_mealy -> states = alloc_ret;       // Ultimate NIGHTMARE!
                cur_state_addr = (target_mealy -> states) + (*cur_state_index);


                if (debug==true)
                {
                    printf("OK (%s):%d :: Memory allocation successful for new state \"%s\".\n", file, __LINE__, cur_state_name);
                }
            }
        }



        /* Setting up the state with attributes. */

        (target_mealy -> total_states)++;     // Incrementing total state counts
        cur_state_addr = (target_mealy -> states) + ((target_mealy -> total_states) - 1);



        /* Giving name to the new state. */

        cur_state_addr -> name = malloc(sizeof(char)*(size_t)(strlen(cur_state_name)+1));

        if (cur_state_addr->name==NULL)
        {
            printf("ERROR (%s):%d :: Memory allocation failed for state name \"%s\"!\n", file, __LINE__, cur_state_name);

            return false;
        }
        else if (debug==true)
        {
            printf("OK (%s):%d :: Memory allocation successful for state name \"%s\".\n", file, __LINE__, cur_state_name);
        }

        strncpy(cur_state_addr->name, cur_state_name, (size_t)(strlen(cur_state_name)+1));



        /* Setting up state type. */

        cur_state_addr -> output = NULL;
        cur_state_addr -> type[START_STATE] = 0;
        cur_state_addr -> type[ACCEPT_STATE] = 0;



        /* Setting pointers initially to NULL. */

        cur_state_addr -> map.head = NULL;
        cur_state_addr -> map.tail = NULL;
        cur_state_addr -> else_trans = -1;
        cur_state_addr -> total_trans = 0;





        /* Final debugging information. */

        if (debug==true)
        {
            printf(
                "STAT (%s):%d :: name=%s, map=%p, else_trans=%d, total_trans=%d\n",
                file, __LINE__,
                cur_state_addr->name, (void*)&(cur_state_addr->map), cur_state_addr->else_trans, cur_state_addr->total_trans
            );

            printf(
                "STAT (%s):%d :: start_state=[%d], total_states=%d, states=%p\n",
                file, __LINE__,
                target_mealy->start_state, target_mealy->total_states, target_mealy->states
            );
        }
    }



    /* Returning if operation was successful in boolean. */

    return true;
}