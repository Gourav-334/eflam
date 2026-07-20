# Embeddable Formal Language and Automata Models


## 1. Introduction

EFLAM (Embeddable Formal Language & Automata Models) is an embeddable library implementing the core computational models of formal language theory, aiming to support most of the major programming languages. It provides reusable implementations of deterministic and nondeterministic finite automata (DFA/NFA), ε-NFA, pushdown automata (PDA), context-free grammars (CFG), Turing machines, and related algorithms. Designed with modularity, portability, and extensibility in mind, EFLAM serves as a foundation for building compilers, interpreters, parsers, lexical analyzers, language-processing tools, educational software, and research prototypes. The project emphasizes clean APIs, reusable components, and faithful implementations of the theoretical models that underpin modern programming languages and compiler construction.


## 2. Expected Structure

```
Formal Languages
|
├── Regular Languages
│   ├── DFA
│   ├── NFA
│   └── Regular Expressions
│
├── Context-Free Languages
│   ├── CFG
│   └── PDA
│
├── Context-Sensitive Languages
│
└── Recursively Enumerable Languages
    └── Turing Machine
```

---