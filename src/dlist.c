#include "dlist.h"

void dllist_init(dllist* list) {  
    if(list){
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
    }
}

uint size(const dllist* list) { 
    return list->size;
}


node* get(const dllist* list, uint index) { 
    if (index >= list->size) {
        return NULL;
    }
    else {
        node* current = list->head;
        for (uint i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    }
}

node* begin(const dllist* list) { 
    return list->head;
}

node* end(const dllist* list) { 
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

void dllist_push_back_merge(dllist* list, node* new_node) {
    if (!new_node) return;
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
node* next(const dllist* list, uint index) { 
    if (list && list->head) {
        node* temp = list->head;
        for(uint i = 0; i <= index + 1 && temp != NULL; i++){
            temp = temp->next;
        }
        return temp;
    } 
    else {
        return NULL;
    }
}

node* prev(const dllist* list, uint index) { 
    if (list && list->head) {
        node* temp = list->head;
        for(uint i = 0; i <= (index - 1) && temp != NULL; i++){
            temp = temp->next;
        }
        if(temp){
            return temp->prev;
        }
    } 
    return NULL;
}

void pop_front(dllist* list) { 
    if (!list || !list->head) return;
    
    node* temp = list->head;
    list->head = list->head->next;
    
    if (list->head) {
        list->head->prev = NULL;
    } else {
        list->tail = NULL;
    }
    
    free(temp->data);
    free(temp);
    list->size--;
}

void pop_back(dllist* list) { 

    if (!list || !list->tail) return; 
    node* temp = list->tail;
    list->tail = list->tail->prev;
    
    if (list->tail) {
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }
    
    free(temp->data);
    free(temp);
    list->size--;
}

void dllist_clear(dllist* list) {

    if (!list) return;
    node* current = list->head;
    while (current) {
        node* next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void insert(dllist* list, uint index, publication* data) { 

    if (!list || index > list->size) {  
        return;
    }
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
    for (uint i = 0; i < index; i++) {
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

void swap(dllist* list, uint i, uint j) { 
    if (!list || i >= list->size || j >= list->size || i == j) { 
        return;
    }
    if (i >= list->size || j >= list->size || i == j) {
        return;
    }
    
    node* node_i = list->head;
    for (uint k = 0; k < i; k++) {
        node_i = node_i->next;
    }                                              
    
    node* node_j = list->head;
    for (uint k = 0; k < j; k++) {
        node_j = node_j->next;
    }
    
   publication* temp = node_i->data;
   node_i->data = node_j->data;
   node_j->data = temp;
}

void dllist_from_array(dllist* list, publication* array, uint size) { 
    if (!list) return;
    dllist_clear(list);
    for (uint i = 0; i < size; i++) {
        publication* copy = malloc(sizeof(publication));
        *copy = array[i];
        dllist_push_back(list, copy);
    }
}

publication* dllist_to_array(dllist* list) {
    if (!list || list->size == 0) return NULL;
    
    publication* array = (publication*)malloc(list->size * sizeof(publication));
    if (!array) return NULL;
    
    node* current = list->head;
    for (uint i = 0; i < list->size && current != NULL; i++) {
        if (current->data) {
            array[i] = *(current->data);  
        }
        current = current->next;
    }
    return array; 
}

void dllist_remove(dllist* list, uint index) {

    if (!list || index >= list->size) {
        return;
    }
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
    for (uint i = 0; i < index; i++) {
        current = current->next;
    }
    
    current->prev->next = current->next;   
    current->next->prev = current->prev;  
    
    free(current->data);
    free(current);
    list->size--;
}

const char* publication_get_i(dllist* list, uint index, uint indicator) {
    static char buffer[20]; 
    if (list == NULL || index >= list->size) {
        return "";
    }
    node* current = get(list, index);

    if (current != NULL && current->data != NULL) {
        if(indicator == 1){
            return current->data->title;
        }
        if(indicator == 2){
            return current->data->author_lastname;
        }
        if(indicator == 3){
            return current->data->author_initials;
        }
        if(indicator == 4){
            return current->data->journal;
        if(indicator == 5){
            snprintf(buffer, sizeof(buffer), "%d", current->data->year);
            return buffer;
        }
        if(indicator == 6){
            snprintf(buffer, sizeof(buffer), "%d", current->data->volume); 
            return buffer;
        }
        if(indicator == 7){
            return current->data->is_rinc ? "YES" : "NO"; 
        }
        if(indicator == 8){
            snprintf(buffer, sizeof(buffer), "%d", current->data->pages); 
            return buffer;
        }
        if(indicator == 9){
            snprintf(buffer, sizeof(buffer), "%d", current->data->citations); 
            return buffer;
        }
        }
    }
    return "";
}

void write_log(const char * message) { 
    FILE* log_file = fopen("log_file.txt", "a");
    fprintf(log_file, "Ошибка %s\n", message);
    fclose(log_file);
}
/*
if (!file) {
    write_log(file_name);
    return;
}
*/