# MEALY MACHINE



## 1. About


A very basic string validation model, telling if a string will be accepted or not. Makes just one transition at a time for one input symbol. Contains three states: States, accept state, and dead state. Doesn't have its own memory, all it can tell is whether a string will be accepted or not.

Implementation of the automata machine is made in form of graph using structures. It has certain differences from DFA's implementation:
- Change in byte processing automata to capture current state output.
- Introduction of a linked list that stores the output strings.
- Addition of a new field in state structure that tells its output.



## 2. Implementation


### 2.1 <u>Mealy State (Structure)</u>://

```c
// mealy/mealy_ops/mealy_units.h
/* Structure from which created instances represent unit state. */

typedef struct mealy_state {
    char *name;                             // States where the current state makes transition to
    char *output;                           // Output string for current state
    bool type[TOTAL_TYPES];                 // Tells if the state is accept state or not
    mealy_map_ll map;                       // Symbols to state transition map
    int else_trans;                         // Index of ELSE transition symbol
    int total_trans;                        // Number of transitions current state makes
} mealy_state;
```


### 2.2 <u>Mealy (Structure)</u>:

```c
// mealy/mealy_ops/mealy_units.h
/* Structure representing whole Mealy, enclosing its states. */

typedef struct mealy {
    int start_state;                        // Index of initial/start state of the Mealy
    int total_states;                       // Number of states that the Mealy contains
    struct mealy_state *states;             // Array of states that Mealy encloses
} mealy;
```


### 2.3 <u>Create Mealy</u>:

```c
// mealy/mealy_create.c
/* Used for loading contents of target EFLAM files into the buffer. */

bool mealy_create(
    mealy *target_mealy,        // Target Mealy for loading the language.
    char *filepaths[],          // Array of file paths passed linearly.
    int file_count,             // Total number of files connected to connector file.
    bool debug                  // Debugging option for getting runtime information.
);
```

1. As per the number of files, in loop, load a filestream into buffer.
2. Pass the buffer & target Mealy into the Mealy state machine.
3. Repeat.


### 2.4 <u>Mealy Byte Processor (Function)</u>:

```c
// mealy/mealy_engine/mealy_byte_proc.h
/* Checks the Mealy as per user given rules. */

int mealy_byte_proc(
    mealy *target_mealy,            // Address to target Mealy structure
    char *filepath,                 // Name of the particular file/ its path
    char *fstream,                  // Pointer to fstream containing Mealy rules
    bool debug                      // Tells if debugging logs are required
);
```

1. Initialize from start state.
2. Read each symbol one-by-one in sequence.
3. From current state, if transition is possible for the current symbol, then move to the next state.
4. If not, return `-1`.


### 2.5 <u>Mealy Special State Character Decoder</u>:

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


### 2.6 <u>Mealy Special Symbol Character Decoder</u>:

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


### 2.7 <u>Mealy Current State Inspector</u>:

```c
// mealy/mealy_func/mealy_cur_state_insp.c
/* Used for creating a state if it doesn't exist yet. */

bool mealy_cur_state_insp(
    mealy *target_mealy,                        // Target Mealy machine
    char *cur_state_name,                       // Current state name
    int *cur_state_index,                       // Relative index of current state
    bool debug                                  // Debugging mode (ON/OFF)
);
```

1. Check if the current state already exists in Mealy.
2. If existing:
    3. Don't make a new state & continue with existing one.
4. Else if not existing:
    5. Create it & add to the record of DFA.
    6. Set all the initial attributes to this new state.


### 2.8 <u>Mealy State Type Inspector</u>:

```c
// mealy/mealy_func/mealy_state_type_insp.c
/* Used for checking if the state types are valid, and add valid ones. */

bool mealy_state_type_insp(
    mealy *target_mealy,                    // Target Mealy
    int cur_state_index,                    // Relative index of current state
    char *type,                             // String showing state type
    bool debug                              // Debugging mode (ON/OFF)
);
```

1. Check the passed string through series of state types:
    2. Check against `S` (meaning ACCEPT).
    3. Check against `A` (meaning ACCEPT).
    4. Otherwise throw error.


### 2.9 <u>Mealy Symbol Pump Inspector</u>:

