/*********************************************************************
 * FILE NAME: myProgram.c
 * PURPOSE: Test program for Student Stack implementations.
 * AUTHOR: P. Matsakis (CIS2520, Assignment 2)
 * DATE: 15/10/2015
 * NOTES: This program uses test data recorded in a text file
 *        (see test.txt). 
 *********************************************************************/

#include "StackInterface.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	FILE * file;
	Stack firstStack;
	Stack secondStack;
	Stack thirdStack;
	Item topStack;
	char in[200];
	int num;
	int counter;
								/*  Declaration of Variables   */
	int i;
	int carry = 0;
	int s1;
	int s2;
	int s3;

	int bigStack = 0;

	file = fopen("test.txt","r");

	/* Initializes the 3 stacks needed */
	Initialize(&firstStack);
	Initialize(&secondStack);
	Initialize(&thirdStack);

	/*
	Reads the first line of the text file into the first stack
	Reads the second line of the text file into the second stack
	*/
	while (fgets(in,2,file) != NULL){

		if (strcmp(in,"\n") == 0) {
			while (fgets(in,2,file) != NULL){
				num = atoi(in);
				Push(num,&secondStack);
			}	
		}

		num = atoi(in);
		/* Pushes the numbers from text file into the stack */
		Push(num,&firstStack);
	}
	Pop(&firstStack);

	/* Calculates the larger of the 2 stacks so find the maximum
	number of addition calculations needed */
	bigStack = firstStack.size;
	if (secondStack.size > firstStack.size) {
		bigStack = secondStack.size;
	}

	/*
	-Loop find the value at the top of each of the first two stacks, adds
	them together and places the sum in the third stack
	-If a stack runs out of numbers, the value becomes 0 and 0 is added
	to the number in the next stack
	-If a sum is greater then 9, a carry of 1 is added to the next
	calculation
	-Stacks 1 and 2 are empty at the end of this loop
	*/
	for (i = 0; i < bigStack; i++) {
		if (firstStack.size == 0) {
			s1 = 0;
		}
		else {
			Top(&firstStack,&s1);
			Pop(&firstStack);
		}
		if (secondStack.size == 0) {
			s2 = 0;
		}
		else {
			Top(&secondStack,&s2);
			Pop(&secondStack);
		}

		s3 = s1 + s2 + carry;
		if (s3 > 9) {
			carry = 1;
			s3 = s3 - 10;
		}
		else {
			carry = 0;
		}
		Push(s3,&thirdStack);
	}

	/*
	-Loops through entire stack using Top() to find the number and
	print it to the screen
	
	*** Loop shows final sum of two stacks

	*/
	counter = thirdStack.size;
	for (i = 0; i < counter; i++) {
		Top(&thirdStack,&topStack);
		printf("%d", topStack);
		Pop(&thirdStack);
	}

	printf("\n");	


	return EXIT_SUCCESS;
}

