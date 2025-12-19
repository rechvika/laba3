#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

node* split(node* head);
node* merge(node* left, node* right);
node* mergeSort(node* head);

#endif