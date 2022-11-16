#include <stdio.h>

typedef unsigned int Int32;
Int32 input; /*example:  Int32 input = 0x22334455*/
Int32 high;  /*max value = 31*/
Int32 low;   /*min value = 0*/

int CheckRangeLoop(Int32 input, Int32 high, Int32 low);
int CheckRangeNoLoop(Int32 input, Int32 high, Int32 low);

#define TEST_BIT(target, bit) \
    ((target >> bit) & (0x01))

int main(void)
{
    while (1)
    {
        printf("Please specify the input: ");
        scanf(" %i", &input);
        if (input > 0xffffffff || input < 0)
        {
            printf("Input wrong num");
        }

        printf("\tPlease specify the high: ");
        scanf(" %i", &high);
        if (high > 32)
        {
            printf("\tThe high should smaller than 32!\n");
            continue;
        }
        else if (high < 0)
        {
            printf("\tThe high should be positive!\n");
            continue;
        }

        printf("\tPlease specify the low: ");
        scanf(" %i", &low);

        if (high < low)
        {
            printf("\tThe high should greater than the low!\n");
            continue;
        }

        printf("Input :0x%08x\n", input);
        printf("high :%i\n", high);
        printf("low :%i\n", low);

        int ans;
        ans = CheckRangeLoop(input, high, low);
        printf("CheckRangeLoop result: %d\n", ans);
        ans = CheckRangeNoLoop(input, high, low);
        printf("CheckRangeNoLoop result: %d\n\n\n", ans);
    }
}

int CheckRangeLoop(Int32 input, Int32 high, Int32 low)
{
    Int32 set = 1;
    int result = 0;

    for (int i = low; i <= high; i++)
    {
        Int32 target = input;
        int test = 0;
        test = TEST_BIT(target, i);
        result = result | test;
        if (result > 0)
        {
            return 1;
        }
    }
    return 0;
}

int CheckRangeNoLoop(Int32 input, Int32 high, Int32 low)
{
    Int32 target = input;
    Int32 test_lst = 0xffffffff;
    Int32 high_lst = test_lst >> (31 - high);
    Int32 low_lst = test_lst << low;
    test_lst = high_lst & low_lst;

    if (test_lst > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}