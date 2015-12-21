#include "ListInterface.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/* some code here (e.g., #include directives, static functions) */

void Initialize (List *L) {

	L = 0;

	
	/* some code here */
}

/*
Evaluates the location of where to insert the data into the list
Conditions will adjust the list to have no gaps

If inserting in the middle of the list, all following items
will be shifted over to make room for new data
*/
void Insert (Item X, int position, List *L) {

	/* Preconditions */
	if (L->size == 4) {
		exit(1);
	}

	/* Preconditions */
	if (position < 0 || position > L->size) {
		exit(1);
	}

	else if (L->size == 0) {
		strcpy(L->items[position].name , X.name);
		L->items[position].grade = X.grade;
		L->size++;
	}

	else if (L->size == 1 && position == 0) {

		strcpy(L->items[position+1].name , L->items[position].name);
		L->items[position+1].grade = L->items[position].grade;

		strcpy(L->items[position].name , X.name);
		L->items[position].grade = X.grade;
		L->size++;
		
	}

	else if (L->size == 1 && position == 1) {
		strcpy(L->items[position].name , X.name);
		L->items[position].grade = X.grade;
		L->size++;
	}

	else if (L->size == 2 && position == 0) {
		strcpy(L->items[position+2].name , L->items[position+1].name);
		L->items[position+2].grade = L->items[position+1].grade;

		strcpy(L->items[position+1].name , L->items[position].name);
		L->items[position+1].grade = L->items[position].grade;
		L->size++;

		strcpy(L->items[position].name , X.name);
		L->items[position].grade = X.grade;
		L->size++;
	}

	else if (L->size == 2 && position == 1) {
		strcpy(L->items[position+1].name , L->items[position].name);
		L->items[position+1].grade = L->items[position].grade;

		strcpy(L->items[position].name , X.name);
		L->items[position].grade = X.grade;
		L->size++;
	}

	else if (L->size == 2 && position == 2) {		
		strcpy(L->items[position].name , X.name);
		L->items[position].grade = X.grade;
		L->size++;
	}

	else if (L->size == 3 && position == 0) {
		strcpy(L->items[position+3].name , L->items[position+2].name);
		L->items[position+3].grade = L->items[position+2].grade;

		strcpy(L->items[position+2].name , L->items[position+1].name);
		L->items[position+2].grade = L->items[position+1].grade;

		strcpy(L->items[position+1].name , L->items[position].name);
		L->items[position+1].grade = L->items[position].grade;

		strcpy(L->items[position].name , X.name);
		L->items[position].grade = X.grade;
		L->size++;
	}

	else if (L->size == 3 && position == 1) {
		strcpy(L->items[position+2].name , L->items[position+1].name);
		L->items[position+2].grade = L->items[position+1].grade;

		strcpy(L->items[position+1].name , L->items[position].name);
		L->items[position+1].grade = L->items[position].grade;

		strcpy(L->items[position].name , X.name);
		L->items[position].grade = X.grade;
		L->size++;
	}

	else if (L->size == 3 && position == 2) {
		strcpy(L->items[position+1].name , L->items[position].name);
		L->items[position+1].grade = L->items[position].grade;

		strcpy(L->items[position].name , X.name);
		L->items[position].grade = X.grade;
		L->size++;
	}

	else if (L->size == 3 && position == 3) {
		strcpy(L->items[position].name , X.name);
		L->items[position].grade = X.grade;
		L->size++;
	}





    /*	 some code here */
}

/*
Evaluates the location in the list as to where to remove the data
Will adjust data lcations to keep the list in order
*/
void Remove (int position, List *L) {

	/* Preconditions */
	if (L->size == 0) {
		exit(1);
	}

	if (L->size == 4 && position == 0) {
		strcpy(L->items[position].name , L->items[position+1].name);
		L->items[position].grade = L->items[position+1].grade;

		strcpy(L->items[position+1].name , L->items[position+2].name);
		L->items[position+1].grade = L->items[position+2].grade;

		strcpy(L->items[position+2].name , L->items[position+3].name);
		L->items[position+2].grade = L->items[position+3].grade;
		L->size--;
	}

	else if (L->size == 4 && position == 1) {
		strcpy(L->items[position].name , L->items[position+1].name);
		L->items[position].grade = L->items[position+1].grade;

		strcpy(L->items[position+1].name , L->items[position+2].name);
		L->items[position+1].grade = L->items[position+2].grade;
		L->size--;
	}

	else if (L->size == 4 && position == 2) {
		strcpy(L->items[position].name , L->items[position+1].name);
		L->items[position].grade = L->items[position+1].grade;
		L->size--;
	}

	else if (L->size == 4 && position == 3) {
		L->items[position].grade = '\0';
		memset(L->items[position].name,0,sizeof(L->items[position].name)); 
		L->size--;
			}

	else if (L->size == 3 && position == 0) {		
		strcpy(L->items[position].name , L->items[position+1].name);
		L->items[position].grade = L->items[position+1].grade;

		strcpy(L->items[position+1].name , L->items[position+2].name);
		L->items[position+1].grade = L->items[position+2].grade;
		L->size--;
	}

	else if (L->size == 3 && position == 1) {
		strcpy(L->items[position].name , L->items[position+1].name);
		L->items[position].grade = L->items[position+1].grade;
		L->size--;
	}

	else if (L->size == 3 && position == 2) {
		L->items[position].grade = '\0';
		memset(L->items[position].name,0,sizeof(L->items[position].name)); 
		L->size--;
	}

	else if (L->size == 2 && position == 0) {
		strcpy(L->items[position].name , L->items[position+1].name);
		L->items[position].grade = L->items[position+1].grade;
		L->size--;
	}

	else if (L->size == 2 && position == 1) {
		L->items[position].grade = '\0';
		memset(L->items[position].name,0,sizeof(L->items[position].name)); 
		L->size--;
	}

	else if (L->size == 1 && position == 0) {
		L->items[position].grade = '\0';
		memset(L->items[position].name,0,sizeof(L->items[position].name)); 
		L->size--;
	}


}

/*
Checks to see if the list is full
*/
int Full (List *L) {

	if (L->size == 4)
		return 0;

	else
		return 1;

}

/*
Check to see if the list is empty
*/
int Empty (List *L) {

	if (L->size == 0)
		return 0;

	else
		return 1;

}

/*
Returns the array size
*/
int Size (List *L) {

	return L->size;
}
void Peek (int position, List *L, Item *X) {

	/* some code here */
}

/*
Free's array data
*/
void Destroy (List *L) {

	free(L);

	/* some code here */
}



