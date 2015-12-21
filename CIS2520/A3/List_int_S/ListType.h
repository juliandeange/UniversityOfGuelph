#define MAXLISTSIZE 100000
typedef struct {
	int items[MAXLISTSIZE];
	int size;
} List;

typedef enum {
	false,
	true
} bool;
