/* Guard macros to avoid multiple inclusions. */

#ifndef MEALY_ERASE_H
    #define MEALY_ERASE_H





/* Including required headers. */

#include "mealy_elem/mealy_unit.h"
#include "mealy_elem/mealy_state.h"
#include "mealy_map/mealy_map_ll.h"
#include "mealy_map/mealy_map_node.h"










/* Erases everything related to the particular Mealy. */

mealy *mealy_erase(
    mealy *target_mealy,            // Target Mealy
    bool debug                      // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif