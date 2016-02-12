#ifndef LIGHTDATA_LIST
#define LIGHTDATA_LIST
#include <stdlib.h>

/****************************************
	List* l = 0;
	
	if(l) printf("List not empty");
*****************************************/

typedef _LNode; typedef struct _LNode{ void* d; _LNode* n; _LNode* p; } LNode;
typedef _List; typedef struct _List{ LNode* f; LNode* e; int size; } List;

LNode* begin(List** l){ return *l?(*l)->f:0; }
LNode* end(List** l){ return *l?(*l)->e:0; }

void next(LNode** t){ *t = *t?(*t)->n:0; }
void prev(LNode** t){ *t = *t?(*t)->p:0; }

int size(List** l){ return *l?(*l)->size:0; }

void push_front(List** l, void* d)
{
	LNode*t = (LNode)malloc(sizeof(LNode));
	t->d = d;
	
	if(*l)
		(*l)->f->p = t,
		t->n = (*l)->f,
		(*l)->f = t;
	else
		(*l)=(List*)malloc(sizeof(List)),
		(*l)->f = t,
		(*l)->e = t;
	
	(*l)->size++;
}

void push_back(List** l, void* d)
{
	LNode*t = (LNode)malloc(sizeof(LNode));
	t->d = d;
	
	if(*l)
		(*l)->e->n = t,
		t->p = (*l)->e,
		(*l)->e = t;
	else
		(*l)=(List*)malloc(sizeof(List)),
		(*l)->f = t,
		(*l)->e = t;
	
	(*l)->size++;
}

void* pop_front(List** l)
{
	LNode* t = 0;
	void* d = 0;
	
	if(*l)
		t = (*l)->f,
		(*l)->f = t->n,
		(*l)->f->p = 0,
		d = t->d,
		free(t),
		(*l)->size--;
	
	if(!(*l)->f) free(*l);
	
	return d;
}

void* pop_back(List** l)
{
	LNode* t = 0;
	void* d = 0;
	
	if(*l)
		t = (*l)->e,
		(*l)->e = t->p,
		(*l)->e->n = 0,
		d = t->d,
		free(t),
		(*l)->size--;
	
	if(!(*l)->e) free(*l);
	
	return d;
}

#endif