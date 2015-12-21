/*********************************************************************
 * FILE NAME: StackImplementation.c
 * PURPOSE: Stack ADT
 * AUTHOR: P. Matsakis (CIS2520, Assignment 2)
 * DATE: 15/10/2015
 *********************************************************************/

#include "StackInterface.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/* Creates and empty stack */
void Initialize (Stack * S) {
	S->size = 0;
	S->first = NULL;

	assert(S->size == 0);
}

/* Adds an item to the stack */
/* Mallocs memory as needed */
void Push (Item X, Stack * S) {

	StackNode * node;
	
	node = (StackNode *)malloc(sizeof(StackNode));
	node->item = X;
			 
	node->next=S->first;
	S->first = node;
	
	S->size++;
}

/* Finds the value at the top of the stack */
extern void Top (Stack *S, Item * X) {

	*X = S->first->item;
}

/* Removes the top value from the stack */
/* Frees memory as required */
extern void Pop (Stack *S) {

	assert(S->size > 0);

	StackNode * node;

	node = S->first;
	S->first = node->next;
	free(node);
	
	S->size--;
}

/* Destroys stack */
extern void Destroy (Stack *S) {
	free(S);
}

/* Returns the number of elements in the stack */
extern int Size (Stack * S) {
	return S->size;
}

/* Evaluates if the stack is empty or not */
extern int Empty (Stack * S) {
	if (S->size == 0)
		return 0;

	else
		return 1;
}


