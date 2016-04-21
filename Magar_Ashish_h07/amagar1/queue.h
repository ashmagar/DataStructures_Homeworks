#include "dlinklist.h"
#include <stdlib.h>


struct queue
{
  struct dlinklist *que;

};
//allocate queue
struct queue* createQueue();
//push item onto the queue
void pushQueue(struct queue *q,struct data *dta);
//get item from top of queue
struct data* topQ(struct queue *q);
//pop item from the queue
void popQueue(struct queue *q);
//test if queue is empty.  return 1 if empty and 0 is not
int isEmptyQueue(struct queue *q);
//print queue.  You have to print from the queue.  You can not call a print function from dlinklist
void printQueue(struct queue *q);
//get number of elements from queue
int sizeQueue(struct queue *q);
//clean queue memory
void cleanQueue(struct queue *q);
//get integer equivalent for roman character
int getIntQ(char rom);
//conver roman numeral to integer
int convertRomanNumeralQueue(struct queue *q);
