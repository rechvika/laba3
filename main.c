#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "args_parser.h"
#include "publication.h"
#include "dllist.h"
#include "comb_sort.h"
#include "io_operations.h"

int main(int argc, char* argv[]) {
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
            // Чтение данных
            read_csv(options.input_file, &list);
            
            // Выбор компаратора
            Comparator cmp = (options.sort_type == SORT_ASC) ? 
                            publication_compare_asc : publication_compare_desc;
            
            // Сортировка
            comb_sort(&list, cmp);
            
            // Запись результата
            write_csv(options.output_file, &list);
            break;
        }
        
        case MODE_PRINT: {
            // В режиме print, если input_file не указан, читаем имя файла из stdin
            if (!options.input_file) {
                char filename[256];
                printf("Enter input filename: ");
                if (fgets(filename, sizeof(filename), stdin)) {
                    filename[strcspn(filename, "\n")] = 0;
                    options.input_file = strdup(filename);
                }
            }
            
            // Чтение данных
            read_csv(options.input_file, &list);
            
            // Вывод таблицы
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