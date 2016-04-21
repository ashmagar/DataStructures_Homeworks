#ifndef HW4_H_
#define HW4_H_

#include<stdio.h>
#include "random.h"

struct data
{
	int Start;
	int End;
	int Max;
};

struct input
{
	int *array;
	int size;
};

struct input* generateArray(int size);			//Generates array of random numbers
struct data* generateData(int s, int e);		//Generates start and end randomly
struct data** generateDataArray(int size);		//Generates array of pointers to data
void getMax(struct input *inputArr, struct data *dVals);	//Calculates maximum difference
void printData(struct data **d, int dataSize);		//Prints he result
void findMax(struct data **points, int pointSize, struct input *inputs);
							//Calculates maximum difference for all data structures

#endif
