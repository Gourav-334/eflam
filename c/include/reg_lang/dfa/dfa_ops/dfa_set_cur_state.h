/* Including guards to avoid multiple inclusions. */

#ifndef DFA_SET_CUR_STATE_H
    #define DFA_SET_CUR_STATE_H





#include "../dfa_units.h"

#include <stdbool.h>        // To allow using boolean return type.










/* Used for creating a state if it doesn't exist yet. */

bool dfa_fix_cur_state(
    dfa *target_dfa,        // Target DFA machine
    char *name,             // Name of state to be created
    int *name_size,         // Length of state's name
    bool debug              // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif