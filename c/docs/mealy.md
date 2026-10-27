# MEALY MACHINE



## 1. About


A very basic string validation model, telling if a string will be accepted or not. Makes just one transition at a time for one input symbol. Contains three states: States, accept state, and dead state. Doesn't have its own memory, all it can tell is whether a string will be accepted or not.

Implementation of the automata machine is made in form of graph using structures. Users can use it in two forms, one by importing/loading the EFLAM file with written state transitions for the grammar of MEALY. And second method is by embedding the grammar or transition within the function itself.



## 2. Implementation


### 2.1 <u>MEALY State (Structure)</u>:

```c
// mealy/mealy_ops/mealy_units.h
/* Structure from which created instances represent unit state. */

typedef struct mealy_state {
    char *name;                             // States where the current state makes transition to
    bool type[TOTAL_TYPES];                 // Tells if the state is accept state or not
    mealy_map_ll map;                       // Symbols to state transition map
    int else_trans;                         // Index of ELSE transition symbol
    char *else_out;                         // Output from ELSE transition
    bool corresp;                           // Tells if ELSE output is correspondant
    int total_trans;                        // Number of transitions current state makes
} mealy_state;
```


### 2.2 <u>MEALY (Structure)</u>:

```c
// mealy/mealy_ops/mealy_units.h
/* Structure representing whole MEALY, enclosing its states. */

typedef struct mealy {
    int start_state;                        // Index of initial/start state of the MEALY
    int total_states;                       // Number of states that the MEALY contains
    struct mealy_state *states;             // Array of states that MEALY encloses
} mealy;
```


### 2.3 <u>Create MEALY</u>:

```c
// utils/mealy_create.c
/* Used for loading contents of target EFLAM files into the buffer. */

bool mealy_create(
    mealy *target_mealy,        // Target MEALY for loading the language.
    char *filepaths[],          // Array of file paths passed linearly.
    int file_count,             // Total number of files connected to connector file.
    bool debug                  // Debugging option for getting runtime information.
);
```

1. As per the number of files, in loop, load a filestream into buffer.
2. Pass the buffer & target MEALY into the MEALY state machine.
3. Repeat.


### 2.4 <u>MEALY Byte Processor (Function)</u>:

```c
// mealy/mealy_engine/mealy_byte_proc.h
/* Checks the MEALY as per user given rules. */

int mealy_byte_proc(
    mealy *target_mealy,        // Address to target MEALY structure
    char *filepath,             // Name of the particular file/ its path
    char *fstream,              // Pointer to fstream containing MEALY rules
    bool debug                  // Tells if debugging logs are required
);
```

1. Initialize from start state.
2. Read each symbol one-by-one in sequence.
3. From current state, if transition is possible for the current symbol, then move to the next state.
4. If not, return `-1`.


### 2.5 <u>MEALY Special State Character Decoder</u>:

```c
// mealy/mealy_func/mealy_spl_state_char.c
/* Used for decoding certain special characters in strings. */

char mealy_spl_state_char(
    char spl_char,          // Special character found
    bool debug              // Debugging mode (ON/OFF)
);
```

1. If special character is `\\`, return `\\`.
2. Else if special character is `'`, return `\'`.
3. Else if special character is `n`, return `\n`.
4. Else if special character is `t`, return `\t`.
5. Else if special character is `b`, return `\b`.
6. Else if special character is `a`, return `\a`.
7. Else return whatever the character is.


### 2.6 <u>MEALY Special Symbol Character Decoder</u>:

```c
// mealy/mealy_func/mealy_spl_sym_char.c
/* Used for decoding certain special characters in symbols. */

char mealy_spl_sym_char(
    char spl_char,          // Special character found
    bool debug              // Debugging mode (ON/OFF)
);
```

1. If special character is `\\`, return `\\`.
2. Else if special character is `$`, return `$`.
3. Else if special character is `n`, return `\n`.
4. Else if special character is `t`, return `\t`.
5. Else if special character is `b`, return `\b`.
6. Else if special character is `a`, return `\a`.
7. Else return whatever the character is.


### 2.7 <u>MEALY Current State Inspector</u>:

```c
// mealy/mealy_func/mealy_cur_state_insp.c
/* Used for creating a state if it doesn't exist yet. */

bool mealy_cur_state_insp(
    mealy *target_mealy,                        // Target MEALY machine
    char *cur_state_name,                       // Current state name
    int *cur_state_index,                       // Relative index of current state
    bool debug                                  // Debugging mode (ON/OFF)
);
```

1. Check if the current state already exists in MEALY.
2. If existing:
    3. Don't make a new state & continue with existing one.
4. Else if not existing:
    5. Create it & add to the record of MEALY.
    6. Set all the initial attributes to this new state.


### 2.8 <u>MEALY State Type Inspector</u>:

```c
// mealy/mealy_func/mealy_state_type_insp.c
/* Used for checking if the state types are valid, and add valid ones. */

bool mealy_state_type_insp(
    mealy *target_mealy,                        // Target MEALY
    int cur_state_index,                    // Relative index of current state
    char *type,                             // String showing state type
    bool debug                              // Debugging mode (ON/OFF)
);
```

1. Check the passed string through series of state types:
    2. Check against `S` (meaning ACCEPT).
    3. Check against `A` (meaning ACCEPT).
    4. Otherwise throw error.


### 2.9 <u>MEALY Symbol Pump Inspector</u>:

```c
// mealy/mealy_func/mealy_sym_pump_insp.c
/* Used for checking if a supplied symbol already exists & adding if not. */

bool mealy_sym_pump_insp(
    mealy *target_mealy,                    // Target MEALY
    int cur_state_index,                    // Relative index of current state
    char *sym,                              // String representing symbol
    int *total_sym,                         // Count of total symbols for the transition
    bool debug                              // Debugging mode (ON/OFF)
);
```

1. Check from the array of symbols of current state if it contains the supplied symbol.
2. If yes, give user error that the symbol is already mentioned for the state.
3. If not, pump it to the array of symbols for the state.


### 2.10 <u>MEALY Transition State Inspector</u>:

```c
// mealy/mealy_func/mealy_trans_state_insp.c
/* Checks if a transition state exists or needs to be created. */

bool mealy_trans_state_insp(
    mealy *target_mealy,                // Target MEALY
    int cur_state_index,                // Relative index of current state
    char *trans_state_name,             // Name of transition state
    int *total_sym,                     // Total symbols to be pushed
    bool debug                          // Debugging mode (ON/OFF)
);
```

1. Check if the transition state already exists or not in MEALY.
2. If yes, just take its address as reference for modifications.
3. Else if not, create it and fill its details accordingly.
4. And then connect it to the current state's transition list as per number of symbols supplied.


### 2.11 <u>MEALY Other Symbol Inspector</u>:

```c
// mealy/mealy_func/mealy_other_sym_insp.c
/* Sets transition to a state for the remaining symbols. */

bool mealy_other_sym_insp (
    mealy *target_mealy,                // Target MEALY
    int cur_state_index,                // Relative index of current state
    char *trans_state_name,             // Name of transition state
    bool debug                          // Debugging mode (ON/OFF)
);
```

1. Check if an ELSE transition already exists.
    2. If yes, throw error stating that there can't be multiple ELSE transitions.
    3. Else if not, check if the state already exists.
        4. If not existing, create it.
        5. And then add its address as ELSE transition for current state.


### 2.12 <u>MEALY Stop State Feedback</u>:

```c
// mealy/mealy_func/mealy_stop_state_feed.c
/* Tells at which state the byte processor stopped. */

void mealy_stop_state_feed(
    int stop_state,             // Stop state for byte processor
    char *filepath,             // File path for particular file
    int row,                    // Row value of the file
    int column,                 // Column value of the file,
    bool debug                  // Debugging mode (ON/OFF)
);
```

- NOTE: State feedbacks might vary as per EFLAM version.


### 2.13 <u>MEALY String Tester</u>:

```c
// mealy/mealy_str_test.c
/* Passes a string through MEALY byte processor to check where it stops. */

mealy_state *mealy_str_test(
    mealy target_mealy,                 // Target MEALY
    char *symbols[],                // Array of strings
    int total_sym,                  // Total number of strings
    bool debug                      // Debugging mode (ON/OFF)
);
```

1. Give an error if there is no START state for the MEALY.
2. Begin from the START state.
3. Move from one state to another based on the corresponding address to the string in transition list & add its output to tape.
4. If none of the strings in transition list matches to current string & there is no ELSE transition, return this DUMP state.
5. Keep doing it until exhaust of all the strings.
6. Return the address of stop state at last.


