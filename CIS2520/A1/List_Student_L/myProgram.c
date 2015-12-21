#include "ListInterface.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* some code here (e.g., #include directives, static functions) */

int main (void) {
	/* some code here */

    FILE * file;
    List myList;
    Item student;

    char buffer[100];
    char * action;
    char * tokPos;
    char * tokName;
    char * tokGrade;
                                /* Declaration of variables */
    char * rem;
    char * remSpot;
    int toRemove;

    int pos = 0;
    int grade; 

    /* Opens text file in root directory */
  	file = fopen("test.txt","r");


  	Initialize(&myList);

    if (Empty(&myList) == 0) {
        printf("List is Empty; List is of size 0\n");
    }

    if (file != NULL) {
        /* Read each line in the text file */
        while (fgets (buffer, sizeof buffer, file) != NULL) {
            
            if (buffer[0] == 'I' || buffer[0] == 'i') {

                /* Parses each line of input on the 'space' */
                action = strtok(buffer," ");
                tokPos = strtok(NULL," ");
                tokName = strtok(NULL," ");
                tokGrade = strtok(NULL,"\n");

                pos = atoi(tokPos);
                grade = atoi(tokGrade);

                /* Creates a student struct */
                InitializeStudent(tokName, grade, &student);

                /* Inserts student struct into linked list at specified position */
                Insert(student, pos, &myList);

                /* Prints current status of the list (If anyone has been added and the size) */
                if (Empty(&myList) == 0) {
                    printf("List is empty; List is of size 0:\n");
                }
                else
                    printf("List is not empty; List is of size %d:\n", myList.size);

                printf("%s %d%% was added to the list in position %d\n", student.name , student.grade , pos);
                printf("\n");

            }

            if (buffer[0] == 'R' || buffer[0] == 'r') {

                rem = strtok(buffer," ");
                remSpot = strtok(NULL," ");

                toRemove = atoi(remSpot);

                /* Removes student struct form the list in position specified */
                Remove(toRemove, &myList);

                if (Empty(&myList) == 0) {
                    printf("List is empty; List is of size 0:\n");
                }
                else
                    printf("List is not empty; List is of size %d:\n", myList.size);

                printf("%s %d%% was removed from position %d in the list\n", student.name , student.grade , toRemove);
                printf("\n");

            }
        }
    }

    /* Frees student structs and destroys list */
    FreeStudent(&student);
    Destroy(&myList);

    return EXIT_SUCCESS;
}



