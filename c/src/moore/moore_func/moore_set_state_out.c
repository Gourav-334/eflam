/* Including required headers. */

#include "../../../include/moore/moore_func/moore_set_state_out.h"

#include <stdio.h>              // To access basic I/O functionalities
#include <stdlib.h>             // To dynamically allocate memory
#include <string.h>             // To copy & measure string length










/* Pushes a string as output to particular Moore machine state. */

bool moore_set_state_out(moore *target_moore, int cur_state_index, char *output, bool debug)
{
    /* Variables & constants */

    char *file = "moore_set_state_out.c";
    moore_state *cur_state_addr = (target_moore -> states) + cur_state_index;





    /* Checking if output already exists for the state. */

    if (cur_state_addr->output!=NULL)
    {
        if (strcmp(output, cur_state_addr->output))
        {
            printf(
                "ERROR (%s):%d :: Output of state \"%s\" does not match to previous description!\n",
                file, __LINE__, cur_state_addr->name
            );

            return false;
        }
        else if (debug==true)
        {
            printf(
                "OK (%s):%d :: Output of state \"%s\" matches to previous description.\n",
                file, __LINE__, cur_state_addr->name
            );
        }
    }
    else if (debug==true)
    {
        printf(
            "STAT (%s):%d :: No output for state \"%s\" found yet.\n",
            file, __LINE__, cur_state_addr->name
        );
    }





    /* Reserving memory for the output string. */

    cur_state_addr -> output = malloc(sizeof(char)*(size_t)(strlen(output)));


    if (cur_state_addr->output==NULL)
    {
        printf(
            "ERROR (%s):%d :: Memory allocation for state \"%s\" output failed!\n",
            file, __LINE__, cur_state_addr->name
        );

        return false;
    }
    else if (debug==true)
    {
        printf(
            "OK (%s):%d :: Memory allocation for state \"%s\" output successful.\n",
            file, __LINE__, cur_state_addr->name
        );
    }



    /* Copying the input to state's output. */

    strcpy(cur_state_addr->output, output);


    /* Sending final debug information to user. */

    if (debug==true)
    {
        printf(
            "STAT (%s):%d :: Output for state \"%s\" is set as \"%s\".\n",
            file, __LINE__, cur_state_addr->name, cur_state_addr->output
        );
    }





    /* Returning true for successful completion of operations. */

    return true;
}