#include "bst.h"
#include<float.h>

//create new leaf
struct leaf* createLeaf(struct data *d)
{
  struct leaf* maple = malloc(sizeof(struct leaf));
  maple->right = NULL;
  maple->left = NULL;
  maple->dta = d;
  return maple;
}

/* **************************************************************************** */
//create new tree
struct tree* createTree()
{
  struct tree* oak = malloc(sizeof(struct tree));
  oak->root = NULL;
  return oak;
}

/* **************************************************************************** */
//insert element into binary tree
void insertBst(struct tree *t,struct data *d)
{
  	struct leaf *l = createLeaf(d);
  	if(t->root == NULL)
	{
		 t->root = l;	
		 return;
	}

	insertBst_r(t->root,l);
}

void insertBst_r(struct leaf* current,struct leaf* newLeaf)
{
	if(sumData(newLeaf->dta) <= sumData(current->dta))	//insert to the left 
	{
		if(current->left==NULL)
		{
			current->left = newLeaf;
		}
		else
		{
			insertBst_r(current->left,newLeaf);
		}
	}
	else if(sumData(newLeaf->dta) > sumData(current->dta))	//insert to the right
	{
		if(current->right==NULL)
		{
			current->right = newLeaf;
		}
		else
		{
			insertBst_r(current->right,newLeaf);
		}
	}
}

/* **************************************************************************** */
//print in-order
void inOrderBst(struct tree *t)
{
	inOrderBst_r(t->root);
}

void inOrderBst_r(struct leaf *current)		
	/* recurse left, print, recurse right */
{
	if (current->left != NULL)
	{
		inOrderBst_r(current->left);
	}
	printData(current->dta);
	if(current->right != NULL)
	{
		inOrderBst_r(current->right);
	}
}

/* **************************************************************************** */
//sum of tree
float totalSum(struct tree *t)
{
	return totalSum_r(t->root);
}

float totalSum_r(struct leaf* current)
{
	if(current==NULL)
	{
		return 0;
	}
	return ( totalSum_r(current->left) + totalSum_r(current->right) + sumData(current->dta) );
	//total sum of left sub-tree + total sum right sub-tree + sum of current leaf
}

/* **************************************************************************** */
//maximum v1 in the tree
float bstMaxV1(struct tree *t)
{
	return (bstMaxV1_r(t->root));
}

float bstMaxV1_r(struct leaf *current)
{
	if(current==NULL)
	{
		return -(FLT_MAX);		//smallest value of float
	}

	return maxV( (current->dta->v1) , bstMaxV1_r(current->left) , bstMaxV1_r(current->right) );

}

float maxV(float a, float b, float c)
{

	if(a>b && a>c)
	{
		return a;
	}

	return b > c ? b : c;

}

/* **************************************************************************** */
//print pre-order
void preOrderBst(struct tree *t)
{
	preOrderBst_r(t->root);
}

void preOrderBst_r(struct leaf *lf)
{
	//print, recurse left, recurse right
	if(lf==NULL)
	{
		return;
	}
	printData(lf->dta);
	preOrderBst_r(lf->left);
	preOrderBst_r(lf->right);
}

/* **************************************************************************** */
//print post-order
void postOrderBst(struct tree *t)
{
	postOrderBst_r(t->root);
}

void postOrderBst_r(struct leaf *lf)
{
	//recurse left, recurse right, print
	if(lf==NULL)
	{
		return;
	}
	postOrderBst_r(lf->left);
	postOrderBst_r(lf->right);
	printData(lf->dta);
}

/* **************************************************************************** */

/*finds the data structure with the largest value in the bst,
 first occurrence if multiple max */

	/*we add an element if its equal to current node then to the left of
	that node(leaf), that's why traversing till the rightmost element gives
	us data structure with the maximum value (FIRST OCCURRENCE )*/
	
struct data* getMaxData(struct tree *tr)
{
	return(getMaxData_r(tr->root));
}
struct data* getMaxData_r(struct leaf* lf)
{
	if(lf->right == NULL)
	{
		return lf->dta;
	}
	return getMaxData_r(lf->right);
}

/* **************************************************************************** */

