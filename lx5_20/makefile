build : main.o gettoken.o dcl.o parmdcl.o getch.o
	gcc -o build main.o gettoken.o dcl.o parmdcl.o getch.o
main.o : main.c abc.h
	gcc -g -c main.c
gettoken.o : gettoken.c abc.h
	gcc -g -c gettoken.c
dcl.o : dcl.c abc.h
	gcc -g -c dcl.c
parmdcl.o : parmdcl.c abc.h
	gcc -g -c parmdcl.c
getch.o : getch.c abc.h
	gcc -g -c getch.c
clean : 
	rm *.o