/* Including required headers. */

#include "../include/utils/str_to_arr_pump.h"

#include <stdio.h>
#include <stdlib.h>





/* Main function for testing. */

int main(int argc, char *argv[])
{
    /* Code to be tested. */

    char *str="Typology\0", *str2="rocks!\0";
    char **str_arr = NULL;
    int str_count = 0;

    str_to_arr_pump(str, &str_arr, &str_count, true);
    str_to_arr_pump("Atlas", &str_arr, &str_count, true);
    str_to_arr_pump(str2, &str_arr, &str_count, true);

    for (int i=0; i<str_count; i++)
    {
        printf("str_arr[%d]=\"%s\"\n", i, *(str_arr + i));
    }





    /* Returning normal status. */

    return 0;
}