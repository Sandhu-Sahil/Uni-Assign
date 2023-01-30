#include<stdio.h>

int main(void)
{
    float a;
    printf("Input temperature in fahrenhiet :\n");
    scanf("%f",&a);

    printf("Temperature in centigrade degrees = %f", (a - 32) / 1.8);
}