#include<stdio.h> 
void main() 
{ 
	float w, c;
	printf("input wire length:");
	scanf("%f",&w);
	printf("input area of cardboard:");
	scanf("%f",&c);
	
	// by manual calculation quadratic eqn of area formed is c-wx/2-2x^2
	// max value by -D/4a = (w^2/32)+c

	float max = ( (w*w) / 32) + c;

	printf("maximum area of cardboaard is %f", max);
}