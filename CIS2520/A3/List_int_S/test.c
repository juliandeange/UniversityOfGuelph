#include "ListImplementation.c"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

int main(){

	/* Declaration of variables */
	FILE * file;
	List myList;
	int i = 0;
	int num = 0;
	float sec;
	clock_t t1, t2;

	int lastIndex;

	file = fopen("test.txt","r");

	/* Reads integers from textfile */
	while (fscanf(file, "%d", &num) > 0) {
		myList.items[i] = num;
		i++;
		myList.size++;
	}

	/* Prints integers from textfile */
	for (i = 0; i < myList.size; i++) {
		printf("%d ", myList.items[i]);
	}

	printf("to sort\n");

	/* Calculates time of first BubbleSort using clock() */
	t1 = clock();
	BubbleSort1(&myList);
	t2 = clock();
	sec = (t2 - t1) / (float)CLOCKS_PER_SEC;

	/* Prints sorted List */
	for (i = 0; i < myList.size; i++) {
		printf("%d ", myList.items[i]);
	}

	printf("BubbleSort1 in %f\n", sec);

	/* Calculates time of second BubbleSort using clock() */
	t1 = clock();
	BubbleSort2(&myList);
	t2 = clock();
	sec = (t2 - t1) / (float)CLOCKS_PER_SEC;

	/* Prints sorted List */
	for (i = 0; i < myList.size; i++) {
		printf("%d ", myList.items[i]);
	}

	printf("BubbleSort2 in %f\n", sec);

	lastIndex = myList.size - 1;

	/* Calculates time of second MergeSort using clock() */
	t1 = clock();
	MergeSort(&myList, 0, lastIndex);
	t2 = clock();
	sec = (t2 - t1) / (float)CLOCKS_PER_SEC;

	/* Prints sorted List */
	for (i = 0; i < myList.size; i++) {
		printf("%d ", myList.items[i]);
	}

	printf("MergeSort in %f\n", sec);

	return 0;


}


