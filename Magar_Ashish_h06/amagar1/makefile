all: main

data.o: data.c data.h
	gcc -Wall -c -g data.c

hw6.o: hw6.c hw6.h 
	gcc -Wall -c -g hw6.c

main.o: main.c
	gcc -Wall -c -g main.c

main: data.o hw6.o main.o
	gcc -Wall -g data.o hw6.o main.o -o main

clean:
	rm -f *.o *~ main
