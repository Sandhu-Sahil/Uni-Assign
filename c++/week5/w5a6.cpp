#include<iostream>
using namespace std;

class Base
{
    public:
        int sum;
        virtual void display() = 0;
        Base(int x, int y)
        {
            sum = x + y;
        }
};

class Derived: public Base
{
    public:
        Derived(int x, int y):Base(x,y){}

        void display() 
        {
            cout<<"Sum is "<<sum<<endl;
        }
};

int main()
{
    //Base obj;
	Derived d(2,3);
    d.display();
	return 0;
}