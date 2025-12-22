#pragma once

#define MERGE_SORT_H

#include <stdio.h>
#include <stdlib.h>

#include "../include/dlist.h"
#include "../include/comparator.h"

void merge(dllist* list, uint left, uint mid, uint right, comparator cmp);
void merge_sort(dllist* list, uint left, uint right, comparator cmp);
