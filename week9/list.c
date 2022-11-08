#include "list.h"
#include <stdio.h>


void node_add(tNumStorHead *list, int num, int loc, int choice)
{
  tNumStorage *new;
  tNumStorage *node_ptr = list->head;
  new = (tNumStorage *) malloc (sizeof(tNumStorage));
  new->number = num;
  new->prev = NULL;
  new->next = NULL;

  if(list->counts == 0)          //input as head and tail
  {
    list->head = (tNumStorage *) malloc (sizeof(tNumStorage));
    list->tail = (tNumStorage *) malloc (sizeof(tNumStorage));
    list->head->number = num;
    list->head->next = NULL;
    list->head->prev = NULL;
    list->tail = list->head;
  }

  else if (loc == 0)              //loc > cnt || loc < 1
  {
    printf("Please enter the number from 1 to %d\n", list->counts);
    return;
  }

  else if (choice == 0)
  {
    printf("No such choice!\n");
    return;
  }

  else
  {
    if (loc == 1 && choice == 1)                  // insert as head
    {
      // printf("head flag \n");
      new->next = list->head;
      list->head->prev = new;
      list->head = new;
    }

    else if (loc == list->counts && choice == 2)   // insert as tail
    {
      // printf("tail flag \n");
      list->tail->next = new;
      new->prev = list->tail;
      list->tail = new;
    }

    else                                        // between head and tail
    {
      // printf("mid flag\t");
      for (int i = 1; i < loc; i++)
      {
        node_ptr = node_ptr->next;
      }
      if (choice == 1)
      {
        // printf("Before\n");
        tNumStorage *prev_ptr = node_ptr->prev;
        new->next = node_ptr;
        new->prev = prev_ptr;
        prev_ptr->next = new;
        node_ptr->prev = new;
      }
      else
      {
        // printf("After\n");
        tNumStorage *next_ptr = node_ptr->next;
        new->next = next_ptr;
        new->prev = node_ptr;
        next_ptr->prev = new;
        node_ptr->next = new;
      }
    }
  }
  
  list->counts ++;
}

void node_del(tNumStorHead *list, int loc)
{
  tNumStorage *target;
  tNumStorage *node_ptr = list->head;

  if (loc == 0)                     // loc > cnt || loc < 1
  {
    printf("wrong location!");
    return;
  }

  else if (loc == -1)               // cnt < 1
  {
    printf("there is nothing to delete!\n");
    return;
  }

  else if(list->counts == 1)        // cnt == 1
  {
    target = node_ptr;
    initial_list(list);
    list->counts ++;
  }
  else if(loc == 1)                 //delete head
  {
    target = node_ptr;
    list->head = node_ptr->next;
    list->head->prev = NULL;
  }
  else if (loc == list->counts)     //delete tail
  {
    target = list->tail;
    list->tail = list->tail->prev;
    list->tail->next =NULL;
  }
  else                              //delete the mid location
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

}

void initial_list(tNumStorHead *list)
{
    list->counts = 0;
    list->head = NULL;
    list->tail = NULL;
}

void print_list(tNumStorHead *list)
{
    tNumStorage *node_ptr = list->head;
    printf("\n  list->counts: %d\n", list->counts);
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