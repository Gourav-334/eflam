# UTILITIES



## 1. About


Basic utility box, which provides custom functions to ease with repetitive writing of generic codes. For example, for appending a character to given string. A proper function written for its safe implementation for debugging feedback will be useful against boilerplates.



## 2. Implementation


### 2.1 <u>Character Append</u>:

```c
// utils/char_append.c
/* Used for appending a character to target string. */

bool char_append(
    char *str,          // Target string to be updated
    char c,             // Character to be appended with
    int *str_size,      // Current size of string
    bool debug          // Debugging mode (ON/OFF)
);
```

1. If string's size is zero, allocate memory for a character & push the encountered character to string buffer.
2. Else if size isn't zero, reallocate memory by extending with another character & push the encountered character to string buffer.



## 3. Test Cases & Benchmarks



## 4. Special Notes