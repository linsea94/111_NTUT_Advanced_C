#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int Hex2Dec (char *x)
{
    int num1, num2, total;
    memmove(&x[0],&x[1], 3); //delete first bit
    // extract each bit
    num1 = x[0];
    num2 = x[1];
    // the string is ascii, and the hex only contain 0~9 & a~f
    // 48~57 means 0~9, 65~70 means A~F, 97~102 means a~f
    if (num1 >=48 & num1 <= 57 )
    {
        num1 -= 48;
    }
    else if (num1 >=65 & num1 <= 70 )
    {
        num1 -=55;
    }
    else if (num1 >=97 & num1 <= 102 )
    {
        num1 -=87;
    }
    else
    {
        printf("wrong input!\n");
        return -1;
    }
    if (num2 >=48 & num2 <= 57 )
    {
        num2 -= 48;
    }
    else if (num2 >=65 & num2 <= 70 )
    {
        num2 -=55;
    }
    else if (num2 >=97 & num2 <= 102 )
    {
        num2 -=87;
    }
    else
    {
        printf("wrong input!\n");
        return -1;
    }
    total = num1 * 16 + num2;
    return total;
}
int Binary2Dec (char *x)
{
    int num1, num2, num3, num4, total;
    memmove(&x[0],&x[1], 5);
    // extract each bit
    num1 = x[0]-48;
    num2 = x[1]-48;
    num3 = x[2]-48;
    num4 = x[3]-48;
    if (num1 >1 || num2 >1 || num3>1 || num4>1)
    {
        printf("wrong input!\n");
        return -1;
    }
    
    total = num1 * 8 + num2 * 4 + num3 * 2 + num4;
    return total;
}

void PrintFunction(char *buf, int(*func)(char *))
{
    int result;
    result = func( buf);
    if (result == -1)
    {
        return;
    }
    printf("the decimal is : %d \n", result);
}

int main (void)
{
    int flag;
    int (*func[2]) (char *x) = {Hex2Dec, Binary2Dec};
    char *buf = (char *) malloc (sizeof(char)* 5) ;
    while (1)
    {
        printf("  Please enter a string as hxx or bxxxx: ");
        scanf(" %s", buf);
        
        if (buf[0]=='h')
        {
            flag = 0;
            if (strlen(buf) > 3)
            {
                printf("wrong input!\n");
                continue;
            }
            
        }
        else if(buf[0]=='b')
        {
            flag = 1;
            if (strlen(buf)>5)
            {
                printf("wrong input!\n");
                continue;
            }
            
        }
        else
        {
            printf("wrong input!\n");
            continue;
        }

        PrintFunction(buf, func[flag]);
    }
}
