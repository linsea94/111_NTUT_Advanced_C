#include "stack.h"

tStack *create_stack(void)
{
    tStack *stack_ptr = (tStack *)malloc(sizeof(tStack));
    stack_ptr->count = 0;
    stack_ptr->head = NULL;
    return stack_ptr;
}

void handle_push_operation(tStack *stack_ptr)
{
    int cnt = &stack_ptr->count;
    int score;
    tNode *ptr = stack_ptr->head;
    tNode *new;
    tTypeScore **pp_score;
    if (cnt == N)
    {
        printf("[Error]  handle_push_operation(): space full \n");
        return;
    }

    printf("  handle_push_operation(): enter score value: ");
    scanf(" %d", &score);

    printf("flag\n");
    get_score_space(*pp_score, score, cnt);
    new->data_ptr = pp_score;
    new->next = NULL;

    if (cnt == 0)
    {
        stack_ptr->head = new;
    }
    else
    {
        while (ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = new;
    }
    return;
}

void handle_pop_operation(tStack *stack_ptr)
{
    int cnt = &stack_ptr->count;
    if (cnt == 0)
    {
        printf("[Error]  handle_pop_operation(): nothing in stack = \n");
    }

    tNode *ptr = stack_ptr->head;
    while (ptr->next)
    {
        ptr = ptr->next;
    }
    int value, loc;
    value = ptr->data_ptr->score;
    loc = ptr->data_ptr->loc;
    printf("  handle_pop_operation(): poped value: %d\n", value);
    return_score_space(loc);
    ptr = NULL;
}

void print_stack_content(tStack *stack_ptr)
{
    tNode *ptr = stack_ptr->head;
    printf("   print_stack_content(): stack items -> ");
    while (ptr)
    {
        printf(" %d(%d)", &ptr->data_ptr->score, &ptr->data_ptr->loc);
        if (ptr->next)
        {
            ptr = ptr->next;
        }
        else
        {
            break;
        }
    }
}
