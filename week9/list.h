#include <stdlib.h>

typedef struct num_storage
{
    int number;
    struct num_storage *next;
    struct num_storage *prev;
} tNumStorage;

typedef struct num_stor_head
{
    int counts;
    struct num_storage *head;
    struct num_storage *tail;
} tNumStorHead;

void node_add(tNumStorHead *list, int num, int loc, int choice);
void node_del(tNumStorHead *list, int loc);
void initial_list(tNumStorHead *list);
void print_list(tNumStorHead *list);