/* Including required headers. */

#include "../../include/dfa/dfa_str_test.h"

#include <stdio.h>              // To get access to basic I/O functions
#include <string.h>             // To compare string against each other










/* Passes a string through DFA byte processor to check where it stops. */

dfa_state *dfa_str_test(dfa target_dfa, char *symbols[], int total_sym, bool debug)
{
    /* Variables & constants */

    char *file = "dfa_str_test.c";
    dfa_state *cur_state_addr;
    dfa_state *next_state_addr;





    /* Checking if a START state even exists or not. */

    if (target_dfa.start_state<0)
    {
        printf("ERROR (%s):%d :: DFA at %p does not contain a start state!\n", file, __LINE__, (void*)&target_dfa);
        return NULL;
    }
    else if (debug==true)
    {
        printf("OK (%s):%d :: For DFA at %p, start state \"%s\" exists.\n", file, __LINE__, (void*)&target_dfa, (target_dfa.states + target_dfa.start_state)->name);
    }



    /* Setting start state as initial state. */

    cur_state_addr = (target_dfa.states) + (target_dfa.start_state);





    /* State transition loop. */

    for (int i=0; i<total_sym; i++)
    {
        /* Traversing through every transition from current state. */

        for (int j=0; j<cur_state_addr->total_trans; j++)
        {
            if (!strcmp(symbols[i], *((cur_state_addr->symbols)+j)))
            {
                /* Getting address of next state. */

                next_state_addr = (target_dfa.states) + (*(cur_state_addr -> trans)) + j;


                if (debug==true)
                {
                    printf(
                        "STAT (%s):%d :: From \"%s\" to \"%s\" (with \"%s\")\n",
                        file, __LINE__, cur_state_addr->name, next_state_addr->name, symbols[i]
                    );
                }


                cur_state_addr = next_state_addr;
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
                    cur_state_addr = (target_dfa.states) + (cur_state_addr -> else_trans);
                }
            }
        }
    }





    /* Returning the address of stop state. */

    return cur_state_addr;
}