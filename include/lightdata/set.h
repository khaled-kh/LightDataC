#ifndef LIGHTDATA_SET
#define LIGHTDATA_SET
#include "tree.h"

typedef BTREE SET;

int set_size(SET** t){ return tree_size(t); }

void set_insert(SET** t, int k, void* d){ if(!btree_find(t,k)) btree_insert(t,k,d); }

SET* set_find(SET** t, int k){ return btree_find(t,k); }

void* set_get(SET** t, int k){ return btree_get(t,k); }

#endif