#pragma once

#include <stdlib.h>
#include <string.h>
#include "publication.h"
#include "logging.h"

typedef unsigned int uint;

typedef struct node{
    publication* data;  
    struct node* prev;
    struct node* next;
} node;

typedef struct {
    node* head;
    node* tail;
    uint size;
} dllist;

void dllist_init(dllist* list);
uint size(const dllist* list);
node* get(const dllist* list, uint index);
node* begin(const dllist* list);
node* end(const dllist* list);
void dllist_push_front(dllist* list, publication* data); 
void dllist_push_back(dllist* list, publication* data);
node* next(const dllist* list, unsigned int index);
node* prev(const dllist* list, unsigned int index);
void pop_front(dllist* list);
void pop_back(dllist* list);
void dllist_clear(dllist* list);
void insert(dllist* list, unsigned int index, publication* data);
void swap(dllist* list, unsigned int i, unsigned int j);
void dllist_remove(dllist* list, unsigned int index);
void dllist_from_array(dllist* list, publication* array, unsigned int size);
publication* dllist_to_array(dllist* list);
const char* publication_get_i(dllist* list, uint index, uint indicator);
void write_log(const char* message);