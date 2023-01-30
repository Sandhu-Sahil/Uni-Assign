#include <iostream>
using namespace std;

int main()
{
	int m , n ;
    cout<<"Input dimentions of 2D array as MxN: "<<endl;
    cin>>m>>n;

	int* arr = new int[m * n];

	for (int i = 0; i < m; i++) 
    {
        cout<<"Input "<<n<<" elements for "<<i+1<<" row"<<endl;
		for (int j = 0; j < n; j++) 
        {
			cin>>*(arr + (i * n) + j);
		}
	}

    cout<<"Printing 2D  array:"<<endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) 
        {
			cout<<*(arr + (i * n) +j)<<" ";
		}
        cout<<"\n";
	}

	delete[] arr;
	return 0;
}
