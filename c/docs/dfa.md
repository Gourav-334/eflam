# DETERMINISTIC FINITE AUTOMATA



## 1. About


A very basic string validation model, telling if a string will be accepted or not. Makes just one transition at a time for one input symbol. Contains three states: States, accept state, and dead state. Doesn't have its own memory, all it can tell is whether a string will be accepted or not.

Implementation of the automata machine is made in form of graph using structures. Users can use it in two forms, one by importing/loading the EFLAM file with written state transitions for the grammar of DFA. And second method is by embedding the grammar or transition within the function itself.



## 2. Implementation


### 2.1 <u>File Loader</u>


### 2.2 <u>DFA State (Structure)</u>:

```c
// dfa/dfa_ops/dfa_units.h
/* Structure from which created instances represent unit state. */

typedef struct dfa_state {
    char *name;                             // States where the current state makes transition to
    bool type[TOTAL_TYPES];                 // Tells if the state is accept state or not
    char **symbols;                         // Array of symbols from where this state transists
    struct dfa_state **trans;               // Corresponding transitions for given symbols
    struct dfa_state *else_trans;
    int total_trans;                        // Number of transitions current state makes
} dfa_state;
```


### 2.3 <u>DFA (Structure)</u>:

```c
// dfa/dfa_ops/dfa_units.h
/* Structure representing whole DFA, enclosing its states. */

typedef struct dfa {
    struct dfa_state *start_state;          // Initial/start state of the DFA
    int total_states;                       // Number of states that the DFA contains
    struct dfa_state *states;               // Array of states that DFA encloses
} dfa;
```


### 2.6 <u>DFA Machine (Function)</u>:

```c
// dfa/dfa_ops/dfa_machine.h
/* DFA machine, that tells if it stops at accept state or not. */

int dfa_machine(
    char *sym_seq[],            // Sequence of symbols in input string
    struct *target_dfa,         // Address to target DFA
    bool debug                  // Tells if debugging logs are required
);
```

1. Initialize from start state.
2. Read each symbol one-by-one in sequence.
3. From current state, if transition is possible for the current symbol, then move to to next state.
4. If not, return `-1`.


### 2.7 <u>DFA Create Current State</u>:

```c
// dfa/dfa_ops/dfa_cur_create_state.c
/* Used for creating a state if it doesn't exist yet. */

bool dfa_fix_cur_state(
    dfa *target_dfa,                            // Target DFA machine
    char *name,                                 // Name of state to be created
    int *name_size,                             // Length of state's name
    char *cur_state_name,                       // Current state name
    int *cur_state_size,                        // Size of current state name
    dfa_state *cur_state_addr,                  // Address of current state
    bool debug                                  // Debugging mode (ON/OFF)
);
```

1. Check if the current state already exists in DFA.
2. If existing:
    3. Don't make a new state & continue with existing one.
    4. Store the properties/type of current state.
5. Else if not existing:
    6. Create it & add to the record of DFA.
    7. Set all the initial attributes to this new state.



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
$4$ | (@)$3$, ('$')$5$;
$5$ | (';')$0$, (' ','\n','\t')$5$, ('{')$6$, ('|')$13$, (@)$-3$;
$6$ | (' ','\n','\t')$6$, ('\'')$7$, ('}')$11$, (@)$-4$;
$7$ | (@)$8$, ('\\')$9$, ('\'')$-5$;
$8$ | (@)$8$, ('\\')$9$, ('\'')$10$;
$9$ | (@)$8$, ('\'')$10$;
$10$ | (',')$6$, (' ','\n','\t')$10$, ('}')$11$, (@)$-6$;
$11$ | (';')$0$, (' ','\n','\t')$11$, ('|')$13$, (@)$-7$;
$12$ | (' ','\n','\t')$12$, (')')$20$, (@)$-8$;
$13$ | (' ','\n','\t')$13$, ('(')$14$, (@)$-9$;
$14$ | ('@')$12$, (' ','\n','\t')$14$, ('\'')$15$, (@)$-10$;
$15$ | (@)$16$, ('\\')$17$;
$16$ | (@)$16$, ('\\')$17$, ('\'')$18$;
$17$ | (@)$17$, ('\'')$18$;
$18$ | (' ','\n','\t')$18$, (',')$19$, (')')$20$, (@)$-11$;
$19$ | ('\'')$15$, (' ','\n','\t')$19$, (@)$-12$;
$20$ | (' ','\n','\t')$20$, ('$')$21$, (@)$-13$;
$21$ | (@)$22$, ('\\')$23$;
$22$ | (@)$22$, ('\\')$23$, ('$')$24$;
$23$ | (@)$22$, ('$')$24$;
$24$ | (';')$0$, (' ','\n','\t')$24$, (@)$-14$;
```

---