/* this wont work for 'first occurance' of minData
struct data* getMinData(struct tree *tr)
{
	return(getMinData_r(tr->root));
}

struct data* getMinData_r(struct leaf* lf)
{
	if(lf->left == NULL)
	{
		return lf->dta;
	}
	return getMinData_r(lf->left);
}
*/

/* **************************************************************************** */

/*		//no need of this as rightmost element gives max
struct data* getMaxData(struct tree *tr)
{
	return(getMaxData_r(tr->root));
}
struct data* getMaxData_r(struct leaf* lf)
{
	if(lf==NULL)
	{
		return NULL;
	}

	return maxDta(lf->dta, getMaxData_r(lf->left), getMaxData_r(lf->right) );
}

struct data* maxDta(struct data* d,struct data* dl,struct data* dr)
{
	float sum, suml, sumr;
	sum = sumData(d);
	if(dl==NULL)	{	suml = 0;		}
	else		{	suml = sumData(dl);	}
	if(dr==NULL)	{	sumr = 0;		}
	else		{	sumr = sumData(dr);	}

	if( (sum >= suml) && (sum >= sumr) )
	{
		return d;
	}

	return suml > sumr ? dl : dr;
}
*/

/* **************************************************************************** */

//finds the data structure with the smallest value in the bst

	/* its the different case than getMaxData, if we want first occurrence of min data
	then simply traversing till the leftmost element won't work. e.g. if elements are
	1.0 2.0, 2.0 1.0, 0.0 3.0 then the leftmost element will be 0.0 3.0 but 'FIRST
	OCCURRENCE' of min data structure is 1.0 2.0 i.e root, hence following logic
	*/
struct data* getMinData(struct tree *tr)
{
	return(getMinData_r(tr->root));
}
struct data* getMinData_r(struct leaf* lf)
{
	if(lf==NULL)
	{
		return NULL;
	}

	return minDta(lf->dta, getMinData_r(lf->left), getMinData_r(lf->right) );
}

struct data* minDta(struct data* d,struct data* dl,struct data* dr)
{
	float sum, suml, sumr;
	sum = sumData(d);
	if(dl==NULL)	{suml = FLT_MAX;	}	//largest float
	else		{suml = sumData(dl);	}
	if(dr==NULL)	{sumr = FLT_MAX;	}	//largest float
	else		{sumr = sumData(dr);	}

	if( (sum <= suml) && (sum <= sumr) )
	{
		return d;
	}
		//if sum of current is greater then return data structure of current
	return suml < sumr ? dl : dr;
		/*else if sum of left is greater then return data structure of left
		  otherwise data structure of right */
}

/* **************************************************************************** */
//height of bst
int getBstHeight(struct tree *tr)
{
	return getBstHeight_r(tr->root);
}
int getBstHeight_r(struct leaf* lf)
{
	if(lf==NULL)
	{
		return 0;
	}

	return ( 1 + max(getBstHeight_r(lf->left), getBstHeight_r(lf->right)) );
	//1 + larger value of height of left sub-tree and right sub-tree (recursively)
}

int max(int a,int b)
{
	return a>b?a:b;
}

/* **************************************************************************** */
//print elements between begin and end (excluding) - in-order
void printInRange(struct tree *tr, float begin, float end)
{
	printInRange_r(tr->root,begin,end);
}
void printInRange_r(struct leaf* lf, float begin,float end)
{
	if(lf==NULL)
	{
		return;
	}
	printInRange_r(lf->left,begin,end);
	if(sumData(lf->dta) > begin && sumData(lf->dta) < end )
	{
		printData(lf->dta);
	}
		printInRange_r(lf->right,begin,end);
}

/* **************************************************************************** */
//checks if the tree is complete - all leaves at same level
int isCompleteBst(struct tree *tr)
{
	return isCompleteBst_r(tr->root);
}
int isCompleteBst_r(struct leaf* lf)
{
	if(lf->left!=NULL && lf->right!=NULL)
	{	
		/* this condition handles trees like linked list
		i.e. all elements greater than root or or less than 
		root so if both left and right child not null :- */
	
		if(getBstHeight_r(lf->left) != getBstHeight_r(lf->right))
		{	
			/* if height of left sub-tree is not equal
			to height of right sub-tree then return 0 */
			return 0;
		}
			/* else if it's equal then check of 
			left and right sub-trees recursively */
		return isCompleteBst_r(lf->left)*isCompleteBst_r(lf->right);
			
		/* used multiplication so that in any condition it returns 0
		then all parent functions of that recursive call will return 0 
		hence getting the required answer */
	}
	return 1;
}

