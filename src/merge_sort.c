#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"

void merge(dllist* list, uint left, uint mid, uint right, comparator cmp) {
    uint i, j;
    uint len_1 = mid - left + 1;
    uint len_2 = right - mid;
    
    dllist* left_dllist = (dllist*)malloc(len_1 * sizeof(int));
    dllist* right_dllist = (dllist*)malloc(len_2 * sizeof(int));
    
    if (left_dllist == NULL || right_dllist == NULL) {
      //  write_log(dllist* left_dllist);
        free(left_dllist);
        free(right_dllist);
        return;
    }
    
    for (i = 0; i < len_1; i++){
        dllist_push_back_merge(left_dllist, get(list, i));
    }
    for (j = 0; j < len_2; j++){
        dllist_push_back_merge(right_dllist, get(list, j));
    }
    
    i = 0; 
    j = 0; 
    dllist_clear(list);
    
    while (i < len_1 && j < len_2) {
        if (cmp(get(left_dllist, i), get(right_dllist, j)) <= 0) {
            dllist_push_back_merge(list, get(left_dllist, i));
            i++;
        } else {
            dllist_push_back_merge(list, get(right_dllist, j));
            j++;
        }
    }
    
    while (i < len_1) {
       dllist_push_back_merge(list, get(left_dllist, i));
        i++;
    }
    
    while (j < len_2) {
        dllist_push_back_merge(list, get(right_dllist, j));
        j++;
    }
    
    dllist_clear(left_dllist);
    dllist_clear(right_dllist);
}

void merge_sort(dllist* list, uint left, uint right, comparator cmp) {
    if (left < right) {
        uint mid = left + (right - left) / 2;
        
        merge_sort(list, left, mid, cmp);
        merge_sort(list, mid + 1, right, cmp);
        
        merge(list, left, mid, right, cmp);
    }
}

