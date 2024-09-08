# Variables
# Compiler
CC := gcc
# Compiling flags
CFLAGS := -Wall -Wextra -O3
# linking flags
LDFLAGS := -llua54 -lm
# src directory
SRC := src
# lib directory
LIB := $(SRC)/lib
# object
OBJ := complex.o trig.o arith.o other.o
# clean recipe
CLN := 

# Os handling
ifeq ($(OS), Linux)
	TARGET := complex.so
	LDFLAGS += -L./$(LIB)/$(OS)
	CLN = clean-unix
else ifeq ($(OS), MacOS)
	TARGET := complex.dylib
	LDFLAGS += -L./$(LIB)/$(OS)
	CLN = clean-unix
else ifeq ($(OS), Windows)
	TARGET := complex.dll
	LDFLAGS += -L./$(LIB)/$(OS)
	CLN = clean-windows
else ifeq ($(OS), BSD)
	TARGET := complex.so
	LDFLAGS += -L./$(LIB)/$(OS)
	CLN = clean-unix
endif

# Phonys
.PHONY: install clean

install:
	$(MAKE) $(TARGET)

clean:
	$(MAKE) $(CLN)

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

# objects
%.o : $(SRC)/%.c
	$(CC) -c $< $(CFLAGS)

# clean for windows
clean-windows:
	del /F $(OBJ)
# clean for unix-like systems
clean-unix:
	rm -f $(OBJ)
