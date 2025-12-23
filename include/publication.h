#pragma once

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
    unsigned short year;
    unsigned short volume; 
    unsigned short is_rinc;
    unsigned short pages;
    unsigned short citations;
} publication;

void publication_print(const publication* pub);
int publication_compare_asc(const publication* pub_1, const publication* pub_2);
int publication_compare_desc(const publication* pub_1, const publication* pub_2);
publication* publication_generate_random(publication* pub);

