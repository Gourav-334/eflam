/* Guard macros to avoid multiple inclusions. */

#ifndef MEALY_MACHINE_VIEW_H
    #define MEALY_MACHINE_VIEW_H





/* Including required headers. */

#include "mealy_elem/mealy_unit.h"










/* Views the complete Mealy at a given instant. */

void mealy_machine_view(
    mealy target_mealy             // Target Mealy
);










/* Closing guard macros. */

#endif