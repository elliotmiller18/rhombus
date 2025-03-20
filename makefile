# Simple Makefile for a C project

# Compiler
CC = gcc

# Compiler flags: -Wall enables all warnings, -Wextra enables extra warnings,
# -std=c99 specifies the C standard, and -g adds debugging info.
CFLAGS = -Wall -Wextra -std=c99 -g

# List your source files here.
SRC = main.c lexer.c bar.c

# Object files: automatically replace .c with .o
OBJ = $(SRC:.c=.o)

# Target executable name
TARGET = myprogram

# The default rule, invoked when you type 'make'
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJ) $(TARGET)

# Declare targets that are not files
.PHONY: all clean