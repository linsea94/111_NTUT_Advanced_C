#include "list.h"
#include <stdlib.h>

void get_input(tNumStorHead *list);
void process_add(tNumStorHead *list);
void process_delete(tNumStorHead *list);
void get_input_add(int cnt, int* num, int* loc, int* choice);
void get_input_del(int cnt, int* loc);