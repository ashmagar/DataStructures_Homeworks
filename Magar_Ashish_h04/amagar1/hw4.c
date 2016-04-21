#include "hw4.h"

//1. Generates array of random numbers
struct input* generateArray(int size)
{
	struct input *inputTemp = malloc(sizeof(struct input));
	inputTemp->array = malloc(size * sizeof(struct input));	//Allocate memory for *array in strucutre
	int i = 0;
	for(i=0;i<size;i++)
	{
		inputTemp->array[i] = getRand();		//Generates random numbers and stores in array
	}
	inputTemp->size = size;
	return inputTemp;
}

//2.Generates array of pointers to data
struct data** generateDataArray(int size)
{
	struct data **dTemp = malloc(size * sizeof(struct data*));
	int i = 0;
	for(i=0;i<size;i++)
	{
		dTemp[i] = generateData(getRandBetween(0,size/2),getRandBetween(size/2,size));
			//Generates start and end randomly and assigns to Start,End in structure data
	}

	return dTemp;
}

//3.Generates start and end randomly
struct data* generateData(int s, int e)
{
	struct data *temp = malloc(sizeof(struct data));
	temp->Start = s;
	temp->End = e;
	temp->Max = -99999;
	return temp;
}

//4.Calculates maximum difference for all data structures
void findMax(struct data **points, int pointSize, struct input *inputs)
{
	int i = 0;
	for(i=0;i<pointSize;i++)
	{
		getMax(inputs,points[i]);	//for all structures gets maximum difference
	}
}

//5.Calculates maximum difference
void getMax(struct input *inputArr, struct data *dVals)
{
	int i = 0, j = 0, diff = -99999;
	for(i = dVals->Start; i < dVals->End; i++)  	//i is between start and end
	{
		for(j=i+1; j <= dVals->End; j++)	//j is always greaer then i
		{
			diff = (inputArr->array[j] - inputArr->array[i]); 
			if( diff  > dVals->Max )
			{
				dVals->Max = diff;	//if difference is greater than max, update max
			}
		}
	}
}

//6.Prints the result
void printData(struct data **d, int dataSize)
{
	int i = 0;
	for(i = 0; i<dataSize; i++)
	{
		printf("%d %d %d \n",d[i]->Start,d[i]->End,d[i]->Max);
	}
}
