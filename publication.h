#ifndef PUBLICATION_H
#define PUBLICATION_H


#define MAX_STRING_LENGTH 100
#define MAX_INITIALS_LENGTH 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char title[MAX_STRING_LENGTH];
    char author_lastname[MAX_STRING_LENGTH];
    char author_initials[MAX_INITIALS_LENGTH];
    char journal[MAX_STRING_LENGTH];
    int year;
    int volume;
    int is_rinc;
    int pages;
    int citations;
} Publication;

void publication_print(const Publication* pub);
int publication_compare_asc(const Publication* pub_1, const Publication* pub_2);
int publication_compare_desc(const Publication* a, const Publication* b);
Publication* publication_generate_random(Publication* pub);

#endif