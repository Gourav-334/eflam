# DETERMINISTIC FINITE AUTOMATA



## 1. About


A very basic string validation model, telling if a string will be accepted or not. Makes just one transition at a time for one input symbol. Contains three states: States, accept state, and dead state. Doesn't have its own memory, all it can tell is whether a string will be accepted or not.

Implementation of the automata machine is made in form of graph using structures. Users can use it in two forms, one by importing/loading the EFLAM file with written state transitions for the grammar of DFA. And second method is by embedding the grammar or transition within the function itself.



## 2. Implementation


### 2.1 <u>DFA State (Structure)</u>:

```c
// dfa/dfa_ops/dfa_units.h
/* Structure from which created instances represent unit state. */

typedef struct dfa_state {
    char *name;                             // States where the current state makes transition to
    bool type[TOTAL_TYPES];                 // Tells if the state is accept state or not
    dfa_map_ll map;                         // Symbols to state transition map
    int *else_trans;                        // Index of ELSE transition symbol
    int total_trans;                        // Number of transitions current state makes
} dfa_state;
```


### 2.2 <u>DFA (Structure)</u>:

```c
// dfa/dfa_ops/dfa_units.h
/* Structure representing whole DFA, enclosing its states. */

typedef struct dfa {
    int start_state;                        // Index of initial/start state of the DFA
    int total_states;                       // Number of states that the DFA contains
    struct dfa_state *states;               // Array of states that DFA encloses
} dfa;
```


### 2.3 <u>Create DFA</u>:

```c
// utils/dfa_create.c
/* Used for loading contents of target EFLAM files into the buffer. */

bool dfa_create(
    dfa *target_dfa,        // Target DFA for loading the language.
    char *filepaths[],      // Array of file paths passed linearly.
    int file_count,         // Total number of files connected to connector file.
    bool debug              // Debugging option for getting runtime information.
);
```

1. As per the number of files, in loop, load a filestream into buffer.
2. Pass the buffer & target DFA into the DFA state machine.
3. Repeat.


### 2.4 <u>DFA Byte Processor (Function)</u>:

```c
// dfa/dfa_engine/dfa_byte_proc.h
/* Checks the DFA as per user given rules. */

int dfa_byte_proc(
    dfa *target_dfa,            // Address to target DFA structure
    char *filepath,             // Name of the particular file/ its path
    char *fstream,              // Pointer to fstream containing DFA rules
    bool debug                  // Tells if debugging logs are required
);
```

1. Initialize from start state.
2. Read each symbol one-by-one in sequence.
3. From current state, if transition is possible for the current symbol, then move to the next state.
4. If not, return `-1`.


### 2.5 <u>DFA Special State Character Decoder</u>:

```c
// dfa/dfa_func/spl_state_char.c
/* Used for decoding certain special characters in strings. */

char dfa_spl_state_char(
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


### 2.6 <u>DFA Special Symbol Character Decoder</u>:

```c
// dfa/dfa_func/spl_sym_char.c
/* Used for decoding certain special characters in symbols. */

