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


### 2.2 <u>Character Serializer</u>

```c
// utils/char_serial.c
/* Used for serializing all characters in a string to multiple strings. */

size_t char_serial(
    char *str,              // String to be pushed to array
    char ***str_arr,        // Array that contains strings
    bool debug              // Debugging option for getting runtime information.
);
```

1. If string is NULL, throw error to the user.
2. If string array is not NULL, free it and warn user if debug mode is on.
3. Allocate memory for as many pointers as characters in string.
4. For every pointer in the series, allocate `2` bytes and fill them with corresponding character & `\0`.
5. Return total number of characters converted to string.


### 2.3 <u>Symbol Tape Cell (Structure)</u>:

```c
// utils/sym_tape/sym_tape_cell.h
/* Unit cell of a symbol tape. */

typedef struct sym_tape_cell {
    char *sym;                              // Symbol written on the cell
    struct sym_tape_cell *next;             // Address of next cell in tape
} sym_tape_cell;
```


### 2.4 <u>Symbol Tape Linked List</u>:

```c
// utils/sym_tape/sym_tape_ll.h
/* Tape controller containing details and entry to tape. */

typedef struct sym_tape_ll {
    struct sym_tape_cell *head;             // Pointer to head of linked list
    struct sym_tape_cell *tail;             // Pointer to tail of linked list
    int total_cells;                        // Total number of cells in tape
} sym_tape_ll;
```


### 2.5 <u>Add Cell To Tape</u>:

```c
// utils/sym_tape/add_cell_to_tape.c
/* Adds a cell to the tape along with the symbol. */

sym_tape_cell *add_cell_to_tape(
    sym_tape_ll *tape,                  // Tape to which cell has to be added
    char *sym,                          // Symbol to be written on the new cell
    bool debug                          // Debugging mode (ON/OFF)
);
```

1. Check if any cell exists or not.
    2. If not, create first cell & place the symbol in it.
    3. Else if existing, create a cell and place symbol in it before connecting it to last cell.
4. Return the address to newly created cell now.


### 2.6 <u>Symbol Tape Viewer</u>:

```c
// utils/sym_tape/sym_tape_view.c
/* Iterates through the tape and displays all the symbols it contains in series. */

bool sym_tape_view(
    sym_tape_ll tape              // The tape containing transitions
);
```



## 3. Test Cases & Benchmarks



## 4. Special Notes

---