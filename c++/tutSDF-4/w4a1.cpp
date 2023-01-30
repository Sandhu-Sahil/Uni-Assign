#include <iostream>
#include<string>
using namespace std;

class TravelPlan
{
    private: 
        long PlanCode;
        string place;
        int number_of_travellers;
        int number_of_buses;

    public:
        TravelPlan()
        {
            
        }
        TravelPlan(long x, string x2, int x3, int x4)
        {
            PlanCode = x;
            place = x2;
            number_of_travellers = x3;
            number_of_buses = x4;
        }
        newPlan()
        {
            cout<<"Set Plan-Code : "<<endl;
            cin>>PlanCode;
            cout<<"Change number of travellers :"<<endl;
            cin>>number_of_travellers;
            cout<<"change number of buses: "<<endl;
            cin>>number_of_buses;
        }
        display()
        {
            cout<<PlanCode<<endl;
            cout<<place<<endl;
            cout<<number_of_travellers<<endl;
            cout<<number_of_buses<<endl;
        }
};

int main()
{
    TravelPlan p1(5526664, "Delhi", 5, 1);
    p1.display();
    p1.newPlan();
    p1.display();
    return 0;
}