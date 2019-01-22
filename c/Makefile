# CC = gcc -std=c99
CC = gcc -std=c99 -g

CFLGAS  = -std=c99
CFLAGS += -D TEST
CFLAGS += -g

IDIR = ./head
INC = -I$(IDIR)

TARGET = main 

obj = main.o list.o

$(TARGET) : $(obj)
	$(CC) $(INC) $(CFLAGS)  $(obj)  -o $(TARGET)

	# @echo "=============run program================="
	@./$(TARGET)
	@-rm *.o

%.o : %.c
	$(CC) $(INC) $(CFLAGS) -c $< -o $@

clean:
	@-rm *.exe
	@-rm *.o