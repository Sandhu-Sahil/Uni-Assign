#include<stdio.h>

int main(void)
{
    float a, b, c;

    printf("Input length of rectangle :\n");
    scanf("%f",&a);
    printf("Input breadth of rectangle :\n");
    scanf("%f",&b);
    printf("Input radius of circle :\n");
    scanf("%f",&c);

    printf("Area of rectangle = %f\n",a*b);
    printf("Perimeter of rectangle = %f\n",(2*a)+(2*b));
    
    float d = 22;
    float e = 7;
    float pie = d / e; 
    printf("Area of circle = %f\n",pie * c * c);
    printf("Circumference of circle = %f", 2 * pie * c);
}