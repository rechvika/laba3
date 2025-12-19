#include "dlist.h"

int check_null(dllist* list){
    if(!list){ 
        printf("Memory allocation error!\n");
        exit(1); 
    } 
}
void dllist_init(dllist* list) { 
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int size(dllist* list) { 
    int check_null(dllist* list);
    return list->size;
}

publication* get(dllist* list, unsigned int index) { 
    int check_null(dllist* list);
    if (index >= list->size) {
        return NULL;
    }
    else {
        node* current = list->head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }
}

node* begin(dllist* list) { 
    int check_null(dllist* list);
    return list->head;
}

node* end(dllist* list) { 
    int check_null(dllist* list);
    return list->tail;
}

void dllist_push_front(dllist* list, publication* data) {  
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = list->head;
    
    if (list->head) {
        list->head->prev = new_node;
    } else {
        list->tail = new_node;
    }
    
    list->head = new_node;
    list->size++;
}

void dllist_push_back(dllist* list, publication* data) { 
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = list->tail;
    
    if (list->tail) {
        list->tail->next = new_node;
    } else {
        list->head = new_node;
    }
    
    list->tail = new_node;
    list->size++;
}

node* next(node* node) {
    if (!node) {
        return node->next;
    } 
    else {
        return NULL;
    }
}

node* prev(node* node) { 
    if(!node){
        return node->prev;
    }
    else {
        return NULL;
    }
}

void pop_front(dllist* list) { 
    int check_null(dllist* list);
    
    node* temp = list->head;
    list->head = list->head->next;
    
    if (list->head) {
        list->head->prev = NULL;
    } else {
        list->tail = NULL;
    }
    
    free(temp);
    list->size--;
}

void pop_back(dllist* list) { 
    int check_null(dllist* list);
    
    node* temp = list->tail;
    list->tail = list->tail->prev;
    
    if (list->tail) {
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }
    
    free(temp);
    list->size--;
}

void dllist_clear(dllist* list) {
    int check_null(dllist* list);
    node* current = list->head;
    while (current) {
        node* next = current->next;
        free(current);
        current = next;
    }
    
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void insert(dllist* list, unsigned int index, publication* data) { 
    int check_null(dllist* list);
    if (index > list->size) {
        return;
    }
    
    if (index == 0) {
        dllist_push_front(list, data);
        return;
    }
    
    if (index == list->size) {
        dllist_push_back(list, data);
        return;
    }
    
    node* current = list->head;
    for (unsigned int i = 0; i < index; i++) {
        current = current->next; 
    } 
    
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->prev = current->prev;
    new_node->next = current;
    
    current->prev->next = new_node;
    current->prev = new_node;
    
    list->size++;
}

void swap(dllist* list, unsigned int i, unsigned int j) { 
    int check_null(dllist* list);
    if (i >= list->size|| j >= list->size || i == j) {
        return;
    }
    
    node* node_i = list->head;
    for (unsigned int k = 0; k < i; k++) {
        node_i = node_i->next;
    }                                              
    
    node* node_j = list->head;
    for (unsigned int k = 0; k < j; k++) {
        node_j = node_j->next;
    }
    
   Publication* temp = node_i->data;
   node_i->data = node_j->data;
   node_j->data = temp;
}

publication* dllist_from_array(dllist* list, publication* array) { 
    int check_null(dllist* list);
    if(!array){ 
        printf("Memory allocation error!\n");
        return; 
    } 
    dllist_clear(list);
    for (unsigned int i = 0; i < list->size; i++) {
        dllist_push_back(list, array[i]);
    }
    return list;
}                                   

publication* dllist_to_array(dllist* list) {
    int check_null(dllist* list);
    for (unsigned int i = 0; i < list->size; i++) {
        dllist_push_back(array[i], list);
    }
    return array;
}

void dllist_remove(dllist* list, unsigned int index) {
    int check_null(dllist* list);

    if (index >= list->size) {
        return;
    }
    
    if (index == 0) {
        pop_front(list);
        return;
    }
    
    if (index == list->size - 1) {
        pop_back(list);
        return;
    }

    node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    
    current->prev->next = current->next;   
    current->next->prev = current->prev;  
    
    free(current);
    list->size--;
}

node* createnode(publication* data) {
    node* new_node = (node*)malloc(sizeof(node));
    int check_null(dllist* list);      /*логировнаие*/
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}


