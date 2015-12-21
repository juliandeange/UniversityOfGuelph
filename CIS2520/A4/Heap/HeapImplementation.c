#include "HeapInterface.h"
#include "StudentInterface.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Functionsadjusts the heap to retain 
status of a heap
 */
void upHeapify (Heap * H, int position) {
	int parentPos;

	Student * parent;
	Student * child;

	Student * temp;

	parentPos = position / 2;
	parent = H->heap[position / 2];
	child = H->heap[position];

	if (parent == 0 || child >= parent) 
		return;
	else {
		/* Swaps items */
		temp = parent;
		parent = child;
		child = temp;
		upHeapify(H, parentPos);
	}
}

/* Creates a Binary Heap with nothing inside */
extern int Initialize (Heap *H, int capacity,
					   void * (*copyValue) (void *, void *),
					   void (*destroyValue) (void *),
					   int (*compareValues) (void *, void *)) {

	H->heap = malloc(sizeof(int)*capacity);
	
	if (H == NULL)
		return 0;

	H->capacity = capacity;
	H->copyValue = copyValue;
	H->destroyValue = destroyValue;
	H->compareValues = compareValues;
	H->numberOfValues = 0;

	return 1;

}

/* Adds an items to the Heap and upHeapify's */
extern int Insert (Heap *H, void *I) {

	int position;
	position = H->numberOfValues + 1;
	H->heap[position] = H->copyValue(NULL, I);
	upHeapify(H, position);
	H->numberOfValues++;
	return H->numberOfValues;

}

/* Removes first item from the Heap */
extern void Remove (Heap *H) {

	Heap * temp;
	temp = H;

	H->heap[1] = NULL;

	temp = H->heap[1];

}

/* Find the items at the top of the Heap */
extern void Top (Heap *H, void *I) {

	Heap * top;
	top = H->heap[1];

}

/* Calculates if the Heap is full
Returns the capacity
 */
extern int Full (Heap *H) {
	return H->capacity;
}

/* Checks for empty Heap */
extern int Empty (Heap *H) {
	return 0;
}

/* Destroys the Heap */
extern void Destroy (Heap *H) {
	free(H);
}


