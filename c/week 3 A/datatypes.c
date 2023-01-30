#include<stdio.h>

int main(void)
{
    int a = 22;
    int b = 7;
    int c = a / b;

    printf("integer = %i\n",c);
    printf("float = %f\n",(float)c);
    printf("double = %lf\n",(double)c);

    char d = 'c';
    printf("char = %c\n",d);
}