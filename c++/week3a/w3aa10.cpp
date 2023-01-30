#include<iostream>
using namespace std;

class Location
{
    private:
        int a, b;
    public:
        Location(int a1, int b1) { a = a1; b = b1; }
        // Copy constructor
        Location(const Location &x) {a = x.a; b = x.b; }
        int getA() { return a; }
        int getB() { return b; }
};
int main()
{
    Location l1(10, 15); // Normal constructor is called here
    Location l2(l1); // Copy constructor is called here
    
    // Let us access values assigned by constructors
    cout <<"l1.a = "<<l1.getA() <<", l1.b = "<<l1.getB();
    cout <<"\np2.a = "<<l2.getA() <<", l2.b = "<<l2.getB();
    return 0;
}