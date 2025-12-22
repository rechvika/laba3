# argument_parser.c

- parse_arguments(int argc, char* argv[]) - инициализация по умолчанию
- for (int i = 1; i < argc; i++) - узнаем что пользователю от нас надо 

# dlist.с

- void dllist_init(dllist* list) - начальные данные(когда двусвязный список пуст) 
- int size(dllist* list) - получение размера
- publication* get(dllist* list, int index) - получение элемента по индексуn беззнаков
- node* begin(dllist* list) - получение первого элемента
- node* end(dllist* list) - получение последнего элемента
- void dllist_push_front(dllist* list, publication data) - добавление в начало
- void dllist_push_back(dllist* list, publication data) - добавление в конец
- node* next(node* node) - получение следующего
- node* prev(node* node) - получение предыдущего
- void pop_front(dllist* list) - удаление элемента из начала
- void pop_back(dllist* list) - удаление элемента из конца
- void dllist_clear(dllist* list) - очистка
- void insert(dllist* list, int index, publication data) - добавление элемента в любое место
- void swap(dllist* list, int i, int j) - Обмен местами
- void dllist_from_array(dllist* list, publication* array, int size) - из массива в список
- publication* dllist_to_array(dllist* list) - из списка в массив
- void dllist_remove(dllist* list, int index) - удалкение элемента из произвольного метса
- node* create_node(publication data) - создание новвого узла (для сортировки слиянием)

# io_operators.с

- void write_csv(const char* filename, dllist* list) - запись в файл
- void read_csv(const char* filename, dllist* list) - чтение из файла
- while (fgets(line, sizeof(line), fp)) - читаем из файла и в двусвяззный список
- void print_table(const char* filename, dllist* list) - генерация таблицы

# merge_sort.c

- node* mergesort(node* head) - сортировка слиянием
- node* merge(node* left, node* right) - функция слияния
- node* split(node* head) - деление строки пополам

# publication.c

- void publication_print(const publication* pub) - вывод публикации
- int publication_compare_asc(const publication* pub_1, const publication* pub_2) - компаратор для сравнения по фамилиям, году
/*  1 — если str1 > str2*/ /*0 — если str1 == str2*/ /*-1 — если str1 < str2 */
- int publication_compare_desc(const publication* pub_1, const publication* pub_2) - если нужно отсортировать в обратном порядке
- publication* publication_generate_random(publication* pub) - генерация рандмной публикацииSS