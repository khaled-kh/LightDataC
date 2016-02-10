#ifndef LIGHTDATA_STACK
#define LIGHTDATA_STACK
#include <stdlib.h>

/****************************************
	int in = 10;
	Stack* s = 0;
	push(&s, in);
	int out = (int)pop(&s);
	if(s) printf("stack not empty");
*****************************************/

typedef _Stack; typedef struct _Stack{void* d; _Stack* n;} Stack;

void* pop(Stack** s)
{
	Stack*t=0;void*d=0;
	if(*s)(*s)->d,t=(*s),(*s)=(*s)->n,free(t);
	return d;
}

void push(Stack** s, void* d)
{
	Stack*t=(Stack*)malloc(sizeof(Stack));
	if((*s)==0)(*s)=t,(*s)->d=d;
	else t->d=d,t->n=(*s),(*s)=t;
}

#endif