all:main

data.o: data.h data.c
	gcc -Wall -g -c data.c

dlinklist.o: dlinklist.h dlinklist.c
	gcc -Wall -g -c dlinklist.c

queue.o: queue.h queue.c
	gcc -Wall -g -c queue.c

stack.o: stack.h stack.c
	gcc -Wall -g -c stack.c

bst.o: bst.h bst.c
	gcc -Wall -g -c bst.c 

main.o: main.c
	gcc -Wall -g -c main.c

main: data.o dlinklist.o queue.o bst.o main.o stack.o
	gcc -Wall -g data.o dlinklist.o queue.o stack.o bst.o main.o -o main

clean:
	rm *.o *~ main
