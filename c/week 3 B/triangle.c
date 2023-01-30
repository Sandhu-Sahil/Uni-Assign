#include<stdio.h>

int main(void)
{
    int a, b, c;
    printf("Input sides of triangle:\n");
    scanf("%i",&a);
    scanf("%i",&b);
    scanf("%i",&c);

    if (a == b && b == c)
    {
        printf("This is equilateral triangle");
    }
    else if ((a == b && b != c) || (a != b && b == c) || (a == c && b != c))
    {
        printf("This is isosceles triangle");
    }
    else
    {
        printf("This is scalene triangle");
    }
}