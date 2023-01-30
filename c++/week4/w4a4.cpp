#include <iostream>
using namespace std;
class Teacher 
{
    public:
    Teacher()
    {
        cout<<"Hey Guys, I am a teacher. "<<endl;
    }
    string collegeName = "Beginnersbook";
};

class MathTeacher: public Teacher 
{
    public:
    MathTeacher()
    {
        cout<<"I am a Math Teacher"<<endl;
    }
    string mainSub = "Math";
    string name = "Negan";
};

int main() 
{
    MathTeacher obj;
    cout<<"Name: "<<obj.name<<endl;
    cout<<"College Name: "<<obj.collegeName<<endl;
    cout<<"Main Subject: "<<obj.mainSub<<endl;
    cout<<obj.Teacher()<<obj.MathTeacher()<<endl;
    return 0;
}