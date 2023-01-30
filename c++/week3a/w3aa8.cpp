#include <iostream>
#include <string>
using namespace std;

class data
{
    private:
        string enrollNo;
        string name;
        string branch;
        float cgpa;
        
    public:
        data(string a, string b, string c, float d)
        {
            enrollNo = a;
            name = b;
            branch = c;
            cgpa = d;
        }
        data(string a, string b, float d)
        {
            enrollNo = a;
            name = b;
            branch = "CSE";
            cgpa = d;
        }
        data()
        {
            enrollNo = "1";
            name = "Unknown";
            branch = "CSE";
            cgpa = 6;
        }
        void set(data x)
        {
            cout<<x.enrollNo<<"\n"<<x.name<<"\n"<<x.branch<<"\n"<<x.cgpa<<endl;
            cout<<"Input the value you want to reset: \n1 - Enrollment Number \n2 - Name\n3 - Branch\n4 - CGPA"<<endl;
            int i;
            cin>>i;
            if (i >= 1 && i <= 4)
            {
                get(x, i);
            }
            else
            {
                cout<<"Wrong Input"<<endl;
            }
        }
        void get(data d, int x)
        {
            if (x==1)
            {
                cout<<"Input updated enrollment number:"<<endl;
                cin.ignore();
                getline(cin,d.enrollNo);
                cout<<"Updated......!!"<<endl;
                cout<<d.enrollNo<<"\n"<<d.name<<"\n"<<d.branch<<"\n"<<d.cgpa<<endl;
            }
            if (x==2)
            {
                cout<<"Input updated name of student"<<endl;
                cin.ignore();
                getline(cin,d.name);
                cout<<"Updated......!!"<<endl;
                cout<<d.enrollNo<<"\n"<<d.name<<"\n"<<d.branch<<"\n"<<d.cgpa<<endl;
            }
            if(x==3)
            {
                cout<<"Input updated branch of student"<<endl;
                cin.ignore();
                getline(cin,d.branch);
                cout<<"Updated......!!"<<endl;
                cout<<d.enrollNo<<"\n"<<d.name<<"\n"<<d.branch<<"\n"<<d.cgpa<<endl;
            }
            if (x==4)
            {
                cout<<"Input updated CGPA of student"<<endl;
                cin>>d.cgpa;
                cout<<"Updated......!!"<<endl;
                cout<<d.enrollNo<<"\n"<<d.name<<"\n"<<d.branch<<"\n"<<d.cgpa<<endl;
            }
        }
};

int main()
{
    data s1, s2("9921103131", "Sahilsher Singh", 9.2), s3("9921103131", "Sahilsher Singh", "CSE-128", 9.0);
    s3.set(s2);
    s2.set(s2);
    s1.set(s1);
    return 0;
}