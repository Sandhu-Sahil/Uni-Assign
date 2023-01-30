#include <iostream>
using namespace std;

int main()
{
    int n; 
    cout<<"Input length of array: "<<endl;
    cin>>n;
    int arr[n];
    int* ptr = arr;
    cout<<"Input "<<n<<" elements of array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<"Original array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<*(ptr+i)<<" ";
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (*(ptr+j) > *(ptr+j+1))
            {
                int temp = *(ptr+j);
                *(ptr+j) = *(ptr+j+1);
                *(ptr+j+1) = temp;
            }
        }
    }

    cout<<"\nArray after Sorting:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<*(ptr+i)<<" ";
    }

    for (int i = 0; i < n/2; i++)
    {
        int temp = *(ptr+i);
        *(ptr+i) = *(ptr+n-i-1);
        *(ptr+n-i-1) = temp;
    }
    
    cout<<"\nAfter reversing the array:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<*(ptr+i)<<" ";
    }

    return 0;
}