#include "StudentInterface.h"
#include "TreeInterface.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void destroyValue (void * S) {

	Student * X = S;

	FreeStudent(X);
	free(X);
}

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

void * copyValue (void * A, void * B) {

	Student * copyLocation = A;
	Student * toBeCopied = B;

	if (copyLocation == NULL)
		copyLocation = malloc(sizeof(toBeCopied));

	copyLocation = toBeCopied;
	
	return copyLocation;

}

int main() {

	FILE * file;

	char name[50];
	int grade;
	Student S;
	Tree T;

	/* Creates empty tree */
	Initialize(&T, copyValue, destroyValue, compareValues);

	printf("Initialize()");
	printf("Size=0, Height=-1, Balanced=YES\n");
	printf("\n");


	file = fopen("test.txt","r");

	while (fscanf(file,"%s %d", name, &grade) == 2) {
			InitializeStudent(name, grade, &S);

			printf("Insert(%s,%d)\n", name, grade);
			printf("Size=%d, Height=, Balanced=\n",T.size);
			printf("\n");

			/* Insert is commented out due to srg fault from
			the copyValue function
			*/

			/*
			Insert(&T, &S);
			*/

		}

		rewind(file);

		while (fscanf(file,"%s %d", name, &grade) == 2) {
			printf("%s %d\n", name, grade);
		}

	fclose(file);
	return 0;

}


