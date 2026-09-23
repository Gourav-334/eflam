/* Including required headers. */

#include "../../../include/dfa/dfa_func/dfa_spl_sym_char.h"

#include <stdio.h>          // To use standard I/O functions










/* Used for decoding certain special characters in strings. */

char dfa_spl_sym_char(char spl_char, bool debug)
{
    /* Variables & constants */

    char *file = "dfa_spl_sym_char.c\0";



    /* Sending debugging information. */

    if (debug==true)
    {
        printf("STAT (%s):%d :: spl_char=\'%c\'\n", file, __LINE__, spl_char);
    }





    /* Returning the intended character. */

    if (spl_char=='\\') {return '\\';}
    else if (spl_char=='$') {return '$';}
    else if (spl_char=='n') {return '\n';}
    else if (spl_char=='t') {return '\t';}
    else if (spl_char=='b') {return '\b';}
    else if (spl_char=='a') {return '\a';}
    else {return spl_char;}
}