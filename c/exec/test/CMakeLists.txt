cmake_minimum_required(VERSION 3.10)
project(eflam C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

add_executable(test
    ../../src/utils/char_to_str_pump.c
    ../../src/test.c
)