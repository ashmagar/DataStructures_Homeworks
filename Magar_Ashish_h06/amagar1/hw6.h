#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
  struct node *next;
  struct data *dta;
};

struct linkedList{
  struct node *head;
};


struct node* createNode(struct data *dta);
struct linkedList* createLinkedList();

void addNPos(struct linkedList *ll,struct data *dta,int n);
void removeNPos(struct linkedList *ll,int n);
void cleanLinkedList(struct linkedList *ll);
char* getLetterCount(struct linkedList *ll);

void printLinkedList(struct linkedList *ll);

#endif
