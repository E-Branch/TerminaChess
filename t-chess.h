#include <stdio.h>
#include <string.h>

#define BG_BLK  	"\x1B[40m"
#define BG_WHT  	"\x1B[47m"
#define TXT_RED		"\x1B[31m"
#define TXT_GREEN	"\x1B[32m"
#define TXT_YELLOW	"\x1B[33m"
#define TXT_BLUE	"\x1B[34m"
#define TXT_MAGENTA	"\x1B[35m"
#define TXT_CYAN	"\x1B[36m"
#define COL_RESET    	"\x1B[0m"


#define BOARD_SIZE 8

//TODO: CLEAN UP CODE
//TODO: ADD MOVE FUNCTIONS


enum piece_type{ EMPTY , KING , QUEEN , BISHOP , ROOK , KNIGHT , PAWN };
enum team{ PLAYER_1, PLAYER_2 };
enum cols{ RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN };

char types[6][2] = {"Ki","Qu","Bi","Ro","Kn","Pw"};


typedef struct Player{
	char p_name[50];
	enum team p_team;
	enum cols p_col;	
	
}player;

typedef struct Piece{
	enum piece_type p_type;
	char p_num;	
	player* p_player;
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

player player_1;
player player_2;

void print_welcome();

player player_setup(char* name, int len, int team, int col);

piece piece_setup(int type, int num, player* team);

void board_setup(piece B[BOARD_SIZE][BOARD_SIZE]);

void print_board(piece B[BOARD_SIZE][BOARD_SIZE]);

void str_copy(char* src, int src_len, char* dest, int dest_len);

int str_to_col(char* str);

void change_text_col(int col);

move str_to_mov(char str[6]);

void print_welcome(){
	printf(BG_WHT);
	change_text_col(BLUE);
	printf("WELCOME TO TERMINA CHESS!!!");
	printf(COL_RESET);
	printf("\n");	
}

player player_setup(char* name, int len, int team, int col){
	player p;
	str_copy(name,len,p.p_name,50);	
	p.p_team = team;
	p.p_col = col;
	printf("player col is %d",p.p_col);
	return p;
}

piece piece_setup(int type, int num, player* team){
	piece p = { type, (char)num, team, (char)0};;
	return p;
}

void board_setup(piece B[BOARD_SIZE][BOARD_SIZE]){
	
	//BLACKS PIECES
	
	piece p = piece_setup(ROOK,0,&player_2);
	B[0][0] = p;

	p = piece_setup(KNIGHT,0,&player_2);
	B[0][1] = p;

	p = piece_setup(BISHOP,0,&player_2);
	B[0][2] = p;

	p = piece_setup(QUEEN,0,&player_2);
	B[0][3] = p;
	
	p = piece_setup(KING,0,&player_2);
	B[0][4] = p;
	
	p = piece_setup(BISHOP,1,&player_2);
	B[0][5] = p;
	
	p = piece_setup(KNIGHT,1,&player_2);
	B[0][6] = p;
	
	p = piece_setup(ROOK,1,&player_2);
	B[0][7] = p;
	
	p = piece_setup(PAWN,0,&player_2);
	B[1][0] = p;
	
	p = piece_setup(PAWN,0,&player_2);
	B[1][0] = p;
	
	p = piece_setup(PAWN,1,&player_2);
	B[1][1] = p;
	
	p = piece_setup(PAWN,2,&player_2);
	B[1][2] = p;
	
	p = piece_setup(PAWN,3,&player_2);
	B[1][3] = p;
	
	p = piece_setup(PAWN,4,&player_2);
	B[1][4] = p;
	
	p = piece_setup(PAWN,5,&player_2);
	B[1][5] = p;
	
	p = piece_setup(PAWN,6,&player_2);
	B[1][6] = p;
	
	p = piece_setup(PAWN,7,&player_2);
	B[1][7] = p;
	
	
	//WHITES PIECES
	p = piece_setup(ROOK,0,&player_1);
	B[7][0] = p;

	p = piece_setup(KNIGHT,0,&player_1);
	B[7][1] = p;

	p = piece_setup(BISHOP,0,&player_1);
	B[7][2] = p;

	p = piece_setup(QUEEN,0,&player_1);
	B[7][3] = p;
	
	p = piece_setup(KING,0,&player_1);
	B[7][4] = p;
	
	p = piece_setup(BISHOP,1,&player_1);
	B[7][5] = p;
	
	p = piece_setup(KNIGHT,1,&player_1);
	B[7][6] = p;
	
	p = piece_setup(ROOK,1,&player_1);
	B[7][7] = p;
	
	p = piece_setup(PAWN,0,&player_1);
	B[6][0] = p;
	
	p = piece_setup(PAWN,0,&player_1);
	B[6][0] = p;
	
	p = piece_setup(PAWN,1,&player_1);
	B[6][1] = p;
	
	p = piece_setup(PAWN,2,&player_1);
	B[6][2] = p;
	
	p = piece_setup(PAWN,3,&player_1);
	B[6][3] = p;
	
	p = piece_setup(PAWN,4,&player_1);
	B[6][4] = p;
	
	p = piece_setup(PAWN,5,&player_1);
	B[6][5] = p;
	
	p = piece_setup(PAWN,6,&player_1);
	B[6][6] = p;
	
	p = piece_setup(PAWN,7,&player_1);
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
			char pi[3] = {' ',' ', '\0'};
			piece p = B[i][ii];
			if(p.p_type != EMPTY){
				pi[0] = types[p.p_type-1][0];
				pi[1] = types[p.p_type-1][1];
				change_text_col(p.p_player->p_col);
			}
			//if the sum of i and ii is even, white space, else black space
			if((i+ii)%2 == 0){
				printf(BG_WHT);	
			} else {
				printf(BG_BLK);
			}
			
			printf("%s",pi);
			printf(COL_RESET);
			ii++;
		}
		printf("  %d\n  ",(8-i));
		i++;
		ii = 0;
		
	}
	
	printf("A B C D E F G H   ·\n");
	
}

void str_copy(char* src, int src_len, char* dest, int dest_len){
	int len = 0;
	if( src_len >= dest_len){
		len = dest_len;	
	} 
	else{
		len = src_len;
	}
	int k;
	for( k = 0; k<len; k++){
		dest[k] = src[k];	
	}
}

int str_to_col(char* str){
	
	if( strcmp(str,"red\n") == 0 ){
		return RED;
	}
	if( strcmp(str,"green\n") == 0 ){
		return GREEN;	
	}
	if( strcmp(str,"yellow\n") == 0 ){
		return YELLOW;
	}
	if( strcmp(str,"blue\n") == 0 ){
		return BLUE;
	}
	if( strcmp(str,"magenta\n") == 0 ){
		return MAGENTA;
	}
	if( strcmp(str,"cyan\n") == 0 ){
		return CYAN;
	}
	return -1;
}

void change_text_col(int col){
	if(col == RED){
		printf(TXT_RED);	
	}
	else if(col == GREEN){
		printf(TXT_GREEN);
	}
	else if(col == YELLOW){
		printf(TXT_YELLOW);	
	}
	else if(col == BLUE){
		printf(TXT_BLUE);	
	}
	else if(col == MAGENTA){
		printf(TXT_MAGENTA);
	}
	else if(col == CYAN){
		printf(TXT_CYAN);	
	}
}

move str_to_mov(char str[6]){
	//stub
	move m = {0,0,0,0};
	return m;
}
