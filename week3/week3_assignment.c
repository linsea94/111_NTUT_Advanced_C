#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct num_list
{
  int counts;
  int *p_list;
}tNumList;

void bubble_sort(tNumList *list, int lst_num);
void merge(tNumList *list1, tNumList *list2);
void swap(int *a, int *b);

int main()
{
  tNumList *lst1;
  tNumList *lst2;
  int *head1;
  int *head2;
  lst1 = (tNumList *) malloc (sizeof(tNumList));
  lst2 = (tNumList *) malloc (sizeof(tNumList));

  printf("Please enter how many numbers in list1:");
  scanf(" %d", &(lst1->counts));
  lst1->p_list = (int *) malloc (sizeof(int) * lst1->counts); 
  printf("\tPlease input %d numbers: ", lst1->counts);
  for(int i = 0; i < lst1->counts; i++)
  {
    scanf(" %d", lst1->p_list+i);
  }
  head1 = lst1->p_list;

  printf("Please enter how many numbers in list2: ");
  scanf(" %d", &(lst2->counts));
  lst2->p_list = (int *) malloc (sizeof(int) * lst2->counts); 
  printf("\tPlease input %d numbers: ", lst2->counts);
  for(int i = 0; i < lst2->counts; i++)
  {
    scanf(" %d", lst2->p_list+i);
  }
  head2 = lst2->p_list ;

  printf("\n");
  bubble_sort(lst1, 1);
  bubble_sort(lst2, 2);

  merge(lst1, lst2);

  return 0;
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubble_sort(tNumList *list, int lst_num)
{
  int len = list->counts;
  while (len > 1)
  {
    for(int i = 0; i < (list->counts-1); i++)
    {
      while(*(list->p_list + i) > *(list->p_list + i+1))
      {
        swap(list->p_list + i, list->p_list+ i+1);
    }
      }
    len --;
  }
  if(lst_num == 0)
  {
    printf("merged list:");
    for(int i = 0; i < list->counts; i++)
    {
      printf(" %d",*(list->p_list + i));
    }
    printf("\n");
  }
  else
  {
    printf("sorted list%d:", lst_num);
    for(int i = 0; i < list->counts; i++)
    {
      printf(" %d",*(list->p_list + i));
    }
    printf("\n");
  }
}

void merge(tNumList *list1, tNumList *list2)
{
  tNumList *merge_lst;
  tNumList *head;
  merge_lst = (tNumList *) malloc (sizeof(tNumList));
  merge_lst->counts = list1->counts + list2->counts;
  head = merge_lst;

  merge_lst->p_list = list1->p_list;
  for(int i = 0; i < list2->counts; i ++)
  {
    *(merge_lst->p_list + (list1->counts+i)) = *(list2->p_list + i);
  }
  bubble_sort(merge_lst, 0);
  printf("\n");

}