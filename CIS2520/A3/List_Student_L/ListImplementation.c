#include "ListInterface.h"
#include <stdlib.h>

/*Initializes a student passing the grade and name*/
static void copyItem (Item *Y, Item X) {
	InitializeStudent(NameOfStudent(X),GradeOfStudent(X),Y);
}

/* Destroys student object */
static void destroyItem (Item *X) {
	FreeStudent(X);
}


static ListNode *moveTo (int position, List *L) {
	int i;
	ListNode *p=L->first;
	for(i=0;i<position;i++) p=p->next;
	return p;
}

/* Creates an empty list */
void Initialize (List *L) {
	L->size=0;
	L->first=NULL;
}

/* Takes and Item, position, and List and adds to the
designated position in the list (position)
 */
void Insert (Item X, int position, List *L) {
	ListNode *p, *q;
	
	L->size++;
	q=(ListNode *)malloc(sizeof(ListNode));
	copyItem(&q->item,X);
			 
	if(position==0) {
		q->next=L->first;
		L->first=q;
	}
	else {
		p=moveTo(position-1,L);
		q->next=p->next;
		p->next=q;
	}
}

/* Removes item from list in designated position */
void Remove (int position, List *L) {
	ListNode *p, *q;
	
	if(position==0) {
		q=L->first;
		L->first=q->next;
	}
	else {
		p=moveTo(position-1,L);
		q=p->next;
		p->next=q->next;
	}
	
	destroyItem(&q->item);
	free(q);
	L->size--;
}

/* Checks for full list */
int Full (List *L) {
	return 0;
}

/* Check for empty list */
int Empty (List *L) {
	return L->size==0;
}

/* Returns the size of the list */
int Size (List *L) {
	return L->size;
}

/* Looks at an item in a list at the designated position */
void Peek (int position, List *L, Item *X) {
	ListNode *p;
	p=moveTo(position,L);
	copyItem(X,p->item);
}

/* Destroys a List
Frees all memory */
void Destroy (List *L) {
	int i;
	ListNode *p, *q;
	
	p=L->first;
	for(i=0;i<L->size;i++) {
		q=p;
		p=p->next;
		destroyItem(&q->item);
		free(q);
	}
}

/* Reverses the list
Rearranges pointers to the at the 
previous node
 */
void Reverse (List *L) {

	ListNode * prevNode = NULL;
	ListNode * curNode;
	ListNode * next;

	curNode = L->first;

	/*
	Changes the pointers to point at the
	previous node in the List
	*/
	while (curNode != NULL) {

		next = curNode->next;
		curNode->next = prevNode;
		prevNode = curNode;
		curNode = next;
	}

	/* Reassigns new head */
	L->first = prevNode;
	
}





