#include <stdio.h>

int main(void)
{
    int change = 0;
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
    printf("Input Amount: ");
    scanf("%i",&change);
    if (change >= 500)
    {
        while (change >= 500)
        {
            a++;
            change = change - 500;
        }
    }        
    printf("\n500 : %i \n", a);
    if (change >= 100)
    {
        while (change >= 100)
        {
            b++;
            change = change - 100;
        }
    }
    printf("100 : %i \n", b);
    if (change >= 50)
    {
        while (change >= 50)
        {
            c++;
            change = change - 50;
        }
    }
    printf("50 : %i \n", c);
    if (change >= 20)
    {
        while (change >= 20)
        {
            d++;
            change = change - 20;
        }
    }
    printf("20 : %i \n", d);
    if (change >= 10)
    {
        while (change >= 10)
        {
            e++;
            change = change - 10;
        }
    }
    printf("10 : %i \n", e);
    if (change >= 5)
    {
        while (change >= 5)
        {
            f++;
            change = change - 5;
        }
    }
    printf("5 : %i \n", f);
    if (change >= 2)
    {
        while (change >= 2)
        {
            g++;
            change = change - 2;
        }
    }
    printf("2 : %i \n", g);
    if (change >= 1)
    {
        while (change >= 1)
        {
            h++;
            change = change - 1;
        }
    }
    printf("1 : %i \n", h);
}