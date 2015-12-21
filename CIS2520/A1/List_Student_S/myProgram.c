#include "ListInterface.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* some code here (e.g., #include directives, static functions) */

int main (void) {

    FILE * file;
    
    List myList;
    Item student;

    char buffer[100];
    char * action;
    char * tokPos;
    char * tokName;
    char * tokGrade;

    char * rem;
    char * remSpot;
    int toRemove;

    int pos;
    int grade;
    int i;

    /* Opens file */
    file = fopen("test.txt","r");
    myList.size = 0;
    if (file != NULL) {
        while (fgets (buffer, sizeof buffer, file) != NULL) {
            
            /*
            Parses the Insert line and calls function that adds data...
            ...to the specified location in the list.
            Calls another function to initialize the student data in a struct.
            Prints status of list (size, empty / full) as well as the order of the list.
            */
            if (buffer[0] == 'I' || buffer[0] == 'i') {

                if (Empty(&myList) == 0) {
                    printf("List is empty; ");
                }

                if (Empty(&myList) == 1) {
                    printf("List is not empty; ");
                }

                if (Full(&myList) == 1) {
                    printf("List is not full; ");
                }

                if (Full(&myList) == 0) {
                    printf("List is full;\n");
                }

                printf("List is of size %d:\n", myList.size);


                for (i = 0; i < myList.size; i++) {
                    printf("%s %d%%\n", myList.items[i].name , myList.items[i].grade);
                }

                if (Full(&myList) == 0) {
                    printf("List is not empty; ");
                    printf("The List is full; ");
                    printf("List is of size %d:\n", myList.size);
                }

                action = strtok(buffer," ");
                tokPos = strtok(NULL," ");
                tokName = strtok(NULL," ");
                tokGrade = strtok(NULL,"\n");

                pos = atoi(tokPos);
                grade = atoi(tokGrade);

                InitializeStudent(tokName , grade , &student);

                Insert(student, pos, &myList);

            }

            /*
            Parses the remove line and calls function to remove the data from the list
            rints status of list (size, empty / full) as well as the order of the list.
            */
            if (buffer[0] == 'R' || buffer[0] == 'r') {

                if (Empty(&myList) == 0) {
                    printf("List is empty; ");
                }

                if (Empty(&myList) == 1) {
                    printf("List is not empty; ");
                }

                if (Full(&myList) == 1) {
                    printf("List is not full; ");
                }

                printf("List is of size %d:\n", myList.size);


                for (i = 0; i < myList.size; i++) {
                    printf("%s %d%%\n", myList.items[i].name , myList.items[i].grade);
                }

                if (Full(&myList) == 0) {
                    printf("List is not empty; ");
                    printf("List is full; ");
                    printf("List is of size %d:\n", myList.size);
                }
                rem = strtok(buffer," ");
                remSpot = strtok(NULL," ");

                toRemove = atoi(remSpot);

                Remove(toRemove, &myList);

            }

        }

        if (Empty(&myList) == 0) {
            printf("List is empty; List is not full; List is of size %d:\n", myList.size);
        }

    }
 
/*	some code here */
    return EXIT_SUCCESS;
}



