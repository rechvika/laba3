#pragma once

#define IO_OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/dlist.h"

typedef enum { 
    MODE_GENERATE,
    MODE_SORT,
    MODE_SORT_MERGE,
    MODE_PRINT,
    MODE_UNKNOWN
} programmode;

typedef enum {
    SORT_ASC,
    SORT_DESC
} sort__type;

void write_csv(const char* filename, dllist* list);
void read_csv(const char* filename, dllist* list);
void print_table(const char* filename, dllist* list);

