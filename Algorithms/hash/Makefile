CC = gcc
TARGET = main.exe
SYMBOLS = -DTEST


SRC_FILES = main.c hashmap.c


all: default

default:
	$(CC) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES) -o $(TARGET)
	./$(TARGET)

clean:
	rm *.exe
