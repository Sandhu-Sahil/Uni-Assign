#include<stdio.h>

int main(void)
{
    int a, b;
    printf("Input two integers : \n");
    scanf("%i",&a);
    scanf("%i",&b);

    if (a > b)
    {
        printf("%i is greater",a);
    }
    else if (a == b)
    {
        printf("%i is equal to %i", a,b);
    }
    else
    {
        printf("%i is greater",b);
    }
        

}