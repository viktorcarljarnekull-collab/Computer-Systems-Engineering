# make       builds part1 and part2
# ./part1    question 1, type: Re(z1) Im(z1) Re(z2) Im(z2)
# ./part2    question 2, prints the magnitude statistics

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic
LDLIBS = -lm

.PHONY: all clean

all: part1 part2

part1: part1.c
	$(CC) $(CFLAGS) -o part1 part1.c $(LDLIBS)

part2: part2.c
	$(CC) $(CFLAGS) -o part2 part2.c $(LDLIBS)

clean:
	rm -f part1 part2
