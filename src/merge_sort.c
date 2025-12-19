#include "merge_sort.h"

node* split(node* head) {
    node* slow = head;
    node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge(node* left, node* right) { 
    
    if (!left) return right;
    if (!right) return left;
    
    node* result = NULL;
    
    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);  
        if (!result->next) {
            result->next->prev = result;
        }
    } else {
        result = right;
        result->next = merge(left, right->next);
        if (!result->next) {
            result->next->prev = result;
        }
    }
    
    result->prev = NULL;
    return result;
}

node* mergeSort(node* head) { 
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    node* middle = split(head);
    node* nextToMiddle = middle->next;
    
    middle->next = NULL;
    if (nextToMiddle != NULL) {
        nextToMiddle->prev = NULL;
    }
    
    node* left = mergeSort(head);
    node* right = mergeSort(nextToMiddle);
    
    return merge(left, right);
}

void sortList(node** headRef, node** tailRef) {
    if (*headRef == NULL) return;
    
    *headRef = mergeSort(*headRef);
   
    *tailRef = *headRef;
    if (*tailRef != NULL) {
        while ((*tailRef)->next != NULL) {
            *tailRef = (*tailRef)->next;
        }
    }
}

