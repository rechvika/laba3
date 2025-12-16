#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

Node* split(Node* head);
Node* merge(Node* left, Node* right);
Node* mergeSort(Node* head);
void freeList(Node* head);

#endif