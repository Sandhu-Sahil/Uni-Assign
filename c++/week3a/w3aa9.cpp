#include <iostream>
#include <string>
using namespace std;

class bill
{
    public:
        int houseNo;
        string name;
        int bill;
        void get()
        {
            cout<<"Input name of the person: "<<endl;
            getline(cin,name);
            cout<<"Input house number of the person: "<<endl;
            cin>>houseNo;
        }
        void calc_bill()
        {
            int x;
            cout<<"Input units used by person: "<<endl;
            cin>>x;
            bill = (7 * x);
        }
        void put()
        {
            cout<<"House number: "<<houseNo<<endl;
            cout<<"Owner name: "<<name<<endl;
            cout<<"Tatal bill: "<<bill<<endl;
        }
};

int main()
{
    bill p1;
    p1.get();
    p1.calc_bill();
    p1.put();
}