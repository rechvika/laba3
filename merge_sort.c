#include <merge_sort.h>

Node* split(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


Node* merge(Node* left, Node* right) {
    
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

Node* mergeSort(Node* head) {
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

void freeList(Node* head) {
    Node* current = head;
    Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    printf("creating a spike\n");
    append(&head, &tail, 5);
    append(&head, &tail, 2);
    append(&head, &tail, 8);
    append(&head, &tail, 1);
    append(&head, &tail, 3);
    append(&head, &tail, 7);
    append(&head, &tail, 4);
    append(&head, &tail, 6);
    
    printf("Before sorting:\n");
    printListForward(head);
    printListBackward(tail);

    printf("\nthe sorting process\n");
    sortList(&head, &tail);
    
    printf("\nAfter sorting:\n");
    printListForward(head);
    printListBackward(tail);

    printf("\ncheck\n");
    Node* current = head;
    int isSorted = 1;
    while (current != NULL && current->next != NULL) {
        if (current->data > current->next->data) {
            isSorted = 0;
            break;
        }
        current = current->next;
    }
    
    if (isSorted) {
        printf("The list is correctly sorted in ascending order!\n");
    } else {
        printf("Error: the list is not sorted!\n");
    }
    
    freeList(head);
    
    return 0;
}