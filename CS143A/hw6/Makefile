CC = gcc
CFLAGS = -I.
PROGRAM = banker
INPUT = test_safe.txt

all:banker.c
	$(CC) -o $(PROGRAM) banker.c $(CFLAGS)

run: $(PROGRAM) $(INPUT)
	$(PROGRAM) < $(INPUT)

clean:
	rm $(PROGRAM)
