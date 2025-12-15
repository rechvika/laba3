#ifndef IO_OPERATIONS_H
#define IO_OPERATIONS_H

#include "dlist.h"

typedef enum {
    MODE_GENERATE,
    MODE_SORT,
    MODE_PRINT,
    MODE_UNKNOWN
} ProgramMode;


typedef enum {
    SORT_ASC,
    SORT_DESC
} SortType;


void write_csv(const char* filename, DLList* list);
void read_csv(const char* filename, DLList* list);
void print_table(const char* filename, DLList* list);

#endif