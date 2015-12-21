#include "StudentInterface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Places data into a student struct */
void InitializeStudent (char *name, int grade, Student *S) {

	/* Postconditions */
	S->name = name;
	S->grade = grade;
}

/* Returns name of a student */
char *NameOfStudent (Student S) {

	return S.name;
}

/* Returns grade of a student */
int GradeOfStudent (Student S) {
	return S.grade;
}

/* Frees student struct memory */
void FreeStudent (Student *S) {

	free(S->name);
	free(S);


}



