/*********************************************************************
 * FILE NAME: myProgram.c
 * PURPOSE: Test program for generic Binary Heap implementations
 * AUTHOR: P. Matsakis (CIS2520 F13, Assignment 4)
 * DATE: 08/11/2013
 *********************************************************************/


#include "StudentInterface.h"
#include "HeapInterface.h"
#include <stdio.h>
#include <stdlib.h>


static void * copyStudent (void *Y, void *X) {
	if(Y==NULL) Y=malloc(sizeof(Student));
	if(Y!=NULL) InitializeStudent(NameOfStudent(*(Student*)X),
								  GradeOfStudent(*(Student*)X),
								  Y);	
	return Y;
}


static void destroyStudent (void *X) {
	FreeStudent(X);
	free(X); 
} 


static int compareStudents (void *X, void *Y) {
	int i, j;
	i=GradeOfStudent(*(Student*)X);
	j=GradeOfStudent(*(Student*)Y);
	if(i>j) return -1;
	if(i==j) return 0;
	return 1;
}


int main (int argc, char* argv[]) {
	FILE *test;
	char s[20];
	int i;
	Student S;
	Heap H; 
	
	i=strtol(argv[1],NULL,10);
	Initialize(&H,i,copyStudent,destroyStudent,compareStudents);
	
	test=fopen("test.txt","r");
	while(fscanf(test,"%s %d",s,&i)==2)
		if(!Full(&H)) {
			InitializeStudent(s,i,&S);			
			Insert(&H,&S);
			FreeStudent(&S);
		}
		else {
			Top(&H,&S);
			if(i>GradeOfStudent(S)) {
				Remove(&H);
				FreeStudent(&S);
				InitializeStudent(s,i,&S);
				Insert(&H,&S);
				FreeStudent(&S);
			}
		}
	fclose(test);
	
	while(!Empty(&H)) {
		Top(&H,&S);
		Remove(&H);
		printf("%s %d\n",NameOfStudent(S),GradeOfStudent(S));
		FreeStudent(&S);
	}

	Destroy(&H);
	return EXIT_SUCCESS;
}
