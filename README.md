# C8

C8 is a minimal Chip8 emulator written in C99. It's specification was based off of [this pdf](http://www.cs.columbia.edu/~sedwards/classes/2016/4840-spring/designs/Chip8.pdf). The emulator was written in a day and tries to be as close to the specification as possible.

# Compiling

Simply run `make` to compile using the CLang compiler.

```
make clean && make
```

or you can specify a different C compiler by specifying CC, eg. to use the GNU C compiler

```
make CC=gcc
```

the output binary will be located at `bin/c8`