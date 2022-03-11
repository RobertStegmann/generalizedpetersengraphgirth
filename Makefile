CC = gcc
CCFLAGS = -std=gnu99 -Wpedantic -g -lm

all: girthGP girthGP2

girthGP: girthGP.o girthGP.h
	$(CC) $(CCFLAGS) girthGP.o -o girthGP

girthGP.o: girthGP.c
	$(CC) $(CCFLAGS) -c girthGP.c -o girthGP.o

girthGP2: girthGP2.o girthGP.h
	$(CC) $(CCFLAGS) girthGP2.o -o girthGP2

girthGP2.o: girthGP2.c
	$(CC) $(CCFLAGS) -c girthGP2.c -o girthGP2.o

clean:
	rm *.o
	rm girthGP
	rm girthGP2
	
	