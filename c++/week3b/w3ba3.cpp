#include <iostream>
using namespace std;
class Demo
{
    private:
        //static data members
        static int X;
        static int Y;
    public:
        //static member function
        static void Print()
        {
        cout <<"Value of X: " << X << endl;
        cout <<"Value of Y: " << Y << endl;
        }
};
//static data members initializations

int Demo :: X =10;
int Demo :: Y =20;

int main()
{
    Demo OB;
    //accessing class name with object name
    cout<<"Printing through object name:"<<endl;
    OB.Print();
    //accessing class name with class name
    cout<<"Printing through class name:"<<endl;
    Demo::Print();
    return 0;
}