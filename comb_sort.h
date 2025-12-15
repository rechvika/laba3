#ifndef COMB_SORT_H
#define COMB_SORT_H

#include "dlist.h"
#include "publication.h"
#include <math.h>

typedef int (*Comparator)(const void*, const void*);

void comb_sort(DLList* list, Comparator cmp);

#endif