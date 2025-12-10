#include <math.h>
#include "comb_sort.h"

void comb_sort(DLList* list, Comparator cmp) {
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
            Publication* a = dllist_get(list, i);
            Publication* b = dllist_get(list, i + gap);
            
            if (cmp(a, b) > 0) {
                dllist_swap(list, i, i + gap);
                sorted = 0;
            }
        }
    }
}