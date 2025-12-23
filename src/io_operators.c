#include "io_operators.h"

void write_csv(const char* filename, dllist* list) { 
    FILE* fp;
    
    if (filename) {
        fp = fopen(filename, "w");
        if (!fp) {
            write_log(filename);
            return;
        }
    } else {
        fp = stdout;
    }
    
    fprintf(fp, "Название,фамилия автора,инициалы автора,журнал,год,том,rinc,страницы,цитирования\n");
    uint count = size(list);   
    for (uint i = 0; i < count; i++) {
        fprintf(fp, "\"%s\",\"%s\",\"%s\",\"%s\",%s,%s,%s,%s,%s\n",
                publication_get_i(list, i, 1),
                publication_get_i(list, i, 2),
                publication_get_i(list, i, 3),
                publication_get_i(list, i, 4),
                publication_get_i(list, i, 5),
                publication_get_i(list, i, 6),
                publication_get_i(list, i, 7),
                publication_get_i(list, i, 8),
                publication_get_i(list, i, 9));
    }
    if (filename) {
        fclose(fp);
    }
}

void read_csv(const char* filename, dllist* list) { 
    FILE* fp;
    
    if (filename) {
        fp = fopen(filename, "r");
        if (!fp) {
            write_log(filename);
            return;
        }
    } else {
        fp = stdin;
    }
    
    char line_1[LEN_LINE];
    
    if (!fgets(line_1, LEN_LINE, fp)) {
        if (filename) {
            fclose(fp); 
        }
        return;
    }
    char line[LEN_LINE];
    
    while (fgets(line, LEN_LINE, fp)) { 
        publication* pub = malloc(sizeof(publication));
        if (!pub) { 
            continue;
        }
        line[strcspn(line, "\n")] = 0; 
        
        char* token = strtok(line, ","); 
        if (!token){ 
            free(pub);
            continue;
        } 
        if (token[0] == '"') {  
            strncpy(token, token + 1, strlen(token));  
            token[strlen(token) - 1] = 0;
        }
        strncpy(pub->title, token, MAX_STRING_LENGTH - 1); 
        pub->title[MAX_STRING_LENGTH - 1] = '\0'; 
        
        token = strtok(NULL, ","); 
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
        pub->year = strtoul(token, NULL, 10);
  //      if(pub->year == ULONG_MAX || pub->year == NULL){
    //        write_log(filename);
      //      return;
        //}
        
        token = strtok(NULL, ",");
        pub->volume = strtoul(token, NULL, 10);
      //  if(pub->volume == ULONG_MAX || pub->year == NULL){
        //    write_log(filename);
      //      return;
    //    }

        token = strtok(NULL, ",");
        pub->is_rinc = (strcmp(token, "true") == 0 || strcmp(token, "1") == 0);
        
        token = strtok(NULL, ",");
        pub->pages = strtoul(token, NULL, 10);
  //      if(pub->pages == ULONG_MAX || pub->year == NULL){
       //     write_log(filename);
     //       return;
   //     }
        
        token = strtok(NULL, ",");
        pub->citations = strtoul(token, NULL, 10);
 //       if(pub->citations == ULONG_MAX || pub->year == NULL){
    //        write_log(filename);
      //      return;
       // }
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
  //      if (!fp) {
    //        write_log(filename);
      //      return;
        //}
//    } else {
  //      fp = stdout;
}
    
    fprintf(fp, "│ %-30s │ %-15s │ %-10s │ %-25s │ Year │ Vol │ RINC │ Pages │ Cit │\n",
            "Title", "Author", "Initials", "Journal");
    
    uint count = size(list);   
    for (uint i = 0; i < count; i++) {
        fprintf(fp, "│ %-30.30s │ %-15.15s │ %-10.10s │ %-25.25s │ %4s │ %3s │ %4s │ %5s │ %3s │\n",
                publication_get_i(list, i, 1),
                publication_get_i(list, i, 2),
                publication_get_i(list, i, 3),
                publication_get_i(list, i, 4),
                publication_get_i(list, i, 5),
                publication_get_i(list, i, 6),
                publication_get_i(list, i, 7),
                publication_get_i(list, i, 8),
                publication_get_i(list, i, 9));
    }
    if (filename) {
        fclose(fp);
    }
}