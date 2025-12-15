#include "argument_parser.h"

ProgramOptions parse_arguments(int argc, char* argv[]) {
    ProgramOptions options;
    options.mode = MODE_UNKNOWN;
    options.sort_type = SORT_ASC;
    options.input_file = NULL;
    options.output_file = NULL;
    options.generate_count = 0;
    
    for (int i = 1; i < argc; i++) { /*узнаем от пользователя, что ему нужно сделать*/
        if (strcmp(argv[i], "--generate") == 0 || strcmp(argv[i], "-g") == 0) {
            options.mode = MODE_GENERATE;
            if (i + 1 < argc) {
                options.generate_count = atoi(argv[++i]);
            }
        } else if (strcmp(argv[i], "--sort") == 0 || strcmp(argv[i], "-s") == 0) {
            options.mode = MODE_SORT;
        } else if (strcmp(argv[i], "--print") == 0 || strcmp(argv[i], "-P") == 0) {
            options.mode = MODE_PRINT;
        } else if (strcmp(argv[i], "--type=asc") == 0 || strcmp(argv[i], "-t") == 0) {
            if (i + 1 < argc && strcmp(argv[i + 1], "A") == 0) {
                options.sort_type = SORT_ASC;
                i++;
            }
        } else if (strcmp(argv[i], "--type=desc") == 0 || strcmp(argv[i], "-t") == 0) {
            if (i + 1 < argc && strcmp(argv[i + 1], "D") == 0) {
                options.sort_type = SORT_DESC;
                i++;
            }
        } else if (strncmp(argv[i], "--in=", 5) == 0) {
            options.input_file = argv[i] + 5;
        } else if (strcmp(argv[i], "-i") == 0 && i + 1 < argc) {
            options.input_file = argv[++i];
        } else if (strncmp(argv[i], "--out=", 6) == 0) {
            options.output_file = argv[i] + 6;
        } else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            options.output_file = argv[++i];
        } else if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
            print_help();
            exit(0);
        }
    }
    
    return options;
}

void print_help() {
    printf("Usage: publication_sort [OPTIONS]\n");
    printf("Modes:\n");
    printf("  --generate N, -g N    Generate N random publications\n");
    printf("  --sort, -s            Sort publications\n");
    printf("  --print, -P           Print publications as table\n");
    printf("\nInput/Output:\n");
    printf("  --in=FILE, -i FILE    Input file (CSV for sort, filename for print)\n");
    printf("  --out=FILE, -o FILE   Output file\n");
    printf("\nSort options:\n");
    printf("  --type=asc, -t A      Sort ascending (default)\n");
    printf("  --type=desc, -t D     Sort descending\n");
    printf("\nOther:\n");
    printf("  --help, -h            Show this help message\n");
}