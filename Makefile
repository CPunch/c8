# make clean && make && ./bin/c8

CC=clang
CFLAGS=-fPIE -Wall #-g
LDFLAGS=-lncurses #-fsanitize=address
OUT=bin/c8

CHDR=\
	src/chip.h\
	src/tui.h

CSRC=\
	src/chip.c\
	src/tui.c\
	src/main.c

COBJ=$(CSRC:.c=.o)

.c.o:
	$(CC) -c $(CFLAGS) $< -o $@

$(OUT): $(COBJ) $(CHDR)
	mkdir -p bin
	$(CC) $(COBJ) $(LDFLAGS) -o $(OUT)

clean:
	rm -rf $(COBJ) $(OUT)