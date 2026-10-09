gcc -c ../src/dfa/dfa_engine/dfa_byte_proc.c -o ../obj/dfa_byte_proc.o
gcc -c ../src/dfa/dfa_engine/dfa_stop_state_feed.c -o ../obj/dfa_stop_state_feed.o
gcc -c ../src/dfa/dfa_func/dfa_cur_state_insp.c -o ../obj/dfa_cur_state_insp.o
gcc -c ../src/dfa/dfa_func/dfa_other_sym_insp.c -o ../obj/dfa_other_sym_insp.o
gcc -c ../src/dfa/dfa_func/dfa_spl_state_char.c -o ../obj/dfa_spl_state_char.o
gcc -c ../src/dfa/dfa_func/dfa_spl_sym_char.c -o ../obj/dfa_spl_sym_char.o
gcc -c ../src/dfa/dfa_func/dfa_state_type_insp.c -o ../obj/dfa_state_type_insp.o
gcc -c ../src/dfa/dfa_func/dfa_sym_pump_insp.c -o ../obj/dfa_sym_pump_insp.o
gcc -c ../src/dfa/dfa_func/dfa_trans_state_insp.c -o ../obj/dfa_trans_state_insp.o
gcc -c ../src/dfa/dfa_map/dfa_add_sym.c -o ../obj/dfa_add_sym.o
gcc -c ../src/dfa/dfa_map/dfa_add_trans.c -o ../obj/dfa_add_trans.o
gcc -c ../src/dfa/dfa_map/dfa_map_view.c -o ../obj/dfa_map_view.o
gcc -c ../src/dfa/dfa_create.c -o ../obj/dfa_create.o
gcc -c ../src/dfa/dfa_machine_view.c -o ../obj/dfa_machine_view.o
gcc -c ../src/dfa/dfa_str_test.c -o ../obj/dfa_str_test.o

gcc -c ../src/utils/char_to_str_pump.c -o ../obj/char_to_str_pump.o
gcc -c ../src/utils/char_serial.c -o ../obj/char_serial.o

ar rcs ../lib/libdfa.a ../obj/dfa_byte_proc.o ../obj/dfa_stop_state_feed.o ../obj/dfa_cur_state_insp.o ../obj/dfa_other_sym_insp.o ../obj/dfa_spl_state_char.o ../obj/dfa_spl_sym_char.o ../obj/dfa_state_type_insp.o ../obj/dfa_sym_pump_insp.o ../obj/dfa_trans_state_insp.o ../obj/dfa_add_sym.o ../obj/dfa_add_trans.o ../obj/dfa_map_view.o ../obj/dfa_create.o ../obj/dfa_machine_view.o ../obj/dfa_str_test.o ../obj/char_to_str_pump.o ../obj/char_serial.o