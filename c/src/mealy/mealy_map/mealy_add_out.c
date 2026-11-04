/* Including required headers. */

#include "../../../include/mealy/mealy_map/mealy_add_out.h"

#include <stdio.h>              // To access basic I/O functions
#include <stdlib.h>             // To dynamically allocate memory
#include <string.h>             // To measure string length & copy them










/* Used for adding index of a transition state to map's node. */

mealy_map_node *mealy_add_out(mealy_map_ll *map, char *output, int out_start, int out_finish, bool debug)
{
    /* Variables & constants */

    char *file = "mealy_add_out.c";
    mealy_map_node *cur_node = map -> head;





    /* Checking if arguments are valid. */

    if ((out_start>map->total_nodes) || (out_finish>map->total_nodes))
    {
        printf("ERROR (%s):%d :: Start or finish index is out of bound!\n", file, __LINE__);
        return NULL;
    }
    else if (out_finish<out_start)
    {
        printf("ERROR (%s):%d :: Finish index can\'t come before start index!\n", file, __LINE__);
        return NULL;
    }
    else if (debug==true)
    {
        printf("OK (%s):%d :: Arguments are coherent logically with available data.\n", file, __LINE__);
    }





    /* Traversing until the start state arrives. */

    for (int i=0; i<out_start; i++) {cur_node = cur_node -> next;}



    /* Filling the rest of the nodes with provided index. */

    for (int i=out_start; i<=out_finish; i++)
    {
        /* Allocating memory for output string. */

        cur_node -> output = malloc(sizeof(char)*((size_t)(strlen(output))+1));


        if (cur_node->output==NULL)
        {
            printf(
                "ERROR (%s):%d :: malloc() failure for [%d] cur_node->output\n",
                file, __LINE__, i
            );
        }
        else if (debug==true)
        {
            printf(
                "OK (%s):%d :: malloc() successful for [%d] cur_node->output\n",
                file, __LINE__, i
            );
        }


        /* Copying string to the allocated memory. */

        strcpy(cur_node->output, output);


        
        /* Progressing to next node in series. */

        if (i<out_finish) {cur_node = cur_node -> next;}
    }





    /* Returning the address of last node filled. */

    return cur_node;
}