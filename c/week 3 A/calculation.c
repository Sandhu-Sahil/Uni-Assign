#include<stdio.h>

int main(void)
{
    int a, b;
    printf("input 2 integers :\n");
    scanf("%i",&a);
    scanf("%i",&b);

    printf("sum = %i\n", a + b);
    printf("diference = %i\n", a - b);
    printf("multiplication = %i\n", a * b);
    printf("division = %i\n", a / b);
}