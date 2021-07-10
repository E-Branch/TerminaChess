#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdalign.h>
#include "t-chess.h"

//TODO: ADD MOVE LOOP

int main(int argc, char *argv[]){
	
	print_welcome();
	char buf1[50];
	char buf2[10];
	memset(buf1, '\0',50);
	memset(buf2, '\0',10);
	
	//get player names
	printf("player 1 name: ");
	fgets(buf1, 50, stdin);
	
	printf("player 1 colour(red, green, yellow, blue, magenta, cyan): ");
	fgets(buf2, 10, stdin);
	printf("buf2 is: %s",buf2);
	
	player_1 = player_setup(buf1,strlen(buf1), PLAYER_1, str_to_col(buf2));
	
	printf("player 2 name: ");
	fgets(buf1, 50, stdin);
	
	printf("player 2 colour(red, green, yellow, blue, magenta, cyan): ");
	fgets(buf2, 10, stdin);
	
	player_2 = player_setup(buf1,strlen(buf1), PLAYER_2, str_to_col(buf2));

	
	
	//initialize board
	piece p = piece_setup(EMPTY,0,&player_1);
	piece board[BOARD_SIZE][BOARD_SIZE] = {p};
	
	
	
	board_setup(board);
	print_board(board);
	
	
	printf("\n");
	
	return 0;
}
