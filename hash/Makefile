# Makefile

CC = gcc
CFLAGS = -Wall -std=c99
BIN = test
CHAINING_SRC = chaining/chaining.c chaining/test.c
DOUBLE_HASH_SRC = double_hash/double_hash.c double_hash/test.c
LINEAR_PROBE_SRC = linear_probe/linear_probe.c linear_probe/test.c

test_chaining:
	$(CC) $(CFLAGS) $(CHAINING_SRC) -o $(BIN)
	./$(BIN)
	rm ./$(BIN)
	
test_linear_probe:
	$(CC) $(CFLAGS) $(LINEAR_PROBE_SRC) -o $(BIN)
	./$(BIN)
	rm ./$(BIN)

test_double_hash:
	$(CC) $(CFLAGS) $(DOUBLE_HASH_SRC) -o $(BIN)
	./$(BIN)
	rm ./$(BIN)
	

clean:
	rm -f $(BIN)
