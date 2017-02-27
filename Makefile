BIN=bin/getaddrinfo

all: $(BIN)

$(BIN): lib/getaddrinfo.c
	mkdir -p bin
	gcc -o $(BIN) -static lib/getaddrinfo.c

clean:
	-rm -rf bin
