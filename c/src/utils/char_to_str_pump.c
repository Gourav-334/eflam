/* Including required headers. */

#include "../../include/utils/char_to_str_pump.h"

#include <stdio.h>          // For using I/O functions useful in debugging.
#include <stdlib.h>         // For supporting memory management operations.










/* Used for fetching first letter in name of current state, with precautions. */

bool char_to_str_pump(char **str, char c, int *str_size, bool debug)
{
    /* Checking if the allocation required is for first character or other. */

    char *file = "char_to_str_pump.c";
    void *alloc_ret = NULL;





    /* Memory allocation process */

    if (*str_size==0)
    {
        *str = malloc(sizeof(char)*2);         // Allocating memory for first character



        /* Sending debug feedback to user */

        if (*str==NULL)
        {
            printf("ERROR (%s):%d :: Memory allocation failed for first character.\n", file, __LINE__);
            return false;
        }
        else
        {
            *str_size += 2;            // Incrementing the size of string


            if (debug==true)
            {
                printf("OK (%s):%d :: Memory allocated successfully for first character.\n", file, __LINE__);
            }
        }
    }
    else if (*str_size>0)
    {
        alloc_ret = realloc(*str, ((size_t)(*str_size + 1))*sizeof(char));      // Reallocate memory for next character



        /* Sending debug feedback to user */

        if (alloc_ret==NULL)
        {
            printf("ERROR (%s):%d :: Memory allocation failed for new character.\n", file, __LINE__);
            return false;
        }
        else
        {
            (*str_size)++;            // Incrementing the size of string


            if (debug==true)
            {
                printf("OK (%s):%d :: Memory allocated successfully for new character.\n", file, __LINE__);
            }
        }
    }
    else {printf("ERROR (%s):%d :: String size data corrupted!\n", file, __LINE__);}





    /* Character assignation process */

    *(*str + (*str_size - 2)) = c;           // Assigning character to the first index in string.
    *(*str + (*str_size - 1)) = '\0';

    if (debug==true)
    {
        printf("STAT (%s):%d :: c=\'%c\', str=\"%s\", str_size=%d\n", file, __LINE__, c, *str, *str_size);
    }





    /* Returning successfullyly from the function. */

    return true;
}