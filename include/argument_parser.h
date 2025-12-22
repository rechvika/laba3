#pragma once

#define ARGUMENT_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/io_operators.h"
#include "../include/publication.h"

typedef struct { 
    programmode mode;
    sort__type sort_type;
    char* input_file;
    char* output_file;
    uint generate_count;
} programoptions;

programoptions parse_arguments(uint argc, char* argv[]);
void print_help();

