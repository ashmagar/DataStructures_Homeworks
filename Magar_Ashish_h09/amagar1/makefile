all:main

data.o: data.h data.c
	gcc -Wall -g -c data.c

random.o: random.h random.c
	gcc -Wall -g -c random.c

timing.o: timing.h timing.c
	gcc -Wall -g -c timing.c

avl.o: avl.h avl.c
	gcc -Wall -g -c avl.c

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

main: data.o random.o timing.o avl.o main.o dlinklist.o stack.o queue.o bst.o
	gcc -Wall -g data.o random.o timing.o avl.o dlinklist.o stack.o queue.o bst.o main.o -o main

clean:
	rm *.o *~ main
