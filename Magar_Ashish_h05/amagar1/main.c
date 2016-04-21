#include "vector.h"
#include "data.h"

int main()
{

//1.Create vector
	struct vector *myVector = createVector();

//2.Create data
	struct data *myData = createData(0.0,0.0);

//3.Add data to vector using addFront()
	addFront(myVector,myData);

//4.Print
	printf("addFront()\n");
	printVector(myVector);

//remove() 3 times to check if empty then what happens.. nothing happens
	printf("removeBack()\n");
	removeBack(myVector);
	printVector(myVector);

	printf("removeFront()\n");
	removeFront(myVector);
	printVector(myVector);

	printf("removeBack()\n");
	removeBack(myVector);
	printVector(myVector);


//repeate steps 2&3 4 times

	int i =0;
	for(i=0;i<4;i++)
	{
		myData = createData(i+1.2,(i+1.3)*10);
		addFront(myVector,myData);
		printf("\n");
		printf("addFront()\n");
		printVector(myVector);
	}

//5.removeBack()
	removeBack(myVector);
	printf("\n\n");
	printf("removeBack() \n");
	printVector(myVector);

//6.addBack()
	myData = createData(99.0, 98.0);
	addBack(myVector,myData);
	printf("\n\n");
	printf("addBack() \n");
        printVector(myVector);

//7.removeFront()
	removeFront(myVector);
	printf("\n\n");
	printf("removeFront() \n");
	printVector(myVector);

//8.sumVector()
	printf("\nsumVector()\n");
	printf("%f\n\n",sumVector(myVector));

//9.cloneVector() and printVector()
	struct vector *myVector1 = cloneVector(myVector);
	printf("\n\nCloned vector\n");
	printVector(myVector1);

//10.compareVectors()
	printf("compareVectors()");
	printf("\n%d\n",compareVectors(myVector,myVector1));

//11.reverseVector() and printVector()
	reverseVector(myVector);
	printf("\n\nreverseVector()\n");
	printVector(myVector);

//12.cleanVector()  -> clean both vectors
	cleanVector(myVector);		//need to free each element in array i.e. myVector->array[i], then myVector->array then myVector
	cleanVector(myVector1);		//need to free each element in array i.e. myVector->array[i], then myVector->array then myVector

	return 0;
}
