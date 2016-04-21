#include "avl.h"
#include<assert.h>

//create new leaf
struct avlLeaf* createAvlLeaf(struct data *d)
{
  struct avlLeaf* maple = malloc(sizeof(struct avlLeaf));
  maple->right = NULL;
  maple->left = NULL;
  maple->parent = NULL;
  maple->dta = d;
  maple->height = 1;
  return maple;
}

/* ****************************************************************** */
//create new tree
struct avlTree* createAvlTree()
{
  struct avlTree* oak = malloc(sizeof(struct avlTree));
  oak->root = NULL;
  return oak;
}

/* ****************************************************************** */
//Height of tree
int getHeight(struct avlLeaf *lf)
{
	return (lf==NULL ? 0 : lf->height);
}
//maximum height from two sub-trees
int maxHeight(int a,int b)
{
	return (a > b ? a : b);
}
//calculate balance factor
int getBalanceFact(struct avlLeaf *lf)
{
	return ( getHeight(lf->right) - getHeight(lf->left) );
}

/* ****************************************************************** */
//the position of leaf with respect to it's parent
int isRoot(struct avlLeaf *lf)
{
	return lf->parent == NULL ? 1 : 0;
}

int isLeftChild(struct avlLeaf *lf)
{
	return !isRoot(lf) && (lf->parent->left == lf) ;
}

int isRightChild(struct avlLeaf *lf)
{
	return !isRoot(lf) && (lf->parent->right == lf);
}

/* ****************************************************************** */
//right rotation
void rotateRight(struct avlTree *t,struct avlLeaf *current)
{
	current = current -> left;
	struct avlLeaf *x = current->parent;

	x->left = current->right;
        if(current->right!=NULL){
		current->right->parent = x;
	}
	current->right = x;
	current->parent = x -> parent;

	if(isRoot(x)){
		t->root = current;
	}else if(isLeftChild(x)){
		current->parent->left = current;
	}else{
		assert(isRightChild(x));
		current->parent->right = current;
	}

	x->parent = current;
	x->height = maxHeight(getHeight(x->right),getHeight(x->left)) + 1;
        current->height = maxHeight(getHeight(current->left),getHeight(current->right))+1;
}

/* ****************************************************************** */
//left rotation
void rotateLeft(struct avlTree *t,struct avlLeaf *current)
{
        current = current -> right;
        struct avlLeaf *x = current->parent;

        x->right = current->left;
        if(current->left!=NULL){
		current->left->parent = x;
	}

	current->left = x;
        current->parent = x -> parent;
        if(isRoot(x)){
                t->root = current;
        }else if(isRightChild(x)){
                current->parent->right = current;
        }else{
                assert(isLeftChild(x));
                current->parent->left = current;
        }

        x->parent = current;
        x->height = maxHeight(getHeight(x->left),getHeight(x->right))+1;
        current->height = maxHeight(getHeight(current->left),getHeight(current->right))+1;
}

/* ****************************************************************** */
//insertion
void insertAvl(struct avlTree *t,struct data *d)
{
	struct avlLeaf* newLeaf = createAvlLeaf(d);
	if(t->root == NULL){
		t->root = newLeaf;
	}else{
		insertAvl_r(t,t->root,newLeaf);
	}
}

void insertAvl_r(struct avlTree *t,struct avlLeaf* current,struct avlLeaf* newLeaf)
{
	if(sumData(newLeaf->dta) <= sumData(current->dta)){
		if(current->left==NULL){
			current->left = newLeaf;
			newLeaf->parent = current;
		}else{
			insertAvl_r(t,current->left,newLeaf);
		}
	}else if(sumData(newLeaf->dta) > sumData(current->dta)){
		if(current->right==NULL){
			current->right = newLeaf;
			newLeaf->parent = current;
		}else{
			insertAvl_r(t,current->right,newLeaf);
		}
	}

	current->height = maxHeight(getHeight(current->right),getHeight(current->left)) + 1;
	int bf = getBalanceFact(current);
	if(bf == 2){
		//single rotate
		if(getBalanceFact(current->right) == 1){
			rotateLeft(t,current);
		}
		//special case double rotate (e.g. 5 8 6)
		else if(getBalanceFact(current->right) == -1){
			rotateRight(t,current->right);
			rotateLeft(t,current);
		}
	}

	if(bf == -2){
		//single rotate
		 if(getBalanceFact(current->left) == -1){
                        rotateRight(t,current);
                }
                //special case double rotate (e.g. 5 3 4)
                else if(getBalanceFact(current->left) == 1)
                {
                        rotateLeft(t,current->left);
                        rotateRight(t,current);
                }
	}
}

/* ****************************************************************** */
//print inorder
void inOrderAvl(struct avlTree *t)
{
	if(t->root != NULL)
	{
		inOrderAvl_r(t->root);
	}
}
void inOrderAvl_r(struct avlLeaf *current)
{
	if(current == NULL)
	{
		return;
	}

	inOrderAvl_r(current->left);
	printData(current->dta);
	inOrderAvl_r(current->right);
}

/* ****************************************************************** */
//print preorder
void preOrderAvl(struct avlTree *t)
{
	if(t->root != NULL)
	{
		preOrderAvl_r(t->root);
	}
}
void preOrderAvl_r(struct avlLeaf *current)
{
	if(current == NULL)
	{
		return;
	}

	printData(current->dta);
	inOrderAvl_r(current->left);
	inOrderAvl_r(current->right);
}

/* ****************************************************************** */
//search in the avl
int searchAvl(struct avlTree *t,struct data *d)
{
	if(t->root==NULL){
		return 0;
	}
	return searchAvl_r(t->root,d);

}
int searchAvl_r(struct avlLeaf *curr,struct data *d)
{
	if(curr==NULL){
		return 0;
	}
	else if(compareData(curr->dta,d)==1){
		return 1;
	}
	else{
		if(sumData(d) <= sumData(curr->dta)){
			return searchAvl_r(curr->left,d);
		}
		else if(sumData(d) > sumData(curr->dta)){
			return searchAvl_r(curr->right,d);
		}
	}
	return 0;
}

/* ****************************************************************** */

//clean memory
void cleanAvl(struct avlTree *t)
{
        cleanAvl_r(t->root);
        free(t);
}
void cleanAvl_r(struct avlLeaf *lf)
{
        if(lf==NULL){
                return;
        }
        cleanAvl_r(lf->left);
        cleanAvl_r(lf->right);
        free(lf->dta);
        free(lf);
}
