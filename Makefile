CC = g++
CFLAGS = -Wall -Wextra -Wpedantic -O0
FILES = main.cpp
TARGET = loops

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(FILES)

debug:
	$(CC) $(CFLAGS) -g $(FILES) -o $(TARGET)

clean:
	rm $(TARGET)

clang:
	clang++ $(CFLAGS) -o $(TARGET) $(FILES)
