/* Including required headers. */

#include "../../../include/moore/moore_func/moore_state_out_insp.h"
#include "../../../include/moore/moore_elem/moore_unit.h"
#include "../../../include/moore/moore_elem/moore_state.h"

#include <stdio.h>              // To access basic I/O functionalities










/* Inspects and makes sure that every state produces an output. */

bool moore_state_out_insp(moore *target_moore, bool debug)
{
    /* Variables & constants */

    char *file = "moore_state_out_insp.c";          // File name
    bool exists_all = true;                         // Tells if all outputs exist





    /* Checking which states don't contain any output. */

    for (int i=0; i<target_moore->total_states; i++)
    {
        if (((target_moore->states)+i)->output==NULL)
        {
            printf(
                "ERROR (%s):%d :: State \"%s\" has no output!\n",
                file, __LINE__, ((target_moore->states)+i)->name
            );

            exists_all = false;
        }
        else if (debug==true)
        {
            printf(
                "OK (%s):%d :: State \"%s\" has output \"%s\".\n",
                file, __LINE__, ((target_moore->states)+i)->name, ((target_moore->states)+i)->output
            );
        }
    }





    /* Returning if all output exist. */

    return exists_all;
}