#include<iostream>
#include<cmath>
using namespace std;

class triangle
{
    public:
        int a = 0, b = 0, c = 0;
        triangle(int x, int y, int z)
        {
            a = x;
            b = y;
            c = z;
        }
        perimeter()
        {
            return (a + b + c);
        }
        area()
        {
            float s = (a + b + c)/2;
            float x = s*(s-a)*(s-b)*(s-c);
            float a = sqrt(x);
            return a;
        }
};

int main()
{
    cout<<"Input sides of triangle:"<<endl;
    int x, y, z;
    cin>>x>>y>>z;
    triangle t1(x,y,z);
    cout<<"Perimeter of triangle is: "<< t1.perimeter()<<endl;
    cout<<"Area of triangle is: "<< t1.area()<<endl;
    return 0;
}