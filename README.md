# Embeddable Formal Language and Automata Models


## 1. Introduction

- EFLAM (*Embeddable Formal Language & Automata Models*) is an embeddable library implementing the core computational models of formal language theory, aiming to support most of the major programming languages.
- It provides reusable implementations of **Deterministic** and **Non-Deterministic Finite Automata (DFA/NFA)**, **Pushdown Automata (PDA)**, **Context-Free Grammars (CFG)**, **Turing Machines (TM)**, **Mealy's Machine**, **Moore's Machine** and related algorithms.
- Designed with modularity, portability, and extensibility in mind, EFLAM serves as a foundation for building compilers, interpreters, parsers, lexical analyzers, language-processing tools, educational software, and research prototypes.
- The project emphasizes clean APIs, reusable components, and faithful implementations of the theoretical models that underpin modern programming languages and compiler construction.


## 2. General Directory Structure

```
(ANY PROGRAMMING LANGUAGE)
|
├── dfa/
│   ├── dfa_elem/
|   |   ├── dfa_state
|   |   └── dfa_unit
|   |
|   ├── dfa_engine/
|   |   ├── dfa_byte_proc
|   |   └── dfa_stop_state_feed
|   |
│   ├── dfa_func/
|   |   ├── dfa_cur_state_insp
|   |   ├── dfa_other_sym_insp
|   |   ├── dfa_spl_state_char
|   |   ├── dfa_spl_sym_char
|   |   ├── dfa_state_type_insp
|   |   ├── dfa_sym_pump_insp
|   |   └── dfa_trans_state_insp
|   |
│   ├── dfa_map/
|   |   ├── dfa_add_sym
|   |   ├── dfa_add_trans
|   |   └── dfa_map_view
|   |
|   ├── dfa_create
|   ├── dfa_machine_view
|   └── dfa_str_test
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
|   ├── char_to_str_pump
|   └── str_to_arr_pump
|
├── test
└── main
```


## 3. Manuals

Manuals are provided in `docs/` directory of each language, like for manual guiding through *EFLAM* usage in **C** would be found at `c/docs/c_man.md` or as `c/docs/c_man.pdf`. And as another example, for **Java** it would be found at and as `java/docs/java_man.md` or as `java/docs/java_man.pdf`.

---