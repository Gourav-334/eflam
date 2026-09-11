# Embeddable Formal Language and Automata Models


## 1. Introduction

EFLAM (*Embeddable Formal Language & Automata Models*) is an embeddable library implementing the core computational models of formal language theory, aiming to support most of the major programming languages. It provides reusable implementations of deterministic and nondeterministic finite automata (DFA/NFA), ε-NFA, pushdown automata (PDA), context-free grammars (CFG), Turing machines, and related algorithms. Designed with modularity, portability, and extensibility in mind, EFLAM serves as a foundation for building compilers, interpreters, parsers, lexical analyzers, language-processing tools, educational software, and research prototypes. The project emphasizes clean APIs, reusable components, and faithful implementations of the theoretical models that underpin modern programming languages and compiler construction.


## 2. General Directory Structure

```
(ANY PROGRAMMING LANGUAGE)
|
├── dfa/
|   ├── dfa_code/
|   |   ├── dfa_str_test
|   |   └── dfa_loc_valid
|   |
│   ├── dfa_elem/
|   |   ├── dfa_state
|   |   └── dfa_unit
|   |
|   ├── dfa_engine/
|   |   ├── dfa_byte_proc
|   |   └── dfa_stop_feed
|   |
|   └── dfa_func/
|       ├── spl_state_char
|       ├── cur_state_insp
|       ├── state_type_insp
|       ├── spl_sym_char
|       ├── sym_pump_insp
|       ├── trans_state_insp
|       └── other_sym_insp
|
├── nfa/
|
├── moore/
|
├── mealy/
|
├── pda/
|
├── reg_lang/
|
├── cfg/
|
├── turing/
│
├── utils/
|   ├── file_load
|   ├── char_to_str_pump
|   └── str_to_arr_pump
|
├── test
└── main
```

---