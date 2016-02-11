#ifndef LIGHTDATA_QUEUE
#define LIGHTDATA_QUEUE
#include <stdlib.h>
#include "stack.h"

/****************************************
	int in = 10;
	Queue* s = 0;
	enqueue(&s, in);
	int out = (int)dequeue(&s);
	if(s) printf("queue not empty");
*****************************************/

typedef _Queue; typedef struct _Queue{ Stack* e; Stack* f; } Queue;

void* dequeue(Queue** q)
{
	void* d = 0;
	Stack* t = 0;
	
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
	Stack* t = 0;
	
	if(*q)
		(*q)->f->n = (Stack*)malloc(sizeof(Stack)),
		(*q)->f = (*q)->f->n,
		(*q)->f->d = d;
	else
		(*q) = (Queue*)malloc(sizeof(Queue)),
		(*q)->e = (Stack*)malloc(sizeof(Stack)),
		(*q)->e->d = d,
		(*q)->f = (*q)->e;
}

#endif