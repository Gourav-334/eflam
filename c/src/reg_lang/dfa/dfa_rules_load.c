/* List of included headers. */

#include "../../../include/reg_lang/dfa/dfa_rules_load.h"
#include "../../../include/reg_lang/dfa/dfa_ops/dfa_erase.h"
#include <stdio.h>          // For using `FILE` pointer.
#include <stdlib.h>         // For allocating memory.
#include <string.h>         // To know length of a string.
#include <stdbool.h>        // To use `bool` keyword.










/* Loads the rules given by users and creates the DFA. */

bool dfa_rules_load(char dfa_rules[], dfa *target_dfa, bool debug)
{
    /* Variables & constants */

    FILE *fptr = fopen(dfa_rules, "r");         // Pointer to file with DFA rules.
    char *fstream = NULL;                       // String to load file content into.





    /* Making sure the file with DFA rules exists. */

    if (fptr==NULL)         // What if rule file doesn't exist or didn't open?
    {
        fprintf(stderr, "ERROR: File \"%s\" doesn\'t exist!\n", dfa_rules);
        return false;
    }
    else                    // Otherwise...
    {
        if (debug==false) {}
        else if (debug==true) {fprintf(stdout, "OK: File \"%s\" exists.\n", dfa_rules);}
    }





    /* Allocating memory for the written rules. */

    fseek(fptr, 0, SEEK_END);                               // Reach EOF to calculate total bytes
    fstream = malloc(sizeof(char)*(ftell(fptr)+1));         // Allocate 1 byte extra for `\0`

    if (debug==false){}
    else if (debug==true) {fprintf(stdout, "STAT: File size is of %ld bytes.\n", ftell(fptr));}





    /* Loading filestream into the allocated string. */

    fseek(fptr, 0, SEEK_SET);                       // Moving file cursor back to start of file
    fgets(fstream, strlen(fstream), fptr);          // Loading filestream into the string

    if (debug==false){}
    else if (debug==true) {fprintf(stdout, "STAT: Loaded rule file is \"%s\".\n", fstream);}

    fclose(fptr);           // Closing file pointer after use





    /* Memory-based hardcoded DFA implementation. */

    bool dfa_machine(char *fstream, dfa *target_dfa, bool debug);
}