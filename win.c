#include <stdbool.h>
#include <stdlib.h>
#include "win.h"

bool all_same(char* characters, int size){
    for(int i = 1; i < size; ++i){
        if(characters[i] != characters[0]){
            return false;
        }
    }
    return true;
}

char* get_column(int column_index, char** board, int dimensions){
    char* column = (char*)calloc(dimensions, sizeof(char));
    for(int i = 0; i < dimensions; ++i){
        column[i] = board[i][column_index];
    }
    return column;
}

bool someone_won_vertically(char** board, int dimensions, char blank_space, int num_pieces_needed, int num_rows){
    for(int i = 0; i < dimensions; ++i){
         char* column = get_column(i, board, dimensions);
            if(column[0] != blank_space && all_same(column, dimensions)){
             free(column);
            return true;
         }
         free(column);
     }
     return false;

}

bool someone_won_on_left_diagonal(char** board, int num_cols, char blank_space, int num_pieces_needed, int num_rows){
    /* Checking for a win on the main diagonal that looks like this

        X
          X
            X
    */

    // if(board[0][0] == blank_space){
    //     return false;
    // }

    // for(int i = 1; i < dimensions; ++i){
    //     if(board[i][i] != board[0][0]){
    //         return false;
    //     }
    // }
    // return true;
    

    int count;
    char inital_piece;


    for(int i = num_rows - 1; i >= 0; --i){
        for(int j = num_cols - 1; j >= 0; --j){
            inital_piece = board[i][j];

            if(inital_piece == blank_space){
                continue;
            }

            else{
                for(count = 0; count < num_rows; ++count){

                    if(count == num_pieces_needed){
                        return true;
                    }

                    if(board[i - count][j - count] != inital_piece){
                        break;
                    }   

                    else{
                        continue;
                    }
                }

            }        

        }
    }

    return false;
}

//}

bool someone_won_on_right_diagonal(char** board, int dimensions, char blank_space, int num_pieces_needed, int num_rows){
    /* Checking for a win on the main diagonal that looks like this

            X
          X
        X
    */

    // const char upper_right_corner = board[0][dimensions - 1];

    // if(upper_right_corner == blank_space){
    //     return false;
    // }

    // for(int i = 1; i < dimensions; ++i){
    //     if(board[i][dimensions - 1 - i] != upper_right_corner){
    //         return false;
    //     }
    // }
    // return true;




    int count;
    char inital_piece;


    // for(int i = num_rows - 1; i >= 0; --i){
    //     for(int j = dimensions + 1; j >= 0; ++j){
    //         inital_piece = board[i][j];

    //         if(inital_piece == blank_space){
    //             continue;
    //         }

    //         else{
    //             for(count = 0; count < num_rows; ++count){


    //                 if(count == num_pieces_needed){
    //                     return true;
    //                 }

    //                 if(board[i - count][j + count] != inital_piece){
    //                     break;
    //                 }   

    //                 else{
    //                     continue;
    //                 }

    //             }
    //         }        

    //     }

    // }
    // return false;


         int count_right_diagonal = 0;
     for (int i = 0; i < 3; ++i) {
         int row = num_rows - i;
         int col = col + i;
         if (row >= 0 && col < dimensions && board[row][col] == player_piece) {
             count_right_diagonal++;
         } else {
             break;
         }
     }
     return count_right_diagonal == 3;

}



bool someone_won_diagonally(char** board, int dimensions, char blank_space, int num_pieces_needed, int num_rows){
    return //someone_won_on_left_diagonal(board, dimensions, blank_space, num_pieces_needed, num_rows) || 
    someone_won_on_right_diagonal(board, dimensions, blank_space, num_pieces_needed, num_rows);
}


bool in_a_row(char** board, int dimensions, char blank_space, int num_pieces_needed, int num_rows, char player_piece){

for (int i = 0; i < num_rows; ++i) {
        int count = 0;

        for (int j = 0; j < dimensions; ++j) {
            if (board[i][j] == player_piece) {
                count++;
            
                if (count == num_pieces_needed) {
                    return true;  // Found four consecutive characters in the current row
                }
             }else {
                count = 0;  // Reset count if the sequence is broken
            }
        }
    }

    return false;  // No four consecutive characters found in any row

}



bool someone_won_horizontally(char** board, int dimensions, char blank_space, int num_pieces_needed, int num_rows){
    // for(int i = 0; i < dimensions; ++i){
    //     if(board[i][0] != blank_space && all_same(board[i], dimensions)){
    //         return true;
    //     }
    // }
    // return false;
    //////////////////////////////
    char player1 = 'x';
     char player2 = 'o';

    if(in_a_row(board, dimensions,  blank_space, num_pieces_needed,  num_rows, player1) || in_a_row( board, dimensions,  blank_space, num_pieces_needed,  num_rows, player2)){
            return true;
         }
     return false;




}



bool someone_won(char** board, int dimensions, char blank_space, int num_pieces_needed, int num_rows){
    
    return someone_won_horizontally(board, dimensions, blank_space, num_pieces_needed, num_rows) ||
           someone_won_vertically(board, dimensions, blank_space, num_pieces_needed, num_rows) || 
           someone_won_diagonally(board, dimensions, blank_space, num_pieces_needed, num_rows);
}

bool tie(char** board, int dimensions, char blank_space, int num_rows){
    /*
    Make sure to only use this after checking if someone has won
    */

    for(int i = 0; i < num_rows; ++i){
        for(int j = 0; j < dimensions; ++j){
            if(board[i][j] == blank_space){
                return false;
            }
        }
    }
    return true;

}

bool is_game_over(char** board, int dimensions, char blank_space, int num_pieces_needed, int num_rows){
    return someone_won(board, dimensions, blank_space, num_pieces_needed, num_rows) || tie(board, dimensions, blank_space, num_rows);
}