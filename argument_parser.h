#ifndef ARGUMENT_PARSER_H
#define ARGUMENT_PARSER_H

#include "io_operations.h"

typedef struct {
    ProgramMode mode;
    SortType sort_type;
    char* input_file;
    char* output_file;
    int generate_count;
} ProgramOptions;

ProgramOptions parse_arguments(int argc, char* argv[]);
void print_help();

#endif