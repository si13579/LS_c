build : main.o getch.o getop.o stack.o
	gcc -o build main.o getch.o getop.o stack.o -lm
main.o : main.c calc.h
	gcc -g -c main.c 
getch.o : getch.c calc.h
	gcc -g -c getch.c
getop.o : getop.c calc.h
	gcc -g -c getop.c
stack.o : stack.c calc.h
	gcc -g -c stack.c
clean : 
	rm *.o