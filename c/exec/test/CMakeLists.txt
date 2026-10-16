cmake_minimum_required(VERSION 3.10)
project(eflam C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

add_executable(test
    ../../src/test.c
    ../../src/mealy/mealy_engine/mealy_byte_proc.c
    ../../src/mealy/mealy_engine/mealy_stop_state_feed.c
    ../../src/mealy/mealy_func/mealy_cur_state_insp.c
    ../../src/mealy/mealy_func/mealy_other_sym_insp.c
    ../../src/mealy/mealy_func/mealy_set_state_out.c
    ../../src/mealy/mealy_func/mealy_spl_state_char.c
    ../../src/mealy/mealy_func/mealy_spl_sym_char.c
    ../../src/mealy/mealy_func/mealy_state_out_insp.c
    ../../src/mealy/mealy_func/mealy_state_type_insp.c
    ../../src/mealy/mealy_func/mealy_sym_pump_insp.c
    ../../src/mealy/mealy_func/mealy_trans_state_insp.c
    ../../src/mealy/mealy_map/mealy_add_sym.c
    ../../src/mealy/mealy_map/mealy_add_trans.c
    ../../src/mealy/mealy_map/mealy_map_view.c
    ../../src/mealy/mealy_create.c
    ../../src/mealy/mealy_erase.c
    ../../src/mealy/mealy_machine_view.c
    ../../src/mealy/mealy_str_test.c

    ../../src/dfa/dfa_engine/dfa_byte_proc.c
    ../../src/dfa/dfa_engine/dfa_stop_state_feed.c
    ../../src/dfa/dfa_func/dfa_cur_state_insp.c
    ../../src/dfa/dfa_func/dfa_other_sym_insp.c
    ../../src/dfa/dfa_func/dfa_spl_state_char.c
    ../../src/dfa/dfa_func/dfa_spl_sym_char.c
    ../../src/dfa/dfa_func/dfa_state_type_insp.c
    ../../src/dfa/dfa_func/dfa_sym_pump_insp.c
    ../../src/dfa/dfa_func/dfa_trans_state_insp.c
    ../../src/dfa/dfa_map/dfa_add_sym.c
    ../../src/dfa/dfa_map/dfa_add_trans.c
    ../../src/dfa/dfa_map/dfa_map_view.c
    ../../src/dfa/dfa_create.c
    ../../src/dfa/dfa_erase.c
    ../../src/dfa/dfa_machine_view.c
    ../../src/dfa/dfa_str_test.c

    ../../src/utils/sym_tape/add_cell_to_tape.c
    ../../src/utils/sym_tape/sym_tape_view.c
    ../../src/utils/char_to_str_pump.c
    ../../src/utils/char_serial.c
)