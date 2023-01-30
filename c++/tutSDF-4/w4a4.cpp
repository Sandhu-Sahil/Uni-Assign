#include<iostream>
using namespace std;

class student{
int rollno;
char grade;
static int count;
public:
student()
{
rollno=0; grade=' ';
cout<<"Creating object"<<++count<<"\n";
}
void init(void)
{
cout<<"\n Enter rollo and grade :";
cin>>rollno>>grade;
cout<<"\n";
}
~student()
{
    cout<<"Destroying object"<<--count<<"\n";
}
};
int student::count=0;
int main()
{
student classes[5];
for(int i=0;i<5;i++)
{
    cout<<"Enter details for student"<<i+1<<"\n";
    classes[i].init();
}
return 0;
}