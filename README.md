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
|   |   ├── moore_map_ll
|   |   ├── moore_map_node
|   |   └── dfa_map_view
|   |
|   ├── dfa_create
|   ├── dfa_erase
|   ├── dfa_machine_view
|   └── dfa_str_test
|
├── nfa/
|
├── moore/
│   ├── moore_elem/
|   |   ├── moore_state
|   |   └── moore_unit
|   |
|   ├── moore_engine/
|   |   ├── moore_byte_proc
|   |   └── moore_stop_state_feed
|   |
│   ├── moore_func/
|   |   ├── moore_cur_state_insp
|   |   ├── moore_other_sym_insp
|   |   ├── moore_set_state_out
|   |   ├── moore_spl_state_char
|   |   ├── moore_spl_sym_char
|   |   ├── moore_state_out_insp
|   |   ├── moore_state_type_insp
|   |   ├── moore_sym_pump_insp
|   |   └── moore_trans_state_insp
|   |
│   ├── moore_map/
|   |   ├── moore_add_sym
|   |   ├── moore_add_trans
|   |   ├── moore_map_ll
|   |   ├── moore_map_node
|   |   └── moore_map_view
|   |
|   ├── moore_create
|   ├── moore_erase
|   ├── moore_machine_view
|   └── moore_str_test
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
│   ├── sym_tape/
|   |   ├── add_cell_to_tape
|   |   ├── sym_tape_cell
|   |   ├── sym_tape_ll
|   |   └── sym_tape_view
|   |
|   ├── char_to_str_pump
|   └── str_to_arr_pump
|
├── test
└── main
```


## 3. Manuals

Manuals are provided in `docs/` directory of each language, like for manual guiding through *EFLAM* usage in **C** would be found at `c/docs/c_man.md` or as `c/docs/c_man.pdf`. And as another example, for **Java** it would be found at and as `java/docs/java_man.md` or as `java/docs/java_man.pdf`.

---