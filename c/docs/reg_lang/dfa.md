# DETERMINISTIC FINITE AUTOMATA



## 1. About


A very basic string validation model, telling if a string will be accepted or not. Makes just one transition at a time for one input symbol. Contains three states: States, accept state, and dead state. Doesn't have its own memory, all it can tell is whether a string will be accepted or not.

Implementation of the automata machine is made in form of graph using structures. Users can use it in two forms, one by importing/loading the EFLAM file with written state transitions for the grammar of DFA. And second method is by embedding the grammar or transition within the function itself.



## 2. Implementation


### 2.1 <u>Key Elements</u>:

- `str` string buffer
- `str_size` integer
- Members of `target_dfa`
- Members of `target_dfa -> states`
- `else_exists` flag


### 2.2 <u>DFA State (Structure)</u>:

```c
// det_finite_auto/dfa_units.h
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
// det_finite_auto/dfa_units.h
/* Structure representing whole DFA, enclosing its states. */

typedef struct dfa {
    struct dfa_state *start_state;          // Initial/start state of the DFA
    int total_states;                       // Number of states that the DFA contains
    struct dfa_state *states;               // Array of states that DFA encloses
} dfa;
```


### 3.4 <u>Loading DFA Rules (Function)</u>:

```c
// det_finite_auto/dfa_rules_load.h
/* Loads the rules given by users and creates the DFA. */

bool dfa_rules_load(
    char dfa_rules[],                   // Pointer to file containing DFA rules
    struct dfa *target_dfa,       // Address to target DFA structure
    bool debug                          // Tells if debugging logs are required
);
```

1. Check if the file exists or not.
2. If not, return error, else open the file in read mode.
3. Move to the end of the file, and check the size of it.
4. Allocate a string with size equivalent to size of file `+1` for `\0`.
5. Load the file stream into it.
5. Now start reading it and implement DFA.


### 3.5 <u>Embedding DFA Rules (Function)</u>:

```c
// det_finite_auto/embed_dfa_rules.h
/* Same as previous, but rules are directly embedded in the function. */

bool dfa_rules_embed(
    char *dfa_rules[],          // Array of transition rules
    struct dfa *target_dfa,     // Address to target DFA structure
    bool debug                  // Tells if debugging logs are required
);
```

1. Read each string sequentially and implement the DFA accordingly.
2. Now start implementing the DFA.


### 3.6 <u>DFA String Verifier (Function)</u>:

```c
// det_finite_auto/dfa_str_verif.h
/* DFA string verifier, that tells if it stops at accept state or not. */

bool dfa_str_verif(
    char *sym_seq[],            // Sequence of symbols in input string
    struct *target_dfa,         // Address to target DFA
    bool debug                  // Tells if debugging logs are required
);
```

1. Initialize from start state.
2. Read each symbol one-by-one in sequence.
3. From current state, if transition is possible for the current symbol, then move to to next state.
4. If not, return false.
5. If symbols exhaust, then check if the current state is an accept state or not. Return true if it is, else false.



## 4. Test Cases & Benchmarks


### 4.1 <u>Print</u>:

```eflam
# A basic DFA that accepts `print("STRING");` codes.

q0(S,A) | (print)q1, ( )q0, (@)q7;
q1 | ($()q2, ( )q1, (@)q7;
q2 | (")q3, ( )q2, (@)q7;
q3 | (")q4, (@)q3;
q4 | ($))q5, ( )q0, (@)q7;
q5 | (;)q7, ( )q0, (@)q7;
q6(A) | ( )q0, (@)q7;
```



## 5. Special Notes


### 3.1 <u>Bootstrapped EFLAM DFA</u>:

- Special characters (`|`, `(`, `)`, `,`, `@`, `$`, `#`, `;`) must use `$` before themselves if intended to be used literally.

```eflam
# For this representation, consider \n as endlines & \t as tabspaces.

0(S,A) | ( ,\t,\n)0, ($$)2, (#)16, (@)1;
1(A) | ($$)2, ( ,\t,\n)3, ($()4, (@)1;
2 | ( ,\t,\n)-1, (@)1;
3 | ( ,\t,\n)3, ($()4, (@)-1;
4 | ( ,\t,\n)4, (S,A)5, ($))6, (@)-2;
5 | ($,)4, ( ,\t,\n)5, ($))6, (@)-2;
6(A) | ( ,\t,\n)6, ($|)7, (@)-3;
7 | ( ,\t,\n)7, ($()8;
8 | ($$)10, ($@)12, ($,)-4, (@)9;
9 | ($,)8, ($$)10, ($))11, (@)9;
10 | (@)9;
11 | ( ,\t,\n)11, ($$)14, (@)13;
12 | ($()11, (@)-5
13 | ($,)7, ($$)14, ( ,\t,\n)15, ($;)0, (@)13;
14 | ( ,\t,\n)-1, (@)13;
15 | ($,)7, ( ,\t,\n)15, ($;)0;
16(A) | (\n)0, (@)16;
```

---