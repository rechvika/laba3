#include <stdlib.h>
#include <string.h>
#include "dllist.h"

void init(DLList* list) { /*начальные данные(когда двусвязный список пуст)*/
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int size(DLList* list) {  /*получение размера*/
    return list->size;
}

Publication* get(DLList* list, int index) { /*получение элемента по индексу*/
    if (index < 0 || index >= list->size) {
        return NULL;
    }

    Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return *(current->data);
}

Node* begin(DLList* list) { /*получение первого элемента*/
    return list->head;
}

Node* end(DLList* list) { /*получение последнего элемента*/
    return list->tail;
}

void push_front(DLList* list, Publication data) {  /*добавление в начало*/
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

void push_back(DLList* list, Publication data) { /*добавление в конец*/
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