#include "dlist.h"

void dllist_init(DLList* list) { /*начальные данные(когда двусвязный список пуст)*/
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int size(DLList* list) {  /*получение размера*/
    return list->size;
}

Publication* get(DLList* list, int index) { /*получение элемента по индексу*/
    if (list == NULL || index < 0 || index >= list->size) {
        return NULL;
    }
    else {
        Node* current = list->head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return &(current->data);
    }
}

Node* begin(DLList* list) { /*получение первого элемента*/
    return list->head;
}

Node* end(DLList* list) { /*получение последнего элемента*/
    return list->tail;
}

void dllist_push_front(DLList* list, Publication data) {  /*добавление в начало*/
    Node* new_node = (Node*)malloc(sizeof(Node));
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

void dllist_push_back(DLList* list, Publication data) { /*добавление в конец*/
    Node* new_node = (Node*)malloc(sizeof(Node));
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

Node* next(Node* node) { /*получение следующего*/
    if (node != NULL) {
        return node->next;
    } 
    else {
        return NULL;
    }
}

Node* prev(Node* node) { /*получение предыдущего*/
    if(node != NULL){
        return node->prev;
    }
    else {
        return NULL;
    }
}

void pop_front(DLList* list) { /*удаление элемента из начала*/
    if (!list->head) {
        return;
    }
    
    Node* temp = list->head;
    list->head = list->head->next;
    
    if (list->head) {
        list->head->prev = NULL;
    } else {
        list->tail = NULL;
    }
    
    free(temp);
    list->size--;
}

void pop_back(DLList* list) { /*удаление элемента из конца*/
    if (!list->tail) {
        return;
    }
    
    Node* temp = list->tail;
    list->tail = list->tail->prev;
    
    if (list->tail) {
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }
    
    free(temp);
    list->size--;
}

void dllist_clear(DLList* list) { /*очистка*/
    Node* current = list->head;
    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void insert(DLList* list, int index, Publication data) { /*добавление элемента в любое место*/
    if (index < 0 || index > list->size) {
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
    
    Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next; 
    } 
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = current->prev;
    new_node->next = current;
    
    current->prev->next = new_node;
    current->prev = new_node;
    
    list->size++;
}


void swap(DLList* list, int i, int j) {           /*Обмен местами*/
    if (i < 0 || i >= list->size || j < 0 || j >= list->size || i == j) {
        return;
    }
    
    if (i > j) {
        int temp = i;
        i = j;
        j = temp;
    }
    
    Node* node_i = list->head;
    for (int k = 0; k < i; k++) {
        node_i = node_i->next;
    }                                              
    
    Node* node_j = node_i;
    for (int k = i; k < j; k++) {
        node_j = node_j->next;
    }
    
    Publication temp = node_i->data;
    node_i->data = node_j->data;
    node_j->data = temp;
}

void dllist_from_array(DLList* list, Publication* array, int size) {
    dllist_clear(list);
    for (int i = 0; i < size; i++) {
        dllist_push_back(list, array[i]);
    }
}                                         

Publication* dllist_to_array(DLList* list) {
    Publication* array = (Publication*)malloc(list->size * sizeof(Publication));
    Node* current = list->head;
    for (int i = 0; i < list->size; i++) {
        array[i] = current->data;
        current = current->next;
    }
    return array;
}

void dllist_remove(DLList* list, int index) {  /*удалкение элемента из произвольного метса*/
    if (index < 0 || index >= list->size) {
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
    
    Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    
    current->prev->next = current->next;   
    current->next->prev = current->prev;  
    
    free(current);
    list->size--;
}

/*для сортировки слиянием*/

/*Создание нового узла (с возвращением его)*/
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
