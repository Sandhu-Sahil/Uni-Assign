#include <iostream>
using namespace std;

int main()
{
    int a=10, b=0, c;
    try 
    {
        if(b == 0)
        {
            throw "Division by zero not possible";            
        }
        c = a/b;
    }
    catch(const char* ex) // catches exception
    {
        cout<<ex<<endl;
    }

    char d = 'A';
    try
    {
        if (d == 'A')
        {
            throw d;
        }
    }
    catch(const char a)
    {
        cout<<"exception thrown it's a char '"<<d<<"'"<<endl;
    }

    try
    {
        throw 28.06;
    }
    catch(double x)
    {
        cout<<"exception thrown it's a double '"<<x<<"'"<<endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}