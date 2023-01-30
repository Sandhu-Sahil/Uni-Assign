#include <iostream>
using namespace std;

int main ()
{
	int* p = NULL;

	p = new int;

	cout << "Input value of p: " << endl;
    cin>> *p;
    cout << "Value of p is : " << *p << endl;

	float *r = new float;
    cout << "Input value of r: " << endl;
    cin>>*r;

	cout << "Value of r: " << *r << endl;

	delete p;
	delete r;

	return 0;
}
