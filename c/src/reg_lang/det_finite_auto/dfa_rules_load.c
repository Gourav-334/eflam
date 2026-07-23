/* List of included headers. */

#include "../../../include/reg_lang/det_finite_auto/dfa_rules_load.h"
#include <stdlib.h>         // For allocating memory.
#include <string.h>         // To know length of a string.
#include <stdbool.h>        // To use `bool` keyword.










/* Loads the rules given by users and creates the DFA. */

bool dfa_rules_load(char dfa_rules[], dfa *target_dfa, bool debug)
{
    /* Variables & constants */

    FILE *fptr = fopen(dfa_rules, "r");         // Pointer to file with DFA rules.
    char *fstream = NULL;                       // String to load file content into.
    int state = 0;                              // Current state for the hardcoded DFA.
    bool accept;                                // Tells whether current state is A/non-A.
    int row=0, column=0;                        // Recording row & column count for error feedback.
    char *str=NULL;                             // Buffer string to read and store names.
    int str_size = 0;                           // Size of the string `str`.
    void *alloc_ret=NULL;                       // Allocator return type catcher.





    /* Making sure the file with DFA rules exists. */

    if (fptr==NULL)
    {
        fprintf(stderr, "ERROR: File \"%s\" doesn\'t exist!\n", dfa_rules);
        return false;
    }
    else
    {
        if (debug==false) {}
        else if (debug==true) {fprintf(stdout, "OK: File \"%s\" exists.\n", dfa_rules);}
    }



    /* Allocating memory for the written rules. */

    fseek(fptr, 0, SEEK_END);
    fstream = malloc(sizeof(char)*(ftell(fptr)+1));

    if (debug==false){}
    else if (debug==true) {fprintf(stdout, "STAT: File size is of %ld bytes.\n", ftell(fptr));}



    /* Loading file stream into the allocated string. */

    fseek(fptr, 0, SEEK_SET);
    fgets(fstream, strlen(fstream), fptr);

    if (debug==false){}
    else if (debug==true) {fprintf(stdout, "STAT: Loaded rule file is \"%s\".\n", fstream);}



    /* Closing the file pointer safely. */

    fclose(fptr);





    /* Memory-based hardcoded DFA implementation. */

    for (int i=0; i<strlen(fstream); i++)
    {
        /* Checking and modifying row & column numbers. */

        if (fstream[i]=='\n') {row++; column = 1;}
        else {column++;}



        /* Memory-based modified base DFA. */

        switch (state)
        {
            case 0:
                if (fstream[i]==' ' || fstream[i]=='\t' || fstream[i]=='\n') {state = 0; accept = true;}
                else if (fstream[i]=='$') {state = 2; accept = false;}
                else if (fstream[i]=='#') {state = 16; accept = true;}
                else
                {
                    /* Next state as per input. */

                    state = 1; accept = true;


                    /* Receiving first character of current state into buffer. */

                    str = malloc(sizeof(char)*1);

                    if (str==NULL) {perror("ERROR"); return false;}
                    else if (str!=NULL && debug==true)
                    {
                        fprintf(stdout, "OK: Memory of %d bytes allocated to `str`.\n", ++str_size);
                    }

                    *str = fstream[i];
                }
                
                break;




            
            case 1:
                if (fstream[i]=='$') {state = 2; accept = false;}
                else if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 3; accept = false;}
                else if (fstream[i]=='(')
                {
                    /* Next state as per input. */

                    state = 4; accept = false;



                    /* Packing state name with a null terminator. */

                    alloc_ret = realloc(str, sizeof(char)*(++str_size));

                    if (alloc_ret==NULL) {perror("ERROR"); free(str); return false;}
                    else if (alloc_ret!=NULL && debug==true)
                    {
                        fptrintf(stdout, "OK: Memory pointed by `str` reallocated to %d.\n", str_size);
                    }

                    *(str + (str_size-1)) = '\0';



                    /* Transferring pointer to the DFA. */

                    if (target_dfa->total_states==0)
                    {
                        target_dfa -> states = malloc(sizeof(dfa_state));               // Allocating memory for first state
                        target_dfa -> states -> name = malloc((size_t)str_size);        // Allocating memory for state name
                        strcpy(target_dfa->states->name, str);                          // Assigning state its name
                    }
                    else if (target_dfa->total_states>0)
                    {
                        /* Checking if the state already exists. */

                        for (int i2=0; i2<(target_dfa->total_states); i2++)
                        {
                            if (!strcmp((target_dfa -> states + i2), str))
                            {
                                fprintf(stderr, "ERROR: State already exists at index `%d`!\n", i2);

                                for (int i3=0; i3<(target_dfa->total_states); i3++)
                                {
                                    free((target_dfa->states+i3)->name);
                                    for (int i4=0; i4<(target_dfa->states+i3)->total_trans; i4++)
                                    {
                                        free(((target_dfa->states+i3)->symbols+i4));
                                        free(((target_dfa->states+i3)->transitions+i4));
                                    }
                                }
                                free(target_dfa->states); free (str);

                                return false;
                            }
                        }


                        /* Continuing operations if the state doesn't exist. */

                        alloc_ret = realloc(target_dfa->states, sizeof(dfa_state)*((target_dfa->total_states) + 1));
                        (target_dfa -> states + (target_dfa->total_states)) -> name = malloc((size_t)str_size);
                        strcpy((target_dfa->states + (target_dfa->total_states))->name, str);
                    }


                    free(str); str_size = 0;                                        // Resetting string & string size
                    target_dfa -> states -> type[0] = false;                        // By default not start state
                    target_dfa -> states -> type[1] = false;                        // By default not accept state

                    (target_dfa -> total_states)++;



                    /* Reading the string buffer. */

                    if (debug==false) {}
                    else if (debug==true) {fprintf(stdout, "STAT: str=%s\n", str);}
                }
                else
                {
                    /* Next state as per input. */

                    state = 1; accept = true;
                }
                
                break;




            
            case 2:
                state = 1; accept = true;
                
                break;




            
            case 3:
                if (fstream[i]=='(') {state = 4; accept = false;}
                else if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 3; accept = false;}
                else {state = -1; accept = false;}
                
                break;




            
            case 4:
                if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 4; accept = false;}
                else if (fstream[i]=='S' || fstream=='A') {state = 5; accept = false;}
                else if (fstream[i]==')') {state = 6; accept = true;}
                else {state = -2; accept = false;}
                
                break;




            
            case 5:
                if (fstream[i]==',') {state = 4; accept = false;}
                else if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 5; accept = false;}
                else if (fstream[i]==')') {state = 6; accept = true;}
                else {state = -2; accept = false;}
                
                break;




            
            case 6:
                if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 6; accept = true;}
                else if (fstream[i]=='|') {state = 7; accept = false;}
                else {state = -3; accept = false;}
                
                break;


            
            case 7:
                if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 7; accept = false;}
                else if (fstream[i]=='(') {state = 8; accept = false;}
                else {state = -4; accept = false;}
                
                break;


            
            case 8:
                if (fstream[i]=='$') {state = 9; accept = false;}
                else if (fstream[i]==')' || fstream[i]=='$') {state = 11; accept = true;}
                else {state = 8; accept = false;}
                
                break;


            
            case 9:
                state = 8; accept = false;
                
                break;


            
            case 10:
                if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 10; accept = false;}
                else {state = 12; accept = false;}
                
                break;


            
            case 11:
                if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 11; accept = false;}
                else if (fstream[i]==')') {state = 10; accept = false;}
                else {state = -5; accept = false;}
                
                break;


            
            case 12:
                if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 14; accept = false;}
                else if (fstream[i]=='$') {state = 13; accept = false;}
                else {state = 12; accept = false;}
                
                break;


            
            case 13:
                state = 14; accept = false;
                
                break;


            
            case 14:
                if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 14; accept = false;}
                else if (fstream[i]==';') {state = 15; accept = true;}
                else {state = -1; accept = false;}
                
                break;


            
            case 15:
                if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 0; accept = true;}
                else if (fstream[i]=='#') {state = 16; accept = true;}
                else {state = 1; accept = true;}
                
                break;


            
            case 16:
                if (fstream=='\n') {state = 0; accept = true;}
                else {state = 16; accept = true;}
                
                break;
        }



        /* Returning local status (if debugging mode is on). */

        if (debug==false) {}
        else if (debug==true)
        {
            fprintf(stdout, "STAT: fstream[i]=%c, state=%d, row=%d, column=%d\n", fstream[i], state, row, column);
        }
    }
}