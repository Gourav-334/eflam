/* Including required headers. */

#include "../../include/utils/str_to_arr_pump.h"

#include <stdio.h>          // To enable standard I/O to programs.
#include <stdlib.h>         // To manage dynamically allocated memories.










/* Used for pushing strings to array of strings. */

bool str_to_arr_pump(char *str, char ***str_arr, int *str_count, bool debug)
{
    /* Variables & constants */

    char *file = "str_to_arr_pump.c";
    void *alloc_ret;





    /* Checking if string points to anything or not. */

    if (str==NULL)
    {
        printf("ERROR (%s):%d :: Supplied string points to NULL!\n", file, __LINE__);
        return false;
    }
    else if (debug==true)
    {
        printf("OK (%s):%d :: Supplied string points to %p.\n", file, __LINE__, str);
    }





    /* Expanding memory occupied by string array as per total strings in it. */

    if (*str_count==0)
    {
        *str_arr = malloc(sizeof(char*)*1);



        /* Returning debug information. */

        if (*str_arr==NULL)
        {
            printf("ERROR (%s):%d :: Memory allocation failed for string array!\n", file, __LINE__);
            return false;
        }
        else
        {
            (*str_count)++;         // Incrementing string count

            if (debug==true)
            {
                printf("OK (%s):%d :: Memory allocation successful for string array.\n", file, __LINE__);
            }
        }
    }
    else if (*str_count>0)
    {
        alloc_ret = realloc(*str_arr, sizeof(char*)*(*str_count + 1));



        /* Returning debug information. */

        if (alloc_ret==NULL)
        {
            printf("ERROR (%s):%d :: Memory expansion failed for string array!\n", file, __LINE__);
            return false;
        }
        else
        {
            (*str_count)++;         // Incrementing string count

            if (debug==true)
            {
                printf("OK (%s):%d :: Memory expansion successful for string array.\n", file, __LINE__);
            }
        }
    }
    else {printf("ERROR (%s):%d :: String size data corrupted!\n", file, __LINE__);}





    /* Pushing the address of string to the array. */

    *(*str_arr + *str_count - 1) = str;



    /* Final feedback to the user. */

    if (debug==true)
    {
        printf("STAT (%s):%d :: str=\"%s\", str_arr(NEW)=\"%s\", str_count=%d\n", file, __LINE__, str, *(*str_arr + *str_count - 1), *str_count);
    }
}