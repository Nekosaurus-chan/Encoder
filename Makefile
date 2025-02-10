CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0` -I./src/headers
LIBS = `pkg-config --libs gtk+-3.0`

all: main

main: src/main.o src/exec/caesar.o src/exec/vigenere.o src/exec/utils.o
	$(CC) -o main src/main.o src/exec/caesar.o src/exec/vigenere.o src/exec/utils.o $(LIBS)

src/main.o: src/main.c
	$(CC) -c src/main.c -o src/main.o $(CFLAGS)

src/exec/caesar.o: src/exec/caesar.c
	$(CC) -c src/exec/caesar.c -o src/exec/caesar.o $(CFLAGS)

src/exec/vigenere.o: src/exec/vigenere.c
	$(CC) -c src/exec/vigenere.c -o src/exec/vigenere.o $(CFLAGS)

src/exec/utils.o: src/exec/utils.c
	$(CC) -c src/exec/utils.c -o src/exec/utils.o $(CFLAGS)

clean:
	rm -f src/*.o src/exec/*.o main
