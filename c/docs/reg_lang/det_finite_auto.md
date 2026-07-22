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
/* Structure from which created instances represent unit state. */

struct dfa_state {
    _Bool accept:1;             // Tells if the state is accept state or not
    char **symbols;             // Array of symbols from where this state transists
    struct *transitions[];      // Corresponding transitions for given symbols
};
```


### 3.2 <u>DFA</u>:

```c
/* Structure representing whole DFA, enclosing its states. */

struct dfa {
    struct *start_state;        // Initial/start state of the DFA
    struct *states[];           // Array of states that DFA encloses
};
```


### 3.3 <u>Loading DFA Rules</u>:

```c
/* Loads the rules given by users and creates the DFA. */

_Bool dfa_rules_load(
    FILE *dfa_rules,        // Pointer to file containing DFA rules
    struct *target_dfa      // Address to target DFA structure
);
```


### 3.4 <u>Embedding DFA Rules</u>:

```c
/* Same as previous, but rules are directly embedded in the function. */

_Bool dfa_rules_embed(
    char *dfa_rules[],      // Array of transition rules
    struct *target_dfa      // Address to target DFA structure
);
```


### 3.5 <u>DFA String Verifier</u>:

```c
// DFA string verifier, that tells if it stops at accept state or not.

_Bool dfa_str_verif(
    char *sym_seq[],        // Sequence of symbols in input string
    struct *dfa             // Address to target DFA
);
```



## 4. Algorithm(s)


### 4.1 <u>DFA Transitions Rules</u>:

- Special characters (`|`, `(`, `)`, `,`, `@`, `$`, `#`) must use `$` before themselves if intended to be used literally.

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

- For each string, do the following.
- Start reading from left while skipping spaces and tabs.
- When something else encounters, keep pushing them to state name string.
- If the state already exists, return error.

---