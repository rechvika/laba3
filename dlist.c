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