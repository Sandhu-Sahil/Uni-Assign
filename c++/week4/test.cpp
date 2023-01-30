#include <iostream>
using namespace std;

class complex
{
    private:
        int a,b;
    public:
        complex()
        {}
        complex(int x, int y)
        {
            a=x;
            b=y;
            cout<<a<<endl<<b<<endl;
        }
        complex(int x)
        {
            a=x;
            b=0;
        }
        complex(const complex &y)
        {
            a=y.a; b=y.b;
        }
        void show()
        {
            cout<<a<<endl<<b;
        }     
};
int main()
{
    complex c1, c2(5), c3(c2);
    c3.show();
    return 0;
}