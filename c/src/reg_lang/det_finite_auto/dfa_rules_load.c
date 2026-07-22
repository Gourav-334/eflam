/* List of included headers. */

#include "../../../include/reg_lang/det_finite_auto/dfa_rules_load.h"
#include <stdlib.h>         // For allocating memory.
#include <string.h>         // To know length of a string.










/* Loads the rules given by users and creates the DFA. */

bool dfa_rules_load(char dfa_rules[], struct dfa_state *target_dfa, bool debug)
{
    /* Variables & constants */

    FILE *fptr = fopen(dfa_rules, "r");         // Pointer to file with DFA rules.
    char *fstream = NULL;                       // String to load file content into.





    /* Making sure the file with DFA rules exists. */

    if (fptr==NULL)
    {
        printf("ERROR: File \"%s\" doesn\'t exist!\n", dfa_rules);
        return;
    }
    else
    {
        if (debug==false) {}
        else if (debug==true) {printf("OK: File \"%s\" exists.\n", dfa_rules);}
    }



    /* Allocating memory for the written rules. */

    fseek(fptr, 0, SEEK_END);
    fstream = malloc(sizeof(char)*(ftell(fptr)+1));

    if (debug==false){}
    else if (debug==true) {printf("STAT: File size is of %ld bytes.\n", ftell(fptr));}



    /* Loading file stream into the allocated string. */

    fseek(fptr, 0, SEEK_SET);
    fgets(fstream, strlen(fstream), fptr);
}