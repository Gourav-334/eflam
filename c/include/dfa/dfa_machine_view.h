/* Guard macros to avoid multiple inclusions. */

#ifndef DFA_MACHINE_VIEW_H
    #define DFA_MACHINE_VIEW_H





/* Including required headers. */

#include "dfa_elem/dfa_unit.h"










/* Views the complete DFA at a given instant. */

void dfa_machine_view(
    dfa target_dfa             // Target DFA
);










/* Closing guard macros. */

#endif