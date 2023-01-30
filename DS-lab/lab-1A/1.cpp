#include<iostream>
using namespace std;
class time_stamp
{
    public:
    int hour;
    int minutes;
    int seconds;
    time_stamp()
    {}

    time_stamp(int h,int m,int s)
    {
        hour=h;
        minutes=m;
        seconds=s;
    }
    void testing(time_stamp ts)
    {

        try{
            if(ts.hour>23)
            {throw ts.hour;}
           }
        catch(int x)
           {
        cout<<"You have entered "<<x<<". Hours must be <=23"<<endl;
           }
        try{
            if(ts.minutes>60)
            {throw ts.minutes;}
           }
        catch(int y)
           {
        cout<<"You have entered "<<y<<". Minutes must be <=60"<<endl;
           }
        try{
            if(ts.seconds>60)
            {throw ts.seconds;}
           }
        catch(int z)
           {
        cout<<"You have entered "<<z<<". Seconds must be <=60"<<endl;
           }
    }
    time_stamp operator -(time_stamp const &ts2)
    {
        time_stamp sub;
        sub.hour=hour-ts2.hour;
        sub.minutes=minutes-ts2.minutes;
        sub.seconds=seconds-ts2.seconds;
        return sub;
    }
    void print_data()
    {
        cout<<"Hours: "<<hour<<endl;
        cout<<"Minutes: "<<minutes<<endl;
        cout<<"Seconds: "<<seconds<<endl;
    }
};
int main()
{

    time_stamp ts1(7,59,54);
    time_stamp ts2(5,13,52);
    time_stamp ts3=ts1-ts2;
    ts1.print_data();
    cout<<endl;
    ts2.print_data();
     cout<<endl;
    cout<<"On subtracting 1st from 2nd , we get : "<<endl;
    ts3.print_data();
    return 0;
}
