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


void get_input(tNumStorHead *list);
void add_num(tNumStorHead *list);
void delete_num(tNumStorHead *list);
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
void get_input(tNumStorHead *list)
{
  int input_ad, input_num, input_loc = 0;
  list->head = (tNumStorage *) malloc (sizeof(tNumStorage));
  list->tail = (tNumStorage *) malloc (sizeof(tNumStorage));
  while(1)
  {
    printf("1. Add a number or 2. Delete a number: ");
    scanf(" %d", & input_ad);
    if(input_ad == 2)           //if input == -2 go delete_num
    {
      delete_num(list);
    }
    else if(input_ad == 1)
    {
      add_num(list);
    }
    else
    {
      printf("No Such choose!\n");
    }
  }
}

void add_num(tNumStorHead *list)
{
  int input, loc, BA = -999;
  tNumStorage *new;
  tNumStorage *node_ptr = list->head;
  new = (tNumStorage *) malloc (sizeof(tNumStorage));
  printf("Add a number: ");
  scanf(" %d", &input);
  new->number = input;
  new->prev = NULL;
  new->next = NULL;

  if(list->counts == 0)          //input as head and tail
  {
    list->head->number = input;
    list->head->next = NULL;
    list->head->prev = NULL;
    list->tail = list->head;
  }
  else
  {
    printf("Specify a target location: ");
    scanf(" %d", &loc);
    printf("1.Before or 2. After the location %d: ", loc);
    scanf(" %d", &BA);
    if (loc == 1 && BA == 1)                  // insert as head
    {
      printf("head flag \n");
      new->next = list->head;
      list->head->prev = new;
      list->head = new;
    }
    else if (loc == list->counts && BA == 2)   // insert as tail
    {
      printf("tail flag \n");
      list->tail->next = new;
      new->prev = list->tail;
      list->tail = new;
    }
    else                                        // between head and tail
    {
      printf("mid flag\t");
      for (int i = 1; i < loc; i++)
      {
        node_ptr = node_ptr->next;
      }
      if (BA == 1)
      {
        printf("Before\n");
        tNumStorage *prev_ptr = node_ptr->prev;
        new->next = node_ptr;
        new->prev = prev_ptr;
        prev_ptr->next = new;
        node_ptr->prev = new;
      }
      else
      {
        printf("After\n");
        tNumStorage *next_ptr = node_ptr->next;
        new->next = next_ptr;
        new->prev = node_ptr;
        next_ptr->prev = new;
        node_ptr->next = new;
      }
    }
  }
  
  list->counts ++;
  print_list(list);             //after inserting the input, print it
  
}

void delete_num(tNumStorHead *list)
{
  int loc= 0;
  tNumStorage *target;
  tNumStorage *node_ptr = list->head;
  printf("Specify a target location: ");
  scanf(" %d", &loc);

  printf("delete flag\n");

  if(list->counts <= 1)
  {
    initial_list(list);
    print_list(list);
    list->head = (tNumStorage *) malloc (sizeof(tNumStorage));
    list->tail = (tNumStorage *) malloc (sizeof(tNumStorage));
    return;
  }
  else if(loc == 1)                    //delete head
  {
    target = node_ptr;
    list->head = node_ptr->next;
    list->head->prev = NULL;
  }
  else if (loc == list->counts)   //delete tail
  {
    target = list->tail;
    list->tail = list->tail->prev;
    list->tail->next =NULL;
  }
  else                            //delete the mid location
  {
    for (int i = 1; i < loc; i++)
    {
      node_ptr = node_ptr->next;
    }
    tNumStorage *prev_ptr = node_ptr->prev;
    tNumStorage *next_ptr = node_ptr->next;
    target = node_ptr;
    prev_ptr->next = next_ptr;
    next_ptr->prev = prev_ptr;
  }

  free(target);
  list->counts --;
  print_list(list);
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
    printf("  from head --> ");
    while (node_ptr != NULL)
    {
        printf("%d ", node_ptr->number);
        node_ptr = node_ptr->next;
    }
    printf("\n");
    node_ptr = list->tail;
    printf("  from tail --> ");
    while (node_ptr != NULL)
    {
        printf("%d ", node_ptr->number);
        node_ptr = node_ptr->prev;
    }
    printf("\n\n");
}