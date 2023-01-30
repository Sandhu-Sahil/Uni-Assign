#include <iostream>
using namespace std;
void sample_function(double test) throw (int);
int main()
{
try
{
cout << "Trying.\n";
sample_function(212);
cout << "Trying after call.\n";
}
catch(int)
{
cout << "Catching.\n";
}
cout << "End of program.\n";
return 0;
}
void sample_function(double test) throw (int)
{
cout << "Starting sample_function.\n";
if (test < 100)
throw 42;
}