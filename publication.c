#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "publication.h"


static const char* titles[] = {
    "Research on Algorithms",
    "cones in captivity",
    "squirrels in the wheel",
    "The dream of a test",
    "successful success",
    "SpongeBob vs Patrick",
    "smeshariki vs malyshariki",
    "bears on the hunt",
    "matanalysis for the stupid",
    "The hamster is locked up"};

static const char* lastnames[] = {
    "Ivanov",
    "Sokolov",
    "Popov",
    "Vasnetsov",
    "Antonov",
    "Vasiliev",
    "Aligatorov",
    "Lunikov",
    "Kuznetsov",
    "Gusenkov", 
};

static const char* initials[] = {
    "A.A.",
    "R.R",
    "T.T",
    "E.E",
    "Q.Q",
    "D.D",
    "V.V",
    "C.C",
    "X.X",
    "Z.Z",
};

static const char* journals[] = {
    "cone",
    "squirrel",
    "shawarma",
    "bear",
    "unicorn",
    "flamingo",
    "bird",
    "wolf",
    "pig",
    "fox"
};

void publication_print(const Publication* pub) {
    printf("Title: %s\n", pub->title);
    printf("Author: %s %s\n", pub->author_lastname, pub->author_initials);
    printf("Journal: %s\n", pub->journal);
    printf("Year: %d, Volume: %d\n", pub->year, pub->volume);
    printf("RINC: %s\n", pub->is_rinc ? "YES" : "NO");
    printf("Pages: %d, Citations: %d\n", pub->pages, pub->citations);
}

int publication_compare_asc(const Publication* pub_1, const Publication* pub_2) {
    

    int author_cmp = strcmp(pub_1->author_lastname, pub_2->author_lastname);
    if (author_cmp != 0) return author_cmp;
    
    if (pub_1->year != pub_2->year) return pub_1->year - pub_2->year;
    

    return strcmp(pub_1->title, pub_2->title);
}

int publication_compare_desc(const Publication* pub_1, const Publication* pub_2) {
    return -publication_compare_asc(pub_1->title, pub_2->title);
}

Publication publication_generate_random() {
    Publication pub;

    strcpy(pub.title, titles[rand() % 10]);
    strcpy(pub.author_lastname, lastnames[rand() % 10]);
    strcpy(pub.author_initials, initials[rand() % 10]);
    strcpy(pub.journal, journals[rand() % 10]);
    pub.year = 2000 + rand() % 25;
    pub.volume = 1 + rand() % 50;
    pub.is_rinc = (rand() % 2) == 1;
    pub.pages = 5 + rand() % 50;
    pub.citations = rand() % 1000;
    
    return pub;
}