/*********************************************************************
 * FILE NAME: StackType.c
 * PURPOSE: Stack ADT
 * AUTHOR: P. Matsakis (CIS2520, Assignment 2)
 * DATE: 15/10/2015
 *********************************************************************/

typedef int Item;

typedef struct StackNodeTag {
	Item item;
	struct StackNodeTag *next;
} StackNode;

typedef struct {
	int size;
	StackNode *first;
} Stack;


