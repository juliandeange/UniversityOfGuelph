#include "QueueInterface.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	/* Declaration of variables */
	FILE * file;
	char buffer[100];

	char * op;
	char * name;
	char * gr;
	int i;
	int grade;

	Item student;
	Queue myQ;

	Initialize(&myQ);

	file = fopen("test.txt","r");

	if (file != NULL) {
		while (fgets(buffer, sizeof buffer, file) != NULL){

		/* Prints the status of the queue */
		if (Empty(&myQ))
			printf("Queue is empty; ");
		else
			printf("Queue is not empty; ");

		if (Full(&myQ))
			printf("Queue is full; ");
		else
			printf("Queue is not full; ");

		printf("Queue is of size %d:\n", Size(&myQ));

		for (i = 0; i < myQ.size; i++) {
			printf("%s %d%%\n", myQ.items[i].name , myQ.items[i].grade);
		}

		/* Adds an item to the end of the queue */
		if (buffer[0] == 'E' || buffer[0] == 'e') {

			op = strtok(buffer," ");
			name = strtok(NULL," ");
			gr = strtok(NULL, "\n");
			grade = atoi(gr);

			InitializeStudent(name, grade, &student);

			Enqueue(student, &myQ);
		}

		/* Removes an items from the front of the queue */
		if (buffer[0] == 'D' || buffer[0] == 'd') {
				Dequeue(&myQ);
			}
		}

		/* Prints the status of the queue */
		if (Empty(&myQ))
			printf("Queue is empty; ");
		else
			printf("Queue is not empty; ");

		if (Full(&myQ))
			printf("Queue is full; ");
		else
			printf("Queue is not full; ");

		printf("Queue is of size %d:\n", Size(&myQ));

		for (i = 0; i < myQ.size; i++) {
			printf("%s %d%%\n", myQ.items[i].name , myQ.items[i].grade);
		}
	}
	return EXIT_SUCCESS;
}

