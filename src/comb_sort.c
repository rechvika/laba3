#include "../include/comb_sort.h"

void comb_sort(dllist* list, comparator cmp) {
    uint gap = list->size;
    double shrink = 1.3;
    uint sorted = 0;
    
    while (!sorted) {
        gap = (int)(gap / shrink);
        if (gap <= 1) {
            gap = 1;
            sorted = 1;
        }
        
        for (uint i = 0; i + gap < list->size; i++) {
            
            if (cmp(get(list, i), get(list, i + gap)) > 0) {
                swap(list, i, i + gap);
                sorted = 0;
            }
        }
    }
}