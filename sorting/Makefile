# Makefile

CC = gcc
CFLAGS = -Wall -std=c99
BIN = test
BUBBLE_SORT_SRC = bubble_sort/bubble_sort.c bubble_sort/test.c

test_bubble:
	$(CC) $(CFLAGS) $(BUBBLE_SORT_SRC) -o $(BIN)
	./$(BIN)
	rm ./$(BIN)
	

clean:
	rm -f $(BIN)
