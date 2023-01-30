#include<iostream>
using namespace std;
int main()
{
	cout<<"Give m and n for MxN matrix:"<<endl;
	int m, n;
	cin>>m>>n;
	bool arr[m][n];

	for (int i = 0; i<m ; i++)
	{
		cout<<"input "<<i+1<<" row with n elements";
		cout<<endl;
		for (int j = 0 ; j < n ; j++)
		{
			cin>>arr[i][j];
		}
	}

    bool temp[m][n];
    for (int i =0; i < m ; i++)
    {
    	for (int j = 0 ; j< n ; j++)
    	{
    		if (arr[i][j] == 1)
    		{
    			for (int k =0; k<n  ; k++)
    			{
    				temp[i][k] = 1;
    			}
    		}
    	}
    }
    for (int i =0; i < n ; i++)
    {
    	for (int j = 0 ; j< m ; j++)
    	{
    		if (arr[j][i] == 1)
    		{
    			for (int k =0; k<n  ; k++)
    			{
    				temp[k][i] = 1;
    			}
    		}
    	}
    }
    
    cout<<"matrix after transformation: "<<endl;

    for (int i = 0; i < m ;i++)
    {
        for (int j = 0; j< n; j++)
        {
            cout<<temp[i][j];
        }
        cout<<endl;
    }

	return 0;
}