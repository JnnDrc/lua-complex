CC = gcc
CFLAGS = -Wall -Wextra -O2 -I./src/inc
LDFLAGS = -L./src/lib -llua54 -lm
OBJ = complex.o
.PHONY: win linux clean-w clean-u

win:
	$(MAKE) complex.dll

linux:
	$(MAKE) complex.so


complex.dll: $(OBJ)
	$(CC) $(OBJ) --shared -o $@ $(LDFLAGS)
complex.so:
	$(CC) $(OBJ) --shared -o $@ $(LDFLAGS)
complex.o:
	$(CC) -c src/complex.c $(CFLAGS)

clean-w:
	del /F $(OBJ)

clean-u:
	rm -f $(OBJ)
