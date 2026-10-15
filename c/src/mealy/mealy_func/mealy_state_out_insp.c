/* Including required headers. */

#include "../../../include/mealy/mealy_func/mealy_state_out_insp.h"
#include "../../../include/mealy/mealy_elem/mealy_unit.h"
#include "../../../include/mealy/mealy_elem/mealy_state.h"

#include <stdio.h>              // To access basic I/O functionalities










/* Inspects and makes sure that every state produces an output. */

bool mealy_state_out_insp(char *filepaths[], mealy target_mealy, bool debug)
{
    /* Variables & constants */

    char *file = "mealy_state_out_insp.c";          // File name
    bool exists_all = true;                         // Tells if all outputs exist





    /* Checking which states don't contain any output. */

    for (int i=0; i<target_mealy.total_states; i++)
    {
        if (((target_mealy.states)+i)->output==NULL)
        {
            printf(
                "ERROR (%s):%d :: State \"%s\" has no output!\n",
                file, __LINE__, ((target_mealy.states)+i)->name
            );

            exists_all = false;
        }
        else if (debug==true)
        {
            printf(
                "OK (%s):%d :: State \"%s\" has output \"%s\".\n",
                file, __LINE__, ((target_mealy.states)+i)->name, ((target_mealy.states)+i)->output
            );
        }
    }





    /* Returning if all output exist. */

    return exists_all;
}