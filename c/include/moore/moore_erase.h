/* Guard macros to avoid multiple inclusions. */

#ifndef MEALY_ERASE_H
    #define MEALY_ERASE_H





/* Including required headers. */

#include "moore_elem/moore_unit.h"
#include "moore_elem/moore_state.h"
#include "moore_map/moore_map_ll.h"
#include "moore_map/moore_map_node.h"










/* Erases everything related to the particular Moore. */

moore *moore_erase(
    moore *target_moore,            // Target Moore
    bool debug                      // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif