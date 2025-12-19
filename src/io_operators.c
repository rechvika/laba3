#include "io_operators.h"

void write_csv(const char* filename, dllist* list) { 
    FILE* fp;
    
    if (filename) {
        fp = fopen(filename, "w");
        if (!fp) {   
            printf("Error opening file for writing: %s\n", filename);
            return;
        }
    } else {
        fp = stdout;
    }
    
    fprintf(fp, "title,author_lastname,author_initials,journal,year,volume,is_rinc,pages,citations\n");
    
    node* current = list->head;
    while (current != NULL) {
        fprintf(fp, "\"%s\",\"%s\",\"%s\",\"%s\",%d,%d,%s,%d,%d\n",
                current->data->title,
                current->data->author_lastname,
                current->data->author_initials,
                current->data->journal,
                current->data->year,
                current->data->volume,
                current->data->is_rinc ? "true" : "false",
                current->data->pages,
                current->data->citations);
        current = (node *)current->next;
    }
    
    if (filename) {
        fclose(fp);
    }
}

void read_csv(const char* filename, dllist* list) { 
    FILE* fp;
//    node* current = list->head;
    
    if (filename) {
        fp = fopen(filename, "r");
        if (!fp) {
            printf("Error opening file for reading: %s\n", filename);
            return;
        }
    } else {
        fp = stdin;
    }
    
    char line[1024]; /*почему 1024. плохо*/
    
    if (!fgets(line, sizeof(line), fp)) {
        if (filename) {
            fclose(fp);
        }
        return;
    }
    
    while (fgets(line, sizeof(line), fp)) { 
        publication* pub;
        
        line[strcspn(line, "\n")] = 0; 
        
        char* token = strtok(line, ","); 
        if (!token){ 
            continue;
        } 

        if (token[0] == '"') {  
            strncpy(token, token + 1, strlen(token));  
            token[strlen(token) - 1] = 0;
        }
        strncpy(pub->title, token, MAX_STRING_LENGTH - 1); 
        
        token = strtok(NULL, ",");  /* ? нал*/
        if (token[0] == '"') {
            strncpy(token, token + 1, strlen(token));
            token[strlen(token) - 1] = 0;
        }
        strncpy(pub->author_lastname, token, MAX_STRING_LENGTH - 1);
        
        token = strtok(NULL, ",");
        if (token[0] == '"') {
            strncpy(token, token + 1, strlen(token));
            token[strlen(token) - 1] = 0;
        }
        strncpy(pub->author_initials, token, 9);
        
        token = strtok(NULL, ",");
        if (token[0] == '"') {
            strncpy(token, token + 1, strlen(token));
            token[strlen(token) - 1] = 0;
        }
        strncpy(pub->journal, token, MAX_STRING_LENGTH - 1);
        
        token = strtok(NULL, ",");
        pub->year = strtoul(token, NULL, 0);
        
        token = strtok(NULL, ",");
        pub->volume = strtoul(token, NULL, 0);
        /* + повторения в цикл*/
        token = strtok(NULL, ",");
        pub->is_rinc = (strcmp(token, "true") == 0 || strcmp(token, "1") == 0);
        
        token = strtok(NULL, ",");
        pub->pages = strtoul(token, NULL, 0);
        
        token = strtok(NULL, ",");
        pub->citations = strtoul(token, NULL, 0);
        
        dllist_push_back(list, pub);
    }
    
    if (filename) {
        fclose(fp);
    }
}

void print_table(const char* filename, dllist* list) { 
    FILE* fp;
    
    if (filename) {
        fp = fopen(filename, "w");
        if (!fp) {
            printf("Error opening file for writing: %s\n", filename);
            return;
        }
    } else {
        fp = stdout;
    }
    
    fprintf(fp, "┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐\n");
    fprintf(fp, "│ %-30s │ %-15s │ %-10s │ %-25s │ Year │ Vol │ RINC │ Pages │ Cit │\n",
            "Title", "Author", "Initials", "Journal");
    fprintf(fp, "├─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤\n");
    
    node* current = list->head;
    while (current) {
        fprintf(fp, "│ %-30.30s │ %-15.15s │ %-10.10s │ %-25.25s │ %4d │ %3d │ %4s │ %5d │ %3d │\n",
                current->data->title,
                current->data->author_lastname,
                current->data->author_initials,
                current->data->journal,
                current->data->year,
                current->data->volume,
                current->data->is_rinc ? "YES" : "NO",
                current->data->pages,
                current->data->citations);
        current = (node *)current->next;
    }
    
    fprintf(fp, "└─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
    
    if (filename) {
        fclose(fp);
    }
}