CC = gcc
CFLAGS = -lncurses -I$(IDIR)

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c

all: main run clean

main:
	$(CC) $(SOURCES) $(CFLAGS) -o $@

run:
	./main

clean:
	rm main