### 2.14 <u>MEALY Machine Viewer</u>:

```c
// mealy/mealy_machine_view.c
/* Views the complete MEALY at a given instant. */

void mealy_machine_view(
    mealy target_mealy             // Target MEALY
);
```

1. First display the total number of transitions for MEALY.
2. Then display the name of START state.
3. For every state of MEALY, list the transitions in format of `[INDEX] SYMBOL -> STATE`.
4. Then display the ELSE state transition.


### 2.15 <u>MEALY Map Node (Structure)</u>:

```c
// mealy/mealy_map/mealy_map_node.h
/* Node that contains a MEALY mapping. */

typedef struct mealy_map_node {
    char *sym;                  // Symbol string
    int trans;                  // Transition state index
    char *output;               // Output for the particular transition
    bool *corresp;              // Tells if the correspondance rule is applied
    mealy_map_node *next;       // Pointer to next node
} mealy_map_node;
```


### 2.16 <u>MEALY Map Linked List (Structure)</u>:

```c
// mealy/mealy_map/mealy_map_ll.h
/* Linked list that maps MEALY transitions. */

typedef struct mealy_map_ll {
    mealy_map_node *head;           // Pointer to head of linked list
    mealy_map_node *tail;           // Pointer to tail of linked list
    int total_nodes;                // Total count of nodes
} mealy_map_ll;
```


### 2.17 <u>MEALY Add Symbol</u>

```c
// mealy/mealy_map/mealy_add_sym.c
/* Adds a node with symbol to the MEALY map. */

mealy_map_node *mealy_add_sym(
    mealy_map_ll *map,            // Address to MEALY map linked list
    char *sym,                    // Symbol string to add
    bool debug                    // Debugging mode (ON/OFF)
);
```

1. Check if any node exists or not.
    2. If not, create first node & place the symbol in it.
    3. Else if existing, create a node and place symbol in it before connecting it to last node.
4. Return the address to newly created node now.


### 2.18 <u>MEALY Map Viewer</u>:

```c
// mealy/mealy_map/mealy_map_view.c
/* Used for viewing everything that the map contains. */

bool mealy_map_view(
    mealy_map_ll map              // The linked list map containing transitions
);
```

1. Match the count, head, and tail to know if data was corrupted.
2. If there are no nodes in the map, say it.
3. Otherwise display the symbol and transition index that every node contains.


### 2.19 <u>MEALY Add Transition</u>:

```c
// mealy/mealy_map/mealy_add_trans.c
/* Used for adding index of a transition state to map's node. */

mealy_map_node *mealy_add_trans(
    mealy_map_ll *map,          // The linked list map containing transitions
    int trans,                  // Transition state index to fill nodes with
    int trans_start,            // Start point to fill with transition state index
    int trans_finish,           // Finish point to fill with transition state index
    bool debug                  // Debugging mode (ON/OFF)
);
```

1. Check if the start & finish point go out of bound as per available number of nodes, or mismatch in order.
    2. If yes, display error.
    3. If not, continue with flow.
4. Traverse to the node from where to start.
5. Fill every node from there to finish with the index.


### 2.20 <u>MEALY Eraser</u>:

```c
// mealy/mealy_eraser.c
/* Erases everything related to the particular MEALY. */

mealy *mealy_erase(
    mealy *target_mealy,        // Target MEALY
    bool debug                  // Debugging mode (ON/OFF)
);
```

1. For every state in MEALY:
    2. For every transition's map node:
        3. Copy address to next node to a buffer pointer.
        4. Free the current node.
        5. Move to next node using the buffer pointer.
    6. Then free all members inside the state.
    7. Free the state.
8. Free all the members inside the MEALY.
9. Free the MEALY itself.


### 2.21 <u>MEALY Add Output</u>:

```c
// mealy/mealy_map/mealy_add_out.c
/* Used for adding output of a transition to map's node. */

mealy_map_node *mealy_add_out(
    mealy_map_ll *map,          // The linked list map containing transitions
    char *output,               // Transition output to fill nodes with
    int out_start,              // Start point to fill with output
    int out_finish,             // Finish point to fill with output
    bool debug                  // Debugging mode (ON/OFF)
);
```

