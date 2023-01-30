#include<iostream>
using namespace std;
int main()
{
    double a, b, c, d;

    cout << "Enter the values of a, b, c & d :: ";
    cin >> a >>b >>c >>d;

    double x = a / (b-c) + d;
    
    if ( (b-c) == 0)
    {
        cout << "x = Cannot divide by zero Error. Retry with different input";	
    }
    else
    {
        cout<<"x=a/(b-c)+d = "<<x;
    }

    return 0;
}
