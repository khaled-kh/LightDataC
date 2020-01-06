#ifndef LIGHTDATA_BTREE
#define LIGHTDATA_BTREE
#include <stdlib.h>

typedef _BTree; typedef struct _BTree{ int k; void* d; _BTree* l,r; } BTree;

int int_max(int a, int b){ return a > b ? a : b; }
int btree_size(BTree** t){ return *t ? 1 + btree_size((*t)->l) + btree_size((*t)->r) : 0; }
int btree_depth(BTree** t){ return *t ? int_max(btree_depth((*t)->l), btree_depth((*t)->r)) + 1 : 0; }

void btree_insert(BTree** t, int k, void* d)
{
	if(*t)
		btree_insert(k > (*t)->k? &(*t)->r: &(*t)->l, k, d);
	else
		(*t) = (BTree*)malloc(sizeof(BTree)),
		(*t)->k = k,
		(*t)->d = d;
}

BTree* btree_find(BTree** t, int k)
{
	if (!(*t)) return 0;
	else if (k == (*t)->k) return (*t);
	else return k > (*t)->k ? btree_find((*t)->r, k) : btree_find((*t)->l, k);
}

void* btree_get(BTree** t, int k)
{
	BTree* f = btree_find(t, k);
	return f ? f->d : 0;
}

#endif
