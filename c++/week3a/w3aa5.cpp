#include<iostream>
using namespace std;

class second
{
    public:
        int personid;
        second(int x)
        {
            personid = x;
        }
        second()
        {
            //garbage value
        }
        void printid()
        {
            cout<<"Person ID is: "<< personid<<endl;
        }
};

int main()
{
    second p1, p2(11);
    cout<<"Default constructor: "<<endl;
    p1.printid();
    cout<<"Parameterized constructor: "<<endl;
    p2.printid();
    return 0;
}