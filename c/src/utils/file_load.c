/* Including required headers. */

#include "../../include/utils/file_load.h"
#include "../../include/utils/char_to_str_pump.h"
#include "../../include/utils/str_to_arr_pump.h"

#include <stdio.h>              // For using standard I/O facilities
#include <stdlib.h>             // To allow usage of memory management functions










/* Used for loading contents of target EFLAM files into buffer. */

bool file_load(char *conn_file, char ***filenames, int *file_count, bool debug)
{
    /* Variables & constants */

    char *file = "file_load.c\0";           // Name of this source file
    FILE *fptr = NULL;                      // File pointer to any file
    char *path = NULL;                      // Contains the path to connector file
    int conn_file_len, path_file_len;       // Length of connector file & path file
    void *ret_alloc;                        // Catches return value for some functions
    int cur_path_len;                       // Current path name length in loop





    /* Checking if connector file is a valid one. */
    
    if (conn_file==NULL)
    {
        printf("ERROR (%s):%d :: String representing connector file is NULL!\n", file, __LINE__);
        return false;
    }
    else if (debug==true)
    {
        printf("OK (%s):%d :: String reprenting connector file is not NULL.\n", file, __LINE__);
    }



    /* Checking whether filenames is empty or not. */

    if (*filenames!=NULL)
    {
        printf("WARN (%s):%d :: String array to contain filenames isn\'t empty!\n", file, __LINE__);
    }
    else if (debug==true)
    {
        printf("OK (%s):%d :: String array to contain filenames is empty.\n", file, __LINE__);
    }





    /* Copying connector file address to path buffer. */
    
    conn_file_len = (int)strlen(conn_file);
    path = malloc(sizeof(char)*(conn_file_len + 1));


    if (path==NULL)
    {
        printf("ERROR (%s):%d :: Memory allocation for path buffer failed!\n", file, __LINE__);
        return false;
    }
    else if (debug==true)
    {
        printf("OK (%s):%d :: Memory allocated for path buffer successfully.\n", file, __LINE__);
    }


    strncpy(path, conn_file, conn_file_len + 1);
    path_file_len = conn_file_len;





    /* Tracing the directory of connector file. */

    for (int i=path_file_len-1; i>=0; i--)
    {
        cur_path_len = i + 1;

        if (*(path + i)=='/')
        {
            ret_alloc = realloc(path, sizeof(char)*cur_path_len);
            char_to_str_pump(&path, '\0', &cur_path_len, true);
        }
    }
}