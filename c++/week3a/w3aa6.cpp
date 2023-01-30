#include <iostream>
using namespace std;

class Area 
{
    public:
        int l, b;
        void setDim()
        {
            cout<<"Input dimentions of recctangle: "<<endl;
            cout<<"Input length"<<endl;
            cin>>l;
            cout<<"Input breath"<<endl;
            cin>>b;
        }
        void getArea()
        {
            cout<<"Area of rectangle: "<<(l*b)<<endl;
        }
};

int main ()
{
    Area a1;
    a1.setDim();
    a1.getArea();
    return 0;
}