# DETERMINISTIC FINITE AUTOMATA



## 1. About


- A very basic string validation model, telling if a string will be accepted or not.
- Makes just one transition at a time for one input symbol.
- Contains three states: States, accept state, and dead state.
- Doesn't have its own memory, all it can tell is whether a string will be accepted or not.


## 2. Implementation Idea


- First implementation idea was about writing every state and their respective transitions on a text file which is read, and strings can be passed based on that.
- However, it posed a risk on exposing grammar rules which implementers might want to keep closed-source. And with decoders, the program would suffer with performance.
- Better would be to combine it with graph model, where each *graph* contains at least one *state*, and each *state* has a *type* and *transitions*. Each transition is defined with a *symbol* and *state*.



## 3. Code Elements


### 3.1 <u>DFA State</u>:

```c
// dfa_units.h
/* Structure from which created instances represent unit state. */

struct dfa_state {
    bool type[2];                          // Tells if the state is accept state or not
    char **symbols;                         // Array of symbols from where this state transists
    char **states;                          // States where the current state makes transition to
    struct dfa_state *transitions[];        // Corresponding transitions for given symbols
};
```


### 3.2 <u>DFA</u>:

```c
// dfa_units.h
/* Structure representing whole DFA, enclosing its states. */

struct dfa {
    struct dfa_state *start_state;          // Initial/start state of the DFA
    struct dfa_state *states[];             // Array of states that DFA encloses
};
```


### 3.3 <u>Loading DFA Rules</u>:

```c
// dfa_rules_load.h
/* Loads the rules given by users and creates the DFA. */

bool dfa_rules_load(
    char dfa_rules[],                   // Pointer to file containing DFA rules
    struct dfa_state *target_dfa,       // Address to target DFA structure
    bool debug                          // Tells if debugging logs are required
);
```


### 3.4 <u>Embedding DFA Rules</u>:

```c
// embed_dfa_rules.h
/* Same as previous, but rules are directly embedded in the function. */

bool dfa_rules_embed(
    char *dfa_rules[],          // Array of transition rules
    struct *target_dfa,         // Address to target DFA structure
    bool debug                  // Tells if debugging logs are required
);
```


### 3.5 <u>DFA String Verifier</u>:

```c
// dfa_str_verif.h
/* DFA string verifier, that tells if it stops at accept state or not. */

bool dfa_str_verif(
    char *sym_seq[],            // Sequence of symbols in input string
    struct *target_dfa,         // Address to target DFA
    bool debug                  // Tells if debugging logs are required
);
```



## 4. Algorithm(s)


### 4.1 <u>DFA Rules</u>:

- Special characters (`|`, `(`, `)`, `,`, `@`, `$`, `#`, `;`) must use `$` before themselves if intended to be used literally.

```eflam
# For this representation, consider \n as endlines & \t as tabspaces.

0(S,A) | ( )0, (\t)0, (\n)0, ($$)2, (@)1, (#)16;
1(A) | (@)1, ($$)2, ( )3, (\t)3, (\n)3, ($()4;
2 | (@)1;
3 | ($()4, ( )3, (\t)3, (\n)3, (@)-1;
4 | ( )4, (\t)4, (\n)4, (S)5, (A)5, ($))6, (@)-2;
5 | ($,)4, ( )5, (\t)5, (\n)5, ($))6, (@)-2;
6(A) | ( )6, (\t)6, (\n)6, ($|)7, (@)-3;
7 | ( )7, (\t)7, (\n)7, ($()8, (@)-4;
8 | ($$)9, (@)8, ($))11, ($@)11, (\n)-1;
9 | (@)8;
10 | ( )10, (\t)10, (\n)10, (@)12;
11 | ( )11, (\t)11, (\n)11, ($))10, (@)-5;
12 | (@)12, ($$)13, ( )14, (\t)14, (\n)14;
13 | (@)14;
14 | ( )14, (\t)14, (\n)14, ($;)15, (@);
15(A) | ( )0, (\t)0, (\n)0, (#)16, (@)1;
16(A) | (@)16, (\n)0;
```

1. Keep reading the line and column number in order to produce coherent errors and warnings.
2. For multiple start states, throw error.
3. When reading the symbols or state names, don't add those `$` which are written as escape characters.
4. For fetched current state name, check if it already exists. If yes, throw error. Else save it.
5. For written types of state, set flag if valid type and throw error if invalid. Also throw error if they are repeated.
6. When reading transitioning state names, if they don't exist, create them.


### 4.2 <u>Loading DFA Rules</u>:

1. Check if the file exists or not.
2. If not, return error, else open the file in read mode.
3. Move to the end of the file, and check the size of it.
4. Allocate a string with size equivalent to size of file `+1` for `\0`.
5. Load the file stream into it.
5. Now start reading it and implement DFA accordingly.
6. Then follow steps as given in section `4.1`.


### 4.3 <u>Embedding DFA Rules</u>:

1. Read each string sequentially and implement the DFA accordingly.


### 4.4 <u>DFA String Verifier</u>:

1. Initialize from start state.
2. Read each symbol one-by-one in sequence.
3. From current state, if transition is possible for the current symbol, then move to to next state.
4. If not, return false.
5. If symbols exhaust, then check if the current state is an accept state or not. Return true if it is, else false.



## 5. Test Cases


### 5.1 <u>Print</u>:

```eflam
# A basic DFA that accepts `print("STRING");` codes.

q0(S,A) | (print)q1, ( )q0, (@)q7
q1 | ($()q2, ( )q1, (@)q7
q2 | ($")q3, ( )q2, (@)q7
q3 | ($")q4, (@)q3
q4 | ($))q5, ( )q0, (@)q7
q5 | (;)q7, ( )q0, (@)q7
q6(A) | ( )q0, (@)q7
q7(D)
```

---