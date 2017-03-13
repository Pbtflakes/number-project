CC = g++
CFLAGS = -Wall -Wextra
FILES = main.cpp file.cpp
TARGET = loops

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(FILES)

clean:
	rm $(TARGET)

clang:
	clang++ $(CFLAGS) -o $(TARGET) $(FILES)
