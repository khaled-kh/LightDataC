#ifndef LIGHTDATA_QUEUE
#define LIGHTDATA_QUEUE
#include <stdlib.h>

/****************************************
	int in = 10;
	Queue* s = 0;
	enqueue(&s, in);
	int out = (int)dequeue(&s);
	if(s) printf("queue not empty");
*****************************************/

typedef _Queue; typedef struct _Queue{void* d; _Queue* n;} Queue;

void* dequeue(Queue** s)
{
	Queue*t=0;void*d=0;
	if(*s)(*s)->d,t=(*s),(*s)=(*s)->n,free(t);
	return d;
}

void enqueue(Queue** s, void* d)
{
	Queue*t=(Stack*)malloc(sizeof(Queue)),*p=(*s);
	if(p)while(p->n)p=p->n;
	if((*s)==0)(*s)=t,(*s)->d=d;
	else t->d=d,p->n=t;
}

#endif