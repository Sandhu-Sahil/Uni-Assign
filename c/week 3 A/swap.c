#include<stdio.h>

int main(void)
{
    int a, b;
    printf("Input 2 integers to swap:\n");
    printf("a = ");
    scanf("%i", &a);
    printf("b = ");
    scanf("%i",&b);
    printf("swaping........\n");

    a = a + b;
    b = a - b;
    a = a - b;

    printf("a = %i\n",a);
    printf("b = %i\n",b);
}