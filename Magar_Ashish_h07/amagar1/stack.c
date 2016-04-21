#include "stack.h"

//allocate stack
struct stack* createStack()
{
  struct stack *s = malloc(sizeof(struct stack));
  s->stk = createDLinkedList();
  return s;
}

//push item onto the stack
void pushStack(struct stack *s,struct data *dta)
{
	addFront(s->stk,dta);
}

//get item from top of stack
struct data* topS(struct stack *s)
{
	return getFront(s->stk);
}

//pop item from the stack
void popStack(struct stack *s)
{
	removeFront(s->stk);
}

//test if stack is empty.  return 1 if empty and 0 is not
int isEmptyStack(struct stack *s)
{
	return(isEmpty(s->stk));
}

//print stack.  You have to print from the stack. You can not call a print function from dlinklist
void printStack(struct stack *s)
{
	struct stack *tS = createStack();
	while(!isEmptyStack(s))
	{
		struct data* tDta = topS(s);
		printData(tDta);
		pushStack(tS,createData(tDta->v1,tDta->v2));
		popStack(s);
	}
		//pop elements out from stack print and push in temp stack
		
	while(!isEmptyStack(tS))
	{
		struct data* tDta = topS(tS);
		pushStack(s,createData(tDta->v1,tDta->v2));
                popStack(tS);
	}	
		//push elements back into stack from temp stack
	cleanStack(tS);
}

//get number of elements from stack
int sizeStack(struct stack *s)
{
	struct stack *tS = createStack();
	int size=0;
        while(!isEmptyStack(s))
        {
                struct data* tDta = topS(s);
                size++;
                pushStack(tS,createData(tDta->v1,tDta->v2));
                popStack(s);
        }
		/*Pop elements from stack,increment counter for each element 
		push them into temporary stack */ 
        while(!isEmptyStack(tS))
        {
                struct data* tDta = topS(tS);
                pushStack(s,createData(tDta->v1,tDta->v2));
                popStack(tS);
        }
		//push elements back to the stack from temp stack
    cleanStack(tS);
	return size;
}

//convert Roman numeral to integer and return it
int convertRomanNumeralStack(struct stack *s)
{
	int num=0;
	int element=0;	//current Roman letter
	int temp=0;	//to store previous Roman letter to perform checks
	int flag=0;
	while(!isEmptyStack(s))
	{
		/*In stack we are processing given Roman letters string from
		right to left, we add if the integer equivalent of current letter 
		is greater than previous one and subtract otherwise*/

        struct data* tDta = topS(s);
        element = getInt(tDta->numeral);	//current Roman letter
		if(element<temp)
		{
			element = -element;
			flag = 1;
		}
		else if(element>temp)
		{
			flag = 0;
		}
		if(element==temp)
		{
			if(flag==1) element = -(abs(element));
			if(flag==0) element = abs(element);
		}
		/* if previous and current are equal we need to add or subtract 
		according to previous operation whether it was addition or subtraction */
		
		num = num + element;
		temp = abs(element);
		popStack(s);
	} 
	return num;
}

//returns integer equivalent of the Roman letter
int getInt(char rom)
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

//clean stack memory
void cleanStack(struct stack *s)
{
	while(!isEmptyStack(s))
	{
		popStack(s);
	}
	free(s->stk);
	free(s);
}
