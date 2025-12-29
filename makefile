CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lm

TARGET = test
SOURCE = test.c
OBJECTS = $(SOURCE: .c=.o)

all: $(TARGET)

# General compile 
$(TARGET): $(OBJECTS)
	$(CC) $(CLAGS) -o $@ $^

# Compile with math library
math: $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< # $<

clean:
	rm -f $(TARGET)