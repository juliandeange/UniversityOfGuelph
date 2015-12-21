#include "StudentInterface.h"

typedef Student Item;

typedef struct ListNodeTag {
	Item item;
	struct ListNodeTag *next;
} ListNode;

typedef struct {
	int size;
	ListNode *first;
} List;

