#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Input number of students:"<<endl;
    cin>>n;

    float * ptr = new float[n];
    cout<<"Input CGPA of n students : "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>*(ptr+i);
    }
    cout<<"Displaying CGPA of n students:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"CGPA of Student "<<i+1<<" is "<<*(ptr+i)<<endl;
    }
    
    return 0;
}