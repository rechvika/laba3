#ifndef COMB_SORT_H
#define COMB_SORT_H

#include "dlist.h"
#include "publication.h"
#include <math.h>

typedef int (*comparator)(const void*, const void*);

void comb_sort(dllist* list, comparator cmp);

#endif