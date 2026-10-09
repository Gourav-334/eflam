/* Including required headers. */

#include "../../include/utils/char_serial.h"

#include <stdio.h>          // To enable standard I/O to programs.
#include <stdlib.h>         // To manage dynamically allocated memories.
#include <string.h>         // For copying & measuring string length.










/* Used for serializing all characters in a string to multiple strings. */

size_t char_serial(char *str, char ***str_arr, bool debug)
{
    /* Variables & constants */

    char *file = "char_serial.c";           // Name of this file
    size_t str_size = strlen(str);          // Size of the string





    /* Checking if string really points anything or not. */

    if (str==NULL)
    {
        printf(
            "ERROR (%s):%d :: String must have at least one character to serialize!\n",
            file, __LINE__
        );

        return -1;
    }



    /* Checking if string array contains anything or not. */

    if (*str_arr!=NULL)
    {
        if (debug==true)
        {
            printf(
                "WARN (%s):%d :: String array points to something which will now be freed.\n",
                file, __LINE__
            );
        }

        free(*str_arr);
        *str_arr = NULL;
    }





    /* Allocating memory for pointers that will point to strings. */

    *str_arr = malloc(sizeof(char*)*str_size);


    if (*str_arr==NULL)
    {
        printf(
            "ERROR (%s):%d :: Memory allocation for pointers in string array failed!\n",
            file, __LINE__
        );
        
        return -1;
    }
    else if (debug==true)
    {
        printf(
            "OK (%s):%d :: Memory allocation for pointers in string array successful.\n",
            file, __LINE__
        );
    }





    /* Allocating memory for every character as string & filling them in loop. */

    for (size_t i=0; i<str_size; i++)
    {
        *(*str_arr + i) = malloc(sizeof(char)*2);



        if (*(*str_arr+i)==NULL)
        {
            printf(
                "ERROR (%s):%d :: Memory allocation for string in string array failed!\n",
                file, __LINE__
            );
            
            return -1;
        }
        else if (debug==true)
        {
            printf(
                "OK (%s):%d :: Memory allocation for string in string array successful.\n",
                file, __LINE__
            );
        }


        
        /* Assigning the character and string terminator to each string. */

        **(*str_arr + i) = *(str + i);
        *(*(*str_arr + i) + 1) = '\0';



        /* Final debugging information in loop. */

        if (debug==true)
        {
            printf("STAT (%s):%d :: String fetched = \"%s\"\n", file, __LINE__, *(*str_arr + i));
        }
    }





    /* Returning the length of the original string. */

    return str_size;
}