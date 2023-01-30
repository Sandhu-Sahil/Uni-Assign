#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Input the length of array : "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Input array : \n";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    bool b[n+1];
    int count=1;
    for (int i = 0; i < n+1 ; i++)
    {
        if (arr[i] > n)
        {
            continue;
        }
        if (arr[i] <= 0)
        {
            continue;
        }
        if (arr[i] <= n)
        {
            b[arr[i]-1] = true;
        }
    }

    for (int i = 0; i < n+1; i++)
    {
        if (b[i] == false)
        {
            cout<<i+1;
            break;
        }
    }

    return 0;
}