#ifndef LIGHTDATA_BTREE
#define LIGHTDATA_BTREE
#include <stdlib.h>

typedef _BTree; typedef struct _BTree{ int k; void* d; _BTree* l,r; } BTree;

int max(int a, int b){ return a > b ? a : b; }
int size(BTree** t){ return *t ? size((*t)->l) + size((*t)->r) : 0; }
int depth(BTree** t){ return *t ? max(depth((*t)->l), depth((*t)->r)) + 1 : 0; }

void insert(BTree** t, int k, void* d)
{
	if(*t)
		insert(k > (*t)->k? &(*t)->r: &(*t)->l);
	else
		(*t) = (BTree*)malloc(sizeof(BTree)),
		(*t)->k = k,
		(*t)->d = d;
}

BTree* find(BTree** t, int k)
{
	if (!(*t)) return 0;
	else if (k == (*t)->k) return (*t);
	else return k > (*t)->k ? find((*t)->r,k) : find((*t)->l,k);
}

void* get(BTree** t, int k)
{
	BTree* f = find(t,k);
	return f ? f->d : 0;
}

#endif