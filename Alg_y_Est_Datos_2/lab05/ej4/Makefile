CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g

SOURCES = stack.c hanoi.c main.c
OBJECTS = $(SOURCES:.c=.o)

TARGET = solve-hanoi

.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full ./solve-hanoi 10