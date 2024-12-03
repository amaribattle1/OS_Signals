signals: signal.c
	gcc signal.c -o signalab 

CC = gcc
CFLAGS = -Wall -g

# Targets for the programs
all: signal timer

signal: signal.c
	$(CC) $(CFLAGS) -o signal signal.c

timer: timer.c
	$(CC) $(CFLAGS) -o timer timer.c

# Clean up generated files
clean:
	rm -f signal timer
