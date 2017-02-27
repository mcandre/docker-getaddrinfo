BIN=bin/getaddrinfo
UNAME=$(shell uname)
STATIC=

ifeq ($(UNAME), Linux)
  STATIC="-static"
endif

all: $(BIN)

$(BIN): lib/getaddrinfo.c
	mkdir -p bin
	gcc -o $(BIN) $(STATIC) lib/getaddrinfo.c

clean:
	-rm -rf bin
