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

void dllist_init(DLList* list);
int size(DLList* list);
Publication* get(DLList* list, int index);
Node* begin(DLList* list);
Node* end(DLList* list);
void push_front(DLList* list, Publication data);
void dllist_push_back(DLList* list, Publication data);
Node* next(Node* node);
Node* prev(Node* node);
void pop_front(DLList* list);
void pop_back(DLList* list);
void dllist_clear(DLList* list);
void insert(DLList* list, int index, Publication data);
void swap(DLList* list, int i, int j);
void dllist_remove(DLList* list, int index);


#endif