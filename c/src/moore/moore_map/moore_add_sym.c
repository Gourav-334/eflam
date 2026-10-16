/* Including required headers. */

#include "../../../include/moore/moore_map/moore_add_sym.h"

#include <stdio.h>              // To access basic I/O functions
#include <stdlib.h>             // To dynamically allocate memory
#include <string.h>             // To copy & measure string length










/* Adds a node with symbol to the moore map. */

moore_map_node *moore_add_sym(moore_map_ll *map, char *sym, bool debug)
{
    /* Variables & constants */

    char *file = "moore_add_sym.c";
    moore_map_node *new_node = NULL;





    /* Creating a new node. */

    new_node = malloc(sizeof(moore_map_node));
        

    if (new_node==NULL)
    {
        printf("ERROR (%s):%d :: Memory allocation for moore Map Node failed!\n", file, __LINE__);
        return NULL;
    }
    else if (debug==true)
    {
        printf("OK (%s):%d :: Memory allocation for moore Map Node successful.\n", file, __LINE__);
    }





    /* Checking if node already exists. */

    if (map->total_nodes==0) {map -> head = new_node;}
    else if (map->total_nodes<0)
    {
        printf(
            "ERROR (%s):%d :: Total nodes can\'t be less than %d, data corrupted!\n",
            file, __LINE__, 0
        );

        return NULL;
    }
    else if (map->total_nodes>0)
    {
        map -> tail -> next = new_node;
    }



    /* Assigning the tail to point to newly created node. */

    map -> tail = new_node;
    (map -> total_nodes)++;





    /* Filling the string at node. */

    map -> tail -> sym = malloc(sizeof(char)*((size_t)(strlen(sym))+1));


    if (map->tail->sym==NULL)
    {
        printf("ERROR (%s):%d :: Memory allocation for symbol failed!\n", file, __LINE__);
        return NULL;
    }
    else if (debug==true)
    {
        printf("OK (%s):%d :: Memory allocation for symbol successful.\n", file, __LINE__);
    }


    strcpy(new_node->sym, sym);        // Copying argument symbol to created node
    new_node -> trans = -1;            // -ve transition initially to avoid false +ve


    if (debug==true)
    {
        printf("STAT (%s):%d :: Symbol \"%s\" is added as a map node.\n", file, __LINE__, new_node->sym);
    }





    /* Returning address of the recently created node. */

    return new_node;
}