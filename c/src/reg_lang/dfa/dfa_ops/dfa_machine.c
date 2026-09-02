/* List of included headers. */

#include "../../../../include/reg_lang/dfa/dfa_ops/dfa_machine.h"
#include <stdio.h>










/* Loads the rules given by users and creates the DFA. */

bool dfa_machine(char *fstream, dfa *target_dfa, bool debug)
{
    /* Variables & constants */

    int state = 0;                              // Current state for the hardcoded DFA.
    bool accept;                                // Tells whether current state is A/non-A.
    bool resume = true;                         // Tells if state machine needs to resume.
    int row=0, column=0;                        // Recording row & column count for error feedback.
    /* RECONSIDER IN COMMON STORAGE */
    char *cur_state_name=NULL;                  // Current state name
    int cur_state_size = 0;                     // Size of current state name
    dfa_state *cur_state_addr=NULL;             // Address of current state
    bool cur_state_type[TOTAL_TYPES];           // Properties of current state

    char *trans_state_name=NULL;                // Transition state name
    int trans_state_size = 0;                   // Size of transition state name
    dfa_state *trans_state_addr=NULL;           // Address of transition state

    char *sym_arr=NULL;                         // Transition symbols array
    int sym_arr_size = 0;                       // Size of transition symbols array





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
                else
                {
                    state = 1; accept = true;
                    resume = char_append(cur_state_name, fstream[i], &cur_state_size, debug);
                }

                break;



            case 1:
                if (fstream[i]=='$') {state = 2; accept = false;}
                else if (fstream[i]==' ' || fstream=='\t' || fstream=='\n') {state = 3; accept = false;}
                else if (fstream[i]=='(') {state = 4; accept = false; /* FUNCTION REQUIRED */}
                else
                {
                    state = 1; accept = true;
                    resume = char_append(cur_state_name, fstream[i], &cur_state_size, debug);
                }

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





        /* Providing user feedback about next step. */

        if (char_append(cur_state_name, fstream[i], &cur_state_size, debug)==false)
        {
            if (debug==false) {}
            else if (debug==true) {printf("STAT (%s): Exiting state machine...\n", __FILE__);}
        }
        else if (char_append(cur_state_name, fstream[i], &cur_state_size, debug)==true)
        {
            if (debug==false) {}
            else if (debug==true) {printf("STAT (%s): Continuing with remaining symbols...\n", __FILE__);}
        }




















        /* Returning local status (if debugging mode is on). */

        if (debug==false) {}
        else if (debug==true)
        {
            fprintf(stdout, "STAT: fstream[i]=%c, state=%d, row=%d, column=%d\n", fstream[i], state, row, column);
        }
    }
}