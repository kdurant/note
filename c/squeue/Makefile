cc = gcc -std=c99 
prog = main 
deps = squeue.h
obj = main.o squeue.o

$(prog) : $(obj)
	$(cc) -o $(prog) $(obj)

%.o : %.c $(deps)
	$(cc) -c $< -o $@

clean:
	rm *.exe
	rm *.o