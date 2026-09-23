cmake_minimum_required(VERSION 3.10)
project(eflam C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

add_executable(test
    ../../src/dfa/dfa_engine/dfa_byte_proc.c
    ../../src/dfa/dfa_create.c
    ../../src/test.c
)