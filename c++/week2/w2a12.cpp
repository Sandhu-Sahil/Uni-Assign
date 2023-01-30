#include <iostream>
using namespace std;

int main()
{
    int arr[4];
    cout<<"Input array of length 4 : "<<endl;
    for (int i = 0; i < 4; i++)
    {
        cin>>arr[i];
    }
    
    int (*ptr)[4];
    ptr = &arr;

    for (int i = 0; i < 4; i++)
    {
        cout<<"Value at location "<<ptr + i<<" is "<<arr[i]<<endl;
    }
    
    return 0;
}