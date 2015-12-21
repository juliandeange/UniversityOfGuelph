/*********************************************************************
 * FILE NAME: StackInterface.c
 * PURPOSE: Stack ADT
 * AUTHOR: P. Matsakis (CIS2520, Assignment 2)
 * DATE: 15/10/2015
 *********************************************************************/

#include "StackType.h"

extern void Initialize (Stack *S);
extern void Push (Item X, Stack *S);
extern void Pop (Stack *S);
extern int Full (Stack *S);
extern int Empty (Stack *S);
extern int Size (Stack *S);
extern void Top (Stack *S, Item * X);
extern void Destroy (Stack *S);

