/* List of included headers. */

#include "../../../include/reg_lang/dfa/dfa_ops/dfa_machine.h"










/* Loads the rules given by users and creates the DFA. */

bool dfa_machine(char *fstream, dfa *target_dfa, bool debug)
{
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
                        str_size = 0;                                   // String size reset after transfer
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

                        str_size = 0;           // String size reset after transfer
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
                if (fstream[i]==' ' || fstream[i]=='\t' || fstream[i]=='\n') {state = -1; accept = false;}
                else
                {
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
                        str_size = 0;                                   // String size reset after transfer
                    }





                    /* STATE-3 :: `(` appears :: Transferring address */

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

                        str_size = 0;           // String size reset after transfer
                    }





                    /* STATE-3 :: `(` appears  :: Transferring address */

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


            







            /*********************** STATE-7 ************************/

            case 7:
                if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 7; accept = false;}
                else if (fstream[i]=='(') {state = 8; accept = false;}
                else {state = -3; accept = false;}
                
                break;


            







            /*********************** STATE-8 ************************/

            case 8:
                if (fstream[i]=='$') {state = 10; accept = false;}
                else if (fstream[i]==',') {state = -4; accept = true;}
                else if (fstream[i]=='@') {state = 12; accept = true;}
                else
                {
                    state = 9; accept = false;          // Next state as per input



                    /* STATE-8 :: Push first character */

                    str = malloc(sizeof(char)*1);           // Getting first character in string name


                    if (str==NULL) {perror("ERROR"); return false;}     // What if string wasn't allocated?
                    else if (str!=NULL && debug==true)                  // What if string was allocated & debug mode is ON?
                    {
                        fprintf(stdout, "OK: Memory of %d bytes allocated to `str`.\n", ++str_size);
                    }


                    *str = fstream[i];          // Assigning currect char to string's first char
                }
                


                break;










            /*********************** STATE-9 ************************/

            case 9:
                if (fstream[i]==',') {state = 8; accept = false;}
                else if (fstream[i]=='$') {state = 10; accept = false;}
                else if (fstream[i]==')') {state = 11; accept = false;}
                else {state = 9; accept = false;}

                break;









            
            /*********************** STATE-10 ************************/

            case 10:
                state = 9; accept = false;
                
                break;


            







            /*********************** STATE-11 ************************/
            
            case 11:
                if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 11; accept = false;}
                else if (fstream[i]=='$') {state = 14; accept = false;}
                else {state = 13; accept = false;}
                
                break;


            







            /*********************** STATE-12 ************************/

            case 12:
                if (fstream[i]=='(') {state = 11; accept = false;}
                else {state = -5; accept = false;}
                
                break;


            







            /*********************** STATE-13 ************************/

            case 13:
                if (fstream[i]==',') {state = 7; accept = false;}
                else if (fstream[i]=='$') {state = 14; accept = false;}
                else if (fstream[i]==' ' || fstream[i]=='\t' || fstream[i]=='\n') {state = 15; accept = false;}
                else if (fstream[i]==';') {state = 0; accept = true;}
                else {state = 13; accept = false;}
                
                break;


            







            /*********************** STATE-14 ************************/

            case 14:
                if (fstream[i]==' ' || fstream[i]=='\t' || fstream[i]=='\n') {state = -1; accept = false;}
                else {state = 13; accept = false;}
                
                break;


            







            /*********************** STATE-15 ************************/

            case 15:
                if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 15; accept = false;}
                else if (fstream[i]==',') {state = 7; accept = true;}
                else if (fstream[i]==';') {state = 0; accept = true;}
                else {state = -1; accept = false;}
                
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