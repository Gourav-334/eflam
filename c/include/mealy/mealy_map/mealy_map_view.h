/* Guard macros to avoid multiple inclusions. */

#ifndef MEALY_MAP_VIEW_H
    #define MEALY_MAP_VIEW_H





/* Including required headers. */

#include "mealy_map_ll.h"

#include <stdbool.h>                // To return boolean value with function










/* Used for viewing everything that the map contains. */

bool mealy_map_view(
    mealy_map_ll map              // The linked list map containing transitions
);










/* Closing guard macros. */

#endif