1. Check if the start & finish point go out of bound as per available number of nodes, or mismatch in order.
    2. If yes, display error.
    3. If not, continue with flow.
4. Traverse to the node from where to start.
5. Fill every node from there to finish with the index.


### 2.22 <u>MOORE Set ELSE Transition Output</u>:

```c
// mealy/mealy_func/mealy_set_else_out.c
/* Sets output for given transition. */

bool mealy_set_else_out(
    mealy *target_mealy,                // Target MEALY
    char *output,                       // Output to configure
    int cur_state_index,                // Current state index
    bool debug                          // Debugging mode (ON/OFF)
);
```


### 2.23 <u>MEALY Add Correspondant Output</u>:

```c
// mealy/mealy_map/mealy_add_corresp_out.c
/* Used for adding correspondant output of a transition to map's node. */

mealy_map_node *mealy_add_corresp_out(
    mealy_map_ll *map,          // The linked list map containing transitions
    bool corresp,               // Correspondant value to fill nodes with
    int corresp_start,          // Start point to fill with correspondant
    int corresp_finish,         // Finish point to fill with correspondant
    bool debug                  // Debugging mode (ON/OFF)
);
```

1. Check if the start & finish point go out of bound as per available number of nodes, or mismatch in order.
    2. If yes, display error.
    3. If not, continue with flow.
4. Traverse to the node from where to start.
5. Fill every node from there to finish with the index.


### 2.24 <u>MOORE Set ELSE Correspondant Output</u>:

```c
// mealy/mealy_func/mealy_set_corresp_else_out.c
/* Sets output as corresponding symbol for given ELSE transition. */

bool mealy_set_corresp_else_out(
    mealy *target_mealy,                // Target MEALY
    int cur_state_index,                // Current state index
    bool debug                          // Debugging mode (ON/OFF)
);
```



## 3. Test Cases & Benchmarks


### 3.1 <u>Print</u>:

```eflam
# A basic Mealy machine that accepts `print("STRING")` codes.

$0$ {'S','A'} |
    (' ','\n','\t')$0$ ['ALPHA'],
    ('print')$1$ ['BETA'],
    (@)$-1$ ['ERROR-1'];

$1$ |
    (' ','\t')$1$ ['CHARLIE'],
    ('(')$2$ ['DELTA'],
    (@)$-2$ ['ERROR-2'];

$2$ |
    (' ','\t')$2$ ['ECHO'],
    ('"')$3$ ['FOXTROT'],
    (@)$-3$ ['ERROR-3'];

$3$ |
    ('"')$4$ ['GOLF'],
    (@)$3$ ['HOTEL'];

$4$ |
    (' ','\t')$4$ ['INDIA'],
    (')')$5$ ['PRINT_STR'],
    (@)$-4$ ['ERROR-4'];

$5$ {'A'} |
    ('\n')$0$ ['JULIETTE'],
    (' ','\t')$5$ ['KILO'],
    (@)$-5$ ['ERROR-5'];
```



## 4. Special Notes


### 4.1 <u>Bootstrapped EFLAM MEALY</u>:

