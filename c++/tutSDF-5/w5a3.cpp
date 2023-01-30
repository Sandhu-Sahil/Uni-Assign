#include<iostream>
#include<string>
using namespace std;
class mystring
{
    string str;
    public:
        void accept()
        {
        cout<<"Enter string:-";
        cin>>str;
        }
        void operator !();
};
void mystring::operator !()
{
    int len;
    len=str.size();
    cout<<"\nReverse string is:-";
    for(int i=len-1;i>=0;i--)
    {
    cout<<str[i];
    }
}

int main()
{
    mystring m1;
    m1.accept();
    !m1;
    return 0;
}