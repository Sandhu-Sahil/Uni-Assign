#include <iostream>
#include <string>
using namespace std;

class studentsDetails 
{
    public:
        string name;
        string enroll;
        void getDetails()
        {
            cout<<"enter value of name : ";
            getline(cin, name);
            cout<<"enter value of eno. : ";
            getline(cin, enroll);
        }
};

class Marks
{
    public:
        int marks[5];
        void getMarks()
        {
            for (int i = 0; i < 5; i++)
            {
                cout<<"enter value of marks ["<<i<<"] ";
                cin>>marks[i];
            }            
        }
};

class C: public studentsDetails, public Marks
{
    public:
        int total1 = 0;
        void total()
        {
            for (int i = 0; i < 5; i++)
            {
                total1 = total1 + marks[i];
            }
            cout<<"Total = "<<total1<<endl;
        }               
};

int main()
{
    C obj;
    obj.getDetails();
    obj.getMarks();
    obj.total();

    return 0;
}