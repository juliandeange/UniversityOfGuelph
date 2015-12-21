#include "StudentInterface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* some code here (e.g., #include directives, static functions) */

void InitializeStudent (char *name, int grade, Student *S) {
	
	strcpy(S->name , name);
	S->grade = grade;

	/* some code here */
}

/* Finds the name of a student
Data is malloced because using char *
 */
char *NameOfStudent (Student S) {

	char *stuName;
	stuName = malloc(strlen(S.name)+1);
	strcpy(stuName,S.name);

	return stuName; /* change this */
}

/* Finds the grade of a student */
int GradeOfStudent (Student S) {
	return S.grade;
}

/* Frees memory */
void FreeStudent (Student *S) {

	free(S->name);
	free(S);

	/* some code here */
}


