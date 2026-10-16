gcc -c ../src/moore/moore_engine/moore_byte_proc.c -o ../obj/moore_byte_proc.o
gcc -c ../src/moore/moore_engine/moore_stop_state_feed.c -o ../obj/moore_stop_state_feed.o
gcc -c ../src/moore/moore_func/moore_cur_state_insp.c -o ../obj/moore_cur_state_insp.o
gcc -c ../src/moore/moore_func/moore_other_sym_insp.c -o ../obj/moore_other_sym_insp.o
gcc -c ../src/moore/moore_func/moore_spl_state_char.c -o ../obj/moore_spl_state_char.o
gcc -c ../src/moore/moore_func/moore_spl_sym_char.c -o ../obj/moore_spl_sym_char.o
gcc -c ../src/moore/moore_func/moore_state_type_insp.c -o ../obj/moore_state_type_insp.o
gcc -c ../src/moore/moore_func/moore_sym_pump_insp.c -o ../obj/moore_sym_pump_insp.o
gcc -c ../src/moore/moore_func/moore_trans_state_insp.c -o ../obj/moore_trans_state_insp.o
gcc -c ../src/moore/moore_func/moore_set_state_out.c -o ../obj/moore_set_state_out.o
gcc -c ../src/moore/moore_func/moore_state_out_insp.c -o ../obj/moore_state_out_insp.o
gcc -c ../src/moore/moore_map/moore_add_sym.c -o ../obj/moore_add_sym.o
gcc -c ../src/moore/moore_map/moore_add_trans.c -o ../obj/moore_add_trans.o
gcc -c ../src/moore/moore_map/moore_map_view.c -o ../obj/moore_map_view.o
gcc -c ../src/moore/moore_create.c -o ../obj/moore_create.o
gcc -c ../src/moore/moore_erase.c -o ../obj/moore_erase.o
gcc -c ../src/moore/moore_machine_view.c -o ../obj/moore_machine_view.o
gcc -c ../src/moore/moore_str_test.c -o ../obj/moore_str_test.o

gcc -c ../src/utils/char_to_str_pump.c -o ../obj/char_to_str_pump.o
gcc -c ../src/utils/char_serial.c -o ../obj/char_serial.o
gcc -c ../src/utils/sym_tape/add_cell_to_tape.c -o ../obj/add_cell_to_tape.o
gcc -c ../src/utils/sym_tape/sym_tape_view.c -o ../obj/sym_tape_view.o

ar rcs ../lib/libmoore.a ../obj/moore_byte_proc.o ../obj/moore_stop_state_feed.o ../obj/moore_cur_state_insp.o ../obj/moore_other_sym_insp.o ../obj/moore_spl_state_char.o ../obj/moore_spl_sym_char.o ../obj/moore_state_type_insp.o ../obj/moore_sym_pump_insp.o ../obj/moore_trans_state_insp.o ../obj/moore_add_sym.o ../obj/moore_add_trans.o ../obj/moore_map_view.o ../obj/moore_create.o ../obj/moore_machine_view.o ../obj/moore_str_test.o ../obj/char_to_str_pump.o ../obj/char_serial.o ../obj/moore_set_state_out.o ../obj/moore_state_out_insp.o ../obj/add_cell_to_tape.o ../obj/sym_tape_view.o ../obj/moore_erase.o