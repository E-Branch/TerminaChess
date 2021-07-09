#include <stdio.h>

//{ 'CSI', '[' , '3' , '7' , ':' , '4' , '0' , 'm' , '\0'}
// �[37:40m
//[37:40m
//"\x1B[47:30m"
#define COL_BLK_WHT  "\x1B[37m\x1B[40m"
#define COL_WHT_BLK  "\x1B[47m\x1B[30m"
#define COL_RESET    "\x1B[0m"


#define BOARD_SIZE 8

enum piece_type{ EMPTY , KING , QUEEN , BISHOP , ROOK , KNIGHT , PAWN };
enum team{ WHITE, BLACK };

char type_chars[6] = {'K','Q','B','R','k','P'};
char team_chars[2] = {'w','b'};

typedef struct Piece{
	enum piece_type p_type;
	char p_num;	
	enum team p_team;
	char p_moved;
}piece;

typedef struct Move{
	unsigned int src_x:8;
	unsigned int scr_y:8;
	unsigned int dst_x:8;
	unsigned int dst_y:8;
}move;

union move_message{
	move M;
	char C[4];
};

void print_welcome(){
	printf(COL_WHT_BLK);
	printf("WELCOME TO TERMINA CHESS!!!");
	printf(COL_RESET);
	printf("\n");	
}
piece piece_setup(int type, int num, int team){
	piece p = { type, (char)num, team, (char)0};;
	return p;
}
void board_setup(piece B[BOARD_SIZE][BOARD_SIZE]){
	
	//BLACKS PIECES
	
	piece p = piece_setup(ROOK,0,BLACK);
	B[0][0] = p;

	p = piece_setup(KNIGHT,0,BLACK);
	B[0][1] = p;

	p = piece_setup(BISHOP,0,BLACK);
	B[0][2] = p;

	p = piece_setup(QUEEN,0,BLACK);
	B[0][3] = p;
	
	p = piece_setup(KING,0,BLACK);
	B[0][4] = p;
	
	p = piece_setup(BISHOP,1,BLACK);
	B[0][5] = p;
	
	p = piece_setup(KNIGHT,1,BLACK);
	B[0][6] = p;
	
	p = piece_setup(ROOK,1,BLACK);
	B[0][7] = p;
	
	p = piece_setup(PAWN,0,BLACK);
	B[1][0] = p;
	
	p = piece_setup(PAWN,0,BLACK);
	B[1][0] = p;
	
	p = piece_setup(PAWN,1,BLACK);
	B[1][1] = p;
	
	p = piece_setup(PAWN,2,BLACK);
	B[1][2] = p;
	
	p = piece_setup(PAWN,3,BLACK);
	B[1][3] = p;
	
	p = piece_setup(PAWN,4,BLACK);
	B[1][4] = p;
	
	p = piece_setup(PAWN,5,BLACK);
	B[1][5] = p;
	
	p = piece_setup(PAWN,6,BLACK);
	B[1][6] = p;
	
	p = piece_setup(PAWN,7,BLACK);
	B[1][7] = p;
	
	
	//WHITES PIECES
	p = piece_setup(ROOK,0,WHITE);
	B[7][0] = p;

	p = piece_setup(KNIGHT,0,WHITE);
	B[7][1] = p;

	p = piece_setup(BISHOP,0,WHITE);
	B[7][2] = p;

	p = piece_setup(QUEEN,0,WHITE);
	B[7][3] = p;
	
	p = piece_setup(KING,0,WHITE);
	B[7][4] = p;
	
	p = piece_setup(BISHOP,1,WHITE);
	B[7][5] = p;
	
	p = piece_setup(KNIGHT,1,WHITE);
	B[7][6] = p;
	
	p = piece_setup(ROOK,1,WHITE);
	B[7][7] = p;
	
	p = piece_setup(PAWN,0,WHITE);
	B[6][0] = p;
	
	p = piece_setup(PAWN,0,WHITE);
	B[6][0] = p;
	
	p = piece_setup(PAWN,1,WHITE);
	B[6][1] = p;
	
	p = piece_setup(PAWN,2,WHITE);
	B[6][2] = p;
	
	p = piece_setup(PAWN,3,WHITE);
	B[6][3] = p;
	
	p = piece_setup(PAWN,4,WHITE);
	B[6][4] = p;
	
	p = piece_setup(PAWN,5,WHITE);
	B[6][5] = p;
	
	p = piece_setup(PAWN,6,WHITE);
	B[6][6] = p;
	
	p = piece_setup(PAWN,7,WHITE);
	B[6][7] = p;	
}

void print_board(piece B[BOARD_SIZE][BOARD_SIZE]){
	int i = 0;
	int ii = 0;
	printf("\n  ");
	while(i < BOARD_SIZE){
		//row
		while(ii< BOARD_SIZE){
			//column
			char square[3] = {' ',' ', '\0'};
			piece p = B[i][ii];
			if(p.p_type != EMPTY){
				square[0] = team_chars[p.p_team];
				square[1] = type_chars[p.p_type-1];
			}
			//if the sum of i and ii is even, white space, else black space
			if((i+ii)%2 == 0){
				printf(COL_WHT_BLK);	
			} else {
				printf(COL_BLK_WHT);
			}
			printf("%s",square);
			printf(COL_RESET);
			ii++;
		}
		printf("  %d\n  ",(8-i));
		i++;
		ii = 0;
		
	}
	
	printf("A B C D E F G H   ·\n");
	
}
