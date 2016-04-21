#include <stdio.h>
#include <assert.h>
#include "random.h"
#include "structures.h"
#include "avl.h"
#include "bst.h"
#include "timing.h"
int main(int argc,char* argv[])
{
	randSeed();
	if(argc!=2){
		return -1;
	}
//variable declaration
	int i=0;
	struct avlTree* myAvlT = createAvlTree();
	struct tree* myBst = createTree();
	clock_t start1,end1;
	clock_t start2,end2;
	float diff1=0.0,diff2=0.0;
	struct data *d,*d1;

//Insert
	for(i=0; i<(atoi(argv[1])*1000000); i++)
	{
		d = randomData();
		d1 = createData(d->v1,d->v2);
			/*inserting same data struct in both trees for
			better comparision of performances*/
	//avl insert
		start1 = getTime();
		insertAvl(myAvlT,d);
		end1 = getTime();
		diff1 += timeDiff(start1,end1);
			/*while inserting in avl clock of bst 
			will pause and vice versa */
	//bst insert
		start2 = getTime();
		insertBst(myBst,d1);
		end2 = getTime();
		diff2 += timeDiff(start2,end2);		
	}
	//printf("AVL insertion TIME:");
        printf("%f\n",diff1);
	//printf("BST insertion TIME:");
        printf("%f\n",diff2);

//Search
	diff1=0.0;
	diff2=0.0;
	for(i=0;i<(atoi(argv[1]) * 1000000);i++) 
	{
	//AVL Search
		d = randomData();
		d1 = createData(d->v1,d->v2);	
			/*searching same data struct in both trees for
			better comparision of performances*/

		start1 = getTime();
		searchAvl(myAvlT,d);
		end1 = getTime();
		diff1 += timeDiff(start1,end1);
			/*while searching in avl clock of bst 
			will pause and vice versa */
		free(d);
	//BST Search
        	start2 = getTime();
	        searchBst(myBst,d1);
       		end2 = getTime();
		diff2 += timeDiff(start2,end2);		
		free(d1);

	}	

	//printf("AVL search TIME:");
	printf("%f\n",diff1);
	//printf("BST search TIME:");
        printf("%f\n",diff2);

	cleanBST(myBst);
	cleanAvl(myAvlT);
	return 0;
}
