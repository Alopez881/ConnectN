#ifndef WIN_H
    #define WIN_H
    bool all_same(char* characters, int size);
    char* get_column(int column_index, char** board, int dimensions);
    bool someone_won_vertically(char** board, int dimensions, char blank_space, int num_pieces_needed, int num_row);
    bool someone_won_on_left_diagonal(char** board, int dimensions, char blank_space, int num_pieces_needed, int num_row);
    bool someone_won_on_right_diagonal(char** board, int dimensions, char blank_space, int num_pieces_needed, int num_row);
    bool someone_won_diagonally(char** board, int dimensions, char blank_space, int num_pieces_needed, int num_row);
    //bool in_a_row(char** board, int dimensions, char blank_space, int num_pieces_needed, int num_rows, char player_piece);
    bool in_a_row(char** board, int dimensions, char blank_space, int num_pieces_needed, int num_rows, char player_piece);
    bool someone_won_horizontally(char** board, int dimensions, char blank_space, int num_pieces_needed, int num_row);
    bool someone_won(char** board, int dimensions, char blank_space, int num_pieces_needed, int num_rows);
    bool tie(char** board, int dimensions, char blank_space, int num_rows);
    bool is_game_over(char** board, int dimensions, char blank_space, int num_pieces_needed, int num_rows);
#endif