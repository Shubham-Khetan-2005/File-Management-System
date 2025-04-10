CC = gcc
CFLAGS = -Wall -Wextra -g
CFLAGS += -DDBG

INCLUDES = -I./src
LDFLAGS = -lfuse

# List of source files in the src directory.
SRC = src/lib.c src/objstore.c
OBJ = $(SRC:.c=.o)

TARGET = objfs

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
