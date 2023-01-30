#include<stdio.h>

int main(void)
{
    int a;
    printf("Input an integer :");
    scanf("%i",&a);

    if (a >= 0)
    {
        printf("intger is positive");
    }
    else
    {
        printf("integer is negative");
    }
}