/* List of included headers. */

#include "../../../include/dfa/dfa_engine/dfa_byte_proc.h"
#include "../../../include/utils/char_to_str_pump.h"
#include "../../../include/dfa/dfa_elem/dfa_state.h"

#include <stdio.h>          // For using basic I/O services from C
#include <string.h>         // For using functions related to strings










/* Loads the rules given by users and creates the DFA. */

int dfa_byte_proc(dfa *target_dfa, char *fstream, bool debug)
{
    /* Variables & constants */

    char *file = "dfa_byte_proc.c\0";
    int state = 0;                              // Current state for the hardcoded DFA.
    bool accept;                                // Tells whether current state is A/non-A.
    bool resume = true;                         // Tells if state machine needs to resume.
    int row=1, column=0;                        // Recording row & column count for error feedback.
    long fstream_len = strlen(fstream);         // Length of the file stream.
    
    char *cur_state_name=NULL;                  // Current state name
    int cur_state_size = 0;                     // Size of current state name
    dfa_state *cur_state_addr=NULL;             // Address of current state
    bool cur_state_type[TOTAL_TYPES];           // Properties of current state

    char *trans_state_name=NULL;                // Transition state name
    int trans_state_size = 0;                   // Size of transition state name
    dfa_state *trans_state_addr=NULL;           // Address of transition state

    char **sym_arr=NULL;                        // Transition symbols array
    int sym_arr_size = 0;                       // Size of transition symbols array





    /* Memory-based hardcoded DFA implementation. */

    for (int i=0; i<fstream_len; i++)
    {
        /* Checking and modifying row & column numbers. */

        if (fstream[i]=='\n') {row++; column = 1;}          // If endline occurs, reset column number
        else {column++;}                                    // Increase column number if on same line





        /* Memory-based modified base DFA. */

        switch (state)
        {
            case 0:
                if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 0;}
                else if (fstream[i]=='#') {state = 1;}
                else if (fstream[i]=='$') {state = 2;}
                else {state = -1;}

                break;
            


            case 1:
                if (fstream[i]=='\n') {state = 0;}
                else {state = 1;}

                break;


            
            case 2:
                if (fstream[i]=='\\') {state = 4;}
                else if (fstream[i]=='$') {state = -2;}
                else {state = 3;}

                break;
            


            case 3:
                if (fstream[i]=='\\') {state = 4;}
                else if (fstream[i]=='$') {state = 5;}
                else {state = 3;}

                break;
            


            case 4:
                if (fstream[i]=='$') {state = 5;}
                else {state = 3;}

                break;
            


            case 5:
                if (fstream[i]==';') {state = 0;}
                else if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 5;}
                else if (fstream[i]=='{') {state = 6;}
                else if (fstream[i]=='|') {state = 13;}
                else {state = -3;}

                break;
            


            case 6:
                if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 6;}
                else if (fstream[i]=='\'') {state = 7;}
                else if (fstream[i]=='}') {state = 11;}
                else {state = -4;}

                break;
            


            case 7:
                if (fstream[i]=='\\') {state = 9;}
                else if (fstream[i]=='\'') {state = -5;}
                else {state = 8;}

                break;
            


            case 8:
                if (fstream[i]=='\\') {state = 9;}
                else if (fstream[i]=='\'') {state = 10;}
                else {state = 8;}

                break;
            


            case 9:
                if (fstream[i]=='\'') {state = 10;}
                else {state = 8;}

                break;
            


            case 10:
                if (fstream[i]==',') {state = 6;}
                else if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 10;}
                else if (fstream[i]=='}') {state = 11;}
                else {state = -6;}

                break;
            


            case 11:
                if (fstream[i]==';') {state = 0;}
                else if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 11;}
                else if (fstream[i]=='|') {state = 13;}
                else {state = -7;}

                break;
            


            case 12:
                if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 12;}
                else if (fstream[i]==')') {state = 20;}
                else {state = -8;}

                break;
            


            case 13:
                if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 13;}
                else if (fstream[i]=='(') {state = 14;}
                else {state = -9;}

                break;
            


            case 14:
                if (fstream[i]=='@') {state = 12;}
                else if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 14;}
                else if (fstream[i]=='\'') {state = 15;}
                else {state = -10;}

                break;
            


            case 15:
                if (fstream[i]=='\\') {state = 17;}
                else {state = 16;}

                break;
            


            case 16:
                if (fstream[i]=='\\') {state = 17;}
                else if (fstream[i]=='\'') {state = 18;}
                else {state = 16;}

                break;
            


            case 17:
                if (fstream[i]=='\'') {state = 18;}
                else {state = 17;}

                break;
            


            case 18:
                if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 18;}
                else if (fstream[i]==',') {state = 19;}
                else if (fstream[i]==')') {state = 20;}
                else {state = -11;}

                break;
            


            case 19:
                if (fstream[i]=='\'') {state = 15;}
                else if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 19;}
                else {state = -12;}

                break;
            


            case 20:
                if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 20;}
                else if (fstream[i]=='$') {state = 21;}
                else {state = -13;}

                break;
            


            case 21:
                if (fstream[i]=='\\') {state = 23;}
                else {state = 22;}

                break;
            


            case 22:
                if (fstream[i]=='\\') {state = 23;}
                else if (fstream[i]=='$') {state = 24;}
                else {state = 22;}

                break;
            


            case 23:
                if (fstream[i]=='$') {state = 24;}
                else {state = 22;}

                break;
            


            case 24:
                if (fstream[i]==';') {state = 0;}
                else if (fstream[i]==',') {state = 13;}
                else if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 24;}
                else {state = -14;}

                break;
        }





        /* Returning local status (if debugging mode is on). */

        if (debug==true)
        {
            fprintf(
                stdout, "STAT (%s):%d :: fstream[i]=%c, state=%d, row=%d, column=%d, fstream_len=%ld\n",
                file, __LINE__, fstream[i], state, row, column, fstream_len
            );
        }
    }





    /* Returning the value of final state. */

    return state;
}