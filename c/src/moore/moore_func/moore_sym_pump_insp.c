/* Including required headers. */

#include "../../../include/moore/moore_func/moore_sym_pump_insp.h"
#include "../../../include/moore/moore_map/moore_add_sym.h"

#include <stdio.h>              // To access basic I/O services
#include <string.h>             // To compare strings & measure string length










/* Used for checking if a supplied symbol already exists & adding if not. */

bool moore_sym_pump_insp(moore *target_moore, int cur_state_index, char *sym, int *total_sym, bool debug)
{
    /* Variables & constants */

    char *file = "moore_sym_pump_insp.c";
    bool exists = false;        // Indicates if a state already exists or not.
    void *alloc_ret = NULL;     // Allocation return value checker.
    moore_state *cur_state_addr = (target_moore -> states) + cur_state_index;
    moore_map_node *trans_find = cur_state_addr -> map.head;





    /* Checking if the symbol already exists. */

    for (int i=0; i<cur_state_addr->total_trans; i++)
    {
        if (!strcmp(trans_find->sym, sym))
        {
            exists = true;          // The symbol exists already

            printf("ERROR (%s):%d :: Symbol \"%s\" already exists under state \"%s\" at index [%d]!\n", file, __LINE__, sym, cur_state_addr->name, i);

            return false;
        }
        else if (debug==true)
        {
            printf("OK (%s):%d :: Symbol \"%s\" does not exist under state \"%s\" at index [%d].\n", file, __LINE__, sym, cur_state_addr->name, i);
        }


        trans_find = trans_find -> next;
    }





    /* If the symbol is new to state. */

    if (exists==false)
    {
        moore_add_sym(&(cur_state_addr->map), sym, debug);
        (cur_state_addr -> total_trans)++;

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