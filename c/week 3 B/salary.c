#include<stdio.h>

int main(void)
{
    int a;
    printf("Input basic salary : ");
    scanf("%i",&a);

    int b;
    if (a <= 10000)
    {
        b = a + (a * 0.2) + (a * 0.8);
    }
    else if (a > 10000 && a <= 20000)
    {
        b = a + (a * 0.25) + (a * 0.9);
    }
    else if (a > 20000)
    {
        b = a + (a * 0.3) + (a * 0.95);
    }

    printf("The grass salary is : %i",b);
}