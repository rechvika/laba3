#ifndef DLLIST_H
#define DLLIST_H

#include "publication.h"

typedef struct Node {
    Publication data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} DLList;

#endif