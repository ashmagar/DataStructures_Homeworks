#include "vector.h"

struct vector* createVector()
{
	struct vector *tempVect = malloc(sizeof(struct vector));
	tempVect->size= 0;
	tempVect->array = NULL;
	return tempVect;
}

void addFront(struct vector *vec,struct data *dta)
{
	vec->size = vec->size + 1;
		//increase the vector size
	struct data **temp = vec->array;
		//copy array into temp
	vec->array = malloc(vec->size * sizeof(struct data*));
		//create a new array with new size
	vec->array[0] = dta;		//array[0] = dta
		//add new element to the front i.e. array[0]
	int i=0;
	for(i=1;i < (vec->size);i++)
	{
		vec->array[i] = temp[i-1];
			//copy remaining(old) itemes from temp
	}
	free(temp);
		//free the temperory array
}

void removeBack(struct vector *vec)
{
	if(vec->size!=0)	//if size is 0 segfault occurs, hence this condition
	{
		free(vec->array[vec->size-1]);
		//free the dta* to be removed
		vec->size--;
	}
  		//decrement the size
/*
	The above logic lefts one extra space in vector* but it is
	ultimately handled(freed) by either temp(while adding new element)
	or cleanVector function so the above two line logic works perfect.
*/
/*	or
	        struct data **temp = vec->array;
		vec->size = vec->size - 1;
                vec->array = malloc((vec->size) * sizeof(struct data*));
                int i;
                for(i=0;i < (vec->size);i++)
                {
                        vec->array[i] = temp[i];
                }
		free(temp[i]);
		free(temp);
*/
}

void addBack(struct vector *vec,struct data *dta)
{
	vec->size = vec->size + 1;
	struct data **temp = vec->array;
	vec->array = malloc(vec->size * sizeof(struct data*));
	int i=0;
	for(i=0;i < ((vec->size)-1);i++)
	{
		vec->array[i] = temp[i];
	}
	vec->array[(vec->size)-1] = dta;
		/*copy the previous array in new array with size greater
		  by 1 and add new element at the end*/
	free(temp);
}

void removeFront(struct vector *vec)
{
	if(vec->size != 0)		//if size is 0 segfault occurs, hence this condition
	{
	struct data **temp = vec->array;
	vec->size = vec->size - 1;
	vec->array = malloc((vec->size) * sizeof(struct data*));
        int i;
        for(i=0;i < (vec->size);i++)
        {
		vec->array[i] = temp[i+1];
			/*copy old element with index greater by 1
			  hence skipping 1st element*/
        }
	free(temp[0]);
		//free space allocated for dta*
	free(temp);
	}
}

float sumVector(struct vector *vec)
{
	int i=0;
	float sum=0.0;
	for(i=0;i<vec->size;i++)
	{
		sum = sum + sumData(vec->array[i]);
		  //sumData() returns sum of v1 and v2
	}
	return sum;
}

void reverseVector(struct vector *vec)
{
	struct data *temp = NULL;
	int i=0, j=vec->size-1;
	while(i<=j)
	{
		temp = vec->array[i];
		vec->array[i] = vec->array[j];
		vec->array[j] = temp;
		i++;
		j--;
	}
	//swap 1st element with last; 2nd with last 2nd and so on till the center comes

}

struct vector* cloneVector(struct vector *vec)
{
	struct vector *tempVector = createVector();
	tempVector->size = vec->size;
	tempVector->array = malloc(vec->size * sizeof(struct data*));
		/*create an new vector* and allocate space
		  same as size of the vector to be cloned*/

	int i=0;
	for(i=0;i< vec->size; i++)
	{
		tempVector->array[i] = createData(vec->array[i]->v1,vec->array[i]->v2);
			/*copy all the elements from prev. vector to new vector
			using createData() function which creates new data structures
			and passing the arguments as v1 and v2 of data structures of
			prev. array */
	}
	return tempVector;

}

int compareVectors(struct vector *vec1,struct vector *vec2)
{
	if(vec1->size != vec2->size)
	{
		return 0;
	}
		//if size is not equal no need to check further

	int i=0;
	for(i=0;i< vec1->size ;i++)
	{
		if(compareData(vec1->array[i], vec2->array[i]) == 0)
		{
			/*compareData() checks if v1 and v2
			  are equal in data structures and
			  returns 0 if they are not.*/
			return 0;
		}
	}

	return 1;
}

void printVector(struct vector *vec)
{
	int i = 0;
	for(i=0;i < (vec->size);i++)
	{
		printData(vec->array[i]);
	}
	printf("\n");
}

void cleanVector(struct vector *myVector)
{
        int i = 0;
        for(i=0;i < myVector->size; i++)
        {
                free(myVector->array[i]);
			//free space allocated for data structures
        }
        free(myVector->array);
			//free space allocated for array of data structures
        free(myVector);
			//free space allocated for vector structure
}
