#include <stdio.h>

int a = 10; // global variable

int localVariable();

int main(void)
{
    printf("a = %i",a);
    // printf("b = %i",b);
}

int localVariable()
{
    int b = 20;
}