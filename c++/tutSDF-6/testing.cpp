#include<iostream>
using namespace std;

class base
{
    public:
        base() {cout<<"cb";}
        virtual ~base() {cout<<"db";}
};

class derived : public base{
    public:
        derived(){cout<<"cd";}
        ~derived(){cout<<"dd";}
};

int main()
{
    base *ptr = new derived();
    delete ptr;
    return 0;
}