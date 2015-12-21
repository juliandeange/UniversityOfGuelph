#include "ListInterface.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


static void showListSize (List *L) {
	if(Empty(L)) printf("List is empty; ");
	else printf("List is not empty; ");
	if(Full(L)) printf("list is full; ");
	else printf("list is not full; ");
	printf("list is of size %d:\n",Size(L));
}
	
	
static void showListContent (List *L) {
	int i;
	Student S;
	for(i=0;i<Size(L);i++) {
		Peek(i,L,&S);
		printf("\t%s %d%%\n",NameOfStudent(S),GradeOfStudent(S));
		FreeStudent(&S);
	}
}
			   

int main(void) {
	FILE *test;
	char s[20];
	int position, grade;
	
	Student S;
	List L; 
	
	Initialize(&L);
	showListSize(&L);
	showListContent(&L);
	
	/*
	Opens text file
	Reads from file and creates student object
	Inserts Item to designated position in the List
	*/
	test=fopen("test.txt","r");
	while(fscanf(test,"%s %d",s,&position)==2) {
		if(strcmp(s,"Insert")==0) {
			fscanf(test,"%s %d",s,&grade);
			InitializeStudent(s,grade,&S);
			Insert(S,position,&L);
			FreeStudent(&S);
		}
		if(strcmp(s,"Remove")==0) {
			Remove(position,&L);
		}

		/* Calls function to print the list
		Displays list to the user
		 */
		Reverse(&L);
		showListSize(&L);
		showListContent(&L);
	}
	
	fclose(test);
	Destroy(&L);
	return EXIT_SUCCESS;
}



