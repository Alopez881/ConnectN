#ifndef TIC_TAC_TOE_H
    #define TIC_TAC_TOE_H
    #include <stdbool.h>
    bool is_between(int value, int lower, int upper);
    bool is_on_board( int col, int dimensions);
    bool is_valid_play(int num_args_read, int row, int col, char** board, int dimensions, char blank_space);
    void pick_valid_spot_for_play(char** board, int dimensions, char blank_space, int* out_row, int *out_col);
    void place_piece(char** board, int dimentions, int row, int col, char cur_placyer_piece, char blank_space, int num_rows);
    void current_player_take_turn(char cur_player_piece, char** board, int dimensions, int blank_space, int num_rows);
    void announce_game_results(int cur_player_turn, char** board, int dimensions, char blank_space, int num_rows, int num_pieces_needed);
    void play_game( int cur_player_turn,char* player_pieces, char** board, int dimensions, char blank_space, int num_pieces_needed, int num_rows);
    void switch_to_next_player(int *cur_player_turn);

#endif