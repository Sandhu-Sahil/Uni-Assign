#include <iostream>
using namespace std;

int main()
{
    int arr[3][3][3];
    cout<<"Input integers for 3D matrix 3x3x3"<<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cin>>arr[i][j][k];
            }            
        }        
    }

    cout<<"Displaying 3D array"<<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cout<<arr[i][j][k]<<" ";
            } 
            cout<<endl;           
        }  
        cout<<"..."<<endl;      
    }    
}