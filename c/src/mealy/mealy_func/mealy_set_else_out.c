/* Including required headers. */

#include "../../../include/mealy/mealy_func/mealy_set_else_out.h"
#include "../../../include/mealy/mealy_elem/mealy_state.h"

#include <stdio.h>                  // For standard input output functions
#include <stdlib.h>                 // To dynamically allocate memory
#include <string.h>                 // To measure & copy strings










/* Sets ELSE output for given transition. */

bool mealy_set_else_out(mealy *target_mealy, char *output, int cur_state_index, bool debug)
{
    /* Variables & constants */

    char *file = "mealy_set_else_out.c";
    mealy_state *cur_state_addr = (target_mealy -> states) + cur_state_index;





    /* Checking in case ELSE output already exists. */

    if (cur_state_addr->else_out!=NULL)
    {
        printf("ERROR (%s):%d :: cur_state_addr->else_out already exists!\n", file, __LINE__);
        return false;
    }
    else if (debug==true)
    {
        printf("OK (%s):%d :: cur_state_addr->else_out doesn\'t exist yet.\n", file, __LINE__);
    }





    /* Allocating memory for storing ELSE output. */

    cur_state_addr -> else_out = malloc(sizeof(char)*((size_t)(strlen(output))+1));


    if (cur_state_addr->else_out==NULL)
    {
        printf("ERROR (%s):%d :: malloc() failure for cur_state_addr->else_out\n", file, __LINE__);
        return false;
    }
    else if (debug==true)
    {
        printf("OK (%s):%d :: malloc() successful for cur_state_addr->else_out\n", file, __LINE__);
    }



    /* Copying string to ELSE output of the string. */

    strcpy(cur_state_addr->else_out, output);





    /* Returning TRUE if everything up to this point was fine. */

    return true;
}