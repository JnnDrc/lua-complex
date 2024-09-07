# Variables

# Compiler
CC := gcc
# Compiling flags
CFLAGS := -Wall -Wextra -O3
# linking flags
LDFLAGS := -llua54 -lm
# src file(s)
SRC := src/complex.c
# lib directory
LIB := src/lib
# object
OBJ := complex.o

# Os handling
ifeq ($(OS), Linux)
	TARGET := complex.so
	LDFLAGS += -L./$(LIB)/$(OS)
else ifeq ($(OS), MacOS)
	TARGET := complex.dylib
	LDFLAGS += -L./$(LIB)/$(OS)
else ifeq ($(OS), Windows)
	TARGET := complex.dll
	LDFLAGS += -L./$(LIB)/$(OS)
else ifeq ($(OS), BSD)
	TARGET := complex.so
	LDFLAGS += -L./$(LIB)/$(OS)
else
	$(error Platform not supported)
endif

# Phonys
.PHONY: install clean-w clean-u

install:
	$(MAKE) $(TARGET)

# targets

# windows dynamic linked library
complex.dll: $(OBJ)
	$(CC) $(OBJ) --shared -o $@ $(LDFLAGS)
# linux/BSD shared object
complex.so:
	$(CC) $(OBJ) --shared -o $@ $(LDFLAGS)
# macos dynamic lib
complex.dylib:
	$(CC) $(OBJ) --shared -o $@ $(LDFLAGS)

# object
complex.o: $(SRC)
	$(CC) -c $^ $(CFLAGS)

# clean for windows
clean-w:
	del /F $(OBJ)
# clean for unix-like systems
clean-u:
	rm -f $(OBJ)
