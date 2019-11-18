# CC = gcc -std=c99
CC = gcc
CFLAGS  = -std=c99
CFLAGS += 
CFLAGS += -I ./src
CFLAGS += -I ./unity

TARGET = main 
deps = use.h unity.h unity_internals.h
obj = main.o use.o unity.o

$(TARGET) : $(obj)
	$(CC) $(CFLAGS) -o $(TARGET) $(obj) 

	@-rm *.o
	@echo "=============run program================="
	@./$(TARGET)

main.o:
	$(CC) $(CFLAGS) -c	./unit_test/main.c  -o main.o 
	
use.o:
	$(CC) $(CFLAGS) -c	./src/use.c  -o use.o 

unity.o:
	$(CC) $(CFLAGS) -c	./unity/unity.c  -o unity.o 

clean:
	@-rm *.o