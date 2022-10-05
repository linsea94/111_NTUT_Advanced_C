#include <stdio.h>
#include <stdlib.h>

typedef struct num_storage
{
    int number;
    struct num_storage *next;
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

  if(input <= node_ptr->number)
  {
    printf("flag 1\n");
    new->next = node_ptr;
    list->head = new;
    flag = 1;
  }

  while (node_ptr != NULL)
  {
    if (flag)break;
    if(node_ptr->next!= NULL)
    {
      if(input >= node_ptr->number & input < node_ptr->next->number)
      {
        printf("flag 2\n");
        new->next = node_ptr->next;
        node_ptr->next = new;
        break;
        printf("node num: %d > input: %d\n",node_ptr->number, input);
      }
    }
    else if(input >= node_ptr->number)
    {
      printf("flag 3\n");
      node_ptr->next = new;
      list->tail = new;
      break;
    }
    node_ptr = node_ptr->next;
  }
}

void get_input(tNumStorHead *list)
{
  int input = 0;

  list->head = (tNumStorage *) malloc (sizeof(tNumStorage));
  list->tail = (tNumStorage *) malloc (sizeof(tNumStorage));
  while(1)
  {
    printf("Input a number: ");
    scanf(" %d", & input);
    if(input != -1){
      if (list->counts == 0)        //if count = 0 set the first input
      {
        list->head->number = input;
        list->head->next = NULL;
        list->tail = list->head;
      }
      else
      {
        sort_list(list, input);     //if count != 0 call sort_list function to insert the input
      }
      list->counts ++;
      print_list(list);             //after insert the input print it
    }
    else                            //if input == -1 break the loop
    {
      break;
    }
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