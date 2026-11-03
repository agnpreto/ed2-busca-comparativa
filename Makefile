CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c99
SRC = $(wildcard src/*.c)

comparativo: $(SRC) $(wildcard src/*.h)
	$(CC) $(CFLAGS) -o comparativo $(SRC)

clean:
	rm -f comparativo comparativo.exe
