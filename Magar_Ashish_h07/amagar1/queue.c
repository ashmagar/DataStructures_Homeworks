#include "queue.h"

//allocate queue
struct queue* createQueue()
{
  struct queue *q = malloc(sizeof(struct queue));
  q->que = createDLinkedList();
  return q;
}

//push item onto the queue
void pushQueue(struct queue *q,struct data *dta)
{
	addBack(q->que,dta);
}

//get item from top of queue
struct data* topQ(struct queue *q)
{
	return(getFront(q->que));
}

//pop item from the queue
void popQueue(struct queue *q)
{
	removeFront(q->que);
}

//test if queue is empty.  return 1 if empty and 0 is not
int isEmptyQueue(struct queue *q)
{
	return(isEmpty(q->que));
}

//print queue.  You have to print from the queue.  You can not call a print function from dlinklist
void printQueue(struct queue *q)
{
	struct queue* tempQ = createQueue();
	while(!isEmptyQueue(q))
	{
		struct data* tempDta = topQ(q);
		printData(tempDta);
		pushQueue(tempQ,createData(tempDta->v1,tempDta->v2));
		popQueue(q);
	}
		//pop elements out from front of queue print and push in temp queue
	
	while(!isEmptyQueue(tempQ))
	{
		struct data* tempDta = topQ(tempQ);
		pushQueue(q,createData(tempDta->v1,tempDta->v2));
		popQueue(tempQ);
	}
		//push elements back into queue from temp queue
	cleanQueue(tempQ);
}

//get number of elements from queue
int sizeQueue(struct queue *q)
{
	struct queue* tempQ = createQueue();
        int size=0;
        while(!isEmptyQueue(q))
        {
                struct data* tempDta = topQ(q);
                size++;
                pushQueue(tempQ,createData(tempDta->v1,tempDta->v2));
                popQueue(q);
        }
			/*Pop elements from queue,increment counter for each element 
			push them into temporary queue */         
        while(!isEmptyQueue(tempQ))
        {
                struct data* tempDta = topQ(tempQ);
                pushQueue(q,createData(tempDta->v1,tempDta->v2));
                popQueue(tempQ);
		}
			//push elements back to the queue from temp queue
	cleanQueue(tempQ);
	return size;
}

//convert Roman numeral to integer and return it
int convertRomanNumeralQueue(struct queue *q)
{
	int num=0;
	int element=0;		//current Roman letter
	int temp=0;		//to store previous Roman letter to perform checks
	int sequence=0;
	while(!isEmptyQueue(q))
	{
   		/*In queue we are processing given Roman letters string from
		left to right as we pop elements from the front of the queue,
		we add if the integer equivalent of current letter is less 
		than previous one*/
		struct data *tDta = topQ(q);
		element = getIntQ(tDta->numeral);	//current Roman letter

		if(element==temp)		
		{
			/*current element equal to previous then we maintain a sequence
			to handle negative numbers, if next element after last element of sequence
			is greater then we subtract sequence else we add sequence*/
		
 			if(sequence==0) { sequence = sequence+temp; }
				//we already traversed one letter so we need to add it in sequence
			sequence = sequence + element;
				//add element to sequence
		}

		else if(element>temp)
		{
			if(sequence!=0) 	//that means previous few elements are equal
			{
				num = num - sequence;		
					/*we added element(of sequence) after each condition
					 into num so we need to subtract it*/
				element = element - sequence;
			}
			else
			{
				num = num - temp;
				element = element - temp;
  			}
				sequence=0; 
		}
		else if(element<temp)
		{
				sequence=0; 
		}
		num = num + element;
		temp = getIntQ(tDta->numeral);
		
		popQueue(q);
	} 
	return num;
}

//returns integer equivalent of the Roman letter
int getIntQ(char rom)
{
	switch(rom)
	{
		case 'I': return 1;	 break;
		case 'V': return 5; 	 break;
		case 'X': return 10;	 break;
		case 'L': return 50;	 break;
		case 'C': return 100;	 break;
		case 'D': return 500;	 break;
		case 'M': return 1000;	 break;
		default : return 0;
	}
}


//clean queue memory
void cleanQueue(struct queue *q)
{
	while(!isEmptyQueue(q))
	{
		popQueue(q);
	}
	free(q->que);	
	free(q);
}
