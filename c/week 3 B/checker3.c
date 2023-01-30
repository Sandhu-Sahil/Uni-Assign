#include<stdio.h>

int main(void)
{
    int a;
    printf("Input an integer :");
    scanf("%i",&a);

    if (a % 2 == 0)
    {
        printf("integer is even");
    }
    else
    {
        printf("integer is odd");
    }
}