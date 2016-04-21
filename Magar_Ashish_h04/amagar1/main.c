#include "hw4.h"

int main()
{
	SeedRand();
	int size = 6;
//1.Generate random array elements
	struct input *inputArr = generateArray(size);	
	int i=0;
/*	printf("Array is \n");
	for(i=0;i<size;i++)
	{
		printf("%d ",inputArr->array[i]);
	}
	printf("\n");
*/

//2.Generate data structures
	struct data **d = generateDataArray(inputArr->size);
//3.Finding maximum for eact start and end
	findMax(d,size,inputArr);
//4.Printing the result
	printData(d,inputArr->size);
//Freeing the allocated memory
	free(inputArr->array);
	free(inputArr);
	for(i=0;i<size;i++)
	{
		free(d[i]);
	}
	free(d);

	return 0;
}
