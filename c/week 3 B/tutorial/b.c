#include <stdio.h>
#include <string.h>

struct student
{
    char branch_info[10];
    char name[10];
    int roll_no;
    float CGPA;
    char branch[10];
};

int main(void)
{
    struct student s[10];
    for (int i = 0; i < 10; i++)
    {
        printf("student %d\n",i+1);
        scanf("%s",&s[i].branch_info);
        scanf("%s",&s[i].name);
        scanf("%i",&s[i].roll_no);
        scanf("%f",&s[i].CGPA);
        scanf("%s",&s[i].branch);
    }

    int maxcs=0, maxec=0, maxmec=0;
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(s[i].branch, "CS"))
        {
            if (s[i].CGPA >= s[maxcs].CGPA)
            {
                maxcs = i;
            }
        }

        if (strcmp(s[i].branch, "EC"))
        {
            if (s[i].CGPA >= s[maxec].CGPA)
            {
                maxec = i;
            }
        }

        if (strcmp(s[i].branch, "MEC"))
        {
            if (s[i].CGPA >= s[maxmec].CGPA)
            {
                maxmec = i;
            }
        }
    }

    printf("%s",s[maxcs].branch_info);
    printf("%s",s[maxcs].name);
    printf("%s",s[maxcs].roll_no);
    printf("%s",s[maxcs].CGPA);
    printf("%s",s[maxcs].branch);

    printf("%s",s[maxec].branch_info);
    printf("%s",s[maxec].name);
    printf("%s",s[maxec].roll_no);
    printf("%s",s[maxec].CGPA);
    printf("%s",s[maxec].branch);
    
    printf("%s",s[maxmec].branch_info);
    printf("%s",s[maxmec].name);
    printf("%s",s[maxmec].roll_no);
    printf("%s",s[maxmec].CGPA);
    printf("%s",s[maxmec].branch);
}
