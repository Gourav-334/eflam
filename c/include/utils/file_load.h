/* Guard macros to avoid multiple inclusions. */

#ifndef FILE_LOAD_H
    #define FILE_LOAD_H





/* Including required headers. */

#include <stdbool.h>        // For using boolean parameters in function.










/* Used for loading contents of target EFLAM files into buffer. */

bool file_load(
    char *conn_file,        // Connector file containing addresses of EFLAM files.
    char ***filenames,      // Array of filenames arranged linearly.
    int *file_count,        // Total number of files connected to connector file.
    bool debug              // Debugging option for getting runtime information.
);










/* Closing guard macros. */

#endif