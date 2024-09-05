CC = gcc
CFLAGS = -Wall -Wextra -O2 -I./src/inc
LDFLAGS = -L./src/lib -llua54 -lm
OBJ = complex.o
.PHONY: win linux

win:
	$(MAKE) complex.dll

linux:
	$(MAKE) complex.so


complex.dll: $(OBJ)
	$(CC) $(OBJ) --shared -o $@ $(LDFLAGS)
	del /F $(OBJ)
complex.so:
	$(CC) $(OBJ) --shared -o $@ $(LDFLAGS)
	rm -f $(OBJ)
complex.o:
	$(CC) -c src/complex.c $(CFLAGS)
