#include<stdio.h>

void search(char a[10][20], char b[5][20])
{
    printf("Top 10 performers in PHYSICS\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%s\n",(a[i]));
    }
    printf("\nTop 5 performers in CHEMISTRY\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s\n",(b[i]));
    }
}

int main(void)
{
    char p[10][20];
    char c[5][20];
    printf("performers in PHYSICS\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%s",&(p[i]));
    }
    printf("performers in CHEMISTRY\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%s",&(c[i]));
    }
    
    printf("Displaying the names of stidents\n");

    search(p, c);
}