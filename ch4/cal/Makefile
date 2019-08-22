
objs = main.o getch.o getop.o stack.o

calculate:$(objs)
	cc -o calculate $(objs)

$(objs): main.c calc.h getch.c getop.c stack.c 

clean:
	rm -rf *.o