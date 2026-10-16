/* Including required headers. */

#include "../../include/moore/moore_str_test.h"
#include "../../include/utils/sym_tape/sym_tape_ll.h"
#include "../../include/utils/sym_tape/add_cell_to_tape.h"

#include <stdio.h>              // To get access to basic I/O functions
#include <string.h>             // To compare string against each other










/* Passes a string through moore byte processor to check where it stops. */

moore_state *moore_str_test(moore target_moore, char *symbols[], sym_tape_ll *tape, int total_sym, bool debug)
{
    /* Variables & constants */

    char *file = "moore_str_test.c";
    moore_state *cur_state_addr = NULL;
    moore_state *next_state_addr = NULL;
    moore_map_node *trav = NULL;





    /* Checking if a START state even exists or not. */

    if (target_moore.start_state<0)
    {
        printf("ERROR (%s):%d :: Moore at %p does not contain a start state!\n", file, __LINE__, (void*)&target_moore);
        return NULL;
    }
    else if (debug==true)
    {
        printf("OK (%s):%d :: For moore at %p, start state \"%s\" exists.\n", file, __LINE__, (void*)&target_moore, (target_moore.states + target_moore.start_state)->name);
    }



    /* Setting start state as initial state. */

    cur_state_addr = (target_moore.states) + (target_moore.start_state);





    /* State transition loop. */

    for (int i=0; i<total_sym; i++)
    {
        /* Adding output to the tape. */

        if(add_cell_to_tape(tape, cur_state_addr->output, debug)==NULL)
        {
            printf(
                "ERROR (%s):%d :: Cell with symbol \"%s\" failed to be added!\n",
                file, __LINE__, cur_state_addr->output
            );

            return NULL;
        }
        else if (debug==true)
        {
            printf(
                "OK (%s):%d :: Cell with symbol \"%s\" added successfully.\n",
                file, __LINE__, cur_state_addr->output
            );
        }



        /* Starting search from first transition. */

        trav = cur_state_addr -> map.head;



        /* Traversing through every transition from current state. */

        for (int j=0; j<cur_state_addr->total_trans; j++)
        {
            if (!strcmp(symbols[i], trav->sym))
            {
                /* Getting address of next state. */

                next_state_addr = (target_moore.states) + (trav -> trans);


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
                    /* Updating address to next state. */

                    next_state_addr = (target_moore.states) + (cur_state_addr -> else_trans);

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





    /* Adding final state output to tape. */

    if(add_cell_to_tape(tape, cur_state_addr->output, debug)==NULL)
    {
        printf(
            "ERROR (%s):%d :: Cell with symbol \"%s\" failed to be added!\n",
            file, __LINE__, cur_state_addr->output
        );

        return NULL;
    }
    else if (debug==true)
    {
        printf(
            "OK (%s):%d :: Cell with symbol \"%s\" added successfully.\n",
            file, __LINE__, cur_state_addr->output
        );
    }





    /* Returning the address of stop state. */

    return cur_state_addr;
}