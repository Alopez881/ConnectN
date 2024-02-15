#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#include "setting_up.h"

char** create_board(int dimensions, char blank_space, int num_rows){
    /*
        create an empty dimensions X dimensions board filled with blank spaces
    */

//     char** board = (char**)calloc(num_rows, sizeof(char*));
//     for(int i = 0; i < num_rows; ++i){
//         board[i] = (char*)calloc(dimensions, sizeof(char));
//          for(i = 0; i < num_of_rows; ++i){
//             for(j = 0; j < num_of_cols; ++j){

//                 board[i][j] = blank_space;

//         }
//     }
//     return board;
// }

char** board = (char**)malloc(num_rows * sizeof(char*));
    int i, j;


    for(i = 0; i < num_rows; ++i){

        board[i] = (char*)malloc(dimensions * sizeof(char));

    }

    for(i = 0; i < num_rows; ++i){
        for(j = 0; j < dimensions; ++j){

            board[i][j] = '*';

        }
    }


    return board;
}




void setup_game(int dimensions, char blank_space, int num_players,
                int *out_starting_player, char* out_player_pieces, char** *out_board, int num_rows){
    *out_board = create_board(dimensions, blank_space, num_rows);
    //*out_starting_player = choose_who_goes_first(num_players);
    //char out_player_pieces[] = players_pick_their_pieces(num_players, blank_space);
}

// char* players_pick_their_pieces(int num_players, char blank_space){
//     char* pieces = (char*)calloc(num_players, sizeof(char));
//     for(int i = 0; i < num_players; ++i){
//         pieces[i] = get_valid_piece_from_player(i, blank_space, pieces);
//     }
//     return pieces;
// }

// char get_valid_piece_from_player(int player_turn, char blank_space, char* player_pieces){
//     char piece;
//     do{
//         printf("Player %d please choose your piece: ", player_turn + 1);
//         scanf(" %c", &piece);
//     }while(!is_valid_piece(piece, blank_space, player_pieces, player_turn));
//     return piece;
// }

// bool is_valid_piece(char piece, char blank_space, char* player_pieces, int num_pieces){
//     return !isspace(piece) && 
//            piece != blank_space && 
//            !is_in(piece, player_pieces, num_pieces);
// }

// bool is_in(char character, char* characters, int size){
//     for(int i = 0; i < size; ++i){
//         if(character == characters[i]){
//             return true;
//         }
//     }
//     return false;
// }


// int choose_who_goes_first(){
//     /*
//     randomly choose who will go first
//     return 0 if player 1 is first, and 1 if player 2 is first
//     */
//     return rand() % 2;

// }

void cleanup(char** *board, int dimensions){
    for(int i = 0; i < dimensions; ++i){
        free((*board)[i]);// (*board)[i] == *(*board + i) == board[0][i] 
    }
    free(*board);
    *board = NULL;

}