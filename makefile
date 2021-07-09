all: t-chess.h t-chess.o
	gcc -o TerminaChess t-chess.o
	
t-chess.o: t-chess.h t-chess.c
	gcc -o t-chess.o t-chess.c -c
	
clean:
	rm t-chess.o

