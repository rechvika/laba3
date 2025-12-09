#ifndef PUBLICATION_H
#define PUBLICATION_H

#define MAX_STRING_LENGTH 100
#define MAX_INITIALS_LENGTH 10

typedef struct {
    char title[MAX_STRING_LENGTH];
    char lastname[MAX_STRING_LENGTH];
    char author_initials[MAX_INITIALS_LENGTH];
    char journal_name[MAX_STRING_LENGTH];
    int year;
    int volume;
    int is_rinc;
    int num_pages;
    int num_citations;
} Publication;

void publication_print(const Publication* pub);
int publication_compare_asc(const Publication* pub_1, const Publication* pub_2);
int publication_compare_desc(const void* a, const void* b);
Publication publication_generate_random();

#endif