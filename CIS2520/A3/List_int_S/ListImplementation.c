#include "ListInterface.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
BubblesSort1 algorithm
From Professor
Takes in and sorts the List
*/
void BubbleSort1(List * L) {

	int i = 0;
	int j = 0;

	int temp = 0;
	int temp1 = 0;

	int size = L->size;

	for (j = 1; j < size - 1; j++) {
		for (i = 1; i < size - j; i++) {
			if (L->items[i-1] > L->items[i]) {

				temp = L->items[i-1];
				temp1 = L->items[i];
				L->items[i-1] = temp1;
				L->items[i] = temp;
			}
		}
	}
}

/*
BubblesSort2 algorithm
From Professor
Takes in and sorts the List
*/
void BubbleSort2 (List * L) {

	int k = L->size;
	bool swapped;
	int i;
	int temp;
	int temp1;

	do {
		swapped = false;
		for (i = 1; i < k- 1; i++){
			if (L->items[i-1] > L->items[i]) {
				temp = L->items[i-1];
				temp1 = L->items[i];
				L->items[i-1] = temp1;
				L->items[i] = temp;
				swapped = true;
			}
		}
		k = k - 1;
	} while (swapped != false);

}

/*
BubblesSort1 algorithm
From Professor
Takes in List, first index position, last index position
Sorts List
*/
void MergeSort (List * L, int first, int last) {

	int middle;

	if (first < last) {
		middle = ((first + last) / 2);
		MergeSort(L, first, middle);
		MergeSort(L, middle + 1, last);
		Merge(L, first, middle, last);

	}

}

/*
Merge algorith,
From Professor
Takes List, first index, middle index, last index
*/
void Merge (List * A, int first, int middle, int last) {

	int i;
	int j;
	int k;
	int L[100000];
	int R[100000];

	for (i = 0; i <= middle - first; i++) {
		L[i] = A->items[first + i];
	}
	L[middle - first + 1] = 999999;

	for (j = 0; j <= last - middle - 1; j++) {
		R[j] = A->items[middle + j + 1];
	}
	R[last - middle] = 999999;
	i = j = 0;

	for (k = first; k <= last; k++) {
		if (L[i] <= R[j]) {
			A->items[k] = L[i];
			i = i + 1;
		}
		else {
			A->items[k] = R[j];
			j = j + 1;
		}
	}
}




