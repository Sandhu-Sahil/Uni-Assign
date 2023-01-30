#include<iostream>
using namespace std;

class A
{
protected:
    int protectedA = 10;
public:
    void get_data()
    {
        cout<<"In class A :"<<endl;
        cout<<"Value of protected A = "<<protectedA<<endl;
    }
};

class B : protected A
{
protected:
    int protectedB = 20;
public:
    void get_data()
    {
        cout<<"In class B :"<<endl;
        cout<<"Value of protected A = "<<protectedA<<endl;
        cout<<"Value of protected B = "<<protectedB<<endl;
    }
};

int main()
{
    A objA;
    B objB;
    objA.get_data();
    objB.get_data();

    return 0;
}