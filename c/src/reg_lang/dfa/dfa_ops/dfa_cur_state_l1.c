/* Including required headers. */

#include "../../../../include/reg_lang/dfa/dfa_ops/dfa_cur_state_l1.h"

#include <stdlib.h>         // For supporting memory management operations.










/* Used for fetching first letter in name of current state, with precautions. */

bool dfa_cur_state_l1(char *str, char c, bool debug)
{
    /* Memory allocation process */

    str = malloc(sizeof(char));         // Allocating memory for one character.

    if (str==NULL)
    {
        printf("ERROR (dfa_cur_state_l1.c): Memory could not be allocated for the string.\n");
        return false;
    }
    else
    {
        if (debug==false) {}
        else if (debug==true)
        {
            printf("OK (dfa_cur_state_l1.c): Memory allocated for the string.\n");
        }
    }



    /* Character assignation process */

    *str = c;           // Assigning character to the first index in string.

    if (debug==false) {}
    else if (debug==true)
    {
        printf("STAT (dfa_cur_state_l1.c): c=\'%c\', str=\"%s\"\n", c, str);
    }





    /* Returning successfully from the function. */

    return true;
}