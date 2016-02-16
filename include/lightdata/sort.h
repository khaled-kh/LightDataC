#ifndef LIGHTDATA_SORT
#define LIGHTDATA_SORT
#include "list.h"

// COMPRATOR(a,b) should return R
// R < 0 implies a < b
// R > 0 implies a > b
// R = 0 implies a = b
typedef int (*COMPRATOR)(void*, void*);

void list_sort (List** l, COMPRATOR comp)
{
	// TODO
}

LNode* list_search (List** l, COMPRATOR compare, void* key)
{
	LNode* t = 0;
	
	for (t = list_begin(l); t != 0; list_iterator_next(&t))
	{
		if(compare(key,t->d) == 0) return t;
		if(t == list_end(l)) break;
	}
	
	return 0;
}

#endif