#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "argument_parser.h"
#include "publication.h"
#include "dlist.h"
#include "comb_sort.h"
#include "io_operators.h"

int main(int argc, char* argv[]) {

    setlocale(LC_ALL, "ru_RU.UTF-8");
    srand(time(NULL));
    
    ProgramOptions options = parse_arguments(argc, argv);
    
    if (options.mode == MODE_UNKNOWN) {
        print_help();
        return 1;
    }
    
    DLList list;
    dllist_init(&list);
    
    switch (options.mode) {
        case MODE_GENERATE: {
            for (int i = 0; i < options.generate_count; i++) {
                Publication pub = publication_generate_random();
                dllist_push_back(&list, pub);
            }
            
            write_csv(options.output_file, &list);
            break;
        }
        
        case MODE_SORT: {
            read_csv(options.input_file, &list);
            
            Comparator cmp;
            if (options.sort_type == SORT_ASC) {
                cmp = (Comparator)publication_compare_asc;
            } else {
                cmp = publication_compare_desc; 
            }
            
            comb_sort(&list, cmp);
            write_csv(options.output_file, &list);
            break;
        }
        
        case MODE_PRINT: {

            if (!options.input_file) {
                char filename[256];
                printf("Enter input filename: ");
                if (fgets(filename, sizeof(filename), stdin)) {
                    filename[strcspn(filename, "\n")] = 0;
                    options.input_file = strdup(filename);
                }
            }
            

            read_csv(options.input_file, &list);
            

            print_table(options.output_file, &list);
            
            if (!options.input_file) {
                free(options.input_file);
            }
            break;
        }
        
        default:
            break;
    }
    
    dllist_clear(&list);
    return 0;
}