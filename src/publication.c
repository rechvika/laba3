#include "publication.h"

static const char* titles[] = { 
    "Исследование алгоритмов",
    "шишки в неволе",
    "Белки в колесе",
    "Мечта о тесте",
    "Успешный успех",
    "Губка Боб против Патрика",
    "Смешарики против малышариков",
    "медведи на охоте",
    "математический анализ для тупых",
    "Хомяк заперт"};

static const char* lastnames[] = {
    "Иванов",
    "Соколов",
    "Попов",
    "Васнецов",
    "Антонов",
    "Васильев",
    "Аллигаторов",
    "Луников",
    "Кузнецов",
    "Гусенков",
};

static const char* initials[] = {
    "А.А.",
    "Р.Р",
    "Т.Т",
    "Е.Е",
    "К.К",
    "Д.Д",
    "В.В",
    "К.К",
    "Х.Х",
    "З.З",
};

static const char* journals[] = {
    "шишка",
    "белка",
    "шаурма",
    "медведь",
    "единорог",
    "фламинго",
    "птица",
    "волк",
    "свинья",
    "лиса"
};

void publication_print(const publication* pub) { 
    printf("Заголовок: %s\n", pub->title);
    printf("Автор: %s %s\n", pub->author_lastname, pub->author_initials);
    printf("Журнал: %s\n", pub->journal);
    printf("Год: %d, Том: %d\n", pub->year, pub->volume);
    printf("RINC: %s\n", pub->is_rinc ? "YES" : "NO");
    printf("Страницы: %d, Цитирования: %d\n", pub->pages, pub->citations);
}

int publication_compare_asc(const publication* pub_1, const publication* pub_2) {        

    int title_cmp = strcmp(pub_1->title, pub_2->title);           
    if (title_cmp != 0) {
        return title_cmp;
    }

    int authorln_cmp = strcmp(pub_1->author_lastname, pub_2->author_lastname);           
    if (authorln_cmp != 0) {
        return authorln_cmp;
    }
    
    int authorin_cmp = strcmp(pub_1->author_initials, pub_2->author_initials);           
    if (authorin_cmp != 0) {
        return authorin_cmp;
    }
    
    int journal_cmp = strcmp(pub_1->journal, pub_2->journal);           
    if (journal_cmp != 0) {
        return journal_cmp;
    }

    if (pub_1->year != pub_2->year) {
        return pub_1->year - pub_2->year;
    }

    if (pub_1->volume != pub_2->volume) {
        return pub_1->volume - pub_2->volume;
    }

    if (pub_1->pages != pub_2->pages) {
        return pub_1->pages - pub_2->pages;
    }
    return 0;
}

int publication_compare_desc(const publication* pub_1, const publication* pub_2) { 
    return -publication_compare_asc(pub_1, pub_2);
}

publication* publication_generate_random(publication* pub) { 
    strcpy(pub->title, titles[rand() % 10]);  
    strcpy(pub->author_lastname, lastnames[rand() % 10]);
    strcpy(pub->author_initials, initials[rand() % 10]);
    strcpy(pub->journal, journals[rand() % 10]);
    pub->year = 2000 + rand() % 25;
    pub->volume = 1 + rand() % 50;
    pub->is_rinc = (rand() % 2) == 1;
    pub->pages = 5 + rand() % 50;
    pub->citations = rand() % 1000;
    
    return pub;
}