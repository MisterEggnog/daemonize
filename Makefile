
BIN=daemonize

all: $(BIN)

$(BIN): daemon.c
	gcc -Wall -g -o $@ $^

test: $(BIN)
	./$(BIN) nothing.sh
