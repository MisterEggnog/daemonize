
BIN=daemonize

all: $(BIN)

$(BIN): daemon.c
	$(CC) -Wall -g -o $@ $^

release: daemon.c
	$(CC) -Wall -O3 -o $(BIN) $^
	strip $(BIN)

clean:
	$(RM) $(BIN)
