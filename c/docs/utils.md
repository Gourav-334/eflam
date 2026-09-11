# UTILITIES



## 1. About


Basic utility box, which provides custom functions to ease with repetitive writing of generic codes. For example, for appending a character to given string. A proper function written for its safe implementation for debugging feedback will be useful against boilerplates.



## 2. Implementation


### 2.1 <u>Character To String Pump</u>:

```c
// utils/char_to_str_pump.c
/* Used for appending a character to target string. */

bool char_to_str_pump(
    char **str,         // Target string to be updated
    char c,             // Character to be appended with
    int *str_size,      // Current size of string
    bool debug          // Debugging mode (ON/OFF)
);
```

1. If string's size is zero, allocate memory for a character & push the encountered character to string buffer.
2. Else if size isn't zero, reallocate memory by extending with another character & push the encountered character to string buffer.



### 2.2 <u>String To Array Pump</u>

```c
// utils/str_to_arr_pump.c
/* Used for pushing strings to array of strings. */

bool str_to_arr_pump(
    char *str,              // String to be pushed to array
    char ***str_arr,        // Array that contains strings
    int *str_count,         // Number of strings currently in array
    bool debug              // Debugging option for getting runtime information.
);
```

1. Check if `str` is NULL, and return error if so.
2. Check the `str_count` and allocate space for placing pointer to `str` in `str_arr`.
3. Now add pointer of `str` to allocated memory `str_arr`.



### 2.3 <u>File Loader</u>:

```c
// utils/file_load.c
/* Used for loading contents of target EFLAM files into buffer. */

int file_load(
    char *conn_file,        // Connector file containing addresses of EFLAM files.
    char ***filenames,      // Array of filenames arranged linearly.
    int *file_count,        // Total number of files connected to connector file.
    bool debug              // Debugging option for getting runtime information.
);
```



## 3. Test Cases & Benchmarks



## 4. Special Notes

---