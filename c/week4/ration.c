#include<stdio.h>

int main (void)
{
    int w, x, y, z;
    printf("input 4 integers :\n");
    printf("w :");
    scanf("%i",&w);
    printf("x :");
    scanf("%i",&x);
    printf("y :");
    scanf("%i",&y);
    printf("z :");
    scanf("%i",&z);

    if (x - z == 0)
    {
        printf("undefined");
    }
    else
    {
        printf("%i", (w+y)/(x-z));
    }
}