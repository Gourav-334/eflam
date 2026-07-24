# DETERMINISTIC FINITE AUTOMATA



## 1. About


- A very basic string validation model, telling if a string will be accepted or not.
- Makes just one transition at a time for one input symbol.
- Contains three states: States, accept state, and dead state.
- Doesn't have its own memory, all it can tell is whether a string will be accepted or not.


## 2. Implementation


- Implementation of the automata machine is made in form of graph using structures.
- Users can use it in two forms, one by importing/loading the EFLAM file with written state transitions for the grammar of DFA.
- And second method is by embedding the grammar or transition within the function itself.



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
    struct dfa *target_dfa,       // Address to target DFA structure
    bool debug                          // Tells if debugging logs are required
);
```


### 3.4 <u>Embedding DFA Rules</u>:

```c
// embed_dfa_rules.h
/* Same as previous, but rules are directly embedded in the function. */

bool dfa_rules_embed(
    char *dfa_rules[],          // Array of transition rules
    struct dfa *target_dfa,     // Address to target DFA structure
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

0(S,A) | ( ,\t,\n)0, ($$)2, (#)17, (@)1;
1(A) | ( ,\t,\n)3, ($()4, (@)1;
2 | (@)1;
3 | ( ,\t,\n)3, ($()4, (@)-1;
4 | ( ,\t,\n)4, (S,A)5, (@)-2;
5 | ($,)4, ( ,\t,\n)5, ($))6, (@)-2;
6(A) | ( ,\t,\n)6, ($|)7, (@)-3;
7 | ( ,\t,\n)7, ($()8;
8 | ($$)10, ($@)12, ($,)-4, (@)9;
9 | ($,)8, ($$)10, ($))11, (@)9;
10 | (@)9;
11 | ( ,\t,\n)11, ($$)14, (@)13;
12 | ($()11, (@)-5
13 | ($,)7, ($$)14, ( ,\t,\n)15, ($;)16, (@)13;
14 | (@)13;
15 | ($,)7, ( ,\t,\n)15, ($;)16;
16(A) | ($#)17, ( ,\t,\n)0, (@)1;
17(A) | (\n)0, ( ,\t,\n)17;
```

#### **STATE `0`:**
1. Do nothing if `#`, ` `, `\t`, or `\n` comes up.
2. Else if something else is encountered, allocate `1` byte for string & push the character into it.

#### **STATE `1`:**
1. Do nothing if `$`, ` `, `\t`, or `\n` comes up.
2. If `(` comes up, expand string memory by `1` byte & assign `\0` to it, then check if state already exists or not. If yes, else throw error. Else add this as a new state.
3. Else if something else is encountered, expand string memory by `1` byte & push the character into it.

#### **STATE `2`:**
1. No matter what appears, do nothing.

#### **STATE `3`:**
1. If `(` comes up, expand string memory by `1` byte & assign `\0` to it, then check if state already exists or not. If not, add, else throw error.
2. Else throw error for ` `, `\t`, `\n` in state name.

#### **STATE `4`:**
1. Do nothing if ` `, `\t`, or `\n` comes up.
2. If `S` or `A` comes up, if its already set for same state then throw error. Else set it. But if its `S`, which already exists in DFA, then throw error.

#### **STATE `5`:**
1. Do nothing if `)`, ` `, `\t`, or `\n` comes up.
2. Else throw error for unknown state type being encountered.

#### **STATE `6`:**
1. Do nothing if `|`, ` `, `\t`, or `\n` comes up.
2. Else throw error for unnecessary string being encountered.

#### **STATE `7`:**
1. Do nothing if `(`, ` `, `\t`, or `\n` comes up.
2. Else throw error for unknown state type being encountered.

#### *STATE `8`:**
1. If `(` comes up, expand string memory by `1` byte & assign `\0` to it, then check if transition (string) already exists or not. If yes, else throw error. Else add this as a new state.
2. Else expand the memory under string by `1` and add the current character to it.

#### **STATE `9`:**
1. No matter what appears, do nothing.

#### **STATE `10`:**
1. No matter what appears, do nothing.


### 4.2 <u>Loading DFA Rules</u>:

1. Check if the file exists or not.
2. If not, return error, else open the file in read mode.
3. Move to the end of the file, and check the size of it.
4. Allocate a string with size equivalent to size of file `+1` for `\0`.
5. Load the file stream into it.
5. Now start reading it and implement DFA accordingly using steps from `4.1`.


### 4.3 <u>Embedding DFA Rules</u>:

1. Read each string sequentially and implement the DFA accordingly.
2. Read the steps from section `4.1`.


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
```

---