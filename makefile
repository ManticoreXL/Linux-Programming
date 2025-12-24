CC = gcc
CFLAGS = -wall -g

TARGET = test
SOURCE = test.c
OBJECTS = $(SOURCE: .c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< # $<

clean:
	rm -f $(TARGET)