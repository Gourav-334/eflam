/* Including required headers. */

#include "../../../include/dfa/dfa_func/dfa_sym_pump_insp.h"
#include "../../../include/utils/str_to_arr_pump.h"

#include <stdio.h>              // To access basic I/O services
#include <string.h>             // To compare strings & measure string length










/* Used for checking if a supplied symbol already exists & adding if not. */

bool dfa_sym_pump_insp(dfa_state *cur_state_addr, char *sym, int *total_sym, bool debug)
{
    /* Variables & constants */

    char *file = "dfa_sym_pump_insp.c";
    bool exists = false;        // Indicates if a state already exists or not.
    void *alloc_ret = NULL;     // Allocation return value checker.





    /* Checking if the state already exists. */

    for (int i=0; i<cur_state_addr->total_trans; i++)
    {
        if (!strcmp(*((cur_state_addr->symbols)+i), sym))
        {
            exists = true;          // The symbol exists already

            printf("ERROR (%s):%d :: Symbol \"%s\" already exists under state \"%s\" at index [%d]!\n", file, __LINE__, sym, cur_state_addr->name, i);

            return false;
        }
        else if (debug==true)
        {
            printf("OK (%s):%d :: Symbol \"%s\" does not exist under state \"%s\" at index [%d].\n", file, __LINE__, sym, cur_state_addr->name, i);
        }
    }





    /* If the symbol is new to state. */

    if (exists==false)
    {
        /* Pushing the new symbol to the transition list of state. */

        str_to_arr_pump(&(cur_state_addr->symbols), sym, &(cur_state_addr->total_trans), debug);

        (*total_sym)++;                     // Registering count of new symbols

        
        if (debug==true)
        {
            printf(
                "OK (%s):%d :: total_trans=%d | New symbol \"%s\" pushed to state \"%s\".\n",
                file, __LINE__, cur_state_addr->total_trans, sym, cur_state_addr->name
            );
        }


        return true;
    }





    /* Returning TRUE for successful execution. */

    return true;
}