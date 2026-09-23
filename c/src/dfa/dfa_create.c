/* Including required headers. */

#include "../../include/dfa/dfa_create.h"
#include "../../include/dfa/dfa_engine/dfa_byte_proc.h"

#include <stdio.h>              // For using standard I/O facilities
#include <stdlib.h>             // To allow usage of memory management functions










/* Used for loading contents of target EFLAM files into buffer. */

bool dfa_create(dfa *target_dfa, char *filepaths[], int file_count, bool debug)
{
    /* Variables & constants */

    char *file = "dfa_create.c\0";          // Name of this source file.
    char *buff = NULL;                      // Buffer to load filestreams into.
    FILE *fptr = NULL;                      // File pointer which accesses the file.
    long bytes;                             // Number of bytes file contains.
    int final_state;                         // Final state at which the machine stops.





    /* Load & pass loop. */

    for (int i=0; i<file_count; i++)
    {
        /* Opening the file at passed location. */

        fptr = fopen(filepaths[i], "r");

        if (fptr==NULL)
        {
            printf("ERROR (%s):%d :: File filepaths[%d]=\"%s\" failed to open!\n", file, __LINE__, i, filepaths[i]);
            return false;
        }
        else if (debug==true)
        {
            printf("OK (%s):%d :: File filepaths[%d]=\"%s\" opened successfully.\n", file, __LINE__, i, filepaths[i]);
        }



        /* Knowing the number of bytes that file contains. */

        fseek(fptr, 0, SEEK_END);
        bytes = ftell(fptr);
        fseek(fptr, 0, SEEK_SET);



        /* Loading the bytes in file to the buffer. */

        buff = malloc(bytes*sizeof(char));


        if (buff==NULL)
        {
            printf("ERROR (%s):%d :: Memory allocation for buffer failed!\n", file, __LINE__);
            return false;
        }
        else if (debug==true)
        {
            printf("OK (%s):%d :: Memory allocation for buffer successful.\n", file, __LINE__);
        }

        
        fread(buff, 1, bytes, fptr);





        /* General debugging information. */

        if (debug==true)
        {
            printf("STAT (%s):%d :: buff=\"%s\"\n", file, __LINE__, buff);
        }





        /* Passing the stream in buffer to the DFA machine. */

        final_state = dfa_byte_proc(target_dfa, buff, debug);

        if (debug==true) {printf("STAT (%s):%d :: bytes=%ld, final_state=%d\n", file, __LINE__, bytes, final_state);}



        /* Deallocating the memory occupied by buffer & closing file. */

        free(buff);
        fclose(fptr);
    }
}