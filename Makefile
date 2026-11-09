# DT4012 Software Lab 1
#   make        build part1 and part2
#   make test   compile and run the checks, then both programs
#   ./part1     enter Re(z1) Im(z1) Re(z2) Im(z2)
#   ./part2     magnitude statistics for the 100-number appendix

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic
LDLIBS = -lm

.PHONY: all clean test

all: part1 part2

part1: part1.c complex.c complex.h
	$(CC) $(CFLAGS) -o part1 part1.c complex.c $(LDLIBS)

part2: part2.c complex.c stats.c complex.h stats.h
	$(CC) $(CFLAGS) -o part2 part2.c complex.c stats.c $(LDLIBS)

test_complex: test_complex.c complex.c stats.c complex.h stats.h
	$(CC) $(CFLAGS) -o test_complex test_complex.c complex.c stats.c $(LDLIBS)

test: test_complex part1 part2
	./test_complex
	printf '3 4 1 -2\n' | ./part1
	./part2

clean:
	rm -f part1 part2 test_complex
