#ifndef AVL_H_
#define AVL_H_

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "data.h"

//create new leaf
struct avlLeaf* createAvlLeaf(struct data *d);
//create new tree
struct avlTree* createAvlTree();

//insert element into binary tree
void insertAvl(struct avlTree *t,struct data *d);
void insertAvl_r(struct avlTree *t,struct avlLeaf* current,struct avlLeaf* newLeaf);

//print in-order
void inOrderAvl(struct avlTree *t);
void inOrderAvl_r(struct avlLeaf *current);

//print pre-order
void preOrderAvl(struct avlTree *t);
void preOrderAvl_r(struct avlLeaf *current);

//rotate right
void rotateRight(struct avlTree *t,struct avlLeaf *current);
//rotate left
void rotateLeft(struct avlTree *t,struct avlLeaf *current);

//calculating factors
int maxHeight(int a,int b);
int getHeight(struct avlLeaf *lf);
int getBalanceFact(struct avlLeaf *lf);

//checking the position of node
int isRoot(struct avlLeaf *lf);
int isLeftChild(struct avlLeaf *lf);
int isRightChild(struct avlLeaf *lf);

//clean memory
void cleanAvl(struct avlTree *t);
void cleanAvl_r(struct avlLeaf *lf);

//search data

int searchAvl(struct avlTree *t,struct data *d);
int searchAvl_r(struct avlLeaf *curr,struct data *d);
#endif
