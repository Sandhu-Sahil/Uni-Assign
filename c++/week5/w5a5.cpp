#include<iostream>
using namespace std;

class Base
{
    public:
        virtual void display1() = 0;
        virtual void display2() = 0;
};

class Derived: public Base
{
    public:
        void display1() 
        {
            cout<<"This is Display1() method of Derived Class \n";
        }
        void display2()
        {
            cout<<"This is Display2() method of Derived Class";
        }
};

int main(void)
{
    Base *obj;
	Derived d;
    obj = &d;
    obj->display1();
    obj->display2();
	return 0;
}
