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

typedef _Queue; typedef struct _Queue{ Stack* e; Stack* f;} Queue;

void* dequeue(Queue** q)
{
	void* d = 0;
	
	if (*q) d = pop(&(*q)->e);
	if (!(*q)->e) free(*q);
	
	return d;
}

void enqueue(Queue** q, void* d)
{
	if(*q)
		push(&(*q)->f->n,d),
		(*q)->f = (*q)->f->n;
	else
		(*q) = (Queue*)malloc(sizeof(Queue)),
		(*q)->e=0,
		push(&(*q)->e,d),
		(*q)->f = (*q)->e;
}

#endif