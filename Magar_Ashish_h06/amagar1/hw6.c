#include "hw6.h"

struct node* createNode(struct data *dta)
{
	struct node* nod = malloc(sizeof(struct node));
	nod->dta = dta;
	nod->next = NULL;
	return nod;
}

struct linkedList* createLinkedList()
{
	struct linkedList *ll = malloc(sizeof(struct linkedList));
	ll->head = NULL;
	return ll;
}

void addNPos(struct linkedList *ll,struct data *dta,int n)
{
	struct node* nod = createNode(dta);

//case1: linkedList is empty
	if(ll->head==NULL || n==0) 
 	{
		 //if head is not null but n is 0
//		{
			nod->next=ll->head;
	//if head is already null then nod->next will be null, this will look like  null=null
//		}
		ll->head = nod;
		return;
	}

//case2: else	
	struct node* temp = ll->head;
	int index = 0;
	while(temp->next!=NULL)
	{
		index++;			//index to go to required position in linkedList
		if(index==n) break;
		temp = temp->next;
	}
	if(temp->next!=NULL)	//assert temp->next is not null
							//condition required if there is only element
	{
		nod->next = temp->next;
	}
	temp->next = nod;

}

void removeNPos(struct linkedList *ll,int n)
{
	struct node* delTemp=NULL;

//case 1: List is empty
	if(ll->head==NULL) return;

//case 2:List contains only 1 element
	if(ll->head->next==NULL || n==0)
	{
		delTemp=ll->head;
		if(n==0)
		{
			ll->head=ll->head->next;		
		}
		free(delTemp->dta->letters);
		free(delTemp->dta);
		free(delTemp);	
		return;
	}

//case 2: else
	struct node* temp = ll->head;
	int index=0;
	while(temp->next->next!=NULL)
	{
		index++;			//index is running ahead of temp, it has to
		if(index==n)
		{	
		 	delTemp = temp->next;		//delTemp - node to be deleted
			temp->next = temp->next->next;	//link from previous of node to be deleted to its next
		}
		temp = temp->next;
	}
	if(index!=n)		//if n is greater than size, and complete ll is traversed
	{
		delTemp = temp->next;
		temp->next=NULL;	
	}

	free(delTemp->dta->letters);
	free(delTemp->dta);
	free(delTemp);
}

char* getLetterCount(struct linkedList *ll)
{
		/*
			Logic Description:
			Basically I have taken 2 arrays, one is requiredCount[] and other is currentCount[]
			Both are of size 26, and the logic is 
				-traverse the linked list
				-traverse the string in it, letter by letter	
				-increment count of letters in requiredCount[] arrays	
					*the index is calculated using ASCII value of a letter and subtracting 97 from it
					i.e. 0th index for count of letter a, 1st for b, so on 25th for z
				-for first node, i.e. ll->head I have obtained requiredCount[] array
				-Now I am traversing next nodes and incrementing count of respective letter in
				 currentCount[] array (index calculated same as explained above
				-Then I compare both arrays, if count of letters in both array is not same,
				 I set the count of that respective letter to 0 in requiredCount[] array
				 because we don't need this
				-Going in this fashion I traverse all nodes and make the count in requiredCount[] array
				 0 if the letters count is not same
				-At last I have taken a string (malloc space to length of string in head(+1 for '\0'), we won't need
				 space more than that)
				-And I concatenate the letters number of times equal to the respective value of count in 
				 requiredCount[] array
				 
		Just to achieve linear time complexity I used these arrays of size 26
		*/
	int requiredCount[26];
	int currentCount[26];
	int i=0;
	for(i=0;i<26;i++) 
	{
		requiredCount[i] = currentCount[i] = 0;
	}

	struct node *nodeTemp = ll->head;
	while(nodeTemp!=NULL)
	{
		for(i=0;i<strlen(nodeTemp->dta->letters);i++)
		{
			if (nodeTemp==ll->head)
			{
				requiredCount[(int)nodeTemp->dta->letters[i]-97]++;
			}
			else
			{	
				currentCount[(int)nodeTemp->dta->letters[i]-97]++;
			}
		}
		for(i=0;i<26;i++)	//this for loop has constant complexity as 26, so no worries
		{
			if(requiredCount[i]!=currentCount[i] && nodeTemp!=ll->head)
			{
				requiredCount[i]=0;
			}
			currentCount[i]=0;	//reset for next use
		}

		nodeTemp=nodeTemp->next;
	}

	char *reqString = malloc(strlen(ll->head->dta->letters)+1);
	int j=0, ch=0;
	for(i=0;i<26;i++)
	{
		j=0;
		while(j<requiredCount[i])
		{
			reqString[ch++] = (char)(i+97);
			j++;
		}
	}
	reqString[ch]='\0';
	return reqString;
}

void printLinkedList(struct linkedList *ll)
{
	struct node *nodeTemp = ll->head;
	while(nodeTemp != NULL)
	{
		printData(nodeTemp->dta);
		nodeTemp = nodeTemp->next;
	}
	printf("\n");
}

void cleanLinkedList(struct linkedList* ll)
{
        struct node *temp = ll->head;
        while(ll->head != NULL)
        {
                temp = ll->head;
                ll->head = ll->head->next;
                free(temp->dta->letters);
                free(temp->dta);
                free(temp);
        }
        free(ll);
}

