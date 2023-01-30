#include<stdio.h>

int main(void)
{
    float a;
    printf("Input Diatance in km :\n");
    scanf("%f",&a);

    printf("The distance between two cities is %f km\n",a);
    printf("The distance between two cities is %f m\n",a * 1000);
    printf("The distance between two cities is %f ft\n",a * 3280.8);
    printf("The distance between two cities is %f in\n",a * 39370.078740157);
    printf("The distance between two cities is %f cm\n",a * 100000);
}