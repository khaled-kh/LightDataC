#ifndef LIGHTDATA_QUEUE
#define LIGHTDATA_QUEUE
#include <stdlib.h>

typedef _QNode; typedef struct _QNode{ void* d; _QNode* n; } QueueNode;
typedef _Queue; typedef struct _Queue{ QueueNode* e; QueueNode* f; } Queue;

void* dequeue(Queue** q)
{
	void* d = 0;
	QueueNode* t = 0;
	
	if (*q)
		d = (*q)->e->d,
		t = (*q)->e,
		(*q)->e = (*q)->e->n,
		free(t);
	
	if (!(*q)->e) free(*q);
	
	return d;
}

void enqueue(Queue** q, void* d)
{
	QueueNode* t = (QueueNode*)malloc(sizeof(QueueNode));
	
	if(*q)
		(*q)->f->n = t,
		(*q)->f = (*q)->f->n,
		(*q)->f->d = d;
	else
		(*q) = (Queue*)malloc(sizeof(Queue)),
		(*q)->e = t,
		(*q)->e->d = d,
		(*q)->f = (*q)->e;
}

#endif