# $\fbox{EFLAM's C Manual}$



## 1. Introduction


*EFLAM* is created with goal to provide compact syntax to represent state machines in mathematically established methods like **Deterministic Finite Automata**, **Mealy's Machine**, **Moore's Machine**, **Pushdown Automata**, etc. And to achieve it, a very compact syntax is built that can represent the states and its respective transitions together in a human readable format, with considerably sufficient flexibility in its code.



## 2. General Design


Most directories in root are named to represent a programming or scripting language, containing implementation for its code in service for the respective language user there. And inside those directories, there are directories which represent different *formal language* models.

These directories are generally divided into these key parts:
- **Elements:** These contain definition of certain structures.
- **Engine:** Runtime environment that enable the machines to run.
- **Functions:** Supports the whole EFLAM infrastructure with key functionalities.
- **Map:** Other structures that support implementation of larger elements.
- **User Service:** High-level functionalities for users to access without worrying about abstraction.



## 3. Deterministic Finite Automata (DFA)


### 3.1 Convention

Directories and files are named in format of `dfa_*/` or `dfa_*.*`, where `*` can contain any stream of legal characters used in naming file on ***Linux*** distributions. You can discard directories that are irrelavant to you language or required tools, in order to save space.

Users are advised to keep their EFLAM code files with extension of `.eflam` to keep them recognizable within their projects, though there is no restriction on the extension.


### 3.2 Grammar Rules

1. **<u>Commenting</u>:** Comments can be added starting with `#`, which when used on a line, it is considered a comment afterwards. It is a single line comment system.

1. **<u>State naming</u>:** States are written within `$`, for example `$MY_STATE$`. All characters within `$` are legal, but certain special characters like, `\\`, `\$`, `\n`, `\t`, `\b`, `\a`, etc, as seen they contain `\` to let the function know its a special character.

2. **<u>State type</u>:** State type can be defined as `{'type1', 'type2'}`. Here, `S` as type means *start* state while `A` means *accept* state. One type can be mentioned exactly once, and they can be mentioned in groups like `{'type1'}{'type2','type3'}`, or even left empty as `{}`. Not mentioning them means the state is regular state without any special type assigned.

3. **<u>String naming</u>:** Strings can be named within `'` like `'my_string'`. All characters within `$` are legal, but certain special characters like, `\\`, `\'`, `\n`, `\t`, `\b`, `\a`, etc, as seen they contain `\` to let the function know its a special character.

4. **<u>Other transition</u>:** Other transition is a form of transition where the transition is made to a mentioned state if none other possible symbol can make transition to another state. It is denoted by `@`.


### 3.3 Code Example

```eflam
# A basic DFA that accepts `print("STRING")` codes.
$0${'S','A'} | (' ','\n','\t')$0$, ('print')$1$, (@)$-1$;
$1$ | (' ','\t')$1$, ('(')$2$, (@)$-2$;
$2$ | (' ','\t')$2$, ('"')$3$, (@)$-3$;
$3$ | ('"')$4$, (@)$3$;
$4$ | (' ','\t')$4$, (')')$5$, (@)$-4$;
$5${'A'} | ('\n')$0$, (' ','\t')$5$, (@)$-5$;
```

- On first line we can see there is a comment written which starts with `#`, so it would be discarded by the engine and is kept solely for helping readers.
- `$` are called *state name enclosers*, before and after which, **newline**, **tabspace**, and **whitespace** can be inserted without affecting code's behavior. We can see many state names mentioned like `0` or `-1`, enclosed as `$0$`, `$-1$`, etc.
- The state names written on the left side of `|` (*transition operator*) are *current state*, while those on the right are the state they make transition to when a symbol is received.
- `{` and `}` are together known as *type enclosers*, and they define type of state (like start or accept). Within them we can write comma separated types as for state `0`.
- For state `0` as current state on 2nd line for example, we notice `(' ','\n','\t')` which are three symbols separated by comma, immediately after which is mentioned state `0` as `$0$`. Meaning for those three symbols, state `0` makes transition to state `0` (itself here).
- Immediately after the `$0$` on 2nd line, there is a comma (`,`) which separates symbols that direct the transition to another state, though the states could be repeatedly written or separated for clarity.
- `(@)$-1$` for example shows *other transition*, where if anything other than the previously mentioned symbols comes, then the state `0` (current state on that line) transists to state `-1`.
- At the end of many lines a semicolon (`;`) is used to tell the engine that description for the current state is over. Though current state can be mentioned again.


### 3.4 Special Points

|Special Symbols|Name|
|:-:|:-|
|`#`|Commenter|
|`$`|State enclosers|
|`{`,`}`|Type enclosers|
|`\|`|Transition operator|
|`(`,`)`|Symbols encloser|
|`,`|Comma|
|`@`|Other director|
|`;`|Definition closer|

- Current states for same state could be mentioned multiple times without any limit.
- Transition states for same state could be mentioned multiple times.
- Same symbol couldn't be repeatedly mentioned more that once, whether states differ or remain the same.
- If adding **whitespace**, **newline**, or **tabspace** doesn't change anything that defines DFA's data, they can be added accordingly before and/or after special symbols.


### 3.5 Connecting Library

1. Write your EFLAM code:
```c
/* EFLAM's DFA header in `include/` of respective language. */

#include "include/eflam_dfa.h"


/* Initializing the structure. */

dfa my_dfa = {
    .start_state = -1,
    .total_states = 0,
    .states = NULL
};


/* Providing path to EFLAM code files. */

char *filepaths[] = {"eflam_codes/print.eflam", "../../main_dir/lexer.eflam"};


/* Creating the DFA as per mentioned code:
dfa_crea(address_to_dfa, str_arr_to_paths, total_files, debug_mode) */

dfa_create(&my_dfa, filepaths, 2, false);


/* Passing the array of strings whatever way you want.
dfa_str_test(dfa_struct, symbol_str_array, total_symbols, debug_mode) */

dfa_str_test(my_dfa, symbols, 6, true);
```

2. Link to archive (static) binary when compiling whole project:
```c
gcc -o my_program main.c -L. -static-ldfa
```

---