```c
// mealy/mealy_func/mealy_sym_pump_insp.c
/* Used for checking if a supplied symbol already exists & adding if not. */

bool mealy_sym_pump_insp(
    mealy *target_mealy,                    // Target Mealy
    int cur_state_index,                    // Relative index of current state
    char *sym,                              // String representing symbol
    int *total_sym,                         // Count of total symbols for the transition
    bool debug                              // Debugging mode (ON/OFF)
);
```

1. Check from the array of symbols of current state if it contains the supplied symbol.
2. If yes, give user error that the symbol is already mentioned for the state.
3. If not, pump it to the array of symbols for the state.


### 2.10 <u>Mealy Transition State Inspector</u>:

```c
// mealy/mealy_func/mealy_trans_state_insp.c
/* Checks if a transition state exists or needs to be created. */

bool mealy_trans_state_insp(
    mealy *target_mealy,                // Target Mealy
    int cur_state_index,                // Relative index of current state
    char *trans_state_name,             // Name of transition state
    int *total_sym,                     // Total symbols to be pushed
    bool debug                          // Debugging mode (ON/OFF)
);
```

1. Check if the transition state already exists or not in DFA.
2. If yes, just take its address as reference for modifications.
3. Else if not, create it and fill its details accordingly.
4. And then connect it to the current state's transition list as per number of symbols supplied.


### 2.11 <u>Mealy Other Symbol Inspector</u>:

```c
// mealy/mealy_func/mealy_other_sym_insp.c
/* Sets transition to a state for the remaining symbols. */

bool mealy_other_sym_insp (
    mealy *target_mealy,                // Target Mealy
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


### 2.12 <u>Mealy Stop State Feedback</u>:

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


### 2.13 <u>Mealy String Tester</u>://

```c
// mealy/mealy_str_test.c
/* Passes a string through Mealy byte processor to check where it stops. */

mealy_state *mealy_str_test(
    mealy target_mealy,             // Target Mealy
    char *symbols[],                // Array of strings
    sym_tape_ll *tape,              // Tape to write output on
    int total_sym,                  // Total number of strings
    bool debug                      // Debugging mode (ON/OFF)
);
```

1. Give an error if there is no START state for the DFA.
2. Begin from the START state & add its output to tape.
3. Move from one state to another based on the corresponding address to the string in transition list & add its output to tape.
4. If none of the strings in transition list matches to current string & if there is no ELSE transition (add its output to tape if exists), return this DUMP state.
5. Keep doing it until exhaust of all the strings.
6. Return the address of stop state at last.


### 2.14 <u>Mealy Machine Viewer</u>://

```c
// mealy/mealy_machine_view.c
/* Views the complete Mealy at a given instant. */

void mealy_machine_view(
    mealy target_mealy             // Target Mealy
);
```

1. First display the total number of transitions for DFA.
2. Then display the name of START state with its output.
3. For every state of DFA, list the transitions in format of `[INDEX] SYMBOL -> STATE (OUTPUT)`.
4. Then display the ELSE state transition with its output.


### 2.15 <u>Mealy Map Node (Structure)</u>:

```c
// mealy/mealy_map/mealy_map_node.h
/* Node that contains a Mealy mapping. */

typedef struct mealy_map_node {
    char *sym;                      // Symbol string
    int trans;                      // Transition state index
    mealy_map_node *next;           // Pointer to next node
} mealy_map_node;
```


### 2.16 <u>Mealy Map Linked List (Structure)</u>:

```c
// mealy/mealy_map/mealy_map_ll.h
/* Linked list that maps Mealy transitions. */

typedef struct mealy_map_ll {
    struct mealy_map_node *head;         // Pointer to head of linked list
    struct mealy_map_node *tail;         // Pointer to tail of linked list
    int total_nodes;                     // Total count of nodes
} mealy_map_ll;
```


### 2.17 <u>Mealy Add Symbol</u>

```c
// mealy/mealy_map/mealy_add_sym.c
/* Adds a node with symbol to the Mealy map. */

