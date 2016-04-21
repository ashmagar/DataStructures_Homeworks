all: main
main.o: main.c
	gcc -Wall -c -g main.c
hw4.o: hw4.c
	gcc -Wall -c -g hw4.c
random.o: random.c
	gcc -Wall -c -g random.c
main: main.o hw4.o random.o
	gcc -Wall hw4.o main.o random.o -g -o main
clean:
	rm -f *.o main

