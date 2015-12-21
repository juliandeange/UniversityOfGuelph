#include "StudentInterface.h"
#include "HeapInterFace.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printHeap(Heap * H, int capacity);

/* Destroys the Item */
void destroyValue (void * S) {

	Student * X = S;

	FreeStudent(X);
	free(X);
}

/* Compares 2 void * pointers and returns integer */
int compareValues (void * A, void * B) {
	
	int x;
	int y;

	Student * X = A;
	Student * Y = B;

	x = X->grade;
	y = Y->grade;

	if (x < y)
		return -1;
	else if (x == y)
		return 0;
	else
		return 1;
}

/* Copys item to another location */
void * copyValue (void * A, void * B) {

	Student * copyLocation = A;
	Student * toBeCopied = B;

	if (copyLocation == NULL)
		copyLocation = malloc(sizeof(Student));

	copyLocation = toBeCopied;
	
	return copyLocation;

}

int main(int argc, char * argv[]) {
	
	FILE * file;

	char name[50];
	int grade;
	char * cap = argv[1];
	int capacity;
	Heap H;
	Student S;

	capacity = atoi(cap);

	Initialize(&H, capacity, &copyValue, &destroyValue, &compareValues);

	file = fopen("test.txt","r");



	while (fscanf(file,"%s %d", name, &grade) == 2) {
			InitializeStudent(name, grade, &S);
			Insert(&H, &S);
		}
		printHeap(&H, capacity);

	return 0;
}

/* Prints the heap */
void printHeap(Heap * H, int capacity) {

	Student * X;
	int i;

	for (i = 1; i < capacity; i++) {
		X = H->heap[i];
		printf("%s ", X->name);
		printf("%d", X->grade);
		printf("\n");
		i++;

	}
}



