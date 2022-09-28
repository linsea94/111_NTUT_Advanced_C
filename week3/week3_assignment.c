#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct num_list                                       //def num_list
{
  int counts;
  int *p_list;
}tNumList;

void swap(int *a, int *b);                                    //void function
void bubble_sort(tNumList *list, int lst_num);
void merge(tNumList *list1, tNumList *list2);

int main()
{
  tNumList *lst1;
  tNumList *lst2;
  int *head1;
  int *head2;
  lst1 = (tNumList *) malloc (sizeof(tNumList));              // allocation memory for tNumList
  lst2 = (tNumList *) malloc (sizeof(tNumList));

  printf("Please enter how many numbers in list1:");
  scanf(" %d", &(lst1->counts));                              //scan first list count
  lst1->p_list = (int *) malloc (sizeof(int) * lst1->counts);
  printf("\tPlease input %d numbers: ", lst1->counts);
  for(int i = 0; i < lst1->counts; i++)                       //use for loop to scan the input and 
  {                                                           //place it into lst1->p_list one by one
    scanf(" %d", lst1->p_list+i);
  }
  head1 = lst1->p_list;                                       //make head1 to avoid lost it way

  printf("Please enter how many numbers in list2: ");         
  scanf(" %d", &(lst2->counts));                              //scan second list count
  lst2->p_list = (int *) malloc (sizeof(int) * lst2->counts); 
  printf("\tPlease input %d numbers: ", lst2->counts);
  for(int i = 0; i < lst2->counts; i++)                       //use for loop to scan the input and 
  {                                                           //place it into lst2->p_list one by one
    scanf(" %d", lst2->p_list+i);
  }
  head2 = lst2->p_list;                                       //make head2 to avoid lost it way

  printf("\n");

  bubble_sort(lst1, 1);                                       //call bubble_sort function to arrange the list
  bubble_sort(lst2, 2);                                       //call bubble_sort function to arrange the list

  merge(lst1, lst2);                                          //call merge function to merge two lists

  return 0;
}

void swap(int *a, int *b)                                     //swap the member inside the pointer
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubble_sort(tNumList *list, int lst_num)                 //list_num means the number of list if it is 0
{                                                             //means the merge list
  int len = list->counts;
  while (len > 1)                                             //do the same time as len
  {
    for(int i = 0; i < (list->counts-1); i++)                 //from list->p_list to last one
    {
      while(*(list->p_list + i) > *(list->p_list + i+1))      //if member in list->p_list +i > list->p_list +i+1
      {
        swap(list->p_list + i, list->p_list+ i+1);            //swap them
    }
      }
    len --;
  }
  if(lst_num == 0)                                            //when lst_num == 0 print merged list
  {
    printf("merged list:");
    for(int i = 0; i < list->counts; i++)
    {
      printf(" %d",*(list->p_list + i));
    }
    printf("\n");
  }
  else                                                        //else print the sorted list
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
  merge_lst = (tNumList *) malloc (sizeof(tNumList));                 //memory allocation of merge_lst  
  merge_lst->counts = list1->counts + list2->counts;
  head = merge_lst;                                                   //make head2 to avoid lost it way

  merge_lst->p_list = list1->p_list;                                  //fisrt part of merge_lst is equal the list 1
  for(int i = 0; i < list2->counts; i ++)                             //put the second part which is the list 2
  {                                                                   //one by one
    *(merge_lst->p_list + (list1->counts+i)) = *(list2->p_list + i);
  }
  bubble_sort(merge_lst, 0);                                          //after merge list1 and list2 do the bubble_sort
  printf("\n");

}