char dfa_spl_sym_char(
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


### 2.7 <u>DFA Current State Inspector</u>:

```c
// dfa/dfa_func/dfa_cur_state_insp.c
/* Used for creating a state if it doesn't exist yet. */

bool dfa_cur_state_insp(
    dfa *target_dfa,                            // Target DFA machine
    char *cur_state_name,                       // Current state name
    int *cur_state_index,                       // Relative index of current state
    bool debug                                  // Debugging mode (ON/OFF)
);
```

1. Check if the current state already exists in DFA.
2. If existing:
    3. Don't make a new state & continue with existing one.
4. Else if not existing:
    5. Create it & add to the record of DFA.
    6. Set all the initial attributes to this new state.


### 2.8 <u>DFA State Type Inspector</u>:

```c
// dfa/dfa_func/dfa_state_type_insp.c
/* Used for checking if the state types are valid, and add valid ones. */

bool dfa_state_type_insp(
    dfa *target_dfa,                        // Target DFA
    int cur_state_index,                    // Relative index of current state
    char *type,                             // String showing state type
    bool debug                              // Debugging mode (ON/OFF)
);
```

1. Check the passed string through series of state types:
    2. Check against `S` (meaning ACCEPT).
    3. Check against `A` (meaning ACCEPT).
    4. Otherwise throw error.


### 2.9 <u>DFA Symbol Pump Inspector</u>:

```c
// dfa/dfa_func/dfa_sym_pump_insp.c
/* Used for checking if a supplied symbol already exists & adding if not. */

bool dfa_sym_pump_insp(
    dfa *target_dfa,                        // Target DFA
    int cur_state_index,                    // Relative index of current state
    char *sym,                              // String representing symbol
    int *total_sym,                         // Count of total symbols for the transition
    bool debug                              // Debugging mode (ON/OFF)
);
```

1. Check from the array of symbols of current state if it contains the supplied symbol.
2. If yes, give user error that the symbol is already mentioned for the state.
3. If not, pump it to the array of symbols for the state.


### 2.10 <u>DFA Transition State Inspector</u>:

```c
// dfa/dfa_func/dfa_trans_state_insp.c
/* Checks if a transition state exists or needs to be created. */

bool dfa_trans_state_insp(
    dfa *target_dfa,                    // Target DFA
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


### 2.11 <u>DFA Other Symbol Inspector</u>:

```c
// dfa/dfa_func/dfa_other_sym_insp.c
/* Sets transition to a state for the remaining symbols. */

bool dfa_other_sym_insp (
    dfa *target_dfa,                    // Target DFA
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


### 2.12 <u>DFA Stop State Feedback</u>:

```c
// dfa/dfa_func/dfa_stop_state_feed.c
/* Tells at which state the byte processor stopped. */

void dfa_stop_state_feed(
    int stop_state,             // Stop state for byte processor
    char *filepath,             // File path for particular file
    int row,                    // Row value of the file
    int column                  // Column value of the file
);
```

- NOTE: State feedbacks might vary as per EFLAM version.


### 2.13 <u>DFA String Tester</u>:

```c
// dfa/dfa_str_test.c
/* Passes a string through DFA byte processor to check where it stops. */

dfa_state *dfa_str_test(
    dfa target_dfa,                 // Target DFA
    char *symbols[],                // Array of strings
    int total_sym,                  // Total number of strings
    bool debug                      // Debugging mode (ON/OFF)
);
```

1. Give an error if there is no START state for the DFA.
2. Begin from the START state.
3. Move from one state to another based on the corresponding address to the string in transition list.
4. If none of the strings in transition list matches to current string & there is no ELSE transition, return this DUMP state.
5. Keep doing it until exhaust of all the strings.
6. Return the address of stop state at last.


### 2.14 <u>DFA Machine Viewer</u>:

```c
// dfa/dfa_machine_viewer.c
/* Views the complete DFA at a given instant. */

void dfa_machine_viewer(
    dfa target_dfa             // Target DFA
);
```

1. First display the total number of transitions for DFA.
2. Then display the name of START state.
3. For every state of DFA, list the transitions in format of `[INDEX] SYMBOL -> STATE`.
4. Then display the ELSE state transition.


### 2.15 <u>DFA Map Node (Structure)</u>:

```c
// dfa/dfa_map/dfa_map_node.h
/* Node that contains a DFA mapping. */

typedef struct dfa_map_node {
    char *sym;                  // Symbol string
    int trans;                  // Transition state index
    dfa_map_node *next;         // Pointer to next node
} dfa_map_node;
```


### 2.16 <u>DFA Map Linked List (Structure)</u>:

```c
// dfa/dfa_map/dfa_map_ll.h
/* Linked list that maps DFA transitions. */

typedef struct dfa_map_ll {
    dfa_map_node *head;         // Pointer to head of linked list
    dfa_map_node *tail;         // Pointer to tail of linked list
    int total_nodes;            // Total count of nodes
} dfa_map_ll;
```


### 2.17 <u>DFA Add Symbol</u>

```c
// dfa/dfa_map/dfa_add_sym.c
/* Adds a node with symbol to the DFA map. */

dfa_map_node *dfa_add_sym(
    dfa_map_ll *map,            // Address to DFA map linked list
    char *sym,                  // Symbol string to add
    bool debug                  // Debugging mode (ON/OFF)
);
```

1. Check if any node exists or not.
    2. If not, create first node & place the symbol in it.
    3. Else if existing, create a node and place symbol in it before connecting it to last node.
4. Return the address to newly created node now.


### 2.18 <u>DFA Map Viewer</u>:

```c
// dfa/dfa_map/dfa_map_view.c
/* Used for viewing everything that the map contains. */

bool dfa_map_view(
    dfa_map_ll map              // The linked list map containing transitions
);
```

1. Match the count, head, and tail to know if data was corrupted.
2. If there are no nodes in the map, say it.
3. Otherwise display the symbol and transition index that every node contains.


### 2.19 <u>DFA Add Transition</u>:

```c
// dfa/dfa_map/dfa_add_trans.c
/* Used for adding index of a transition state to map's node. */

dfa_map_node *dfa_add_trans(
    dfa_map_ll *map,            // The linked list map containing transitions
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



## 3. Test Cases & Benchmarks


### 3.1 <u>Print</u>:

```eflam
# A basic DFA that accepts `print("STRING")` codes.

$0${'S','A'} | (' ','\n','\t')$0$, ('print')$1$, (@)$-1$;
$1$ | (' ','\t')$1$, ('(')$2$, (@)$-2$;
$2$ | (' ','\t')$2$, ('"')$3$, (@)$-3$;
$3$ | ('"')$4$, (@)$3$;
$4$ | (' ','\t')$4$, (')')$5$, (@)$-4$;
$5${'A'} | ('\n')$0$, (' ','\t')$5$, (@)$-5$;
```



## 4. Special Notes


### 4.1 <u>Syntax Rules</u>:

1. Every line either starts with comment or a state definition.
2. Comments start with `#`.
3. States might be followed by round brackets mentioning their type.
4. After that there is OR operator `|` which means now transitions will be written.
5. Transisiton symbols are written with symbols inside round bracket & then its equivalent state name outside.
6. If a transition symbol is `@`, then it is meant to be the transitions for rest of the symbols.
7. Transition states of right of `|` are separated by commas.
8. Finally, a `;` is added at the end.
9. A whole state definition could be broken down into multiple lines, and might include a comment at the end.
10. Symbols or state names which might include special bytes critical to EFLAM syntax, need to be followed by `$`.
11. Using `$` before an ordinary byte will add the byte without inclusion of `$`.
12. Transition definitions and states could be defined multiple times.
13. Multiple definitions must however mustn't have differing types & symbol transitions.


### 4.2 <u>Bootstrapped EFLAM DFA</u>:

- Special characters (`|`, `(`, `)`, `,`, `@`, `$`, `#`, `;`) must use `$` before themselves if intended to be used literally.

```eflam
# Bootstrapped code for EFLAM.

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
$24$ | (';')$0$, (',')$13$, (' ','\n','\t')$24$, (@)$-14$;
$25$ | (' ','\n','\t')$25$, ('$')$26$, (@)$-13$;
$26$ | (@)$27$, ('\\')$28$;
$27$ | (@)$27$, ('\\')$28$, ('$')$29$;
$28$ | (@)$27$;
$29$ | (';')$0$, (',')$13$, (' ','\n','\t')$29$, (@)$-14$;
```

---