gcc -c ../src/mealy/mealy_engine/mealy_byte_proc.c -o ../obj/mealy_byte_proc.o
gcc -c ../src/mealy/mealy_engine/mealy_stop_state_feed.c -o ../obj/mealy_stop_state_feed.o
gcc -c ../src/mealy/mealy_func/mealy_cur_state_insp.c -o ../obj/mealy_cur_state_insp.o
gcc -c ../src/mealy/mealy_func/mealy_other_sym_insp.c -o ../obj/mealy_other_sym_insp.o
gcc -c ../src/mealy/mealy_func/mealy_spl_state_char.c -o ../obj/mealy_spl_state_char.o
gcc -c ../src/mealy/mealy_func/mealy_spl_sym_char.c -o ../obj/mealy_spl_sym_char.o
gcc -c ../src/mealy/mealy_func/mealy_state_type_insp.c -o ../obj/mealy_state_type_insp.o
gcc -c ../src/mealy/mealy_func/mealy_sym_pump_insp.c -o ../obj/mealy_sym_pump_insp.o
gcc -c ../src/mealy/mealy_func/mealy_trans_state_insp.c -o ../obj/mealy_trans_state_insp.o
gcc -c ../src/mealy/mealy_map/mealy_add_sym.c -o ../obj/mealy_add_sym.o
gcc -c ../src/mealy/mealy_map/mealy_add_trans.c -o ../obj/mealy_add_trans.o
gcc -c ../src/mealy/mealy_map/mealy_map_view.c -o ../obj/mealy_map_view.o
gcc -c ../src/mealy/mealy_create.c -o ../obj/mealy_create.o
gcc -c ../src/mealy/mealy_machine_view.c -o ../obj/mealy_machine_view.o
gcc -c ../src/mealy/mealy_str_test.c -o ../obj/mealy_str_test.o
gcc -c ../src/mealy/mealy_erase.c -o ../obj/mealy_erase.o

gcc -c ../src/utils/char_to_str_pump.c -o ../obj/char_to_str_pump.o
gcc -c ../src/utils/char_serial.c -o ../obj/char_serial.o

ar rcs ../lib/libmealy.a ../obj/mealy_byte_proc.o ../obj/mealy_stop_state_feed.o ../obj/mealy_cur_state_insp.o ../obj/mealy_other_sym_insp.o ../obj/mealy_spl_state_char.o ../obj/mealy_spl_sym_char.o ../obj/mealy_state_type_insp.o ../obj/mealy_sym_pump_insp.o ../obj/mealy_trans_state_insp.o ../obj/mealy_add_sym.o ../obj/mealy_add_trans.o ../obj/mealy_map_view.o ../obj/mealy_create.o ../obj/mealy_machine_view.o ../obj/mealy_str_test.o ../obj/char_to_str_pump.o ../obj/char_serial.o ../obj/mealy_erase.o