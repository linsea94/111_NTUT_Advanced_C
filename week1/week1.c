#include <stdio.h>
#include <stdbool.h>

int main()
{
  char unsorted[100];
  int inversions = 0;
  int total = 0;
  printf("Please input a character sequence: ");
  scanf("%100s", &unsorted);

  for (int i =0; i<100; i++)
  {
    if (unsorted[i] == false)
    {
      break;
    }
    
    for(int j = i+1; j<100; j++)
    {
      if (unsorted[j] == false)
      {
        break;
      }
      else
      {
        if (unsorted[i] > unsorted[j])
        {
          inversions ++;
        }
        
      }
    }
  }

  printf("number of inversions:%2d",inversions);

}