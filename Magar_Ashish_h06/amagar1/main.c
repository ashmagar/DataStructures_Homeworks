#include "hw6.h"
#include<assert.h>

int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		return -1;
	}
	struct data *myDta = NULL;
	struct linkedList *myLl = createLinkedList();

	int i = 0;
//adding element to ith position
	for(i=1;i<argc;i++)
	{
		myDta = createDataLetters(argv[i]);
		addNPos(myLl,myDta,i);
	}
	printLinkedList(myLl);

//adding element to head
	myDta = createDataLetters("CS580");
	addNPos(myLl,myDta,0);
	printLinkedList(myLl);

//adding element when n>size of linked list
	myDta = createDataLetters("PST");
	addNPos(myLl,myDta,100);
	printLinkedList(myLl);

//removing from 0th position
	removeNPos(myLl,0);
	printLinkedList(myLl);

//removing from last when n>size of linked list
	removeNPos(myLl,49);
	printLinkedList(myLl);

// get letter count
	char *letterCountString = getLetterCount(myLl);
	printf("%s \n",letterCountString);

//clean 
	cleanLinkedList(myLl);
	
//free the string used for printing getLetterCount()
	free(letterCountString);
  return 0;
}
