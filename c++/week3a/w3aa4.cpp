#include<iostream>
#include<string>
using namespace std;

class First
{
    public:
        string studentname;
        void inputname()
        {
            cout<<"Input student name: "<<endl;
            getline(cin,studentname);
        }
        void printname()
        {
            cout<<"Student's name is..."<<endl;
            cout<<studentname;
        }
};

int main()
{
    First s1;
    s1.inputname();
    s1.printname();
}