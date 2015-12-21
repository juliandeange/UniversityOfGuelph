#define n 100000

#include "ListImplementation.c"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

/* 
An array if List struct is stored in this array
Each the list the user creates from the number in the...
...command line will be sorted by both BubbleSorts and...
...the MergeSort functions
*/
List lists[n];

int main(int argc, char ** argv){

	int numList;
	int sizeList;

	int i;
	int j;
	int r;
	int first;
	int last;

	clock_t t1, t2;
	float sec = 0;
	float best;
	float worst;
	float average = 0;

	if (argc != 3)
		exit(0);

	/* Reads numbers from the command line */
	numList = atoi(argv[1]);
	sizeList = atoi(argv[2]);
	
	/* Used for generating random numbers */
	srand(time(NULL));

	/* Sets the size of each list that is created */
	for (i = 0; i < numList; i++) {
		lists[i].size = sizeList;
		for (j = 0; j < sizeList; j++) {
			r = rand() % 100;
			lists[i].items[j] = r;
		}
	}

	/*
	BubblesSort(1) each List in the array
	Calculates the best, average, and worst 
	running times for each List sorted
	*/
	for (i = 0; i < numList; i++) {
		t1 = clock();
		BubbleSort1(&lists[i]);
		t2 = clock();
		sec = (t2 - t1) / (float)CLOCKS_PER_SEC;

		average = average + sec;

		if (sec > worst)
			worst = sec;

		if (sec < best)
			best = sec;
	}

	/* Prints results of BubbleSort1 */
	printf("\n");
	printf("BubbleSort1\n");
	printf("Best Running Time: %f\n", best);
	printf("Average Running Time: %f\n", average);
	printf("Worst Running Time: %f\n", worst);
	printf("\n");

	/*
	BubblesSort(2) each List in the array
	Calculates the best, average, and worst 
	running times for each List sorted
	*/
	for (i = 0; i < numList; i++) {
		t1 = clock();
		BubbleSort2(&lists[i]);
		t2 = clock();
		sec = (t2 - t1) / (float)CLOCKS_PER_SEC;

		average = average + sec;

		if (sec > worst)
			worst = sec;

		if (sec < best)
			best = sec;
	}

	/* Prints results of BubbleSort2 */
	printf("BubbleSort2\n");
	printf("Best Running Time: %f\n", best);
	printf("Average Running Time: %f\n", average);
	printf("Worst Running Time: %f\n", worst);
	printf("\n");

	first = 0;
	last = sizeList - 1;

	/*
	MergeSort each List in the array
	Calculates the best, average, and worst 
	running times for each List sorted
	*/
	for (i = 0; i < numList; i++) {
		t1 = clock();
		MergeSort(&lists[i], first, last);
		t2 = clock();
		sec = (t2 - t1) / (float)CLOCKS_PER_SEC;

		average = average + sec;

		if (sec > worst)
			worst = sec;

		if (sec < best)
			best = sec;
	}

	/* Prints results of MergeSort */
	printf("MergeSort\n");
	printf("Best Running Time: %f\n", best);
	printf("Average Running Time: %f\n", average);
	printf("Worst Running Time: %f\n", worst);
	printf("\n");

	return 0;

}



