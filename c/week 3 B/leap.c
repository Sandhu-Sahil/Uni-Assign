#include<stdio.h>

int main(void)
{
    int a;
    printf("Enter year :");
    scanf("%i",&a);

    if (a % 4 == 0)
    {
        if (a % 100 == 0)
        {
            if (a % 400 == 0)
            {
                printf("This is a leap year");
            }
            else
            {
                printf("This is not a leap year");
            }
        }
        else
        {
            printf("This is a leap year");
        }
    }
    else
    {
        printf("This is not a leap year");
    }
}