mealy_map_node *mealy_add_sym(
    mealy_map_ll *map,          // Address to Mealy map linked list
    char *sym,                  // Symbol string to add
    bool debug                  // Debugging mode (ON/OFF)
);
```

1. Check if any node exists or not.
    2. If not, create first node & place the symbol in it.
    3. Else if existing, create a node and place symbol in it before connecting it to last node.
4. Return the address to newly created node now.


### 2.18 <u>Mealy Map Viewer</u>:

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


### 2.19 <u>Mealy Add Transition</u>:

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


### 2.20 <u>Mealy Eraser</u>://

```c
// mealy/mealy_eraser.c
/* Erases everything related to the particular Mealy. */

mealy *mealy_erase(
    mealy *target_mealy,            // Target Mealy
    bool debug                      // Debugging mode (ON/OFF)
);
```

1. For every state in Mealy:
    2. For every transition's map node:
        3. Copy address to next node to a buffer pointer.
        4. Free the current node.
        5. Move to next node using the buffer pointer.
    6. Then free all members inside the state.
    7. Free the state.
8. Free all the members inside the Mealy.
9. Free the Mealy itself.


### 2.21 <u>State Output Inspector</u>:

```c
// mealy/mealy_func/mealy_state_out_insp.c
/* Inspects and makes sure that every state produces an output. */

bool mealy_state_out_insp(
    mealy target_mealy,             // Target Mealy
    bool debug                      // Debugging mode (ON/OFF)
);
```

1. Move through all the states of the Mealy machine and check if they contain output.
2. Produce error for every state that doesn't contain the output.


### 2.22 <u>Mealy Set State Output</u>:

```c
// mealy/mealy_func/mealy_set_state_out.c
/* Pushes a string as output to particular Mealy machine state. */

bool mealy_set_state_out(
    mealy_state *cur_state_addr,        // Current state address
    char *output,                       // Output string
    bool debug                          // Debugging mode (ON/OFF)
);
```

1. For the output of state, reserve memory for state's output as per input.
2. Fill the memory with input string.



## 3. Test Cases & Benchmarks


### 3.1 <u>Print</u>:

```eflam
# A basic DFA that accepts `print("STRING")` codes & saves them to a tape.

$0$ ['NULL'] {'S','A'} | (' ','\n','\t')$0$, ('print')$1$, (@)$-1$;
$1$ ['PRINT_OPEN'] | (' ','\t')$1$, ('(')$2$, (@)$-2$;
$2$ ['BRACKET_OPEN'] | (' ','\t')$2$, ('"')$3$, (@)$-3$;
$3$ ['STR_START'] | ('"')$4$, (@)$3$;
$4$ ['STR_RECEIVE'] | (' ','\t')$4$, (')')$5$, (@)$-4$;
$5$ ['BRACKET_CLOSE'] {'A'} | ('\n')$0$, (' ','\t')$5$, (@)$-5$;
```



## 4. Special Notes


### 4.1 <u>EFLAM DFA Code For Mealy</u>:

```eflam
# Bootstrapped code for EFLAM's Mealy machine.

$0$ {'S','A'} | (' ','\n','\t')$0$, ('#')$1$, ('$')$2$, (@)$-1$;
$1$ {'A'} | ('\n')$0$, (@)$1$;
$2$ | (@)$3$, ('\\')$4$, ('$')$-2$;
$3$ | (@)$3$, ('\\')$4$, ('$')$5$;
$4$ | (@)$3$;
$5$ | (' ','\n','\t')$5$, ('[')$30$, (@)$-3$;
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
$24$ | (';')$0$, (',')$13$, (' ','\n','\t')$24$, (@)$-14$;
$25$ | (' ','\n','\t')$25$, ('$')$26$, (@)$-13$;
$26$ | (@)$27$, ('\\')$28$;
$27$ | (@)$27$, ('\\')$28$, ('$')$29$;
$28$ | (@)$27$;
$29$ | (';')$0$, (',')$13$, (' ','\n','\t')$29$, (@)$-14$;
$30$ | (' ','\n','\t')$30$, ('\'')$31$, (@)$-15$;
$31$ | ('\'')$-16$, ('\\')$35$, (@)$32$;
$32$ | (@)$32$, ('\'')$33$, ('\\')$35$;
$33$ | (' ','\n','\t')$33$, (']')$34$, (@)$-16$;
$34$ | (';')$0$, ('{')$6$, ('|')$13$, (' ','\n','\t')$13$, (@)$-17$;
$35$ | (@)$32$;
```

---