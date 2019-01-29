# CC = gcc -std=c99
CC = gcc

CFLGAS += -std=c99
CFLAGS += -D TEST
CFLAGS += -g

OBJ_PATH = .
BIN_PATH = .
SRC_PATH = .

# IDIR = ./head
# INC += -I$(IDIR)

TARGET = $(BIN_PATH)/main 
# ifeq ($(OS),Windows_NT)
# 	TARGET_NAME := $(addsuffix .exe,$(TARGET_NAME))
# endif

C_SRCS += ./main.c
C_SRCS += ./linkstack.c
OBJ := $(patsubst %.c,%.o,$(filter %.c,$(C_SRCS)))


$(TARGET) : $(OBJ_PATH)/$(OBJ)
	$(CC) $(INC) $(CFLAGS)  $(OBJ)  -o $(TARGET)
	@find . -name "*.o"  | xargs rm -f
	# @-rm *.exe

$(OBJ): %.o : %.c
	$(CC) $(INC) $(CFLAGS) -c $< -o $@

.PHONY : clean
clean:
	@-rm *.exe
	@-rm *.o