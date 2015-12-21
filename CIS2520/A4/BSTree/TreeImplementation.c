#include "TreeInterface.h"
#include "StudentType.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InsertRecurse (TreeNode * node, Tree * T, void * I);

/* Creates an empty Binary Search Tree */
extern void Initialize (Tree *T,
						void * (*copyValue) (void *, void *),
						void (*destroyValue) (void *),
						int (*compareValues) (void *, void *)) {
	T->root = NULL;
	T->size = 0;
	T->copyValue = copyValue;
	T->destroyValue = destroyValue;
	T->compareValues = compareValues;

}/*end initialize*/

/*
void InsertRecurse (TreeNode * node, Tree * T, void * I) {
	int i;
	i = T->compareValues(node->value, I);

	if (i == -1) {
		if (node->left == NULL) {
			node->left = malloc(sizeof(TreeNode));
			T->copyValue(node->left->value, I);
			node->left->parent = node;
			T->size++;

		}
		else
			InsertRecurse(node->left, T, I);
	}
	else if (i == 0 || i == 1) {
		if (node->right == NULL) {
			node->right = malloc(sizeof(TreeNode));
			T->copyValue(node->right->value, I);
			node->right->parent = node;
			T->size++;
		}
		else
			InsertRecurse(node->right, T, I);
	}
}

*/

/* Insterts an item to the binary tree */
extern void Insert (Tree *T, void *I) {

	TreeNode * n;
	TreeNode * q;
	TreeNode * p;

	n = malloc(sizeof(TreeNode));
	p = malloc(sizeof(TreeNode));
	q = malloc(sizeof(TreeNode));

	/* Copys items to new node */
	T->copyValue(n->value, I);

	n->right = NULL;
	n->left = NULL;

	p->parent = T->root;

	while (p != NULL) {
		q = p;
		if (n->value < p->value)
			p = p->left;
		else
			p = p->right;
	}

	/* Points new node to children and parent */
	n->parent = q;
	if (q == NULL)
		T->root = n;
	else if (n->value < q->value)
		q->left = n;
	else
		q->right = n;

}


/*
	TreeNode * node = T->root;

	if (T->root == NULL) {

		T->root = malloc(sizeof(TreeNode));
		T->copyValue(T->root->value,I);
		T->root->parent = NULL;
		T->root->left = NULL;
		T->root->right = NULL;
	}

	else 
		InsertRecurse(node, T, I);

}
*/

/* Returns the smallest item in the Tree 
***Pseudocode of Lab 10
*/
extern int Minimum (Tree *T, void *I) {
	
	TreeNode * n;
	n = malloc(sizeof(TreeNode));

	while (n->left != NULL)
		n = n->left;

	return 0;
	
}

/* Finds the successor the the item passed in
***Pseudocode of Lab 10
 */
extern int Successor (Tree *T, void *I) {

	TreeNode * n;
	TreeNode * p;

	n = malloc(sizeof(TreeNode));
	p = malloc(sizeof(TreeNode));

	if (n->right == NULL)
		exit(0);

	Minimum(T, n->right);
	p = n->right;

	while (p != NULL && n == p->right) {
		n = p;
		p = p->parent;
	}
	return 0;

}/*end successor*/

/* Calculates the size of the Tree */
extern int Size (Tree *T) {
	return T->size;
}/*end size*/

extern int Height (Tree *T) {
	return 0;
}/*end height*/

extern int Balanced (Tree *T) {
	return 0;
}/*end balanced*/

/* Destroys the Tree */
extern void Destroy (Tree *T) {
	free(T);
}/*end destroy*/
