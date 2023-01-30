#include <iostream>
#include <string>
using namespace std;

class String
{
    private:
        string* s;
        int size;
        string ss;
    public:
        String(string x)
        {
            size = x.length();
            ss = x;
            s = &ss;
        }
        String(const String &x)
        {
            s = x.s;
            size = x.size;
        }
        void print()
        {
            cout<<*s<<", "<<size<<endl;
        }
        ~String()
        {
            delete[] s;
            cout<<"destructor called"<<endl;
        }
};
int main()
{
    String s1("Sahilsher Singh"), s2(s1);
    cout<<"After copying: "<<endl;
    cout<<"s2.s, s2.size is ";
    s2.print();
    return 0;
}