/* Guard macros to avoid multiple inclusions. */

#ifndef DFA_VIEWER_H
    #define DFA_VIEWER_H





/* Including required headers. */

#include "dfa_elem/dfa_unit.h"










/* Views the complete DFA at a given instant. */

void dfa_viewer(
    dfa target_dfa             // Target DFA
);










/* Closing guard macros. */

#endif