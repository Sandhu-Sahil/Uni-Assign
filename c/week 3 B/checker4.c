#include<stdio.h>

int main(void)
{
    char a;
    printf("Input an alphabet :");
    scanf("%c",&a);
    
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
    {
        printf("Alphabet is a vowel");
    }
    else
    {
        printf("Alphabet is consonent");
    }
}