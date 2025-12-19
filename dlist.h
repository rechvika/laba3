#ifndef DLLIST_H
#define DLLIST_H

#include <stdlib.h>
#include <string.h>
#include "publication.h"

typedef struct  {
    publication* data;  
    struct node* prev;
    struct node* next;
} node;

typedef struct {
    node* head;
    node* tail;
    int size;
} dllist;

void dllist_init(dllist* list);
int size(dllist* list);
publication* get(dllist* list, unsigned int index);
node* begin(dllist* list);
node* end(dllist* list);
void dllist_push_front(dllist* list, publication* data); 
void dllist_push_back(dllist* list, publication* data);
node* next(node* node);
node* prev(node* node);
void pop_front(dllist* list);
void pop_back(dllist* list);
void dllist_clear(dllist* list);
void insert(dllist* list, unsigned int index, publication* data);
void swap(dllist* list, unsigned int i, unsigned int j);
void dllist_remove(dllist* list, unsigned int index);
void dllist_from_array(dllist* list, publication* array, unsigned int size);
publication* dllist_to_array(dllist* list);
node* createnode(publication* data);

#endif