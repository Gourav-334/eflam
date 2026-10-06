/* List of included headers. */

#include "../../../include/dfa/dfa_engine/dfa_byte_proc.h"
#include "../../../include/dfa/dfa_engine/dfa_stop_state_feed.h"
#include "../../../include/dfa/dfa_func/dfa_cur_state_insp.h"
#include "../../../include/dfa/dfa_func/dfa_spl_state_char.h"
#include "../../../include/dfa/dfa_func/dfa_spl_sym_char.h"
#include "../../../include/dfa/dfa_func/dfa_state_type_insp.h"
#include "../../../include/dfa/dfa_func/dfa_sym_pump_insp.h"
#include "../../../include/dfa/dfa_func/dfa_trans_state_insp.h"
#include "../../../include/dfa/dfa_func/dfa_other_sym_insp.h"
#include "../../../include/dfa/dfa_create.h"
#include "../../../include/dfa/dfa_viewer.h"
#include "../../../include/utils/char_to_str_pump.h"
#include "../../../include/utils/str_to_arr_pump.h"

#include <stdio.h>          // For using basic I/O services from C
#include <stdlib.h>         // For managing dynamically allocated memory
#include <string.h>         // For using functions related to strings










/* Loads the rules given by users and creates the DFA. */

int dfa_byte_proc(dfa *target_dfa, char *filepath, char *fstream, bool debug)
{
    /* Variables & constants */

    char *file = "dfa_byte_proc.c";
    int state = 0;                              // Current state for the hardcoded DFA.
    bool fine = true;                           // Tells whether byte processor is still running fine.
    bool resume = true;                         // Tells if state machine needs to resume.
    int row=1, column=0;                        // Recording row & column count for error feedback.
    long fstream_len = strlen(fstream);         // Length of the file stream.
    
    char *cur_state_name = NULL;                // Current state name
    int cur_state_name_len = 0;                 // Current state name length
    int cur_state_index;                        // Relative index of current state address

    char *state_type_name = NULL;               // State type name string
    int state_type_name_len = 0;                // State type name length

    char *trans_state_name=NULL;                // Transition state name
    int trans_state_name_len = 0;               // Transition state name length

    char *sym = NULL;                           // Symbol name string
    int sym_len = 0;                            // Symbol name length
    int total_sym = 0;                          // Size of transition symbols array





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
                else
                {
                    state = 3;

                    fine = char_to_str_pump(&cur_state_name, fstream[i], &cur_state_name_len, debug);
                }

                break;
            


            case 3:
                if (fstream[i]=='\\') {state = 4;}
                else if (fstream[i]=='$')
                {
                    state = 5;

                    fine = dfa_cur_state_insp(target_dfa, cur_state_name, &cur_state_index, debug);

                    free(cur_state_name); cur_state_name = NULL;
                    cur_state_name_len = 0;
                }
                else
                {
                    state = 3;

                    fine = char_to_str_pump(&cur_state_name, fstream[i], &cur_state_name_len, debug);
                }

                break;
            


            case 4:
                state = 3;

                fine = char_to_str_pump(&cur_state_name, dfa_spl_state_char(fstream[i], debug), &cur_state_name_len, debug);

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
                else
                {
                    state = 8;

                    fine = char_to_str_pump(&state_type_name, fstream[i], &state_type_name_len, debug);
                }

                break;
            


            case 8:
                if (fstream[i]=='\\') {state = 9;}
                else if (fstream[i]=='\'')
                {
                    state = 10;

                    fine = dfa_state_type_insp(target_dfa, cur_state_index, state_type_name, debug);

                    free(state_type_name); state_type_name = NULL;
                    state_type_name_len = 0;
                }
                else
                {
                    state = 8;

                    fine = char_to_str_pump(&state_type_name, fstream[i], &state_type_name_len, debug);
                }

                break;
            


            case 9:
                state = 8;

                fine = char_to_str_pump(&cur_state_name, dfa_spl_state_char(fstream[i], debug), &cur_state_name_len, debug);

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
                else if (fstream[i]==')') {state = 25;}
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
                else
                {
                    state = 16;

                    fine = char_to_str_pump(&sym, fstream[i], &sym_len, debug);
                }

                break;
            


            case 16:
                if (fstream[i]=='\\') {state = 17;}
                else if (fstream[i]=='\'')
                {
                    state = 18;

                    fine = dfa_sym_pump_insp(target_dfa, cur_state_index, sym, &total_sym, debug);

                    free(sym); sym = NULL;
                    sym_len = 0;
                }
                else
                {
                    state = 16;

                    fine = char_to_str_pump(&sym, fstream[i], &sym_len, debug);
                }

                break;
            


            case 17:
                state = 16;

                fine = char_to_str_pump(&sym, dfa_spl_sym_char(fstream[i], debug), &sym_len, debug);

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
                else
                {
                    state = 22;

                    fine = char_to_str_pump(&trans_state_name, fstream[i], &trans_state_name_len, debug);
                }

                break;
            


            case 22:
                if (fstream[i]=='\\') {state = 23;}
                else if (fstream[i]=='$')
                {
                    state = 24;

                    fine = dfa_trans_state_insp(target_dfa, cur_state_index, trans_state_name, &total_sym, debug);

                    free(trans_state_name); trans_state_name = NULL;
                    trans_state_name_len = 0;
                }
                else
                {
                    state = 22;

                    fine = char_to_str_pump(&trans_state_name, fstream[i], &trans_state_name_len, debug);
                }

                break;
            


            case 23:
                state = 22;

                fine = char_to_str_pump(&trans_state_name, fstream[i], &trans_state_name_len, debug);

                break;
            


            case 24:
                if (fstream[i]==';') {state = 0;}
                else if (fstream[i]==',') {state = 13;}
                else if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 24;}
                else {state = -14;}

                break;
            


            case 25:
                if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 25;}
                else if (fstream[i]=='$') {state = 26;}
                else {state = -13;}

                break;
            


            case 26:
                if (fstream[i]=='\\') {state = 28;}
                else
                {
                    state = 27;

                    fine = char_to_str_pump(&trans_state_name, fstream[i], &trans_state_name_len, debug);
                }

                break;
            


            case 27:
                if (fstream[i]=='\\') {state = 28;}
                else if (fstream[i]=='$')
                {
                    state = 29;

                    fine = dfa_other_sym_insp(target_dfa, cur_state_index, trans_state_name, debug);

                    free(trans_state_name); trans_state_name = NULL;
                    trans_state_name_len = 0;
                }
                else
                {
                    state = 27;

                    fine = char_to_str_pump(&trans_state_name, fstream[i], &trans_state_name_len, debug);
                }

                break;
            


            case 28:
                state = 27;

                fine = char_to_str_pump(&trans_state_name, fstream[i], &trans_state_name_len, debug);

                break;
            


            case 29:
                if (fstream[i]==';') {state = 0;}
                else if (fstream[i]==',') {state = 13;}
                else if (fstream[i]==' ' || fstream[i]=='\n' || fstream[i]=='\t') {state = 29;}
                else {state = -14;}

                break;
        }





        /* Returning local status (if debugging mode is on). */

        if (debug==true)
        {
            fprintf(
                stdout, "STAT (%s):%d :: fstream[i]=\'%c\', state=%d, row=%d, column=%d, fstream_len=%ld\n",
                file, __LINE__, fstream[i], state, row, column, fstream_len
            );
        }



        /* In case something goes wrong in processing. */

        if (fine==false)
        {
            printf("ERROR (%s):%d :: Halting processing for an issue, keep debug mode ON to know it in details.\n", file, __LINE__);

            return false;
        }
    }





    /* Checking for where the machine stops at last. */

    dfa_stop_state_feed(state, filepath, row, column);





    /* Returning the value of final state. */

    return state;
}