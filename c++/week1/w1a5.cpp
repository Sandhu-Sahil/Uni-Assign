#include <iostream>
using namespace std;

bool isprime(int n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
	int arr[] = {3, 0, 2, 5};
	int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < (n); i++)
    {
        for (int j = 0; j < (n-1); j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    int count = 0;
    while (true)
    {
        bool a = isprime(count);
        if (a == true)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == count)
                {
                    count++;
                    break;
                }
                else if (arr[n-1] < count)
                {
                    cout<<"No prime number missing"<<endl;
                    cout<<"As "<< arr[n-1]<<" is the maximum element and all prime numbers upto "<<arr[n-1]<<" are present in the array.";
                    break;
                }
                else
                {
                    if(arr[i]<count)
                    {
                        continue;
                    }
                    if(arr[i]>count)
                    {
                        cout<<count<<" is the smallest prime, which is not present in array.";
                        return 1;
                    }
                }
            }

        }
        else if (arr[n-1] < count)
        {
            cout<<"No prime number missing"<<endl;
            cout<<"As "<< arr[n-1]<<" is the maximum element and all prime numbers upto "<<arr[n-1]<<" are present in the array.";

            break;
        }
        else
        {
            count++;
            continue;
        }
    }

	return 0;
}