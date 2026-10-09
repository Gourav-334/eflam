/* Guard macros to avoid multiple inclusions. */

#ifndef DFA_STOP_STATE_FEED_H
    #define DFA_STOP_STATE_FEED_H





/* Including required headers. */

#include <stdbool.h>            // Specifically for toggling debugging mode










/* Tells at which state the byte processor stopped. */

void dfa_stop_state_feed(
    int stop_state,             // Stop state for byte processor
    char *filepath,             // File path for particular file
    int row,                    // Row value of the file
    int column,                 // Column value of the file
    bool debug                  // Debugging mode (ON/OFF)
);










/* Closing guard macros. */

#endif