/* Including required headers. */

#include "../../../../include/reg_lang/dfa/dfa_ops/dfa_cur_state_l.h"

#include <stdlib.h>         // For supporting memory management operations.










/* Used for fetching first letter in name of current state, with precautions. */

bool dfa_cur_state_l1(char *str, char c, int *str_size, bool debug)
{
    /* Checking if the allocation required is for first character or other. */

    void *alloc_ret = NULL;





    /* Memory allocation process */

    if (str_size==0)
    {
        str = malloc(sizeof(char));         // Allocating memory for first character



        /* Sending debug feedback to user */

        if (str==NULL)
        {
            printf("ERROR (%s): Memory allocation failed for state name\'s first character.\n", __FILE__);
            return false;
        }
        else
        {
            *str_size++;            // Incrementing the size of string


            if (debug==false) {}
            else if (debug==true)
            {
                printf("OK (%s): Memory allocated successful for state name\'s first character.\n", __FILE__);
            }
        }
    }
    else if (str_size>0)
    {
        alloc_ret = realloc(str, ((size_t)str_size + 1)*sizeof(char));      // Reallocate memory for next character



        /* Sending debug feedback to user */

        if (alloc_ret==NULL)
        {
            printf("ERROR (%s): Memory allocation failed for state name\'s remaining character.\n", __FILE__);
            return false;
        }
        else
        {
            *str_size++;            // Incrementing the size of string


            if (debug==false) {}
            else if (debug==true)
            {
                printf("OK (%s): Memory allocated successful for state name\'s remaining character.\n", __FILE__);
            }
        }
    }





    /* Character assignation process */

    *(str + (*str_size) - 1) = c;           // Assigning character to the first index in string.

    if (debug==false) {}
    else if (debug==true)
    {
        printf("STAT (%s): c=\'%c\', str=\"%s\", str_size=%d\n", __FILE__, c, str, *str_size);
    }





    /* Returning successfully from the function. */

    return true;
}