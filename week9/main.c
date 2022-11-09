#include <stdio.h>
#include "main.h"

int main(void)
{
    int i;
    tNumStorHead *list;
    list = (tNumStorHead *)malloc(sizeof(tNumStorHead));
    initial_list(list);
    get_input(list);
}

void get_input(tNumStorHead *list)
{
    int input_ad = 0;
    while (1)
    {
        printf("1. Add a number or 2. Delete a number: ");
        scanf(" %d", &input_ad);
        if (input_ad == 1) // if input == 2 go delete_num
        {
            process_add(list);
        }
        else if (input_ad == 2)
        {
            process_delete(list);
        }
        else
        {
            printf("No Such choose!\n");
        }
    }
}

void process_add(tNumStorHead *list)
{
    int num, loc, choice;

    get_input_add(list->counts, &num, &loc, &choice);
    node_add(list, num, loc, choice);
    print_list(list);
}

void process_delete(tNumStorHead *list)
{
    int loc, choice;

    get_input_del(list->counts, &loc);
    node_del(list, loc);
    print_list(list);
}

void get_input_add(int cnt, int *num, int *loc, int *choice)
{
    printf("Add a number: ");
    scanf(" %d", num);

    if (cnt == 0)
    {
        *loc = 0;
        *choice = 0;
        return;
    }

    printf("Specify a target location: ");
    scanf(" %d", loc);
    if (*loc > cnt || *loc < 1)
    {
        *loc = 0;
        *choice = 0;
        return;
    }

    printf("1.Before or 2. After the location %d: ", *loc);
    scanf(" %d", choice);

    if (*choice > 2 || *choice < 1)
    {
        *choice = 0;
    }
}

void get_input_del(int cnt, int *loc)
{
    if (cnt < 1)
    {
        *loc = -1;
        return;
    }

    printf("Specify a target location: ");
    scanf(" %d", loc);
    if (*loc > cnt || *loc < 1)
    {
        *loc = 0;
    }
}