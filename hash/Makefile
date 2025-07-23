# Makefile

CC = gcc
CFLAGS = -Wall -std=c99
BIN = test
CHAINING_SRC = chaining/chaining.c chaining/test.c

test_chaining:
	$(CC) $(CFLAGS) $(CHAINING_SRC) -o $(BIN)
	./$(BIN)
	rm ./$(BIN)
	

clean:
	rm -f $(BIN)
