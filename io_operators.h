#ifndef IO_OPERATIONS_H
#define IO_OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dlist.h"

typedef enum { 
    MODE_GENERATE,
    MODE_SORT,
    MODE_SORT_MERGE,
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