/* List of included headers. */

#include "../../../../include/reg_lang/dfa/dfa_ops/dfa_machine.h"
#include <stdio.h>










/* Loads the rules given by users and creates the DFA. */

bool dfa_machine(char *fstream, dfa *target_dfa, bool debug)
{
    /* Variables & constants */

    int state = 0;                              // Current state for the hardcoded DFA.
    bool accept;                                // Tells whether current state is A/non-A.
    int row=0, column=0;                        // Recording row & column count for error feedback.
    char *str=NULL;                             // Buffer string to read and store names.
    int str_size = 0;                           // Size of the string `str`.
    void *alloc_ret=NULL;                       // Allocator return type catcher.





    /* Memory-based hardcoded DFA implementation. */

    for (int i=0; i<strlen(fstream); i++)
    {
        /* Checking and modifying row & column numbers. */

        if (fstream[i]=='\n') {row++; column = 1;}          // If endline occurs, reset column number
        else {column++;}                                    // Increase column number if on same line





        /* Memory-based modified base DFA. */

        switch (state)
        {
            case 0:
                if (fstream[i]==' ' || fstream[i]=='\t' || fstream[i]=='\n') {state = 0; accept = true;}
                else if (fstream[i]=='$') {state = 2; accept = false;}
                else if (fstream[i]=='#') {state = 16; accept = true;}
                else {state = 1; accept = true; dfa_cur_state_l1(str, fstream[i], debug);}

                break;



            case 1:
                if (fstream[i]=='$') {state = 2; accept = false;}
                else if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 3; accept = false;}
                else if (fstream[i]=='(') {state = 4; accept = false; /* FUNCTION REQUIRED */}
                else {state = 1; accept = true; /* FUNCTION REQUIRED */}

                break;



            case 2:
                if (fstream[i]==' ' || fstream[i]=='\t' || fstream[i]=='\n') {state = -1; accept = false;}
                else {state = 1; accept = true; /* FUNCTION REQUIRED */}
                
                break;



            case 3:
                if (fstream[i]=='(') {state = 4; accept = false; /* FUNCTION REQUIRED */}
                else if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 3; accept = false;}
                else {state = -1; accept = false;}
                
                break;



            case 4:
                if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 4; accept = false;}
                else if (fstream[i]=='S' || fstream=='A') {state = 5; accept = false; /* FUNCTION REQUIRED */}
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
                else {state = -3; accept = false;}
                
                break;



            case 8:
                if (fstream[i]=='$') {state = 10; accept = false;}
                else if (fstream[i]==',') {state = -4; accept = true;}
                else if (fstream[i]=='@') {state = 12; accept = true;}
                else {state = 9; accept = false; /* FUNCTION REQUIRED */}

                break;



            case 9:
                if (fstream[i]==',') {state = 8; accept = false;}
                else if (fstream[i]=='$') {state = 10; accept = false;}
                else if (fstream[i]==')') {state = 11; accept = false;}
                else {state = 9; accept = false; /* FUNCTION REQUIRED */}

                break;



            case 10:
                state = 9; accept = false;
                
                break;


            
            case 11:
                if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 11; accept = false;}
                else if (fstream[i]=='$') {state = 14; accept = false;}
                else {state = 13; accept = false;}
                
                break;



            case 12:
                if (fstream[i]=='(') {state = 11; accept = false;}
                else {state = -5; accept = false;}
                
                break;



            case 13:
                if (fstream[i]==',') {state = 7; accept = false;}
                else if (fstream[i]=='$') {state = 14; accept = false;}
                else if (fstream[i]==' ' || fstream[i]=='\t' || fstream[i]=='\n') {state = 15; accept = false;}
                else if (fstream[i]==';') {state = 0; accept = true;}
                else {state = 13; accept = false;}
                
                break;



            case 14:
                if (fstream[i]==' ' || fstream[i]=='\t' || fstream[i]=='\n') {state = -1; accept = false;}
                else {state = 13; accept = false;}
                
                break;



            case 15:
                if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 15; accept = false;}
                else if (fstream[i]==',') {state = 7; accept = true;}
                else if (fstream[i]==';') {state = 0; accept = true;}
                else {state = -1; accept = false;}
                
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