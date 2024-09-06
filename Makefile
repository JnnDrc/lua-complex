CC := gcc
CFLAGS := -Wall -Wextra -O2 -I./src/inc
LDFLAGS := -L./src/lib -llua54 -lm
SRC := src/complex.c
OBJ := complex.o
ifeq ($(OS), Linux)
	TARGET := complex.so
else ifeq ($(OS), Mac)
	TARGET := complex.dylib
else ifeq ($(OS), Windows)
	TARGET := complex.dll
else
	$(error Platform not supported)
endif

.PHONY: install clean-w clean-u

install:
	$(MAKE) $(TARGET)

complex.dll: $(OBJ)
	$(CC) $(OBJ) --shared -o $@ $(LDFLAGS)
complex.so:
	$(CC) $(OBJ) --shared -o $@ $(LDFLAGS)
complex.dylib:
	$(CC) $(OBJ) --shared -o $@ $(LDFLAGS)

complex.o: $(SRC)
	$(CC) -c $^ $(CFLAGS)

clean-w:
	del /F $(OBJ)

clean-u:
	rm -f $(OBJ)
