cc = gcc -std=c99
# cc = clang
flags = -D TEST

prog = main 
deps = list.h
obj = main.o list.o

$(prog) : $(obj)
	$(cc) $(flags) -o $(prog) $(obj) 

	@echo "=============run program================="
	@./$(prog)
	# @-rm *.exe
	@-rm *.o
	@-rm $(prog)

%.o : %.c $(deps)
	$(cc) $(flags) -c $< -o $@

clean:
	@-rm *.exe
	@-rm *.o