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
    char **symbols;                         // Array of symbols from where this state transists
    int *trans;                             // Corresponding transitions for given symbols
    int *else_trans;                        // Index of ELSE transition symbol
    int total_trans;                        // Number of transitions current state makes
} dfa_state;
```


### 2.2 <u>DFA (Structure)</u>:

```c
// dfa/dfa_ops/dfa_units.h
/* Structure representing whole DFA, enclosing its states. */

typedef struct dfa {
    struct dfa_state *start_state;          // Initial/start state of the DFA
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
/* DFA machine, that tells if it stops at accept state or not. */

int dfa_byte_proc(
    char *sym_seq[],            // Sequence of symbols in input string
    struct *target_dfa,         // Address to target DFA
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
    dfa_state **cur_state_addr,                 // Address of current state
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
    dfa_state *cur_state_addr,              // Address of current state
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
    dfa_state *cur_state_addr,              // Address of current state
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
/* Checks if a transition state exists or need to be created. */

bool dfa_trans_state_insp(
    dfa *target_dfa,                    // Target DFA
    dfa_state **cur_state_addr,         // Current state's address
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
    dfa_state **cur_state_addr,         // Current state's address
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