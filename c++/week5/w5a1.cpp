#include <iostream>
using namespace std;

class A
{
    public:
        int a;
        void get_base()
        {
            cout<<"enter value of base: "<<endl;
            cin>>a;
        }
};

class B
{
    public:
        int b;
        void get_height()
        {
            cout<<"enter value of height:"<<endl;
            cin.clear();
            cin.ignore(10,'\n');
            cin>>b;
        }
};

class C : public A , public B
{
    public:
        void area()
        {
            cout<<"Area = "<<a*b<<endl;
        }
};

int main()
{
    C obj;
    obj.get_base();
    obj.get_height();
    obj.area();

    return 0;
}