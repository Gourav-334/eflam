/* Including required functions. */

#include "../../../include/mealy/mealy_func/mealy_state_type_insp.h"
#include "../../../include/mealy/mealy_elem/mealy_unit.h"

#include <stdio.h>          // To be able to use I/O functions.
#include <string.h>         // To specifically compare strings.










/* Used for checking if the state types are valid, and add valid ones. */

bool mealy_state_type_insp(mealy *target_mealy, int cur_state_index, char *type, bool debug)
{
    /* Variables & constants. */

    char *file = "mealy_state_type_insp.c";               // Current file name
    char *start_state = "S";                            // Start state string
    char *accept_state = "A";                           // Accept state string
    bool match = false;                                 // Tells if it matches
    mealy_state *cur_state_addr = (target_mealy -> states) + cur_state_index;





    /* Checking through the possible states. */

    if (!strcmp(type, start_state))
    {
        match = true;


        if (target_mealy->start_state<0)
        {
            cur_state_addr -> type[START_STATE] = 1;
            target_mealy -> start_state = cur_state_index;
        }
        else
        {
            printf("ERROR (%s):%d :: Start state already exists as \"%s\"!\n", file, __LINE__, ((target_mealy->states)+(target_mealy->start_state))->name);

            return false;
        }
    }
    else if (!strcmp(type, accept_state))
    {
        match = true;
        cur_state_addr -> type[ACCEPT_STATE] = 1;
    }





    /* Checking if the request matched or not. */

    if (match==true && debug==true)
    {
        printf("OK (%s):%d :: State type matching to \"%s\".\n", file, __LINE__, type);
        return true;
    }
    else if (match==false)
    {
        printf("ERROR (%s):%d :: State type not matching to any type!\n", file, __LINE__);
        return false;
    }





    /* Returning TRUE for successful execution. */

    return true;
}