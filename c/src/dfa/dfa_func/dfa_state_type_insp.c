/* Including required functions. */

#include "../../../include/dfa/dfa_func/dfa_state_type_insp.h"

#include <stdio.h>          // To be able to use I/O functions.
#include <string.h>         // To specifically compare strings.










/* Used for checking if the state types are valid, and add valid ones. */

bool dfa_state_type_insp(dfa_state *cur_state_addr, char *type, bool debug)
{
    /* Variables & constants. */

    char *file = "dfa_state_type_insp.c";               // Current file name
    char *start_state = "S";                            // Start state string
    char *accept_state = "A";                           // Accept state string
    bool match = false;                                 // Tells if it matches





    /* Checking through the possible states. */

    if (!strcmp(type, start_state))
    {
        match = true;
        cur_state_addr -> type[START_STATE] = 1;
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
}