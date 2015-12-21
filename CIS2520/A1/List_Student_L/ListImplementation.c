#include "ListInterface.h"
#include <stdio.h>
#include <stdlib.h>

/* Creates an empty list */
void Initialize (List *L) {

	L->size = 0;
	L->first = NULL;

}

/*
Function take an item and adds struct to the 
list at the designated position
*/
void Insert (Item X, int position, List *L) {
	ListNode * node;
	ListNode * temp;
	temp = NULL;
	int i;

	/* Creates memory for the node to be inserted */
	node = malloc(sizeof(ListNode));
	node->item = X;
	node->next = NULL;
	temp = L->first;

	/* Preconditions */
	if (position < 0 || position > L->size) {
		exit(1);
	}

	/* If the list is empty the new node becomes the head of the list */
	if (position == 0) {
		node->next = L->first;
		L->first = node;
		L->size++;
	}

	/* Loops through the list to the position before insert location.
	Rearranges pointers to properly insert new node
    */
	else if (position == L->size) {
		for (i = 0; i < position-1; i++) {
			temp = temp->next;
		}	
		temp->next = node;
		L->size++;
	}

	else {
		/* Advances to the position before a new item
		is added to the list */	
		for (i = 0; i < position; i++) {
			temp = temp->next;
		}
			node->next = temp->next;
			temp->next = node;
			L->size++;
	}
}

/*
Function removes a node form the list and rearranges pointers
*/
void Remove (int position, List *L) {

	ListNode * newList;
	ListNode * toRemove;
	ListNode * temp;
	int i;

	newList = L->first;;
	temp = L->first;

	/* Preconditions */
	if (position < 0 || position > L->size) {
		exit(1);
	}

	/* Preconditions */
	if (L->size == 0) {
		exit(1);
	}

	if (position == 0) {
		L->first = newList->next;
		free(newList);
	}

	else {

		for (i = 0; i < position; i++) {
			temp = temp->next;
		}

		if (temp->next == NULL) {
			exit(0);
		}

		if (position == 1 && L->size == 1) {
			L->first = NULL;
		}

		/* Deletes specified node, points previous node to following node
		Frees data for the removed node
		 */
		else{
			toRemove = temp->next;
			temp->next = toRemove->next;
			free(toRemove);
		}
	}

	/* Decreases size of list by 1 */
	L->size--;
}

int Full (List *L) {
	return 0; /* change this */
}

/* Checks to see if list is empty or not */
int Empty (List *L) {

	if (L->size == 0)
		return 0;

	else
		return 1;
}

/* Evaluates size of linked list */
int Size (List *L) {

	return L->size; /* change this */
}

void Peek (int position, List *L, Item *X) {


 if (position < 0 || position > L->size) {
 	exit(1);
 }



/*
	ListNode * temp;
	int i;
	temp = L->first;

	for (i = 0; i < position; i++) {
		temp = temp->next;
	}

	X->name = temp->item.name;
	X->grade = temp->item.grade;


	int i;
	int j;
	i = L->size;
	j = 0;

	while (j != i) {
		printf("%s\n", X->name);
		printf("%d\n", X->grade);

		j = j + 1;
	}

---------------------------------------------

	ListNode * node;
	node = L->first;

	while (node != NULL) {
		printf("%s %d\n", node->item.name , node->item.grade);
		node = node->next;
	}
*/

}

/* Frees list data */
void Destroy (List *L) {
	
	free(L);

}



