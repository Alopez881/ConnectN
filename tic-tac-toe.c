#include <stdio.h>
#include <stdbool.h>

#include "tic-tac-toe.h"
#include "input_validation.h"
#include "win.h"


bool is_between(int value, int lower, int upper){
    return value >= lower && value < upper;
}

bool is_on_board( int col, int dimensions){
    return is_between(col, 0, dimensions);
}

bool is_valid_play(int num_args_read, int row, int col, char** board, int dimensions, char blank_space){

    return isValidFormat(num_args_read, 1) && 
    is_on_board(col, dimensions);
}


void pick_valid_spot_for_play(char** board, int dimensions, char blank_space, int *out_row,  int *out_col){
    int num_args_read;
    do{
        printf("Enter a column between 0 and %d to play in: ", dimensions - 1);
        num_args_read = scanf("%d",  out_col);
    }while(!is_valid_play(num_args_read, *out_row, *out_col, board, dimensions, blank_space));
}

void print_board(char** board, int dimensions, int num_rows){



    for(int i = 0; i < num_rows; ++i){
        printf("%d ", i);
        for(int j = 0; j < dimensions; ++j){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    printf("  ");
    for(int i = 0; i < dimensions; ++i){
        printf("%d ", i);
    }
    printf("\n");
}

void place_piece(char** board, int dimensions, int row, int col, char cur_player_piece, char blank_space, int num_rows) {
    for(int  row = 1; row <= num_rows ; ++row){
        if (board[num_rows - row][col] == blank_space){
            board[num_rows - row][col] = cur_player_piece;
            break;
        }
        else {
            continue;
        }
    }
}


void current_player_take_turn(char cur_player_piece, char** board, int dimensions, int blank_space, int num_rows){
    int col;
    int row;
    print_board(board, dimensions, num_rows );
    pick_valid_spot_for_play(board, dimensions, blank_space, &row, &col);
    //board[row][col] = cur_player_piece;//place_piece();
    place_piece(board, dimensions, row, col, cur_player_piece, blank_space, num_rows);
    
}

void announce_game_results(int cur_player_turn, char** board, int dimensions, char blank_space, int num_rows, int num_pieces_needed){
    print_board(board, dimensions, num_rows);
    if(someone_won(board, dimensions, blank_space, num_pieces_needed, num_rows)){
        printf("Player %d won!\n", cur_player_turn + 1);
    } 
    else{
        printf("Tie game.\n");
    }
}
//
void play_game(int cur_player_turn, char* player_pieces, char** board, int dimensions, char blank_space, int num_pieces_needed, int num_rows){;
    do{
        current_player_take_turn(player_pieces[cur_player_turn], board, dimensions, blank_space, num_rows);
        if(is_game_over(board, dimensions, blank_space, num_pieces_needed, num_rows)){
            break;
        }
        switch_to_next_player(&cur_player_turn);
    }while(true);

    announce_game_results(cur_player_turn, board, dimensions, blank_space, num_rows, num_pieces_needed);
}

void switch_to_next_player(int *cur_player_turn){
    if(*cur_player_turn == 0){
        *cur_player_turn = 1;
    }else{
        *cur_player_turn = 0;
    }
    //*cur_player_turn = (*cur_player_turn + 1) % num_players;

}