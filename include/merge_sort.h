#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"
#include "comparator.h"

void merge(dllist* list, uint left, uint mid, uint right, comparator cmp);
void merge_sort(dllist* list, uint left, uint right, comparator cmp);
