#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Input the length of array:"<<endl;
    cin>>n;

    int arr[n];
    cout<< "Input "<<n<<" integers for array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int search;
    cout<<"Input Element to search: "<<endl;
    cin>>search;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == search)
        {
            cout<<"The element "<<search<<" is present at location: "<<i<<endl;
        }    
    }
    
    return 0;
}