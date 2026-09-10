/* List of included headers. */

#include "../../../../include/reg_lang/dfa/dfa_ops/dfa_machine.h"
#include <stdio.h>










/* Loads the rules given by users and creates the DFA. */

int dfa_machine(char *fstream, dfa *target_dfa, bool debug)
{
    /* Variables & constants */

    int state = 0;                              // Current state for the hardcoded DFA.
    bool accept;                                // Tells whether current state is A/non-A.
    bool resume = true;                         // Tells if state machine needs to resume.
    int row=0, column=0;                        // Recording row & column count for error feedback.
    
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
                if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 0;}
                else if (fstream[i]=='#') {state = 1;}
                else if (fstream[i]=='$') {state = 2;}
                else {state = -1;}
            


            case 1:
                if (fstream[i]=='\n') {state = 0;}
                else {state = 1;}


            
            case 2:
                if (fstream[i]=='\\') {state = 4;}
                else if (fstream[i]=='$') {state = -2;}
                else {state = 3;}
            


            case 4:
                if (fstream[i]=='$') {state = 5;}
                else {state = 3;}
            


            case 5:
                if (fstream[i]==';') {state = 0;}
                else if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 5;}
                else if (fstream[i]=='{') {state = 6;}
                else if (fstream[i]=='|') {state = 13;}
                else {state = -3;}
            


            case 6:
                if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 6;}
                else if (fstream[i]=='\'') {state = 7;}
                else if (fstream[i]=='}') {state = 11;}
                else {state = -4;}
            


            case 7:
                if (fstream[i]=='\\') {state = 9;}
                else if (fstream[i]=='\'') {state = -5;}
                else {state = 8;}
            


            case 8:
                if (fstream[i]=='\\') {state = 9;}
                else if (fstream[i]=='\'') {state = 10;}
                else {state = 8;}
            


            case 9:
                if (fstream[i]=='\'') {state = 10;}
                else {state = 8;}
            


            case 10:
                if (fstream[i]==',') {state = 6;}
                else if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 10;}
                else if (fstream[i]=='}') {state = 11;}
                else {state = -6;}
            


            case 11:
                if (fstream[i]==';') {state = 0;}
                else if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 11;}
                else if (fstream[i]=='|') {state = 13;}
                else {state = -7;}
            


            case 12:
                if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 12;}
                else if (fstream[i]==')') {state = 20;}
                else {state = -8;}
            


            case 13:
                if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 13;}
                else if (fstream[i]=='(') {state = 14;}
                else {state = -9;}
            


            case 14:
                if (fstream[i]=='@') {state = 12;}
                else if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 14;}
                else if (fstream[i]=='\'') {state = 15;}
                else {state = -10;}
            


            case 15:
                if (fstream[i]=='\\') {state = 17;}
                else {state = 16;}
            


            case 16:
                if (fstream[i]=='\\') {state = 17;}
                else if (fstream[i]=='\'') {state = 18;}
                else {state = 16;}
            


            case 17:
                if (fstream[i]=='\'') {state = 18;}
                else {state = 17;}
            


            case 18:
                if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 18;}
                else if (fstream[i]==',') {state = 19;}
                else if (fstream[i]==')') {state = 20;}
                else {state = -11;}
            


            case 19:
                if (fstream[i]=='\'') {state = 15;}
                else if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 19;}
                else {state = -12;}
            


            case 20:
                if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 20;}
                else if (fstream[i]=='$') {state = 21;}
                else {state = -13;}
            


            case 21:
                if (fstream[i]=='\\') {state = 23;}
                else {state = 22;}
            


            case 22:
                if (fstream[i]=='\\') {state = 23;}
                else if (fstream[i]=='$') {state = 24;}
                else {state = 22;}
            


            case 23:
                if (fstream[i]=='$') {state = 24;}
                else {state = 22;}
            


            case 24:
                if (fstream[i]==';') {state = 0;}
                else if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 24;}
                else {state = -14;}
        }





        /* Providing user feedback about next step. */

        if (char_append(cur_state_name, fstream[i], &cur_state_size, debug)==false && debug==true)
        {
            printf("STAT (%s): Exiting state machine...\n", __FILE__);
        }
        else if (char_append(cur_state_name, fstream[i], &cur_state_size, debug)==true && debug==true)
        {
            printf("STAT (%s): Continuing with remaining symbols...\n", __FILE__);
        }




















        /* Returning local status (if debugging mode is on). */

        if (debug==true)
        {
            fprintf(stdout, "STAT: fstream[i]=%c, state=%d, row=%d, column=%d\n", fstream[i], state, row, column);
        }





        /* Returning the value of final state. */

        return state;
    }
}