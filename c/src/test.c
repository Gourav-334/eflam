/* Including required headers. */

#include "../include/dfa/dfa_func/dfa_spl_sym_char.h"

#include <stdio.h>





/* Main function for testing. */

int main(int argc, char *argv[])
{
    /* Code to be tested. */

    char c;

    c = dfa_spl_sym_char('\'', true);
    printf("c=\'%c\'\n", c);
    c = dfa_spl_sym_char('$', true);
    printf("c=\'%c\'\n", c);
    c = dfa_spl_sym_char('\\', true);
    printf("c=\'%c\'\n", c);
    c = dfa_spl_sym_char('n', true);
    printf("c=\'%c\'\n", c);
    c = dfa_spl_sym_char('t', true);
    printf("c=\'%c\'\n", c);
    c = dfa_spl_sym_char('b', true);
    printf("c=\'%c\'\n", c);
    c = dfa_spl_sym_char('a', true);
    printf("c=\'%c\'\n", c);
    c = dfa_spl_sym_char('q', true);
    printf("c=\'%c\'\n", c);
    c = dfa_spl_sym_char('w', true);
    printf("c=\'%c\'\n", c);
    c = dfa_spl_sym_char('e', true);
    printf("c=\'%c\'\n", c);





    /* Returning normal status. */

    return 0;
}