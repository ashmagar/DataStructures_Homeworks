#include "stack.h"
#include "queue.h"
#include<assert.h>
#include<string.h>

int main(int argc, char* argv[])
{
	if(argc==1) return -1;
	
	struct stack *myS = createStack();
	struct queue *myQ = createQueue();

	struct data *myDS = NULL;
	struct data *myDQ = NULL;
		//Different data structs for stack and queue as we can't resue them
	char* roman = argv[1];
	//printf("Roman : %s\n",roman);
	int i=0;
	for(i=0;i<strlen(roman);i++)
	{
		myDS = createDataNumeral(roman[i]);
		myDQ = createDataNumeral(roman[i]);
		pushStack(myS,myDS);		
		pushQueue(myQ,myDQ);		
			//Taking characters of entered string and putting in stack and queue
	}
	int romanToInt = 0;
	romanToInt = convertRomanNumeralStack(myS);
	//printf("Equivalent roman(S) : ");
	printf("%d\n",romanToInt);

	romanToInt = convertRomanNumeralQueue(myQ);
	//printf("Equivalent roman(Q) : ");
	printf("%d\n",romanToInt);

	cleanStack(myS);
	cleanQueue(myQ);
	return 0;
}

/*
int main(int argc, char* argv[])
{
	if( (argc==1)|| (argc-1)%2!=0 ) 
	{
		return -1;
	}

	struct stack *myS = createStack();
	struct queue *myQ = createQueue();

	struct data* myDS = NULL;
	struct data* myDQ = NULL;
	int i=0;
	for(i=1;i<argc;i+=2)
	{
		assert(i+1<argc);
		myDS = createData( atof(argv[i]), atof(argv[i+1]) );
		pushStack(myS,myDS);
		printf("\npushS()\n");

		myDQ = createData( atof(argv[i]), atof(argv[i+1]) );
		pushQueue(myQ,myDQ);
		printf("\npushQ()\n");
	}

	printf("\nStack\n");
	printStack(myS);
	printf("\nQueue\n");
	printQueue(myQ);

	popStack(myS);
	printf("\npopS()\n");
	printStack(myS);

	popQueue(myQ);
	printf("\npopQ()\n");
	printQueue(myQ);
	
	myDS= createData(44.44,55.55);
	pushStack(myS,myDS);
	printf("\npushS()\n");
	printStack(myS);

	myDQ= createData(44.44,55.55);
	pushQueue(myQ,myDQ);
	printf("\npushQ()\n");
	printQueue(myQ);

	int sizeS = sizeStack(myS);
	printf("\nsizeS()\n");
	printf("%d\n",sizeS);
	printStack(myS);

	int sizeQ = sizeQueue(myQ);
	printf("\nsizeQ()\n");
	printf("%d\n",sizeQ);
	printQueue(myQ);

	cleanStack(myS);
	cleanQueue(myQ);
	return 0;
}
*/
