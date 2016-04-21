#include <stdio.h>
#include <assert.h>
#include "structures.h"
#include "bst.h"

int main(int argc,char* argv[])
{
	if(argc==1 || argc%2==0)
	{
		return -1;
	}
	int i=0;
	struct data* myDta = NULL;
	struct tree* myT = createTree();
	for(i=1;i<argc;i+=2)
	{
		assert(i+1<argc);
		myDta = createData(atof(argv[i]),atof(argv[i+1]));
		insertBst(myT,myDta);
	}
	printf("\ninOrderBst()\n");
	inOrderBst(myT);
	printf("\npreOrderBst()\n");
	preOrderBst(myT);
	printf("\npostOrderBst()\n");
	postOrderBst(myT);

	printf("\ntotalSum()\n");
	printf("%f\n",totalSum(myT));

	printf("\ngetMaxData()\n");
	printData(getMaxData(myT));

	printf("\ngetMinData()\n");
	printData(getMinData(myT));

	printf("\ngetBstHeight()\n");
	printf("%d\n",getBstHeight(myT));

	printf("\nprintInRange() (range 6.0-14.0)\n");
	printInRange(myT,6.0,14.0);

	printf("\nisCompleteBst()\n");
	printf("%d\n",isCompleteBst(myT));

	printf("\nisFullBst()\n");
	printf("%d\n",isFullBst(myT));

	printf("\nsumLeave()\n");
	printf("%f\n",sumLeave(myT));

	printf("\nprintDepthFirstSearch()\n");
	printDepthFirstSearch(myT);

	printf("\nprintBreadthFirstSearch()\n");
	printBreadthFirstSearch(myT);

	printf("\nreverseBST()\n");
	reverseBST(myT);
	printf("\ninOrderBst()\n");
	inOrderBst(myT);

	cleanBST(myT);

	return 0;
}
