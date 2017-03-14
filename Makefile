CC = g++
CFLAGS = -Wall -Wextra -Wpedantic
FILES = main.cpp
TARGET = loops

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(FILES)

clean:
	rm $(TARGET)

clang:
	clang++ $(CFLAGS) -o $(TARGET) $(FILES)
