#include <iostream>
using namespace std;

class ClassA;
class ClassB;
int sum(ClassA x, ClassB y);

class ClassA
{
    private:
        int numA = 13;
        friend int sum(ClassA x, ClassB y);
};
class ClassB
{
    private:
        int numB = 11;
        friend int sum(ClassA x, ClassB y);
};
int sum(ClassA x, ClassB y)
{
    int s = x.numA + y.numB;
    return s;
}
int main()
{
    ClassA a;
    ClassB b;
    cout<<"The sum is "<<sum(a, b)<<endl;
    return 0;
}