#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdalign.h>
#include "t-chess.h"

int main(int argc, char *argv[]){
	
	print_welcome();
	char p1_name[50];
	char p2_name[50];
	memset(p1_name, '\0',50);
	memset(p2_name, '\0',50);
	
	//get player names
	printf("player 1 name: ");
	fgets(p1_name, 50, stdin);
	
	printf("player 2 name: ");
	fgets(p2_name, 50, stdin);
	
	//initialize board
	piece p = piece_setup(EMPTY,0,WHITE);
	piece board[BOARD_SIZE][BOARD_SIZE] = {p};
	
	board_setup(board);
	print_board(board);
	
	
	printf("\n");
	
	return 0;
}
