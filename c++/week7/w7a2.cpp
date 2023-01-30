#include<iostream>
using namespace std;

int main()
{
    int wait_time = 12;
    try
    {
        cout << "Try block entered.\n";
        if (wait_time > 30)
            throw wait_time;
        cout << "Leaving try block.\n";
    }
    catch(int thrown_value)
    {
        cout << "Exception thrown with\n"<< "wait_time equal to " << thrown_value << endl;
    }
    cout << "After catch block." << endl;
}