cmake_minimum_required(VERSION 3.10)
project(eflam C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

add_executable(test
    ../../src/dfa/dfa_engine/dfa_byte_proc.c
    ../../src/dfa/dfa_func/dfa_cur_state_insp.c
    ../../src/dfa/dfa_func/dfa_spl_state_char.c
    ../../src/dfa/dfa_func/dfa_spl_sym_char.c
    ../../src/dfa/dfa_create.c
    ../../src/utils/char_to_str_pump.c
    ../../src/utils/str_to_arr_pump.c
    ../../src/test.c
)