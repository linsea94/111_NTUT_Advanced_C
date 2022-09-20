#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* swap the element in two pointer */
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}


int main(int argc, char *argv[])
{
  int *p;
  int input_size, sqrt_size;
  input_size = atoi(*(argv+1));   // input size will be the first number of the comment line
  sqrt_size = sqrt(input_size); //sqrt size means the number of one column or one row
  printf("input size:%2d, sqrt size:%2d\n", input_size, sqrt_size);
  p = (int *) malloc (sizeof(int) * input_size); //setting the dynamic memory allocation

  /* scan the input and use atoi to make char become int at the same time */
  for (int i = 1; i<= input_size; i++){
    *(p+i) = atoi(*(argv+i+1));
  }

  /* print the first serial matrix */
  for (int i = 1; i <= input_size; i++)
  {
    printf("%2d ", *(p+i));
    if(i % sqrt_size == 0) printf("\n");
  }

  printf("\n");

  /* 
   * SWAP THE FIRST COLUMN AND THE THIRD COLUMN
     do swap for the first column and third column,
     where the first column goes from 1 to 4
     and the third column will be the number of first column + (sqrt size *2)
   */ 
  for (int i = 1; i <= sqrt_size; i++)
  {
    swap((p + i), (p + i + (sqrt_size*2)));
  }

  /* 
   * since the element in the pointer already be changed
   * just print the pointer by serial
   */
  for (int i = 1; i <= input_size; i++)
  {
    printf("%2d ", *(p+i));
    if(i % sqrt_size == 0) printf("\n");
  }

  printf("\n");

  /* 
   *  SWAP THE FIRST ROW AND THE THIRD ROW
      do swap for the first row and third row,
      where the first row goes from 1 and add sqrt_size by times
      ex. if sqrt_size is 4, the first row will be 1, (1+4=) 5, (5+4=) 9, (9+4=) 13,
      and the third row will be the number of first row + 2 
   */
  for (int i = 1; i <= input_size; i= i + sqrt_size)
  {
    swap((p + i), (p + i + 2));
  }

  /* 
   since the element in the pointer already be changed
   just print the pointer by serial
   */
  for (int i = 1; i <= input_size; i++)
  {
    printf("%2d ", *(p+i));
    if(i % sqrt_size == 0) printf("\n");
  }
}