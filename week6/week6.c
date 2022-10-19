#include <stdio.h>
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


void sort_list(tNumStorHead *list, int input);
void get_input(tNumStorHead *list);
void initial_list(tNumStorHead *list);
void print_list(tNumStorHead *list);
void delete_last(tNumStorHead *list);


int main (void)
{
    int i;
    tNumStorHead *list;
    list = (tNumStorHead *) malloc (sizeof(tNumStorHead));
    initial_list(list);
    get_input(list);
}

//when input larger then num input will be the next of and the origin next of will be the new next 

void sort_list(tNumStorHead *list, int input)
{
  tNumStorage *new;
  tNumStorage *node_ptr = list->head;
  int flag = 0;
  new = (tNumStorage *) malloc (sizeof(tNumStorage));
  new->number = input;
  new->next = NULL;

  if (list->counts == 0)        //if count = 0 set the first input
  {
    list->head->number = input;
    list->head->next = NULL;
    list->head->prev = NULL;
    list->tail = list->head;
  }

  else if(input <= node_ptr->number)  //if input smaller than head
  {
    printf("head flag \n");
    new->next = node_ptr;
    list->head = new;
    list->head->next->prev = list->head;
  }

  else if (input >= list->tail->number) //if input greater than tail
  {
    printf("tail flag \n");
    list->tail->next = new;
    new->prev = list->tail;
    list->tail = new;

  }

  else
  {
    while (node_ptr != NULL)
    {
      if(input >= node_ptr->number && input < node_ptr->next->number) //if input greater than prev and smaller than next
      {
        printf("mid flag\n");
        new->next = node_ptr->next;
        new->prev = node_ptr;
        new->next->prev = new;
        node_ptr->next = new;
        break;
      }
      node_ptr = node_ptr->next;
    }
  }
  
  list->counts ++;
  print_list(list);             //after inserting the input, print it
  
}

void get_input(tNumStorHead *list)
{
  int input = 0;
  list->head = (tNumStorage *) malloc (sizeof(tNumStorage));
  list->tail = (tNumStorage *) malloc (sizeof(tNumStorage));
  while(input != -1)
  {
    printf("Input a number (-1 to exit, -2 to delete last): ");
    scanf(" %d", & input);

    if(input == -2)           //if input == -2 go delete_last
    {
      delete_last(list);
    }
    else if(input != -1)
    {
      sort_list(list, input);  
    }
  }
}

void delete_last(tNumStorHead *list)
{
  printf("delete flag\n");
  if(list->counts > 1)                  //when count > 1 just derectly delete tail
  {
    list->counts--;
    list->tail->prev->next = NULL;
    list->tail = list->tail->prev;
    print_list(list);
  }
  else if (list->counts == 1)           //when count = 1 derectly call initial_list
  {
    initial_list(list);
    print_list(list);
    list->head = (tNumStorage *) malloc (sizeof(tNumStorage));
    list->tail = (tNumStorage *) malloc (sizeof(tNumStorage));
  }
  else
  {
    printf("There is nothing to delete\n\n"); 
  }
}

// from prof.
void initial_list(tNumStorHead *list)
{
    list->counts = 0;
    list->head = NULL;
    list->tail = NULL;
}

//from prof.
void print_list(tNumStorHead *list)
{
    tNumStorage *node_ptr = list->head;
    printf("  list->counts: %d\n", list->counts);
    printf("  The sorted list: ");
    while (node_ptr != NULL)
    {
        printf("%d ", node_ptr->number);
        node_ptr = node_ptr->next;
    }
    printf("\n\n");
}