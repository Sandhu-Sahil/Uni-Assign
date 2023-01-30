#include <iostream>
using namespace std;

class Wall
{
    private:
        float length;
        float height;
    public:
        Wall(float l, float h)
        {
            length = l;
            height = h;
        }
        wall(const Wall &x)
        {
            length = x.length;
            height = x.height;
        }
        void print()
        {
            cout<<length<<", "<<height;
        }
        float area()
        {
            return (length*height);
        }
};
int main()
{
    Wall l1(3.3, 6), l2(l1);
    cout<<"Area of l1 = "<<l1.area()<<endl;
    cout<<"After copying l1 to l2"<<endl;
    cout<<"l2.length, l2.height is ";
    l2.print();
    cout<<endl;
    return 0;
}