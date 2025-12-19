#include "comb_sort.h"

void comb_sort(dllist* list, comparator cmp) {
    int gap = list->size;
    double shrink = 1.3;
    int sorted = 0;
    
    while (!sorted) {
        gap = (int)(gap / shrink);
        if (gap <= 1) {
            gap = 1;
            sorted = 1;
        }
        
        for (int i = 0; i + gap < list->size; i++) {
            publication* a = get(list, i);
            publication* b = get(list, i + gap);
            
            if (cmp(a, b) > 0) {
                swap(list, i, i + gap);
                sorted = 0;
            }
        }
    }
}