#ifndef LIGHTDATA_LIST
#define LIGHTDATA_LIST
#include <stdlib.h>

/****************************************
	
*****************************************/

typedef _LNode; typedef struct _LNode{ void* d; _LNode* n; _LNode* p; } LNode;
typedef _List; typedef struct _List{ LNode* f; LNode* e; } List;

LNode* front(List** l){ return *l?(*l)->f:0; }
LNode* end(List** l){ return *l?(*l)->e:0; }

void insert(List** l, void* d)
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
}

void append(List** l, void* d)
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
}

#endif