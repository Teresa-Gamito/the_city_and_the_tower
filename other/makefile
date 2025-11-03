# Commands
# make - builds debug version (default)
# make debug - same as above
# make release - optimized build
# make run - builds debug then runs ./app
# make clean - deletes .o, .d, and app 

# Compiler
CC      := gcc        # on MacOS we can change to clang

# Common flags
CSTD    := -std=c17
WARN    := -Wall -Wextra -Wpedantic
DEPS    := -MMD -MP     # auto-generate header dependencies

# Debug and Release flags
DBG     := -g -O0 -fno-omit-frame-pointer
REL     := -O2 -DNDEBUG

# Project structure
SRC     := $(wildcard *.c)
OBJ     := $(SRC:.c=.o)
DEP     := $(OBJ:.o=.d)
BIN     := app

.PHONY: all debug release run clean

# Default build: debug
all: debug

debug: CFLAGS := $(CSTD) $(WARN) $(DBG) $(DEPS)
debug: $(BIN)

release: CFLAGS := $(CSTD) $(WARN) $(REL) $(DEPS)
release: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: debug
	./$(BIN)

clean:
	rm -f $(OBJ) $(DEP) $(BIN)

# Include dependency files (auto-updated)
-include $(DEP)
