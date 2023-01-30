#include<stdio.h>

int main(void)
{
    int a[3], b = 0;
    printf("Input three integers :\n");
    for (int i = 0; i < 3; i++)
    {
        scanf("%i", &a[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        if (a[i] > b)
        {
            b = a[i];
        }
    }
    printf("%i is the greatest", b);
}