/* List of included headers. */

#include "../../../include/reg_lang/det_finite_auto/dfa_rules_load.h"
#include <stdlib.h>         // For allocating memory.
#include <string.h>         // To know length of a string.
#include <stdbool.h>        // To use `bool` keyword.










/* Loads the rules given by users and creates the DFA. */

bool dfa_rules_load(char dfa_rules[], struct dfa_state *target_dfa, bool debug)
{
    /* Variables & constants */

    FILE *fptr = fopen(dfa_rules, "r");         // Pointer to file with DFA rules.
    char *fstream = NULL;                       // String to load file content into.
    int state = 0;                              // Current state for the hardcoded DFA.
    bool accept;                                // Tells whether current state is A/non-A.





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

    if (debug==false){}
    else if (debug==true) {printf("STAT: Loaded rule file is \"%s\".\n", fstream);}





    /* Memory-based hardcoded DFA implementation. */

    for (int i=0; i<strlen(fstream); i++)
    {
        switch (state)
        {
            case 0:
                if (fstream[i]==' ' || fstream[i]=='\t' || fstream[i]=='\n') {state = 0; accept = true;}
                else if (fstream[i]=='$') {state = 2; accept = false;}
                else if (fstream[i]=='#') {state = 16; accept = false;}
                else {state = 1; accept = true;}
                
                break;


            
            case 1:
                if (fstream[i]=='$') {state = 2; accept = false;}
                else if (fstream[i]=='$') {state = 2;}
                else if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 3;}
                else if (fstream[i]=='(') {state = 4;}
                else {state = 1; accept = true;}
                
                break;


            
            case 2:
                state = 1; accept = true;
                
                break;


            
            case 3:
                
                
                break;


            
            case 4:
                
                
                break;


            
            case 5:
                
                
                break;


            
            case 6:
                
                
                break;


            
            case 7:
                
                
                break;


            
            case 8:
                
                
                break;


            
            case 9:
                
                
                break;


            
            case 10:
                
                
                break;


            
            case 11:
                
                
                break;


            
            case 12:
                
                
                break;


            
            case 13:
                
                
                break;


            
            case 14:
                
                
                break;


            
            case 15:
                
                
                break;


            
            case 16:
                
                
                break;


            
        }
    }
}