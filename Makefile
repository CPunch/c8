# make clean && make && ./bin/c8

CC=clang
CFLAGS=-fPIE -Wall -std=c89 #-g
LDFLAGS=-pthread -lSDL2 #-fsanitize=address
OUT=bin/c8

CHDR=\
	src/chip.h\
	src/gfx.h

CSRC=\
	src/chip.c\
	src/gfx.c\
	src/main.c

COBJ=$(CSRC:.c=.o)

.c.o:
	$(CC) -c $(CFLAGS) $< -o $@

$(OUT): $(COBJ) $(CHDR)
	mkdir -p bin
	$(CC) $(COBJ) $(LDFLAGS) -o $(OUT)

clean:
	rm -rf $(COBJ) $(OUT)