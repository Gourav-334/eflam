/* Including required headers. */

#include "../../../include/utils/sym_tape/sym_tape_to_str_arr.h"

#include <stdio.h>              // Accessing standard I/O functions
#include <stdlib.h>             // For dynamically allocating memory
#include <string.h>             // To run string-related operations










/* Converts series of symbols on symbol tape into a string array. */

int sym_tape_to_str_arr(sym_tape_ll target_tape, char ***str_arr, bool debug)
{
    /* Variables & constants */

    char *file = "sym_tape_to_str_arr.c";           // This file name
    sym_tape_cell *trav = target_tape.head;         // Copy of pointer to tape head





    /* Checking if the supplied string array is empty. */

    if (*str_arr!=NULL)
    {
        printf("ERROR (%s):%d :: Supplied string array points to something!\n", file, __LINE__);
        return -1;
    }
    else if (debug==true)
    {
        printf("OK (%s):%d :: Supplied string array doesn\'t point to anything.\n", file, __LINE__);
    }





    /* Allocating memory to hold pointers to strings. */

    *str_arr = malloc(sizeof(char*)*((size_t)(target_tape.total_cells)));


    if (*str_arr==NULL)
    {
        printf("ERROR (%s):%d :: Memory allocation for *str_arr failure!\n", file, __LINE__);
        return -1;
    }
    else if (debug==true)
    {
        printf("OK (%s):%d :: Memory allocation for *str_arr successful.\n", file, __LINE__);
    }





    /* Traversing through every cell in symbol tape. */

    for (int i=0; i<target_tape.total_cells; i++)
    {
        /* Allocating memory for the particular instance of string. */

        *(*str_arr + i) = malloc(sizeof(char)*((size_t)(strlen(trav->sym)+1)));


        if (*str_arr==NULL)
        {
            printf("ERROR (%s):%d :: Memory allocation for *(*str_arr + %d) failure!\n", file, __LINE__, i);
            return -1;
        }
        else if (debug==true)
        {
            printf("OK (%s):%d :: Memory allocation for *(*str_arr + %d) successful.\n", file, __LINE__, i);
        }



        /* Copying the string to the allocated memory. */

        strcpy(*(*str_arr + i), trav->sym);


        /* Moving to next cell in the tape. */

        trav = trav -> next;
    }





    /* Returning total number of cells converted. */

    return (target_tape.total_cells);
}