/* **************************************************************************** */
//checks if the tree is full - each node has exact 2 leaves or null
int isFullBst(struct tree *tr)
{
	return isFullBst_r(tr->root);
}
int isFullBst_r(struct leaf *lf)
{
	if(lf->left!=NULL && lf->right!=NULL)	//both left and right not null
	{
		return (isFullBst_r(lf->left) * isFullBst_r(lf->right));
		/* multiplication - because if any recursive 
		call returns 0 then the function should return 0 */
	}
	if(lf->left==NULL && lf->right==NULL)	//or both are null
	{
		return 1;
	}
	return 0;				//else return 0
}

/* **************************************************************************** */
//sum of all leaves
float sumLeave(struct tree *t)
{
	return sumLeaves(t->root);
}
float sumLeaves(struct leaf *lf)
{
	if(lf==NULL)
 	{
		return 0;
	}
	if(lf->left==NULL && lf->right==NULL)		//if (leaf)
	{
		return sumData(lf->dta);
	}
	return sumLeaves(lf->left)+sumLeaves(lf->right);	//recursion
}

/* **************************************************************************** */
//mirror image of bst
void reverseBST(struct tree *t)
{
	reverseBST_r(t->root);
}
void reverseBST_r(struct leaf *lf)
{
	struct leaf * temp;
	if(lf==NULL)
	{
		return;
	}
	//recursion
	reverseBST_r(lf->left);
	reverseBST_r(lf->right);
	//swap left and right children using temp
	temp = lf->left;
	lf->left = lf->right;
	lf->right = temp;

}

/* **************************************************************************** */
//depth first search algorithm using stack
void printDepthFirstSearch(struct tree *t)
{
	struct stack *s = createStack();
	pushStack(s,t->root);		//push root onto the stack
	struct leaf* current = t->root;
	while(!isEmptyStack(s))		//repeat following till stack is not empty
	{
		/* print current, pop it out, push its left and right children onto stack*/
		current = topStack(s);
		printData(current->dta);
		popStack(s);
		if(current->right != NULL)
		{
			pushStack(s,current->right);
		}
		if(current->left != NULL)
		{
			pushStack(s,current->left);
		}
	}
	cleanStack(s);

}

/* **************************************************************************** */
//breadth first search algorithm using queue
void printBreadthFirstSearch(struct tree *t)
{
	struct queue *q = createQueue();
	pushQueue(q,t->root);		//push root onto the queue
	struct leaf* current = t->root;
	while(!isEmptyQueue(q))		//repeat following till queue is not empty
	{
		/* print current, pop it out, push its left and right children onto queue*/
		current = topQueue(q);
		printData(current->dta);
		popQueue(q);
		if(current->left != NULL)
		{
			pushQueue(q,current->left);
		}
		if(current->right != NULL)
		{
			pushQueue(q,current->right);
		}
	}
	cleanQueue(q);
}

/* **************************************************************************** */
//clean memory
void cleanBST(struct tree *t)
{
	cleanBST_r(t->root);
	free(t);
}
void cleanBST_r(struct leaf *lf)
{
	if(lf==NULL)
	{
		return;
	}
	cleanBST_r(lf->left);
	cleanBST_r(lf->right);
	free(lf->dta);
	free(lf);

}
/* ********************************************************************* */
int searchBst(struct tree *t,struct data *d)
{
        if(t->root==NULL){
                return 0;
        }
        return searchBst_r(t->root,d);

}
int searchBst_r(struct leaf *curr,struct data *d)
{
        if(curr==NULL){
                return 0;
        }
        else if(compareData(curr->dta,d)==1){
                return 1;
        }
        else{
		if(sumData(d) <= sumData(curr->dta)){
                        return searchBst_r(curr->left,d);
                }
                else if(sumData(d) > sumData(curr->dta)){
                        return searchBst_r(curr->right,d);
                }
        }
        return 0;
}
