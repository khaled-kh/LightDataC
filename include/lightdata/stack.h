#ifndef LIGHTDATA_STACK
#define LIGHTDATA_STACK
#include <stdlib.h>

typedef _Stack; typedef struct _Stack{ void* d; _Stack* n; } Stack;

void* pop(Stack** s)
{
	void* d = 0;
	Stack* t = 0;
	
	if(*s)
		d = (*s)->d,
		t = (*s),
		(*s) = (*s)->n,
		free(t);
	
	return d;
}

void push(Stack** s, void* d)
{
	Stack* t = 0;
	
	t = (Stack*)malloc(sizeof(Stack));
	t->n = 0, t->d = d;
	if(*s) t->n = (*s);
	(*s) = t;
}

#endif