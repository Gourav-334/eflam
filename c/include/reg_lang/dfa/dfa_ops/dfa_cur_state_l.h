/* Guard macros to avoid multiple inclusions. */

#ifndef DFA_CUR_STATE_L_H
    #define DFA_CUR_STATE_L_H





/* Including required headers. */

#include <stdbool.h>        // To use boolean type variables in function.










/* Used for fetching first letter in name of current state, with precautions. */

bool dfa_cur_state_l(
    char *str,          // Target string to be updated
    char c,             // Character to be appended with
    int *str_size,      // Current size of string
    bool debug          // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif