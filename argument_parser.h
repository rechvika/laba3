#ifndef ARGUMENT_PARSER_H
#define ARGUMENT_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "io_operators.h"

typedef struct { 
    programMode mode;
    sort__type sort_type;
    char* input_file;
    char* output_file;
    int generate_count;
} programoptions;

programoptions parse_arguments(unsigned int argc, char* argv[]);
void print_help();

#endif