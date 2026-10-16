/* Guard macros to avoid multiple inclusions. */

#ifndef MEALY_MACHINE_VIEW_H
    #define MEALY_MACHINE_VIEW_H





/* Including required headers. */

#include "moore_elem/moore_unit.h"










/* Views the complete Moore at a given instant. */

void moore_machine_view(
    moore target_moore             // Target Moore
);










/* Closing guard macros. */

#endif