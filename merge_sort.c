#include <merge_sort.h>

Node* split(Node* head) { /*деление строки пополам*/
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right) { /*функция слияния*/
    
    if (left == NULL) return right;
    if (right == NULL) return left;
    
    Node* result = NULL;
    
    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);  
        if (result->next != NULL) {
            result->next->prev = result;
        }
    } else {
        result = right;
        result->next = merge(left, right->next);
        if (result->next != NULL) {
            result->next->prev = result;
        }
    }
    
    result->prev = NULL;
    return result;
}

Node* mergeSort(Node* head) { /*сортировка слиянием*/
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    Node* middle = split(head);
    Node* nextToMiddle = middle->next;
    
    middle->next = NULL;
    if (nextToMiddle != NULL) {
        nextToMiddle->prev = NULL;
    }
    
    Node* left = mergeSort(head);
    Node* right = mergeSort(nextToMiddle);
    
    return merge(left, right);
}

void sortList(Node** headRef, Node** tailRef) {
    if (*headRef == NULL) return;
    
    *headRef = mergeSort(*headRef);
   
    *tailRef = *headRef;
    if (*tailRef != NULL) {
        while ((*tailRef)->next != NULL) {
            *tailRef = (*tailRef)->next;
        }
    }
}

