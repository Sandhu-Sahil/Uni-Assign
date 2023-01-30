#include<stdio.h>

int main(void)
{
    float a;
    printf("Input number of units :");
    scanf("%f",&a);

    if (a <= 50)
    {
        a = a * 0.50;
    }
    else if (a>50 && a<=150)
    {
        a = (a - 50) * 0.75;
        a = a + (50 * 0.5); 
    }
    else if (a>150 && a<= 250)
    {
        a = (a - 150) * 1.2;
        a = a + (100 * 0.75);
        a = a + (50 * 0.5);
    }
    else if (a>250)
    {
        a = (a - 250) * 1.5;
        a = a + (100 * 1.2);
        a = a + (100 * 0.75);
        a = a + (50 * 0.5);
    }

    a = a + (a * 0.2);
    if (a < 100)
    {
        printf("Minimum amount of bill is 100");
    }
    if (a >= 100)
    {
        printf("Amount of bill is %f",a);
    }
}