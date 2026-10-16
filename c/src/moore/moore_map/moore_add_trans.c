/* Including required headers. */

#include "../../../include/moore/moore_map/moore_add_trans.h"

#include <stdio.h>              // To access basic I/O functions










/* Used for adding index of a transition state to map's node. */

moore_map_node *moore_add_trans(moore_map_ll *map, int trans, int trans_start, int trans_finish, bool debug)
{
    /* Variables & constants */

    char *file = "moore_add_trans.c";
    moore_map_node *cur_node = map -> head;





    /* Checking if arguments are valid. */

    if ((trans_start>map->total_nodes) || (trans_finish>map->total_nodes))
    {
        printf("ERROR (%s):%d :: Start or finish index is out of bound!\n", file, __LINE__);
        return NULL;
    }
    else if (trans_finish<trans_start)
    {
        printf("ERROR (%s):%d :: Finish index can\'t come before start index!\n", file, __LINE__);
        return NULL;
    }
    else if (debug==true)
    {
        printf("OK (%s):%d :: Arguments are coherent logically with available data.\n", file, __LINE__);
    }





    /* Traversing until the start state arrives. */

    for (int i=0; i<trans_start; i++) {cur_node = cur_node -> next;}



    /* Filling the rest of the nodes with provided index. */

    for (int i=trans_start; i<=trans_finish; i++)
    {
        cur_node -> trans = trans;
        
        if (i<trans_finish) {cur_node = cur_node -> next;}
    }





    /* Returning the address of last node filled. */

    return cur_node;
}