```eflam
# Bootstrapped code for EFLAM MEALY.

$0${'S','A'} | (' ','\n','\t')$0$, ('#')$1$, ('$')$2$, (@)$-1$;
$1${'A'} | ('\n')$0$, (@)$1$;
$2$ | (@)$3$, ('\\')$4$, ('$')$-2$;
$3$ | (@)$3$, ('\\')$4$, ('$')$5$;
$4$ | (@)$3$;
$5$ | (';')$0$, (' ','\n','\t')$5$, ('{')$6$, ('|')$13$, (@)$-3$;
$6$ | (' ','\n','\t')$6$, ('\'')$7$, ('}')$11$, (@)$-4$;
$7$ | (@)$8$, ('\\')$9$, ('\'')$-5$;
$8$ | (@)$8$, ('\\')$9$, ('\'')$10$;
$9$ | (@)$8$;
$10$ | (',')$6$, (' ','\n','\t')$10$, ('}')$11$, (@)$-6$;
$11$ | (';')$0$, (' ','\n','\t')$11$, ('|')$13$, (@)$-7$;
$12$ | (' ','\n','\t')$12$, (')')$25$, (@)$-8$;
$13$ | (' ','\n','\t')$13$, ('(')$14$, (@)$-9$;
$14$ | ('@')$12$, (' ','\n','\t')$14$, ('\'')$15$, (@)$-10$;
$15$ | (@)$16$, ('\\')$17$;
$16$ | (@)$16$, ('\\')$17$, ('\'')$18$;
$17$ | (@)$17$;
$18$ | (' ','\n','\t')$18$, (',')$19$, (')')$20$, (@)$-11$;
$19$ | ('\'')$15$, (' ','\n','\t')$19$, (@)$-12$;
$20$ | (' ','\n','\t')$20$, ('$')$21$, (@)$-13$;
$21$ | (@)$22$, ('\\')$23$;
$22$ | (@)$22$, ('\\')$23$, ('$')$24$;
$23$ | (@)$22$;
$24$ | (' ','\n','\t')$24$, ('[')$30$, (@)$-14$;
$25$ | (' ','\n','\t')$25$, ('$')$26$, (@)$-13$;
$26$ | (@)$27$, ('\\')$28$;
$27$ | (@)$27$, ('\\')$28$, ('$')$29$;
$28$ | (@)$27$;
$29$ | (' ','\n','\t')$29$, ('[')$37$, (@)$-14$;
$30$ | (' ','\n','\t')$30$, ('\'')$31$, ('C')$35$, $-15$;
$31$ | (@)$32$, ('\'')$-16$;
$32$ | (@)$32$, ('\'')$33$;
$33$ | (' ','\n','\t')$33$, (']')$34$, (@)$-17$;
$34$ | (';')$0$, (',')$13$, (' ','\n','\t')$34$, (@)$-18$;
$35$ | (' ','\n','\t')$35$, (']')$36$, (@)$-19$;
$36$ | (';')$0$, (',')$13$, (' ','\n','\t')$36$, (@)$-20$;
$37$ | (' ','\n','\t')$37$, ('\'')$38$, ('C')$42$, $-21$;
$38$ | (@)$39$, ('\'')$-22$;
$39$ | (@)$39$, ('\'')$40$;
$40$ | (' ','\n','\t')$40$, (']')$41$, (@)$-23$;
$41$ | (';')$0$, (',')$13$, (' ','\n','\t')$41$, (@)$-24$;
$42$ | (' ','\n','\t')$42$, (']')$43$, (@)$-25$;
$43$ | (';')$0$, (',')$13$, (' ','\n','\t')$43$, (@)$-25$;
```


### 4.2 <u>Differences From DFA Blueprint</u>:

#### 4.2.1 **MACHINE BLUEPRINT**:
- **Modified states:** 24, 29
- **Newly added states:** 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42

#### 4.2.2 **MEALY STATE STRUCT**:
```c
typedef struct mealy_state {
    char *name;
    bool type[TOTAL_TYPES];
    mealy_map_ll map;
    int else_trans;
    char *else_out;             // 1) New field that tells output from @
    bool else_corresp;          // 2) New field telling if @ output is correspondant
    int total_trans;
} mealy_state;
```

#### 4.2.3 **MEALY MAP NODE**:
```c
typedef struct mealy_map_node {
    char *sym;
    int trans;
    char *output;               // 1) New field telling output from transition
    bool *corresp;              // 2) New field tells if output is correspondant
    mealy_map_node *next;
} mealy_map_node;
```

#### 4.2.4 **NEW FILE TYPES**:
- `mealy_add_out.h` & `mealy_add_out.c`
- `mealy_set_else_trans_out.h` & `mealy_set_else_trans_out.c`
- `mealy_add_corresp_out.h` & `mealy_add_corresp_out.c`
- `mealy_set_corresp_else_out.h` & `mealy_set_corresp_else_out.c`

#### 4.2.5 **SUMMARY CHANGES**:
- `mealy_state.h`
- `mealy_map_node.h`
- `mealy_add_out.h` & `mealy_add_out.c`
- `mealy_set_else_trans_out.h` & `mealy_set_else_trans_out.c`
- `mealy_add_corresp_out.h` & `mealy_add_corresp_out.c`
- `mealy_set_corresp_else_out.h` & `mealy_set_corresp_else_out.c`

> NOTE: Eye these files & related components when modifying copied files.

#### 4.2.6 **WARNINGS**:
- Watch for variables which must be preserved before being washed in this modified version of machine.

---