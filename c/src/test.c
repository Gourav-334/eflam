/* Including required headers. */

#include "../include/utils/char_to_str_pump.h"

#include <stdio.h>
#include <stdlib.h>





/* Main function for testing. */

int main(int argc, char *argv[])
{
    /* Code to be tested. */

    char *str = NULL;
    char c = 'T';
    int i = 0;

    char_to_str_pump(str, c, &i, true);
    char_to_str_pump(str, 'y', &i, true);
    char_to_str_pump(str, 'p', &i, true);
    char_to_str_pump(str, 'o', &i, true);

    char c2 = 'l';

    char_to_str_pump(str, 'o', &i, true);

    free(str);

    char_to_str_pump(str, 'A', &i, true);
    char_to_str_pump(str, 't', &i, true);
    char_to_str_pump(str, 'l', &i, true);

    printf("str=%s, i=%d\n", str, i);





    /* Returning normal status. */

    return 0;
}