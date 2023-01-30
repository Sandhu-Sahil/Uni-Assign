#include<stdio.h>

int main (void)
{
    int a, b, c, d, e;
    printf("Input marks in 5 subjects:\n");
    scanf("%i",&a);
    scanf("%i",&b);
    scanf("%i",&c);
    scanf("%i",&d);
    scanf("%i",&e);

    printf("Aggregated marks = %i / 500\n",a+b+c+d+e);
    printf("Percentage = %f",(float)(a+b+c+d+e) / 5);

}