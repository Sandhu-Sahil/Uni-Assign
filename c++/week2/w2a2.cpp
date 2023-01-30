#include <iostream>
using namespace std;

int main()
{
    int a[3];
    int *ptr = a;
    cout<<"Input 3 integers"<<endl;
    for (int i = 0; i < 3; i++)
    {
        cin>>a[i];
    }

    cout<<"Increment a Pointer (++)"<<endl;
    cout<<"\tSample output after incrementing pointer:"<<endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "\tAddress at var["<<i<<"] = " << ptr <<endl;
        cout << "\tValue at var["<<i<<"] = "<< *ptr <<endl;
        ptr++;
    }
    
    cout<<"Decrement a Pointer (--)"<<endl;
    cout<<"\tSample output after decrementing pointer:"<<endl;
    for (int i = 3; i > 0; i--)
    {
        ptr--;
        cout << "\tAddress at var["<<i-1<<"] = " << ptr <<endl;
        cout << "\tValue at var["<<i-1<<"] = "<< *ptr <<endl;
    }
    
    return 0;
}