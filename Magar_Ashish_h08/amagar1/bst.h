#ifndef BST_H_
#define BST_H_

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "data.h"
#include "stack.h"
#include "queue.h"

//create new leaf
struct leaf* createLeaf(struct data *d);
//create new tree
struct tree* createTree();

//insert element into binary tree
void insertBst(struct tree *t,struct data *d);
void insertBst_r(struct leaf* current,struct leaf* newLeaf);

//print in-order
void inOrderBst(struct tree *t);
void inOrderBst_r(struct leaf *current);

//sum of tree
float totalSum(struct tree *t);
float totalSum_r(struct leaf* current);

//maximum v1 in the tree
float bstMaxV1(struct tree* t);
float bstMaxV1_r(struct leaf* current);
float maxV(float a,float b,float c);

//print pre-order
void preOrderBst(struct tree *t);
void preOrderBst_r(struct leaf *lf);

//print post-order
void postOrderBst(struct tree *t);
void postOrderBst_r(struct leaf *lf);

//get data structure with maximum sum, first occurrence in case of multiple max
struct data* getMaxData(struct tree *tr);
struct data* getMaxData_r(struct leaf* lf);
struct data* maxDta(struct data* d,struct data *dl, struct data* dr);

//get data structure with minimum sum, first occurrence in case of multiple min
struct data* getMinData(struct tree *tr);
struct data* getMinData_r(struct leaf* lf);
struct data* minDta(struct data* d,struct data *dl, struct data* dr);

//hight of bst
int getBstHeight(struct tree *tr);
int getBstHeight_r(struct leaf* lf);
int max(int a,int b);

//print elements between begin and end (excluding) - in-order
void printInRange(struct tree *tr, float begin, float end);
void printInRange_r(struct leaf* lf, float begin,float end);

//checks if the tree is complete - all leaves at same level
int isCompleteBst(struct tree *tr);
int isCompleteBst_r(struct leaf* lf);

//checks if the tree is full - each node has exact 2 leaves or null
int isFullBst(struct tree *tr);
int isFullBst_r(struct leaf *lf);

//mirror image of bst
void reverseBST(struct tree *t);
void reverseBST_r(struct leaf *lf);

//sum of all leaves
float sumLeave(struct tree *t);
float sumLeaves(struct leaf *lf);

//breadth first search algorithm using queue
void printBreadthFirstSearch(struct tree *t);
//depth first search algorithm using stack
void printDepthFirstSearch(struct tree *t);

//clean memory
void cleanBST(struct tree *t);
void cleanBST_r(struct leaf *lf);

#endif
