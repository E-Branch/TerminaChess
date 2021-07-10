all: t-chess.h t-chess.o
	gcc -o TerminaChess t-chess.o 
	
t-chess.o: t-chess.h t-chess.c
	gcc -o t-chess.o t-chess.c -c
	
remove:
	rm t-chess.o
	rm functions.o
	rm TerminaChess

