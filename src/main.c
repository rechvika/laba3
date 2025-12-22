#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h> 
#include "../include/argument_parser.h"
#include "../include/publication.h"
#include "../include/dlist.h"
#include "../include/comb_sort.h"
#include "../include/io_operators.h"
#include "../include/merge_sort.h"
#include "../include/comparator.h"

int main(int argc, char* argv[]) {

    setlocale(LC_ALL, "ru_RU.UTF-8");
    srand(time(NULL));
    
    programoptions options = parse_arguments(argc, argv);
    
    if (options.mode == MODE_UNKNOWN) {
        print_help();
        return 1;
    }
    
    dllist list;
    dllist_init(&list);
    
    switch (options.mode) {
        case MODE_GENERATE: {
            publication pub;
            for (uint i = 0; i < options.generate_count; i++) {
                publication_generate_random(&pub);
                dllist_push_back(&list, &pub);
            }
            
            write_csv(options.output_file, &list); 
            break; 
        }
        
        case MODE_SORT: {
            read_csv(options.input_file, &list); 
            
            comparator cmp;
            if (options.sort_type == SORT_DESC) {
                cmp = (comparator)publication_compare_desc; 
            } else {
                cmp = (comparator)publication_compare_asc;
            }
            
            comb_sort(&list, cmp);
            write_csv(options.output_file, &list);
            break;
        }

        case MODE_SORT_MERGE: {
            if (!options.input_file) {
                fprintf(stderr, "Error: Input file required for merge sort mode\n");
                dllist_clear(&list);
                return 1;
            }
            read_csv(options.input_file, &list); 
            
            comparator cmp;
            if (options.sort_type == SORT_DESC) {
                cmp = (comparator)publication_compare_desc;  
            } else {
                cmp = (comparator)publication_compare_asc;
            }
            merge_sort(&list, 0, size(&list) - 1, cmp);

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
            
            if (options.input_file) {
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