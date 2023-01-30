#include <iostream>
using namespace std;

struct phone
{
    int price;
    int battery;
    int rating;
};

int main()
{
    phone p[2];

    for (int i = 0; i < 2; i++)
    {
        cout<<"Enter Phone"<<i+1<<" details:"<<endl;
        cout<<"Enter Price:"<<endl;
        cin >> p[i].price;
        cout<<"Enter Battery Power(In mAh):"<<endl;
        cin >> p[i].battery;
        cout<< "Enter Rating(between 0-5):"<<endl;
        cin >> p[i].rating;
    }

    if (p[0].price > p[1].price)
    {
        cout<<"Phone better w.r.t Price is Phone1"<<endl;
    }
    else
    {
        cout<<"Phone better w.r.t Price is Phone2"<<endl;
    }

    if (p[0].battery > p[1].battery)
    {
        cout<<"Phone better w.r.t Battery Power is Phone1"<<endl;
    }
    else
    {
        cout<<"Phone better w.r.t Battery Power is Phone2"<<endl;
    }
    
    if (p[0].rating > p[1].rating)
    {
        cout<<"Phone better w.r.t Rating is Phone1"<<endl;
    }
    else
    {
        cout<<"Phone better w.r.t Rating is Phone2"<<endl;
    }
}