/* List of included headers. */

#include "../../../include/reg_lang/det_finite_auto/dfa_rules_load.h"
#include "../../../include/reg_lang/det_finite_auto/dfa_erase.h"
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

    for (int i=0; i<strlen(fstream); i++)
    {
        /* Checking and modifying row & column numbers. */

        if (fstream[i]=='\n') {row++; column = 1;}          // If endline occurs, reset column number
        else {column++;}                                    // Increase column number if on same line





        /* Memory-based modified base DFA. */

        switch (state)
        {
            // case -1:
            //     fprintf(stderr,
            //         "ERROR :: %d:%d :: State name can\'t contain any whitespace, tabspace, or newline!\n",
            //         row, column);
                
            //     break;
            // case -2:
            //     fprintf(stderr,
            //         "ERROR :: %d:%d :: Missing comma or unknown state type `%c` requested!\n",
            //         row, column, fstream[i]);
                
            //     break;
            // case -3:
            //     fprintf(stderr,
            //         "ERROR :: %d:%d :: String written after currect state description!\n",
            //         row, column);
                
            //     break;
            









            /*********************** STATE-0 ************************/

            case 0:
                if (fstream[i]==' ' || fstream[i]=='\t' || fstream[i]=='\n') {state = 0; accept = true;}
                else if (fstream[i]=='$') {state = 2; accept = false;}
                else if (fstream[i]=='#') {state = 16; accept = true;}
                else
                {
                    state = 1; accept = true;           // Next state as per input.





                    /* Receiving first character of current state into buffer. */

                    str = malloc(sizeof(char)*1);           // Getting first character in string name


                    if (str==NULL) {perror("ERROR"); return false;}     // What if string wasn't allocated?
                    else if (str!=NULL && debug==true)                  // What if string was allocated & debug mode is ON?
                    {
                        fprintf(stdout, "OK: Memory of %d bytes allocated to `str`.\n", ++str_size);
                    }


                    *str = fstream[i];          // Assigning currect char to string's first char
                }
                


                break;









            
            /*********************** STATE-1 ************************/

            case 1:
                if (fstream[i]=='$') {state = 2; accept = false;}
                else if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 3; accept = false;}
                else if (fstream[i]=='(')
                {
                    state = 4; accept = false;          // Next state as per input



                    /* Packing state name with a null terminator. */

                    alloc_ret = realloc(str, sizeof(char)*(++str_size));        // Expanding string size by 1 byte

                    if (alloc_ret==NULL)                        // What if reallocation failed?
                    {
                        perror("ERROR"); free(str);
                        return false;
                    }
                    else if (alloc_ret!=NULL && debug==true)    // What if reallocation succeeded but debug mode is ON?
                    {
                        fptrintf(stdout, "OK: Memory pointed by `str` reallocated to %d.\n", str_size);
                    }



                    *(str + (str_size-1)) = '\0';           // Adding `\0` as final string char





                    /* STATE-1 :: `(` appears :: Transferring address */

                    if (target_dfa->total_states==0)            // What if its the first state in DFA?
                    {
                        target_dfa -> states = malloc(sizeof(dfa_state));       // Allocating memory for first state



                        if (target_dfa->states==NULL)               // What if the allocation for first state failed?
                        {
                            fprintf(stderr, "ERROR: Memory allocation issue for first state!\n");
                            free(str); return false;
                        }
                        else if (alloc_ret!=NULL && debug==true)    // What if the allocation succeeded but debug is ON?
                        {
                            fprintf(stdout, "OK: Memory allocated for first state.\n");
                        }



                        target_dfa -> states -> name = malloc((size_t)str_size);        // Allocating memory for state name



                        if (target_dfa->states->name==NULL)             // What if allocation for state name failed?
                        {
                            fprintf(stderr, "ERROR: Memory allocation issue for state name `%s`!\n", str);
                            free(str); return false;
                        }
                        else if (alloc_ret!=NULL && debug==true)        // What if allocation succeeded but debug is ON?
                        {
                            fprintf(stdout, "OK: Memory allocated for state name.\n");
                        }

                        strcpy(target_dfa->states->name, str);          // Assigning state its name
                    }





                    /* STATE-1 :: `(` appears :: Transferring address */

                    else if (target_dfa->total_states>0)        //  What if the DFA already contains at least one state?
                    {
                        /* Checking if the state already exists. */

                        for (int i2=0; i2<(target_dfa->total_states); i2++)         // Iterating over each state in DFA
                        {
                            if (!strcmp((target_dfa -> states + i2), str))          // What if state already exists?
                            {
                                fprintf(stderr, "ERROR: State already exists at index `%d`!\n", i2);
                                dfa_erase(target_dfa, str);             // Erase every memory allocated under DFA

                                return false;
                            }
                        }



                        /* Continuing operations if the state doesn't exist. */

                        alloc_ret = realloc(target_dfa->states, sizeof(dfa_state)*((target_dfa->total_states) + 1));
                        (target_dfa -> states + (target_dfa->total_states)) -> name = malloc((size_t)str_size);
                        strcpy((target_dfa->states + (target_dfa->total_states))->name, str);
                    }




                    /* STATE-1 :: `(` appears  :: Transferring address */

                    else        // Otherwise...
                    {
                        fprintf(stderr, "ERROR: State data corruption, total states can\'t be negative!\n");
                    }


                    free(str); str_size = 0;                                    // Resetting string & string size
                    target_dfa -> states -> type[START_STATE] = false;          // By default not start state
                    target_dfa -> states -> type[ACCEPT_STATE] = false;         // By default not accept state

                    (target_dfa -> total_states)++;         // Updating count of total states in DFA



                    /* Debug info about the string buffer. */

                    if (debug==false) {}
                    else if (debug==true) {fprintf(stdout, "STAT: str=%s\n", str);}
                }





                /* STATE-1 :: ELSE */

                else            // Otherwise...
                {
                    state = 1; accept = true;           // Next state as per input



                    /* Expanding memory to store next character in string name. */

                    alloc_ret = realloc(str, sizeof(char)*(++str_size));



                    /* STATE-1 :: ELSE */

                    if (alloc_ret==NULL)        // What if reallocation for string failed?
                    {
                        fprintf(stderr, "ERROR: Memory reallocation issue with string buffer!\n");
                        return false;
                    }
                    else if (alloc_ret!=NULL && debug==true)        // What if reallocation successful but debug is ON?
                    {
                        fprintf(stdout, "OK: Memory reallocated for string buffer.\n");
                    }



                    *(str + str_size-1) = fstream[i];       // Assigning last char of string the current char
                }
                


                break;









            
            /*********************** STATE-2 ************************/

            case 2:
                state = 1; accept = true;       // Next state as per input.





                /* STATE-2 :: Allocating first byte to string */

                if (str==NULL)          // What if the allocation failed?
                {
                    str = malloc(sizeof(char)*1);

                    if (str==NULL) {perror("ERROR"); return false;}
                    else if (str!=NULL && debug==true)
                    {
                        fprintf(stdout, "OK: Memory of %d bytes allocated to `str`.\n", ++str_size);
                    }

                    *str = fstream[i];
                }





                /* STATE-2 :: Allocating first byte to string */

                else if (str!=NULL)         // What if allocation was successful?
                {
                    alloc_ret = realloc(str, sizeof(char)*(++str_size));    // Expanding size of string



                    if (alloc_ret==NULL)        // What if reallocation to string failed?
                    {
                        fprintf(stderr, "ERROR: Memory reallocation issue with string buffer!\n");
                        return false;
                    }
                    else if (alloc_ret!=NULL && debug==true)        // What if allocation succeded but debug is ON?
                    {
                        fprintf(stdout, "OK: Memory reallocated for string buffer.\n");
                    }



                    *(str + str_size-1) = fstream[i];       // Assigning last char of string as current char
                }
                


                break;










            /*********************** STATE-3 ************************/

            case 3:
                if (fstream[i]=='(')        // What if character in stream is `(`?
                {
                    state = 4; accept = false;          // Next state as per input



                    alloc_ret = realloc(str, sizeof(char)*(++str_size));        // Reallocating string size



                    if (alloc_ret==NULL)                        // What if reallocation to string failed?
                    {
                        perror("ERROR"); free(str);
                        return false;
                    }
                    else if (alloc_ret!=NULL && debug==true)    // What if the reallocation succeeded?
                    {
                        fptrintf(stdout, "OK: Memory pointed by `str` reallocated to %d.\n", str_size);
                    }



                    *(str + (str_size-1)) = '\0';           // Assigning last char of string as `\0`





                    /* STATE-3 :: `(` appears :: Packaging state name */

                    if (target_dfa->total_states==0)        // What if its first state in DFA?
                    {
                        target_dfa -> states = malloc(sizeof(dfa_state));       // Allocating memory for first state



                        /* STATE-3 :: `(` appears :: Packaging state name :: State allocation check */

                        if (target_dfa->states==NULL)           // What if allocation of new state failed?
                        {
                            fprintf(stderr, "ERROR: Memory allocation issue for first state!\n");
                            free(str); return false;
                        }
                        else if (alloc_ret!=NULL && debug==true)        // What if allocation of new state succeeded but debug is ON?
                        {
                            fprintf(stdout, "OK: Memory allocated for first state.\n");
                        }



                        target_dfa -> states -> name = malloc((size_t)str_size);        // Allocating memory for state name



                        /* STATE-3 :: `(` appears :: Packaging state name :: Name allocation check */

                        if (target_dfa->states->name==NULL)         // What if allocation of new state failed?
                        {
                            fprintf(stderr, "ERROR: Memory allocation issue for state name `%s`!\n", str);
                            free(str); return false;
                        }
                        else if (alloc_ret!=NULL && debug==true)        // What if allocation of new state succeeded but debug is ON?
                        {
                            fprintf(stdout, "OK: Memory allocated for state name.\n");
                        }



                        strcpy(target_dfa->states->name, str);          // Assigning state its name
                    }
                }
                else if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 3; accept = false;}
                else {state = -1; accept = false;}
                
                break;




            





            /*********************** STATE-4 ************************/

            case 4:
                if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 4; accept = false;}
                else if (fstream[i]=='S' || fstream=='A')
                {
                    state = 5; accept = false;          // Next state as per input.





                    /* STATE-4 :: Setting flags */

                    if (fstream[i]=='S')        // What if its a START flag (`s`)?
                    {
                        /* What if START flag for current state is already set? */

                        if ((target_dfa->states + (target_dfa->total_states - 1))->type[START_STATE]==true)
                        {
                            fprintf(stderr, "ERROR :: %d:%d :: State is already set as START!\n", row, column);
                            dfa_erase(target_dfa, str);

                            return false;
                        }



                        /* What if a START set already exists? */
                        
                        else if (target_dfa->start_state!=NULL)
                        {
                            fprintf(stderr, "ERROR :: %d:%d :: START state already exists!\n", row, column);
                            dfa_erase(target_dfa, str);
                            
                            return false;
                        }



                        /* Otherwise... */

                        else
                        {
                            (target_dfa -> states + (target_dfa -> total_states - 1)) -> type[START_STATE] = true;

                            if (debug==false) {}
                            else if (debug==true) {fprintf(stderr, "OK :: %d:%d :: START state set.\n", row, column);}
                        }
                    }





                    /* STATE-4 :: Setting flags */

                    else if (fstream[i]=='A')       // What if its a START flag (`s`)?
                    {
                        /* What if ACCEPT flag for current state is already set? */

                        if ((target_dfa->states + (target_dfa->total_states - 1))->type[ACCEPT_STATE]==true)
                        {
                            fprintf(stderr, "ERROR :: %d:%d :: State is already set as ACCEPT!\n", row, column);
                            dfa_erase(target_dfa, str);

                            return false;
                        }



                        /* Otherwise... */

                        else
                        {
                            (target_dfa -> states + (target_dfa -> total_states - 1)) -> type[ACCEPT_STATE] = true;

                            if (debug==false) {}
                            else if (debug==true) {fprintf(stderr, "OK :: %d:%d :: ACCEPT state set.\n", row, column);}
                        }
                    }
                }
                else if (fstream[i]==')') {state = 6; accept = true;}
                else {state = -2; accept = false;}
                
                break;









            
            /*********************** STATE-5 ************************/

            case 5:
                if (fstream[i]==',') {state = 4; accept = false;}
                else if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 5; accept = false;}
                else if (fstream[i]==')') {state = 6; accept = true;}
                else {state = -2; accept = false;}
                
                break;









            
            /*********************** STATE-6 ************************/

            case 6:
                if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 6; accept = true;}
                else if (fstream[i]=='|') {state = 7; accept = false;}
                else {state = -3; accept = false;}
                
                break;


            







            /*********************** STATE-4 ************************/

            case 7:
                if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 7; accept = false;}
                else if (fstream[i]=='(') {state = 8; accept = false;}
                else {state = -4; accept = false;}
                
                break;


            







            /*********************** STATE-4 ************************/

            case 8:
                if (fstream[i]=='$') {state = 9; accept = false;}
                else if (fstream[i]==')') {state = 10; accept = true;}
                else if (fstream[i]=='@') {state = 11; accept = true;}
                else
                {
                    state = 8; accept = false;          // Next state as per input





                    /* STATE-8 :: Allocating byte */

                    if (str==NULL)          // What if string is empty?
                    {
                        str = malloc(sizeof(char)*1);       // Allocating first byte



                        if (str==NULL)          // What if allocation failed?
                        {
                            perror("ERROR");
                            return false;
                        }
                        else if (str!=NULL && debug==true)      // What if allocation succeeded but debug is ON?
                        {
                            fprintf(stdout, "OK: Memory of %d bytes allocated to `str`.\n", ++str_size);
                        }



                        *str = fstream[i];          // Assigning first char of string as current char
                    }





                    /* STATE-8 :: Allocating byte */

                    else if (str!=NULL)             // What if string isn't empty?
                    {
                        alloc_ret = realloc(str, sizeof(char)*(++str_size));        // Reallocating string



                        if (alloc_ret==NULL)        // What if allocation failed?
                        {
                            fprintf(stderr, "ERROR: Memory reallocation issue with string buffer!\n");
                            return false;
                        }
                        else if (alloc_ret!=NULL && debug==true)        // What if allocation succeeded but debug is ON?
                        {
                            fprintf(stdout, "OK: Memory reallocated for string buffer.\n");
                        }



                        *(str + str_size-1) = fstream[i];       // Assigning last char of string as current char
                    }
                }


                
                break;










            /*********************** STATE-9 ************************/

            case 9:
                state = 8; accept = false;          // Next state as per input



                /* STATE-9 :: Allocating byte */

                if (str==NULL)          // What if string is empty?
                {
                    str = malloc(sizeof(char)*1);           // Allocating first byte for string



                    if (str==NULL)              // What if allocation failed?
                    {
                        perror("ERROR");
                        return false;
                    }
                    else if (str!=NULL && debug==true)          // What if allocation succeded but debug is ON?
                    {
                        fprintf(stdout, "OK: Memory of %d bytes allocated to `str`.\n", ++str_size);
                    }



                    *str = fstream[i];          // Assigning first char of string as current char
                }





                /* STATE-9 :: Allocating byte */

                else if (str!=NULL)             // What if string isn't empty?
                {
                    alloc_ret = realloc(str, sizeof(char)*(++str_size));        // Reallocating string



                    if (alloc_ret==NULL)        // What if the allocation failed?
                    {
                        perror("ERROR");
                        return false;
                    }
                    else if (alloc_ret!=NULL && debug==true)        // What if allocation succeded but debug is ON?
                    {
                        fprintf(stdout, "OK: Memory reallocated for string buffer.\n");
                    }



                    *(str + str_size-1) = fstream[i];       // Assigning last char of string as current char
                }
                


                break;









            
            /*********************** STATE-10 ************************/

            case 10:
                if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 10; accept = false;}
                else if (fstream[i]==',') {state = 7; accept = false;}
                else {state = 12; accept = false;}
                
                break;


            







            /*********************** STATE-11 ************************/
            
            case 11:
                if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 11; accept = false;}
                else if (fstream[i]==')') {state = 10; accept = false;}
                else if (fstream[i]==',') {state = 7; accept = false;}
                else {state = -5; accept = false;}
                
                break;


            







            /*********************** STATE-12 ************************/

            case 12:
                if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 14; accept = false;}
                else if (fstream[i]=='$') {state = 13; accept = false;}
                else {state = 12; accept = false;}
                
                break;


            







            /*********************** STATE-13 ************************/

            case 13:
                state = 14; accept = false;
                
                break;


            







            /*********************** STATE-14 ************************/

            case 14:
                if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 14; accept = false;}
                else if (fstream[i]==';') {state = 15; accept = true;}
                else {state = -1; accept = false;}
                
                break;


            







            /*********************** STATE-15 ************************/

            case 15:
                if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 0; accept = true;}
                else if (fstream[i]=='#') {state = 16; accept = true;}
                else {state = 1; accept = true;}
                
                break;


            







            /*********************** STATE-16 ************************/

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