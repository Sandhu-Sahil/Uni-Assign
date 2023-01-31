#include <iostream>
using namespace std;
 
int fib(int n)
{
    if (n <= 1){
        return n;
    }
    return (fib(n - 1) + fib(n - 2));
}
 
int main()
{
    int n = 9;
    cout<<fib(n)<<endl;
    return 0;
}

// Time complexity of this is exponential O(2^N) [as everytime two further functions are called]
// space complexity is O(N)