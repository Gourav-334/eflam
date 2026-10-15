/* Including required headers. */

#include "../../include/mealy/mealy_str_test.h"
#include "../../include/utils/sym_tape/sym_tape_ll.h"

#include <stdio.h>              // To get access to basic I/O functions
#include <string.h>             // To compare string against each other










/* Passes a string through mealy byte processor to check where it stops. */

mealy_state *mealy_str_test(mealy target_mealy, char *symbols[], sym_tape_ll *tape, int total_sym, bool debug)
{
    /* Variables & constants */

    char *file = "mealy_str_test.c";
    mealy_state *cur_state_addr = NULL;
    mealy_state *next_state_addr = NULL;
    mealy_map_node *trav = NULL;





    /* Checking if a START state even exists or not. */

    if (target_mealy.start_state<0)
    {
        printf("ERROR (%s):%d :: mealy at %p does not contain a start state!\n", file, __LINE__, (void*)&target_mealy);
        return NULL;
    }
    else if (debug==true)
    {
        printf("OK (%s):%d :: For mealy at %p, start state \"%s\" exists.\n", file, __LINE__, (void*)&target_mealy, (target_mealy.states + target_mealy.start_state)->name);
    }



    /* Setting start state as initial state. */

    cur_state_addr = (target_mealy.states) + (target_mealy.start_state);





    /* State transition loop. */

    for (int i=0; i<total_sym; i++)
    {
        trav = cur_state_addr -> map.head;      // Starting search from first transition



        /* Traversing through every transition from current state. */

        for (int j=0; j<cur_state_addr->total_trans; j++)
        {
            if (!strcmp(symbols[i], trav->sym))
            {
                /* Getting address of next state. */

                next_state_addr = (target_mealy.states) + (trav -> trans);


                if (debug==true)
                {
                    printf(
                        "STAT (%s):%d :: From \"%s\" to \"%s\" (with \"%s\")\n",
                        file, __LINE__, cur_state_addr->name, next_state_addr->name, symbols[i]
                    );
                }


                cur_state_addr = next_state_addr;

                break;
            }
            else if (j==(cur_state_addr->total_trans)-1)
            {
                /* Checking whether ELSE state is mentioned or not. */

                if (cur_state_addr->else_trans<0)
                {
                    if (debug==true)
                    {
                        printf("STAT (%s):%d :: State \"%s\" is a dump state.\n", file, __LINE__, cur_state_addr->name);
                    }

                    return cur_state_addr;
                }
                else
                {
                    next_state_addr = (target_mealy.states) + (cur_state_addr -> else_trans);

                    if (debug==true)
                    {
                        printf(
                            "STAT (%s):%d :: From \"%s\" to \"%s\" (with \"%s\")\n",
                            file, __LINE__, cur_state_addr->name, next_state_addr->name, symbols[i]
                        );
                    }

                    cur_state_addr = next_state_addr;
                }
            }


            trav = trav -> next;
        }
    }





    /* Displaying final state in case debug mode is on. */

    if (debug==true)
    {
        printf("STAT (%s):%d :: Final State = \"%s\"\n", file, __LINE__, cur_state_addr->name);
    }





    /* Returning the address of stop state. */

    return cur_state_addr;
}