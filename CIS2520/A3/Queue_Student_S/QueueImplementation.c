#include "QueueInterface.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* Creates empty Queue */
extern void Initialize (Queue *Q){

	Q->size = 0;

}

/* Adds and item the "end" of tye queue */
extern void Enqueue (Item I, Queue *Q){

	int pos;
	pos = Q->size;

	if (Q->size == 5) {
		printf("Queue is full\n");
		exit(0);
	}

	Q->items[pos] = I;
	Q->size++;

}

/* 
Removes an item from the "front" of the queue
Moves items over to accomodate a gap
*/
extern void Dequeue (Queue *Q){

	int i;

	if (Q->size == 0) {
		printf("Queue is empty\n");
		exit(0);
	}

	for (i = 0; i < Q->size - 1; i++) {
		Q->items[i] = Q->items[i + 1];
	}

	Q->size--;

}

/* Check for full queue */
extern int Full (Queue *Q){
	return Q->size == MAXQUEUESIZE;
}

/* Checks for empty queue */
extern int Empty (Queue *Q){
	return Q->size == 0;
}

/* Returns the size of the queue */
extern int Size (Queue *Q){
	return Q->size;
}

extern void Head (Queue *Q, Item *I){

}

extern void Tail (Queue *Q, Item *I){

} 

/* Destroys queue and free memory */
extern void Destroy (Queue *Q){
	free(Q);
}



