/*********************************************************************
 * FILE NAME: HeapImplementation.c
 * PURPOSE: Implementation of a generic Binary Heap ADT
 * AUTHOR: P. Matsakis (CIS2520 F13, Assignment 4)
 * DATE: 08/11/2013
 *********************************************************************/


#include "HeapInterface.h"
#include <stdlib.h>
#include <string.h>


int Initialize (Heap *H,
				int capacity,
				void * (*copyValue) (void *, void *),
				void (*destroyValue) (void *),
				int (*compareValues) (void *, void *)) {
	H->heap=malloc(sizeof(void *)*(capacity+1));
	if(H->heap==NULL) return 0;
	H->capacity=capacity;
	H->numberOfValues=0;
	H->copyValue=copyValue;
	H->destroyValue=destroyValue;
	H->compareValues=compareValues;
	return 1;
}


int Insert (Heap *H, void *I) {
	int parent, child;
	void *temp;

	temp=H->copyValue(NULL,I);
	if(temp==NULL) return 0;
	H->numberOfValues++;
	H->heap[H->numberOfValues]=temp;
	
	child=H->numberOfValues;
	parent=child/2;
	while(child!=1 && H->compareValues(H->heap[child],H->heap[parent])>0) {
		temp=H->heap[parent];
		H->heap[parent]=H->heap[child];
		H->heap[child]=temp;
		child=parent;
		parent=child/2;
	}
	return 1;
}


void Remove (Heap *H) {
	int parent, child;
	void *temp;
	
	H->destroyValue(H->heap[1]);
	H->heap[1]=H->heap[H->numberOfValues];
	H->numberOfValues--;
	
	parent=1;
	child=2; 
	if(child<H->numberOfValues && H->compareValues(H->heap[child],H->heap[child+1])<0)
		child++;
	while(child<=H->numberOfValues && H->compareValues(H->heap[child],H->heap[parent])>0) {
		temp=H->heap[parent];
		H->heap[parent]=H->heap[child];
		H->heap[child]=temp;
		parent=child;
		child=parent*2;
		if(child<H->numberOfValues && H->compareValues(H->heap[child],H->heap[child+1])<0)
			child++;		
	}
}


void Top (Heap *H, void *I) {
	H->copyValue(I,H->heap[1]);
}


int Full (Heap *H) {
	return H->numberOfValues==H->capacity;
}


int Empty (Heap *H) {
	return H->numberOfValues==0;
}


void Destroy (Heap *H) {
	int i;
	for(i=1;i<=H->numberOfValues;i++)	
		H->destroyValue(H->heap[i]);
	free(H->heap);
}