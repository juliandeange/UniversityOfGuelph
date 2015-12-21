#include "QueueType.h"


extern void Initialize (Queue *Q); 
extern void Enqueue (Item I, Queue *Q); 
extern void Dequeue (Queue *Q);
extern int Full (Queue *Q);
extern int Empty (Queue *Q);
extern int Size (Queue *Q);
extern void Head (Queue *Q, Item *I); 
extern void Tail (Queue *Q, Item *I); 
extern void Destroy (Queue *Q);



